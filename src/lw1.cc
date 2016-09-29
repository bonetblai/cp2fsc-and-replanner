#include <cassert>
#include <iostream>
#include <iomanip>
#include <libgen.h>
#include "action_selection.h"
#include "classical_planner_wrapper.h"
#include "problem.h"
#include "preprocess.h"
#include "parser.h"
#include "state.h"
#include "clg_problem.h"
#include "lw1_problem.h"
#include "lw1_solver.h"
#include "inference.h"
#include "options.h"
#include "available_options.h"
#include "utils.h"
#include "csp.h"
#include "width.h"

using namespace std;

Options::Mode g_options;

void print_usage(ostream &os, const char *exec_name, const char **cmdline_options) {
    char *tmp = strdup(exec_name);
    const char *base_name = basename(tmp);
    int indent = strlen("usage: ") + strlen(base_name) + 1;

    os << endl << "usage: " << base_name << " ";
    free(tmp);

    if( cmdline_options[0] == 0 ) {
        os << endl;
    } else {
        os << cmdline_options[0] << endl;
        for( int i = 1; cmdline_options[i] != 0; ++i ) {
            os << setw(indent) << "" << cmdline_options[i] << endl;
        }
    }

    os << setw(indent) << "" << "[--options=<options>]" << endl
       << setw(indent) << "" << "<pddl-files>" << endl
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
    StringTable symbols(50, lowercase_map);
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
    g_options.enable("lw1:boost:compile-static-observables");

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
        print_usage(cout, exec_name, k_replanner_cmdline_options);
        exit(0);
    }

    int nfiles = 0;
    Parser* reader = new Parser(Parser::replanner, symbols, g_options);

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
        } else {
            cout << argv[k] << endl;
            cout << Utils::error() << "reading from stdin not yet implemented." << endl;
            exit(-1);
        }
    }

    // either lw1:aaai or lw1:strict: one of them but not both. Default is lw1:strict.
    assert(g_options.is_enabled("lw1:aaai") || g_options.is_enabled("lw1:strict"));
    if( g_options.is_enabled("lw1:aaai") )
        g_options.disable("lw1:strict");
    if( g_options.is_enabled("lw1:strict") )
        g_options.disable("lw1:aaai");
    assert(g_options.is_enabled("lw1:aaai") || g_options.is_enabled("lw1:strict"));
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
        cout << Utils::warning() << "subgoaling is an experimental option; use it at risk" << endl;
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
    const PDDL_Base::variable_vec *variables = 0;
    const PDDL_Base::variable_group_vec *variable_groups = 0;
    const list<pair<const PDDL_Base::Action*, const PDDL_Base::Sensing*> > *sensing_models = 0;
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
    //delete reader; // CHECK
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
    LW1_Instance *lw1_instance = new LW1_Instance(instance, *variables, *variable_groups, *sensing_models, *accepted_literals_for_observables);

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
    const ClassicalPlanner *planner = 0;
    if( !g_options.is_enabled("solver:width-based-planner") ) {
        if( opt_planner == "ff" ) {
            planner = new FF_Planner(*lw1_instance, opt_tmpfile_path.c_str(), opt_planner_path.c_str());
        } else if( opt_planner == "lama" ) {
            planner = new LAMA_Planner(*lw1_instance, opt_tmpfile_path.c_str(), opt_planner_path.c_str());
        } else if( opt_planner == "m" ) {
            planner = new M_Planner(*lw1_instance, opt_tmpfile_path.c_str(), opt_planner_path.c_str());
        } else if( opt_planner == "mp" ) {
            planner = new MP_Planner(*lw1_instance, opt_tmpfile_path.c_str(), opt_planner_path.c_str());
        } else if( opt_planner == "lama-server" ) {
            planner = new LAMA_Server_Planner(*lw1_instance, opt_tmpfile_path.c_str(), opt_planner_path.c_str());
        } else {
            std::cout << Utils::error() << "unrecognized planner '" << opt_planner << "'" << std::endl;
            exit(-1);
        }
    }

    // construct action selection
    ActionSelection<STATE_CLASS> *action_selection = 0; // CHECK: STATE_CLASS is defined in lw1_solver.h (this is provisional)
    if( !g_options.is_enabled("solver:width-based-planner") ) {
        assert(planner != 0);
        action_selection = new ClassicalPlannerWrapper<STATE_CLASS>(*planner); // CHECK: STATE_CLASS is defined in lw1_solver.h (this is provisional)
    } else {
        action_selection = new WidthBasedPlanner<STATE_CLASS>(*lw1_instance); // CHECK: STATE_CLASS is defined in lw1_solver.h (this is provisional)
    }
 
    // solve problem
    cout << "solving problem for " << instance.num_hidden_states() << " hidden state(s)" << endl;
    for( int k = 0; k < instance.num_hidden_states(); ++k ) {
        float instance_start_time = Utils::read_time_in_seconds();
        vector<set<int> > fired_sensors, sensed_literals;
        STATE_CLASS hidden_initial_state; // CHECK: STATE_CLASS is defined in lw1_solver.h (this is provisional)
        Instance::Plan plan;

        // set hidden state
        instance.set_hidden_state(k, hidden_initial_state);
        cout << "hidden[" << k << "]=";
        hidden_initial_state.print(cout, instance);
        cout << endl;

        // create and initialize solver
        LW1_Solver solver(instance, *lw1_instance, *action_selection, opt_time_bound, opt_ncalls_bound);

        // reset stats
        action_selection->reset_stats();
        lw1_instance->reset_inference_time();

        // different initializations for inference (this should be moved elsewhere)
        if( g_options.is_enabled("lw1:inference:up:preload") ) {
            solver.initialize(*lw1_instance);
            if( g_options.is_enabled("lw1:inference:up:watched-literals") ) {
                Inference::Propositional::WatchedLiterals wl;
                wl.initialize_axioms(solver.get_cnf());
            }
        }
        if( g_options.is_enabled("lw1:inference:ac3") ) {
            // Build basic CSP from state: CSP variables come from state variables and variable groups.
            solver.fill_atoms_to_var_map(*lw1_instance);
            Inference::CSP::Csp csp;
            csp.initialize(lw1_instance->variables_, solver.atoms_to_vars_);
            if( lw1_instance->has_groups() ) {
                csp.initialize_groups(*lw1_instance);
                Inference::CSP::AC3 ac3;
                ac3.initialize_arcs(*lw1_instance, csp);
            }
        }

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
                            cout << " " << instance.sensors_[*it]->name_;
                        }
                        cout << endl;
                        need_indent = true;
                    }
                }

                if( g_options.is_enabled("solver:print:sensed-literals") ) {
                    const set<int> &sensed = sensed_literals[0];
                    if( sensed.size() > 0 ) {
                        if( need_indent ) cout << "      ";
                        cout << "init@:" << flush;
                        for( set<int>::const_iterator it = sensed.begin(); it != sensed.end(); ++it ) {
                            int literal = *it;
                            int atom = literal < 0 ? -literal - 1 : literal - 1;
                            cout << (literal < 0 ? " (not " : " ")
                                 << instance.atoms_[atom]->name_
                                 << (literal < 0 ? ")" : "");
                        }
                        cout << endl;
                        need_indent = true;
                    }
                }

                for( size_t k = 0; k < plan.size(); ++k ) {
                    if( need_indent ) cout << "      ";
                    cout << setw(4) << k << " : " << instance.actions_[plan[k]]->name_ << endl;
                    if( g_options.is_enabled("solver:print:fired-sensors") ) {
                        const set<int> &sensors = fired_sensors[1+k];
                        if( sensors.size() > 0 ) {
                            cout << "      " << setw(4) << k << "*:";
                            for( set<int>::const_iterator it = sensors.begin(); it != sensors.end(); ++it ) {
                                cout << " " << instance.sensors_[*it]->name_;
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
                                     << instance.atoms_[atom]->name_
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
            } else if( status == LW1_Solver::NCALLS ) {
                cout << "reached limit of " << opt_ncalls_bound << " for #calls to classical planner" << endl;
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
            plan_length += instance.is_original_action(instance.actions_[plan[k]]->name_->to_string()) ? 1 : 0;
        }

        // print some stats
        float current_time = Utils::read_time_in_seconds();
        cout << "stats: "
             << opt_planner << " (planner) "
             << (int)(status != LW1_Solver::SOLVED ? -1 : plan_length) << " (plan-size) "
             << planner->n_calls() << " (planner-calls) "
             << preprocessing_time << " (preprocessing-time) "
             << planner->get_time() << " (planner-time) "
             << planner->get_search_time() << " (planner-search-time) "
             << lw1_instance->get_inference_time() << " (inference-time) "
             << current_time - instance_start_time << " (instance-time) "
             << current_time - start_time << " (total-acc-time)"
             << endl << endl;
    }

    delete action_selection;
    delete planner;
    delete lw1_instance;
    delete reader;

    return 0;
}

