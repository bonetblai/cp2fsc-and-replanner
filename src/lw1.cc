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
#include <libgen.h>
#include <map>
#include <memory>
#include <string>
#if 0
#include "action_selection.h"
#include "problem.h"
#include "state.h"
#include "clg_problem.h"
#include "width.h"
#include "width_search.h"
#include "despot.h"
#endif
#include "available_options.h"
#include "classical_planner_wrapper.h"
#include "hop.h"
#include "inference_engine.h"
#include "lw1_problem.h"
#include "lw1_solver.h"
#include "options.h"
#include "parser.h"
#include "preprocess.h"
#include "random_action_selection.h"
#include "string_table.h"
#include "utils.h"

using namespace std;

Options::Mode g_options;

struct ASMethod {
    string as_name_;
    string solver_option_str_;
    map<string, string> options_;
};

void parse_as_string(const string as_string, ASMethod &as_method) {
    //cout << "as_string=|" << as_string << "|" << endl;

    size_t start_pos = as_string.find('(');
    size_t end_pos = as_string.find(')', start_pos);
    if( (start_pos == string::npos) || (end_pos == string::npos) ) {
        cout << Utils::error() << "bad format for action-selection method." << endl;
        exit(-1);
    }
    as_method.as_name_ = string(as_string, 0, start_pos);
    //cout << "as_name=|" << as_method.as_name_ << "|" << endl;

    assert(as_string.at(start_pos) == '(');
    size_t next_pos = as_string.find_first_of(",)", ++start_pos);
    while( next_pos <= end_pos ) {
        //cout << "start-pos=" << start_pos << ", next-pos=" << next_pos << endl;
        string token(as_string, start_pos, next_pos - start_pos);
        //cout << "token=|" << token << "|" << endl;
        start_pos = 1 + next_pos;
        next_pos = as_string.find_first_of(",)", start_pos);
        if( token != "" ) {
            size_t pos = token.find('=');
            if( pos == string::npos ) {
                cout << Utils::warning() << "invalid token '" << token << "' in AS method; skipping it..." << endl;
            } else {
                //cout << "key=|" << token.substr(0, pos) << "|, value=|" << token.substr(1 + pos) << "|" << endl;
                as_method.options_.insert(make_pair(token.substr(0, pos), token.substr(1 + pos)));
            }
        }
    }

    // global AS options
    if( as_method.options_.find("debug") == as_method.options_.end() )
        as_method.options_.insert(make_pair("debug", "0"));

    // specific AS option
    if( as_method.as_name_ == "classical-planner" ) {
        as_method.solver_option_str_ = "solver:classical-planner";
        if( as_method.options_.find("planner") == as_method.options_.end() ) {
            cout << Utils::warning() << "unspecified planner for classical-planner AS; defaulting to 'ff'..." << endl;
            as_method.options_.insert(make_pair("planner", "ff"));
        }
    } else if( as_method.as_name_ == "random" ) {
        if( as_method.options_.find("type") == as_method.options_.end() ) {
            as_method.solver_option_str_ = "solver:random-action-selection";
            if( as_method.options_.find("planner") == as_method.options_.end() ) {
                cout << Utils::warning() << "unspecified planner for random AS; defaulting to 'ff'..." << endl;
                as_method.options_.insert(make_pair("planner", "ff"));
            }
        } else if( as_method.options_.at("type") == "naive" ) {
            as_method.solver_option_str_ = "solver:naive-random-action-selection";
        } else {
            cout << Utils::error() << "undefined type '" << as_method.options_.at("type") << "' for random AS method." << endl;
            exit(-1);
        }
    } else if( as_method.as_name_ == "hop" ) {
        as_method.solver_option_str_ = "solver:hop";
        if( as_method.options_.find("num-samples") == as_method.options_.end() ) {
            cout << Utils::warning() << "unspecified 'num-samples' for hop AS; defaulting to 1..." << endl;
            as_method.options_.insert(make_pair("num-samples", "1"));
        }
        if( as_method.options_.find("prune-nodes") == as_method.options_.end() ) {
            cout << Utils::warning() << "unspecified 'prune-nodes' for hop AS; defaulting to true..." << endl;
            as_method.options_.insert(make_pair("prune-nodes", "true"));
        }
        if( as_method.options_.find("use-path") == as_method.options_.end() ) {
            cout << Utils::warning() << "unspecified 'use-path' for hop AS; defaulting to true..." << endl;
            as_method.options_.insert(make_pair("use-path", "true"));
        }
        if( as_method.options_.find("random-shuffle") == as_method.options_.end() ) {
            cout << Utils::warning() << "unspecified 'random-shuffle' for hop AS; defaulting to false..." << endl;
            as_method.options_.insert(make_pair("random-shuffle", "false"));
        }
    } else {
        cout << Utils::error() << "undefined action-selection method." << endl;
        exit(-1);
    }
}

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
            os << indent << cmdline_options[i] << endl;
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
    bool        opt_debug_parser = false;
    bool        opt_print_plan = true;
    //string      opt_planner("ff");
    int         opt_time_bound = 3600;
    string      opt_as("classical-planner(planner=ff)");
    int         opt_max_as_calls = 1000;
    string      opt_prefix = "";
    float       start_time = Utils::read_time_in_seconds();
    string      opt_planner_path = "";
    string      opt_tmpfile_path = "";
    bool        need_classical_planner = true;
    int         opt_seed = 0;

    // print cmdline
    cout << "cmdline: " << Utils::cmdline(argc, argv) << endl;

    // initialize options
    for( const char **opt = &available_options[0]; *opt != 0; ++opt ) {
        const char *name = *opt++;
        const char *desc = *opt;
        g_options.add(name, desc);
    }

    // set default options
    g_options.enable("planner:remove-intermediate-files");
    g_options.enable("problem:action-compilation");
    g_options.enable("kp:merge-drules");
    g_options.enable("solver:forced-moves");
    g_options.enable("solver:classical-planner");
    //g_options.enable("lw1:boost:compile-static-observables"); // DEPRECATED?

    // default options for lw1:strict
    g_options.enable("lw1:strict");
    g_options.enable("lw1:boost:enable-post-actions");
    g_options.enable("lw1:boost:drule:sensing:type4");
    g_options.enable("lw1:boost:drule:sensing:type4:add");
    g_options.enable("lw1:boost:literals-for-observables");
    g_options.enable("lw1:boost:drule:sensing:type3");

    // default inference engine
    g_options.enable("lw1:inference:up");
    g_options.enable("lw1:inference:up:preload");
    g_options.enable("lw1:inference:up:watched-literals");

    // check correct number of parameters
    const char *exec_name = argv[0];
    if( argc == 1 ) {
        print_usage(cout, exec_name, lw1_cmdline_options);
        exit(0);
    }

    int nfiles = 0;
