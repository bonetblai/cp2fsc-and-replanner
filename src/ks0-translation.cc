/*
 *  Copyright (C) 2011 - <date> Blai Bonet, Universidad Simon Bolivar
 *
 *  Permission is hereby granted to distribute this software for
 *  non-commercial research purposes, provided that this copyright
 *  notice is included with any such distribution.
 *
 *  THIS SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 *  EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *  PURPOSE.  THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE
 *  SOFTWARE IS WITH YOU.  SHOULD THE PROGRAM PROVE DEFECTIVE, YOU
 *  ASSUME THE COST OF ALL NECESSARY SERVICING, REPAIR OR CORRECTION.
 *
 *  Blai Bonet, bonet@ldc.usb.ve, bonetblai@gmail.com
 *
 */

#include <cassert>
#include <iostream>
#include <iomanip>
#include <limits>
#include <libgen.h>
#include "cp_problem.h"
#include "ks0_problem.h"
#include "preprocess.h"
#include "parser.h"
#include "state.h"
#include "solver.h"
#include "options.h"
#include "available_options.h"
#include "utils.h"

using namespace std;

Options::Mode g_options;

void print_usage(ostream &os, const char *exec_name, const char **cmdline_options) {
    char *tmp = strdup(exec_name);
    const char *base_name = basename(tmp);
    int indent_len = strlen("usage: ") + strlen(base_name) + 1;
    string indent(indent_len, ' ');

    os << endl << "usage: " << base_name << " ";
    free(tmp);

    if( cmdline_options[0] == 0 ) {
        os << endl;
    } else {
        os << cmdline_options[0] << endl;
        for( int i = 1; cmdline_options[i] != 0; ++i ) {
            os << indent << "" << cmdline_options[i] << endl;
        }
    }

    os << indent << "[--options=<options>]" << endl
       << indent << "<pddl-files>" << endl
       << endl
       << "where <options> is a comma-separated list of options from:" << endl
       << endl;

    for( Options::Mode::const_iterator it = g_options.begin(); it != g_options.end(); ++it ) {
        const Options::Option &opt = *it;
        os << "    " << left << setw(35) << opt.name() << "  " << opt.desc() << endl;
    }
    os << endl << endl;
}

