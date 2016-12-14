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
#include "problem.h"
#include "preprocess.h"
#include "parser.h"
#include "state.h"
#include "clg_problem.h"
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
    os << endl;

    os << "The components {cp,ks0} belong to cp2fsc while {kp,clg,mvv} to k-replanner."
       << endl << endl;
}

int main(int argc, const char *argv[]) {
    StringTable parser_symbol_table(lowercase_map, 50);
    bool        opt_debug_parser = false;
    bool        opt_print_plan = true;
    string      opt_planner = "ff";
    int         opt_time_bound = 3600;
    int         opt_ncalls_bound = 1000;
    string      opt_prefix = "";
    float       start_time = Utils::read_time_in_seconds();
    string      opt_planner_path = "";
    string      opt_tmpfile_path = "";

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
    g_options.enable("solver:forced-moves");
    g_options.enable("kp:merge-drules");

    // check correct number of parameters
    const char *exec_name = argv[0];
    if( argc == 1 ) {
        print_usage(cout, exec_name, k_replanner_cmdline_options);
        exit(0);
    }

    int nfiles = 0;
    unique_ptr<Parser> reader = make_unique<Parser>(Parser::replanner, parser_symbol_table, g_options);

    // parse options
    bool skip_options = false;
    for( int k = 1; k < argc; ++k ) {
        if( !skip_options && !strcmp(argv[k], "--help") ) {
            print_usage(cout, exec_name, k_replanner_cmdline_options);
            exit(0);
        } else if( !skip_options && !strcmp(argv[k], "--debug-parser") ) {
            opt_debug_parser = true;
        } else if( !skip_options && !strcmp(argv[k], "--max-time") ) {
            if( k == argc - 1 ) {
                cout << Utils::error() << "not enough arguments for '" << argv[k] << "'." << endl;
                exit(-1);
            }
            opt_time_bound = atoi(argv[++k]);
        } else if( !skip_options && !strcmp(argv[k], "--max-ncalls") ) {
            if( k == argc - 1 ) {
                cout << Utils::error() << "not enough arguments for '" << argv[k] << "'." << endl;
                exit(-1);
            }
            opt_ncalls_bound = atoi(argv[++k]);
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
            opt_planner = argv[++k];
        } else if( !skip_options && !strcmp(argv[k], "--planner-path") ) {
            opt_planner_path = argv[++k];
        } else if( !skip_options && !strcmp(argv[k], "--tmpfile-path") ) {
            opt_tmpfile_path = argv[++k];
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

    // perform necessary translations
    reader->do_translation();
    if( g_options.is_enabled("parser:print:translated") ) {
        reader->print(cout);
    }

    // get translation type: 0=no translation, 1=clg, 2=lw1
    int translation_type = reader->get_translation_type();
    assert(translation_type != 2);

    // create fresh instance
    Instance instance(g_options);

    cout << "instantiating p.o. problem..." << endl;
    reader->emit_instance(instance);
    if( g_options.is_enabled("problem:print:raw") ) {
        instance.print(cout);
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

    cout << "creating KP translation..." << endl;
    unique_ptr<KP_Instance> kp_instance;
    if( translation_type == 0 ) {
        kp_instance = make_unique<Standard_KP_Instance>(instance);
    } else if( translation_type == 1 ) {
        kp_instance = make_unique<CLG_Instance>(instance);
    }
    assert(kp_instance != nullptr);

    if( g_options.is_enabled("kp:print:raw") ) {
        kp_instance->print(cout);
        kp_instance->write_domain(cout);
        kp_instance->write_problem(cout);
    }

    cout << "preprocessing KP translation..." << endl;
    Preprocessor kp_prep(*kp_instance);
    //kp_prep.preprocess(false);
    if( g_options.is_enabled("kp:print:preprocessed") ) {
        kp_instance->write_domain(cout);
        kp_instance->write_problem(cout);
    }
    kp_instance->print_stats(cout);
    float preprocessing_time = Utils::read_time_in_seconds() - start_time;

    // construct classical planner
    unique_ptr<const ClassicalPlanner> planner;
    if( opt_planner == "ff" ) {
        planner = make_unique<const FF_Planner>(*kp_instance, opt_tmpfile_path.c_str(), opt_planner_path.c_str());
    } else if( opt_planner == "lama" ) {
        planner = make_unique<const LAMA_Planner>(*kp_instance, opt_tmpfile_path.c_str(), opt_planner_path.c_str());
    } else if( opt_planner == "m" ) {
        planner = make_unique<const M_Planner>(*kp_instance, opt_tmpfile_path.c_str(), opt_planner_path.c_str());
    } else if( opt_planner == "mp" ) {
        planner = make_unique<const MP_Planner>(*kp_instance, opt_tmpfile_path.c_str(), opt_planner_path.c_str());
    } else if( opt_planner == "lama-server" ) {
        planner = make_unique<const LAMA_Server_Planner>(*kp_instance, opt_tmpfile_path.c_str(), opt_planner_path.c_str());
    }

    // solve problem
    cout << "solving problem for " << instance.num_hidden_states() << " hidden state(s)" << endl;
    for( int k = 0; k < instance.num_hidden_states(); ++k ) {
        float instance_start_time = Utils::read_time_in_seconds();
        vector<set<int> > fired_sensors, sensed_literals;
        State hidden_initial_state;
        Instance::Plan plan;

        instance.set_hidden_state(k, hidden_initial_state);
        cout << "hidden[" << k << "]=";
        hidden_initial_state.print(cout, instance);
        cout << endl;

        planner->reset_stats();
        Solver solver(translation_type, instance, *kp_instance, *planner, opt_time_bound, opt_ncalls_bound);
        int status = solver.solve(hidden_initial_state, plan, fired_sensors, sensed_literals);
        assert(1+plan.size() == fired_sensors.size());

        if( status == Solver::SOLVED ) {
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
            cout << "unable to solve problem: ";
            if( status == Solver::NO_SOLUTION ) {
                cout << "problem has no solution!" << endl;
            } else if( status == Solver::TIME ) {
                cout << "reached time limit of " << opt_time_bound << " seconds" << endl;
            } else if( status == Solver::NCALLS ) {
                cout << "reached limit of " << opt_ncalls_bound << " for #calls to classical planner" << endl;
            } else if( status == Solver::ERROR ) {
                cout << "planner error" << endl;
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
             << opt_planner << " (planner) " << flush
             << (int)(status != Solver::SOLVED ? -1 : plan_length) << " (plan-size) " << flush
             << planner->n_calls() << " (planner-calls) " << flush
             << preprocessing_time << " (preprocessing-time) " << flush
             << planner->get_time() << " (planner-time) " << flush
             << planner->get_search_time() << " (planner-search-time) " << flush
             << current_time - instance_start_time << " (instance-time) " << flush
             << current_time - start_time << " (total-acc-time)" << flush
             << endl << endl;
    }
    return 0;
}