#ifdef SMART
    unique_ptr<Parser> reader = make_unique<Parser>(Parser::replanner, parser_symbol_table, g_options);
#else
    Parser *reader = new Parser(Parser::replanner, parser_symbol_table, g_options);
#endif

    // parse options
    bool skip_options = false;
    for( int k = 1; k < argc; ++k ) {
        if( !skip_options && !strcmp(argv[k], "--help") ) {
            print_usage(cout, exec_name, lw1_cmdline_options);
            exit(0);
        } else if( !skip_options && !strcmp(argv[k], "--debug-parser") ) {
            opt_debug_parser = true;
        } else if( !skip_options && !strcmp(argv[k], "--max-time") ) {
            if( k == argc - 1 ) {
                cout << Utils::error() << "not enough arguments for '" << argv[k] << "'." << endl;
                exit(-1);
            }
            opt_time_bound = atoi(argv[++k]);
        } else if( !skip_options && !strcmp(argv[k], "--as") ) {
            if( k == argc - 1 ) {
                cout << Utils::error() << "not enough arguments for '" << argv[k] << "'." << endl;
                exit(-1);
            }
            opt_as = argv[++k];
        } else if( !skip_options && !strcmp(argv[k], "--max-as-calls") ) {
            if( k == argc - 1 ) {
                cout << Utils::error() << "not enough arguments for '" << argv[k] << "'." << endl;
                exit(-1);
            }
            opt_max_as_calls = atoi(argv[++k]);
        } else if( !skip_options && !strcmp(argv[k], "--no-print-plan") ) {
            opt_print_plan = false;
        } else if( !skip_options && !strcmp(argv[k], "--prefix") ) {
            if( k == argc-1 ) {
                cout << Utils::error() << "not enough arguments for '" << argv[k] << "'." << endl;
                exit(-1);
            }
            opt_prefix = argv[++k];
        } else if( !skip_options && !strcmp(argv[k], "--keep-intermediate-files") ) {
            g_options.disable("planner:remove-intermediate-files");
        } else if( !skip_options && !strcmp(argv[k], "--planner") ) {
            cout << Utils::warning() << "deprecated option. Use --as to specify AS method." << endl;
            //opt_planner = argv[++k];
        } else if( !skip_options && !strcmp(argv[k], "--planner-path") ) {
            opt_planner_path = argv[++k];
        } else if( !skip_options && !strcmp(argv[k], "--tmpfile-path") ) {
            opt_tmpfile_path = argv[++k];
        } else if( !skip_options && !strncmp(argv[k], "--options=", 10) ) {
            const char *options = &argv[k][10];
            parse_options(g_options, options);
        } else if( !skip_options && !strcmp(argv[k], "--override-defaults") ) {
            g_options.clear_enabled_and_disabled();
        } else if( !skip_options && !strcmp(argv[k], "--seed") ) {
            opt_seed = atoi(argv[++k]);

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

    // set seed for random numbers
    unsigned short seed[3];
    seed[0] = seed[1] = seed[2] = opt_seed;
    seed48(seed);

    // parse AS string
    ASMethod as_method;
    parse_as_string(opt_as, as_method);
    g_options.enable(as_method.solver_option_str_);

    // either lw1:aaai or lw1:strict: one of them but not both. Default is lw1:strict.
    if( !g_options.is_enabled("lw1:aaai") && !g_options.is_enabled("lw1:strict") )
        g_options.enable("lw1:strict");
    if( g_options.is_enabled("lw1:aaai") )
        g_options.disable("lw1:strict");
    if( g_options.is_enabled("lw1:strict") )
        g_options.disable("lw1:aaai");
    assert(g_options.is_disabled("lw1:aaai") || g_options.is_disabled("lw1:strict"));

    // if lw1:inference:ac3 is enabled, disable options for UP/FC
    if( g_options.is_enabled("lw1:inference:ac3") ) {
        g_options.disable("lw1:inference:up");
        g_options.disable("lw1:inference:up:preload");
        g_options.disable("lw1:inference:up:watched-literals");
        g_options.disable("lw1:inference:up:watched-literals");
        g_options.disable("lw1:inference:up:lookahead");
        g_options.disable("lw1:inference:up:enhanced");
        g_options.disable("lw1:inference:forward-chaining");
    }

    // if lw1:inference:forward-chaining is enabled, disable options for UP/AC3
    if( g_options.is_enabled("lw1:inference:forward-chaining") ) {
        g_options.disable("lw1:inference:up");
        g_options.disable("lw1:inference:up:preload");
        g_options.disable("lw1:inference:up:watched-literals");
        g_options.disable("lw1:inference:up:watched-literals");
        g_options.disable("lw1:inference:up:lookahead");
        g_options.disable("lw1:inference:up:enhanced");
        g_options.disable("lw1:inference:ac3");
    }

    // set implied options
    if( g_options.is_enabled("kp:subgoaling:non-reversable-goal-atoms") || g_options.is_enabled("kp:subgoaling:static-unknowns") ) {
        cout << Utils::warning() << "subgoaling is an experimental option; use it at risk." << endl;
        g_options.enable("kp:subgoaling");
    }
    if( g_options.is_enabled("lw1:boost:complete-effects:type4:obs") || g_options.is_enabled("lw1:boost:complete-effects:type4:state") )
        g_options.enable("lw1:boost:complete-effects:type4");
    if( g_options.is_enabled("lw1:boost:complete-effects:type4") )
        g_options.enable("lw1:boost:complete-effects");
    if( g_options.is_enabled("lw1:boost:drule:sensing:type4:add") )
        g_options.enable("lw1:boost:drule:sensing:type4");
    if( g_options.is_enabled("lw1:boost:literals-for-observables:dynamic") )
        g_options.enable("lw1:boost:literals-for-observables");

    // solver options:
    //     solver:classical-planner (default)
    //     solver:naive-random-action-selection
    //     solver:random-action-selection
    //     solver:width-based-action-selection
    //     solver:hop
    //     solver:despot
    if( g_options.is_enabled("solver:naive-random-action-selection") ) {
        need_classical_planner = false;
        g_options.disable("solver:classical-planner");
        g_options.disable("solver:random-action-selection");
        g_options.disable("solver:width-based-action-selection");
        g_options.disable("solver:hop");
        g_options.disable("solver:despot");
    }
    if( g_options.is_enabled("solver:random-action-selection") ) {
        need_classical_planner = true;
        g_options.disable("solver:naive-random-action-selection");
        g_options.disable("solver:width-based-action-selection");
        g_options.disable("solver:hop");
        g_options.disable("solver:despot");
    }
    if( g_options.is_enabled("solver:width-based-action-selection") ) {
        need_classical_planner = false;
        g_options.disable("solver:classical-planner");
        g_options.disable("solver:naive-random-action-selection");
        g_options.disable("solver:random-action-selection");
        g_options.disable("solver:hop");
        g_options.disable("solver:despot");
    }
    if( g_options.is_enabled("solver:hop") ) {
        need_classical_planner = false;
        g_options.disable("solver:classical-planner");
        g_options.disable("solver:naive-random-action-selection");
        g_options.disable("solver:random-action-selection");
        g_options.disable("solver:width-based-action-selection");
        g_options.disable("solver:despot");
    }
    if( g_options.is_enabled("solver:despot") ) {
        need_classical_planner = false;
        g_options.disable("solver:classical-planner");
        g_options.disable("solver:naive-random-action-selection");
        g_options.disable("solver:random-action-selection");
        g_options.disable("solver:width-based-action-selection");
        g_options.disable("solver:hop");
    }

    // disable lw1:boost:enable-post-actions
    if( g_options.is_enabled("solver:random-action-selection") ||
        g_options.is_enabled("solver:naive-random-action-selection") ||
        g_options.is_enabled("solver:hop") ||
        g_options.is_enabled("solver:despot") ) {
        g_options.disable("lw1:boost:enable-post-actions");
        //g_options.disable("lw1:boost:drule:sensing:type4");
        //g_options.disable("lw1:boost:drule:sensing:type4:add");
        //g_options.disable("lw1:boost:literals-for-observables");
        //g_options.disable("lw1:boost:drule:sensing:type3");
    }
    // disable options for hop
    if( g_options.is_enabled("solver:hop") ) {
        g_options.disable("lw1:boost:enable-post-actions");
        g_options.disable("lw1:boost:drule:sensing:type4");
        g_options.disable("lw1:boost:drule:sensing:type4:add");
        g_options.disable("lw1:boost:literals-for-observables");
        g_options.disable("lw1:boost:drule:sensing:type3");
    }


    // print enabled options
    cout << "enabled options: " << g_options << endl;

    // check that there is at least one input file
    if( nfiles == 0 ) {
        cout << Utils::error() << "need an input file." << endl;
        exit(-1);
    }

    // print file read by parser
    if( g_options.is_enabled("parser:print:raw") ) {
        reader->print(cout);
    }

    // perform necessary translations
#ifdef SMART
    const PDDL_Base::owned_variable_vec *variables = 0;
    const PDDL_Base::owned_variable_group_vec *variable_groups = 0;
    const list<pair<const PDDL_Base::Action*, unique_ptr<const PDDL_Base::Sensing> > > *sensing_models = 0;
#else
    const PDDL_Base::variable_vec *variables = 0;
    const PDDL_Base::variable_group_vec *variable_groups = 0;
    const list<pair<const PDDL_Base::Action*, const PDDL_Base::Sensing*> > *sensing_models = 0;
#endif
    const map<string, set<string> > *accepted_literals_for_observables = 0;
    reader->do_lw1_translation(variables, variable_groups, sensing_models, accepted_literals_for_observables);
    assert(variables != 0);
    assert(variable_groups != 0);
    assert(sensing_models != 0);

    if( g_options.is_enabled("parser:print:translated") ) {
        reader->print(cout);
    }

    // get translation type: 0=no translation, 1=clg, 2=lw1
#ifndef NDEBUG
    int translation_type = reader->get_translation_type();
    assert(translation_type == 2);
#endif

    // create fresh instance
    Instance instance(g_options);

    cout << "instantiating p.o. problem..." << endl;
    reader->emit_instance(instance);
    if( g_options.is_enabled("problem:print:raw") ) {
        //instance.print(cout);
        instance.write_domain(cout);
        instance.write_problem(cout);
    }

    cout << "preprocessing p.o. problem..." << endl;
    Preprocessor prep(instance);
    prep.preprocess(true);
    if( g_options.is_enabled("problem:print:preprocessed") ) {
        //instance.print(cout);
        instance.write_domain(cout);
        instance.write_problem(cout);
    }

    //cout << "perform action compilation..." << endl;
    //instance.do_action_compilation(*variables);

    cout << "creating KP translation..." << endl;
#ifdef SMART
    unique_ptr<LW1_Instance> lw1_instance = make_unique<LW1_Instance>(instance, *variables, *variable_groups, *sensing_models, *accepted_literals_for_observables);
#else
    LW1_Instance *lw1_instance = new LW1_Instance(instance, *variables, *variable_groups, *sensing_models, *accepted_literals_for_observables);
#endif

    if( g_options.is_enabled("kp:print:raw") ) {
        lw1_instance->print(cout);
        lw1_instance->write_domain(cout);
        lw1_instance->write_problem(cout);
    }

    cout << "preprocessing KP translation..." << endl;
    Preprocessor kp_prep(*lw1_instance);
    //kp_prep.preprocess(false); // CHECK
    if( g_options.is_enabled("kp:print:preprocessed") ) {
        lw1_instance->write_domain(cout);
        lw1_instance->write_problem(cout);
    }
    lw1_instance->print_stats(cout);
    float preprocessing_time = Utils::read_time_in_seconds() - start_time;

    // construct classical planner
#ifdef SMART
    unique_ptr<const ClassicalPlanner> planner;
    if( need_classical_planner || g_options.is_enabled("solver:classical-planner") ) {
        assert(as_method.options_.find("planner") != as_method.options_.end());
        const string &as_planner = as_method.options_.at("planner");

        // override planner path?
        string planner_path(opt_planner_path);
        if( as_method.options_.find("path") != as_method.options_.end() )
            planner_path = as_method.options_.at("path");

        if( as_planner == "ff" ) {
            planner = make_unique<const FF_Planner>(*lw1_instance, opt_tmpfile_path.c_str(), planner_path.c_str());
        } else if( as_planner == "lama" ) {
            planner = make_unique<const LAMA_Planner>(*lw1_instance, opt_tmpfile_path.c_str(), planner_path.c_str());
        } else if( as_planner == "m" ) {
            planner = make_unique<const M_Planner>(*lw1_instance, opt_tmpfile_path.c_str(), planner_path.c_str());
        } else if( as_planner == "mp" ) {
            planner = make_unique<const MP_Planner>(*lw1_instance, opt_tmpfile_path.c_str(), planner_path.c_str());
        } else if( as_planner == "lama-server" ) {
            planner = make_unique<const LAMA_Server_Planner>(*lw1_instance, opt_tmpfile_path.c_str(), planner_path.c_str());
        } else {
            cout << Utils::error() << "unrecognized planner '" << as_planner << "'." << endl;
            exit(-1);
        }
    }
#else
    const ClassicalPlanner *planner = 0;
    if( need_classical_planner || g_options.is_enabled("solver:classical-planner") ) {
        assert(as_method.options_.find("planner") != as_method.options_.end());
        const string &as_planner = as_method.options_.at("planner");

        // override planner path?
        string planner_path(opt_planner_path);
        if( as_method.options_.find("path") != as_method.options_.end() )
            planner_path = as_method.options_.at("path");

        if( as_planner == "ff" ) {
            planner = new FF_Planner(*lw1_instance, opt_tmpfile_path.c_str(), planner_path.c_str());
        } else if( as_planner == "lama" ) {
            planner = new LAMA_Planner(*lw1_instance, opt_tmpfile_path.c_str(), planner_path.c_str());
        } else if( as_planner == "m" ) {
            planner = new M_Planner(*lw1_instance, opt_tmpfile_path.c_str(), planner_path.c_str());
        } else if( as_planner == "mp" ) {
            planner = new MP_Planner(*lw1_instance, opt_tmpfile_path.c_str(), planner_path.c_str());
        } else if( as_planner == "lama-server" ) {
            planner = new LAMA_Server_Planner(*lw1_instance, opt_tmpfile_path.c_str(), planner_path.c_str());
        } else {
            cout << Utils::error() << "unrecognized planner '" << as_planner << "'." << endl;
            exit(-1);
        }
    }
#endif

    // construct inference engine
#ifdef SMART
    unique_ptr<Inference::Engine<STATE_CLASS> > inference_engine;
    if( g_options.is_enabled("lw1:inference:forward-chaining") ) {
        inference_engine = make_unique<Inference::ForwardChaining<STATE_CLASS> >(instance, *lw1_instance, g_options);
    } else if( g_options.is_enabled("lw1:inference:up") ) {
        inference_engine = make_unique<Inference::UnitPropagation<STATE_CLASS> >(instance, *lw1_instance, g_options);
    } else if( g_options.is_enabled("lw1:inference:ac3") ) {
        inference_engine = make_unique<Inference::AC3<STATE_CLASS> >(instance, *lw1_instance, g_options);
    } else {
        cout << Utils::error() << "unspecified inference method for lw1." << endl;
        exit(-1);
    }
#else
    Inference::Engine<STATE_CLASS> *inference_engine = 0;
    if( g_options.is_enabled("lw1:inference:forward-chaining") ) {
        inference_engine = new Inference::ForwardChaining<STATE_CLASS>(instance, *lw1_instance, g_options);
    } else if( g_options.is_enabled("lw1:inference:up") ) {
        inference_engine = new Inference::UnitPropagation<STATE_CLASS>(instance, *lw1_instance, g_options);
    } else if( g_options.is_enabled("lw1:inference:ac3") ) {
        inference_engine = new Inference::AC3<STATE_CLASS>(instance, *lw1_instance, g_options);
    } else {
        cout << Utils::error() << "unspecified inference method for lw1." << endl;
        exit(-1);
    }
#endif

    // construct action selection
    assert(as_method.options_.find("debug") != as_method.options_.end());
    int as_debug = atoi(as_method.options_.at("debug").c_str());
#ifdef SMART
    unique_ptr<ActionSelection<STATE_CLASS> > action_selection;
    if( g_options.is_enabled("solver:naive-random-action-selection") ) {
        action_selection = make_unique<NaiveRandomActionSelection<STATE_CLASS> >(*lw1_instance);
    } else if( g_options.is_enabled("solver:random-action-selection") ) {
        assert(planner != nullptr);
        unique_ptr<ActionSelection<STATE_CLASS> > alternate_action_selection = make_unique<ClassicalPlannerWrapper<STATE_CLASS> >(*planner);
        action_selection = make_unique<RandomActionSelection<STATE_CLASS> >(*lw1_instance, move(alternate_action_selection));
        assert(alternate_action_selection == nullptr);
    } else if( g_options.is_enabled("solver:width-based-action-selection") ) {
        //action_selection = make_unique<Width2::ActionSelection<STATE_CLASS> >(*lw1_instance, *inference_engine);
        assert(0); // CHECK
    } else if( g_options.is_enabled("solver:hop") ) {
        assert(as_method.options_.find("num-samples") != as_method.options_.end());
        int num_samples = atoi(as_method.options_.at("num-samples").c_str());
        assert(as_method.options_.find("prune-nodes") != as_method.options_.end());
        bool prune_nodes = as_method.options_.at("prune-nodes") == "true";
        assert(as_method.options_.find("use-path") != as_method.options_.end());
        bool use_path = as_method.options_.at("use-path") == "true";
        assert(as_method.options_.find("random-shuffle") != as_method.options_.end());
        bool random_shuffle = as_method.options_.at("random-shuffle") == "true";
        action_selection = make_unique<HOP::ActionSelection<STATE_CLASS> >(*lw1_instance, *inference_engine, num_samples, prune_nodes, use_path, random_shuffle, as_debug);
    } else if( g_options.is_enabled("solver:despot") ) {
        //action_selection = make_unique<Despot::ActionSelection<STATE_CLASS> >(*lw1_instance, *inference_engine, 50, 50, 1, .5, 10);
        assert(0); // CHECK
    } else {
        assert(g_options.is_enabled("solver:classical-planner"));
        assert(as_method.as_name_ == "classical-planner");
        assert(planner != nullptr);
        action_selection = make_unique<ClassicalPlannerWrapper<STATE_CLASS> >(*planner);
    }
#else
    ActionSelection<STATE_CLASS> *action_selection = 0;
    if( g_options.is_enabled("solver:naive-random-action-selection") ) {
        action_selection = new NaiveRandomActionSelection<STATE_CLASS>(*lw1_instance);
    } else if( g_options.is_enabled("solver:random-action-selection") ) {
        assert(planner != 0);
        ActionSelection<STATE_CLASS> *alternate_action_selection = new ClassicalPlannerWrapper<STATE_CLASS>(*planner);
        action_selection = new RandomActionSelection<STATE_CLASS>(*lw1_instance, alternate_action_selection);
    } else if( g_options.is_enabled("solver:width-based-action-selection") ) {
        //action_selection = new Width2::ActionSelection<STATE_CLASS>(*lw1_instance, *inference_engine);
        assert(0); // CHECK
    } else if( g_options.is_enabled("solver:hop") ) {
        assert(as_method.options_.find("num-samples") != as_method.options_.end());
        int num_samples = atoi(as_method.options_.at("num-samples").c_str());
        assert(as_method.options_.find("prune-nodes") != as_method.options_.end());
        bool prune_nodes = as_method.options_.at("prune-nodes") == "true";
        assert(as_method.options_.find("use-path") != as_method.options_.end());
        bool use_path = as_method.options_.at("use-path") == "true";
        assert(as_method.options_.find("random-shuffle") != as_method.options_.end());
        bool random_shuffle = as_method.options_.at("random-shuffle") == "true";
        action_selection = new HOP::ActionSelection<STATE_CLASS>(*lw1_instance, *inference_engine, num_samples, prune_nodes, use_path, random_shuffle, as_debug);
    } else if( g_options.is_enabled("solver:despot") ) {
        //action_selection = new Despot::ActionSelection<STATE_CLASS>(*lw1_instance, *inference_engine, 50, 50, 1, .5, 10);
        assert(0); // CHECK
    } else {
        assert(g_options.is_enabled("solver:classical-planner"));
        assert(as_method.as_name_ == "classical-planner");
        assert(planner != 0);
        action_selection = new ClassicalPlannerWrapper<STATE_CLASS>(*planner);
    }
#endif

    // solve problem
    cout << "solving problem for " << instance.num_hidden_states() << " hidden state(s)" << endl;
    for( int k = 0; k < instance.num_hidden_states(); ++k ) {
        float instance_start_time = Utils::read_time_in_seconds();
        vector<set<int> > fired_sensors, sensed_literals;
        STATE_CLASS hidden_initial_state;
        Instance::Plan plan;

        // set hidden state
        instance.set_hidden_state(k, hidden_initial_state);
        cout << "hidden[" << k << "]=";
        hidden_initial_state.print(cout, instance);
        cout << endl;

        // create solver and reset inference engine
        LW1_Solver solver(instance, *lw1_instance, *action_selection, *inference_engine, opt_time_bound, opt_max_as_calls);
        inference_engine->reset();

        // reset stats
        action_selection->reset_stats();
        lw1_instance->reset_inference_time();

        // solve
        int status = solver.solve(hidden_initial_state, plan, fired_sensors, sensed_literals);
        assert(1+plan.size() == fired_sensors.size());

        if( status == LW1_Solver::SOLVED ) {
            if( opt_print_plan ) {
                cout << "PLAN: ";
                bool need_indent = false;

                if( g_options.is_enabled("solver:print:fired-sensors") ) {
                    const set<int> &sensors = fired_sensors[0];
                    if( sensors.size() > 0 ) {
                        cout << "init*:" << flush;
                        for( set<int>::const_iterator it = sensors.begin(); it != sensors.end(); ++it ) {
                            cout << " " << instance.sensors_[*it]->name();
                        }
                        cout << endl;
                        need_indent = true;
                    }
                }

                if( g_options.is_enabled("solver:print:sensed-literals") ) {
                    const set<int> &sensed = sensed_literals[0];
                    if( sensed.size() > 0 ) {
                        if( need_indent ) cout << string(6, ' ');
                        cout << "init@:" << flush;
                        for( set<int>::const_iterator it = sensed.begin(); it != sensed.end(); ++it ) {
                            int literal = *it;
                            int atom = literal < 0 ? -literal - 1 : literal - 1;
                            cout << (literal < 0 ? " (not " : " ")
                                 << instance.atoms_[atom]->name()
                                 << (literal < 0 ? ")" : "");
                        }
                        cout << endl;
                        need_indent = true;
                    }
                }

                for( size_t k = 0; k < plan.size(); ++k ) {
                    if( need_indent ) cout << string(6, ' ');
                    cout << setw(4) << k << " : " << instance.actions_[plan[k]]->name() << endl;
                    if( g_options.is_enabled("solver:print:fired-sensors") ) {
                        const set<int> &sensors = fired_sensors[1+k];
                        if( sensors.size() > 0 ) {
                            cout << "      " << setw(4) << k << "*:";
                            for( set<int>::const_iterator it = sensors.begin(); it != sensors.end(); ++it ) {
                                cout << " " << instance.sensors_[*it]->name();
                            }
                            cout << endl;
                        }
                    }
                    if( g_options.is_enabled("solver:print:sensed-literals") ) {
                        const set<int> &sensed = sensed_literals[1+k];
                        if( sensed.size() > 0 ) {
                            cout << "      " << setw(4) << k << "@:";
                            for( set<int>::const_iterator it = sensed.begin(); it != sensed.end(); ++it ) {
                                int literal = *it;
                                int atom = literal < 0 ? -literal - 1 : literal - 1;
                                cout << (literal < 0 ? " (not " : " ")
                                     << instance.atoms_[atom]->name()
                                     << (literal < 0 ? ")" : "");
                            }
                            cout << endl;
                        }
                    }
                    need_indent = true;
                }
            }
        } else {
            plan.clear();
            cout << Utils::red() << "unable to solve problem: " << Utils::normal();
            if( status == LW1_Solver::NO_SOLUTION ) {
                cout << "problem has no solution!" << endl;
            } else if( status == LW1_Solver::TIME ) {
                cout << "reached time limit of " << opt_time_bound << " seconds" << endl;
            } else if( status == LW1_Solver::AS_CALLS ) {
                cout << "reached limit of " << opt_max_as_calls << " for #calls to action selection" << endl;
            } else if( status == LW1_Solver::ERROR ) {
                cout << "error during action/plan computation" << endl;
            } else  {
                cout << "unrecognized error" << endl;
            }
        }

        // in translations, not every action in the plan corresponds
        // to an original action. Thus, let's compute a faithful plan
        // length
        size_t plan_length = 0;
        for( size_t k = 0; k < plan.size(); ++k ) {
            plan_length += instance.is_original_action(instance.actions_[plan[k]]->name()) ? 1 : 0;
        }

        // print some stats
        float current_time = Utils::read_time_in_seconds();
        cout << "stats: " << flush
             << action_selection->name() << " (action-selection) " << flush
             << (int)(status != LW1_Solver::SOLVED ? -1 : plan_length) << " (plan-size) " << flush
             << action_selection->n_calls() << " (as-calls) " << flush
             << preprocessing_time << " (preprocessing-time) " << flush
             << action_selection->get_time() << " (as-time) " << flush
             << action_selection->get_search_time() << " (as-search-time) " << flush
             << lw1_instance->get_inference_time() << " (inference-time) " << flush
             << current_time - instance_start_time << " (instance-time) " << flush
             << current_time - start_time << " (total-acc-time)" << flush
             << endl << endl;
    }

#ifndef SMART
    // clean up
    delete reader;
    delete lw1_instance;
    delete planner;
    delete inference_engine;
    delete action_selection;
#endif

    return 0;
}