int main(int argc, const char *argv[]) {
    StringTable parser_symbol_table(lowercase_map, 50);
    int         opt_bounded_reachability = numeric_limits<int>::max();
    bool        opt_debug_parser = false;
    string      opt_prefix = "";
    bool        opt_tag_all_literals = true;
    float       start_time = Utils::read_time_in_seconds();

    // print cmdline
    cout << "cmdline: " << Utils::cmdline(argc, argv) << endl;

    // initialize options
    for( const char **opt = &available_options[0]; *opt != 0; ++opt ) {
        const char *name = *opt++;
        const char *desc = *opt;
        g_options.add(name, desc);
    }

    // check correct number of parameters
    const char *exec_name = argv[0];
    if( argc == 1 ) {
        print_usage(cout, exec_name, ks0_cmdline_options);
        exit(0);
    }

    int nfiles = 0;
#ifdef SMART
    unique_ptr<Parser> reader = make_unique<Parser>(Parser::cp2fsc, parser_symbol_table, g_options);
#else
    Parser *reader = new Parser(Parser::cp2fsc, parser_symbol_table, g_options);
#endif

    // parse options
    bool skip_options = false;
    for( int k = 1; k < argc; ++k ) {
        if( !skip_options && !strcmp(argv[k], "--help") ) {
            print_usage(cout, exec_name, ks0_cmdline_options);
            exit(0);
        } else if( !skip_options && !strcmp(argv[k], "--bounded-reachability") ) {
            if( k == argc - 1 ) {
                cout << Utils::error() << "not enough arguments for '" << argv[k] << "'." << endl;
                exit(-1);
            }
            opt_bounded_reachability = atoi(argv[++k]);
        } else if( !skip_options && !strcmp(argv[k], "--debug-parser") ) {
            opt_debug_parser = true;
        } else if( !skip_options && !strcmp(argv[k], "--prefix") ) {
            if( k == argc - 1 ) {
                cout << Utils::error() << "not enough arguments for '" << argv[k] << "'." << endl;
                exit(-1);
            }
            opt_prefix = argv[++k];
        } else if( !skip_options && !strcmp(argv[k], "--no-tag-all-literals") ) {
            opt_tag_all_literals = false;
        } else if( !skip_options && !strncmp(argv[k], "--options=", 10) ) {
            const char *options = &argv[k][10];
            parse_options(g_options, options);
        } else if( !skip_options && !strcmp(argv[k], "--override-defaults") ) {
            g_options.clear_enabled_and_disabled();

        // if '--', stop parsing options. Remaining fields are file names.
        } else if( !skip_options && !strcmp(argv[k], "--") ) {
            skip_options = true;

        // unrecognized option.
        } else if( !skip_options && argv[k][0] == '-' ) {
            cout << Utils::error() << "unrecognized option '" << argv[k] << "'." << endl;
            exit(-1);

        // read input file
        } else if( *argv[k] != '-' ) {
            cout << "reading " << argv[k] << "..." << endl;
            reader->read(argv[k], opt_debug_parser);
            ++nfiles;
            // after first file name, the rest of arguments are assumed to be file names
            skip_options = true;
        } else {
            cout << "reading from <stdin>..." << endl;
            reader->read("-", opt_debug_parser);
            ++nfiles;
        }
    }

    // check that there is at least one input file
    if( nfiles == 0 ) {
        cout << Utils::error() << "need an input file." << endl;
        exit(-1);
    }

    // print file read by parser
    if( g_options.is_enabled("parser:print:raw") ) {
        reader->print(cout);
    }

    Instance instance(g_options);

    cout << "instantiating conformant problem..." << endl;
    reader->instantiate_elements();
    reader->emit_instance(instance);
    if( g_options.is_enabled("problem:print:raw") ) {
        instance.write_domain(cout);
        instance.write_problem(cout);
    }

#if 0 // THIS IS NOT WORKING W/ EXPLICIT INITIAL STATES: GUESS: EXPLICIT I-STATES ARE NOT PREPROCESSED
    cout << "preprocessing conformant problem..." << endl;
    Preprocessor prep(instance);
    prep.preprocess(true);
    if( g_options.is_enabled("problem:print:preprocessed") ) {
        instance.write_domain(cout);
        instance.write_problem(cout);
    }
#endif

    cout << "creating KS0 translation..." << endl;
    KS0_Instance ks0_instance(instance, opt_bounded_reachability, opt_tag_all_literals);
    if( g_options.is_enabled("ks0:print:raw") ) {
        ks0_instance.write_domain(cout);
        ks0_instance.write_problem(cout);
    }

#if 0 // THIS IS NOT WORKING W/ EXPLICIT INITIAL STATES: GUESS: EXPLICIT I-STATES ARE NOT PREPROCESSED
    cout << "preprocessing KS0 translation..." << endl;
    Preprocessor ks0_prep(ks0_instance);
    ks0_prep.preprocess(true);
    if( g_options.is_enabled("ks0:print:preprocessed") ) {
        ks0_instance.write_domain(cout);
        ks0_instance.write_problem(cout);
    }
#endif

    // write output files
    cout << "writing files..." << flush;
    ofstream dom_ofs(string(opt_prefix + "d.pddl").c_str());
    ks0_instance.write_domain(dom_ofs);
    dom_ofs.close();
    ofstream prb_ofs(string(opt_prefix + "p.pddl").c_str());
    ks0_instance.write_problem(prb_ofs);
    prb_ofs.close();
    cout << endl;

    // print some stats
    cout << "stats: "
         << Utils::read_time_in_seconds() - start_time << " (total time)"
         << endl;

    return 0;
}

