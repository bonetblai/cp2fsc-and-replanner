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

    if( cmdline_options[0] == nullptr ) {
        os << endl;
    } else {
        os << cmdline_options[0] << endl;
        for( int i = 1; cmdline_options[i] != nullptr; ++i ) {
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
    float start_time = Utils::read_time_in_seconds();
    StringTable parser_symbol_table(lowercase_map, 50);

    int    opt_bounded_reachability = numeric_limits<int>::max();
    bool   opt_compound_obs_as_fluents = false;
    bool   opt_debug_parser = false;
    bool   opt_forbid_inconsistent_tuples = true;
    int    opt_fsc_states = 1;
    string opt_metadata_filename = "";
    string opt_prefix = "";
    bool   opt_single_monolithic_action = false;
    bool   opt_tag_all_literals = false;
    bool   opt_tag_actions = false;

    // print cmdline
    cout << "cmdline: " << Utils::cmdline(argc, argv) << endl;

    // initialize options
    for( const char **opt = &available_options[0]; *opt != nullptr; ++opt ) {
        const char *name = *opt++;
        const char *desc = *opt;
        g_options.add(name, desc);
    }

    // check correct number of parameters
    const char *exec_name = argv[0];
    if( argc == 1 ) {
        print_usage(cout, exec_name, cp2fsc_cmdline_options);
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
            print_usage(cout, exec_name, cp2fsc_cmdline_options);
            exit(0);
        } else if( !skip_options && !strcmp(argv[k], "--bounded-reachability") ) {
            if( k == argc - 1 ) {
                cout << Utils::error() << "not enough arguments for '" << argv[k] << "'." << endl;
                exit(-1);
            }
            opt_bounded_reachability = atoi(argv[++k]);
        } else if( !skip_options && !strcmp(argv[k], "--compound-obs-as-fluents") ) {
            opt_compound_obs_as_fluents = true;
            cout << Utils::error() << "'" << argv[k] << "' is currently not implemented." << endl;
            exit(-1);
        } else if( !skip_options && !strcmp(argv[k], "--debug-parser") ) {
            opt_debug_parser = true;
        } else if( !skip_options && !strcmp(argv[k], "--fsc-states") ) {
            if( k == argc - 1 ) {
                cout << Utils::error() << "not enough arguments for '" << argv[k] << "'." << endl;
                exit(-1);
            }
            opt_fsc_states = atoi(argv[++k]);
        } else if( !skip_options && !strcmp(argv[k], "--no-forbid-inconsistent-tuples") ) {
            opt_forbid_inconsistent_tuples = false;
        } else if( !skip_options && !strcmp(argv[k], "--output-metadata") ) {
            if( k == argc - 1 ) {
                cout << Utils::error() << "not enough arguments for '" << argv[k] << "'." << endl;
                exit(-1);
            }
            opt_metadata_filename = argv[++k];
        } else if( !skip_options && !strcmp(argv[k], "--prefix") ) {
            if( k == argc - 1 ) {
                cout << Utils::error() << "not enough arguments for '" << argv[k] << "'." << endl;
                exit(-1);
            }
            opt_prefix = argv[++k];
        } else if( !skip_options && !strcmp(argv[k], "--single-monolithic-action") ) {
#ifndef OPTION_FOR_SINGLE_MONOLITHIC_ACTION
            cout << Utils::warning() << "option '" << argv[k] << "' is currently disabled" << endl;
#endif
            opt_single_monolithic_action = true;
        } else if( !skip_options && !strcmp(argv[k], "--tag-actions") ) {
            opt_tag_actions = true;
        } else if( !skip_options && !strcmp(argv[k], "--tag-all-literals") ) {
            opt_tag_all_literals = true;
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

    cout << "instantiating control problem..." << endl;
    reader->instantiate_elements();
    reader->emit_instance(instance);
    if( g_options.is_enabled("problem:print:raw") ) {
        instance.print(cout);
        instance.write_domain(cout);
        instance.write_problem(cout);
    }

    cout << "preprocessing control problem..." << endl;
    Preprocessor prep(instance);
    prep.preprocess(true);
    if( g_options.is_enabled("problem:print:preprocessed") ) {
        instance.print(cout);
        instance.write_domain(cout);
        instance.write_problem(cout);
    }

    cout << "creating CP translation..." << endl;
    CP_Instance cp_instance(instance,
                            opt_fsc_states,
                            opt_bounded_reachability,
                            opt_single_monolithic_action,
                            opt_forbid_inconsistent_tuples,
                            opt_compound_obs_as_fluents);
    if( g_options.is_enabled("cp:print:raw") ) {
        cp_instance.write_domain(cout);
        cp_instance.write_problem(cout);
    }

    cout << "preprocessing CP translation..." << endl;
    Preprocessor cp_prep(cp_instance);

    // For some reason, true instead of false works better in some hard problems such as
    // visual marker. This flag instruct the preprocessor to remove unreachable and
    // static atoms. This odd behaviour could be a bug somewhere...
    cp_prep.preprocess(false);

    if( g_options.is_enabled("cp:print:preprocessed") ) {
        cp_instance.write_domain(cout);
        cp_instance.write_problem(cout);
    }

    cout << "creating KS0 translation..." << endl;
    KS0_Instance ks0_instance(cp_instance, opt_tag_all_literals, opt_tag_actions);
    if( g_options.is_enabled("ks0:print:raw") ) {
        ks0_instance.write_domain(cout);
        ks0_instance.write_problem(cout);
    }

    cout << "preprocessing KS0 translation..." << endl;
    Preprocessor ks0_prep(ks0_instance);
    ks0_prep.preprocess(true);
    if( g_options.is_enabled("ks0:print:preprocessed") ) {
        ks0_instance.write_domain(cout);
        ks0_instance.write_problem(cout);
    }

    // write output files
    cout << "writing files..." << flush;
    ofstream dom_ofs(string(opt_prefix + "d.pddl").c_str());
    ks0_instance.write_domain(dom_ofs);
    dom_ofs.close();
    ofstream prb_ofs(string(opt_prefix + "p.pddl").c_str());
    ks0_instance.write_problem(prb_ofs);
    prb_ofs.close();
    if( opt_metadata_filename != "" ) {
        ofstream met_ofs(string(opt_prefix + opt_metadata_filename).c_str());
        met_ofs << "nqstates " << opt_fsc_states << " "
                << "nobs " << cp_instance.n_obs() << " "
                << "ntags " << ks0_instance.n_tags()
                << endl;
        met_ofs.close();
    }
    cout << endl;

    // print some stats
    cout << "stats: "
         << Utils::read_time_in_seconds() - start_time << " (total time)"
         << endl;

    return 0;
}

