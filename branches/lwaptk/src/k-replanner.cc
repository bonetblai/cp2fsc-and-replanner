#include <iostream>
#include <iomanip>
#include <libgen.h>
#include "problem.h"
#include "preprocess.h"
#include "parser.h"
#include "state.h"
#include "clg_problem.h"
#include "mvv_problem.h"
#include "mvv2_problem.h"
#include "solver.h"
#include "options.h"
#include "available_options.h"
#include "utils.h"
#include "bfs_f_planner.h"
#include "siw_planner.h"
#include "siw_plus_planner.h"
#include "epistemic_siw_planner.h"
#include "dfs_rpiw_planner.h"
#include "ff_lwaptk_planner.h"

using namespace std;

Options::Mode options;

void parse_options(const char *options_str) {
    char *opts = strdup(options_str);
    char *opt = strtok(opts, ",");
    while( opt != 0 ) {
        if( !options.enable(opt) )
            cout << Utils::warning() << "unrecognized option '" << opt << "' (ignored)." << endl;
        opt = strtok(0, ",");
    }
    free(opts);
}

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

    for( int i = 0, isz = options.options_.size(); i < isz; ++i ) {
        const Options::Option &opt = options.options_[i];
        os << "    " << left << setw(35) << opt.name() << "  " << opt.desc() << endl;
    }
    os << endl;

    os << "The components {cp,ks0} belong to cp2fsc while {kp,clg,mvv} to k-replanner."
       << endl << endl;
}

void
sample_population( std::vector<int>& selected, int H, int N, int seed ) {
	selected.clear();
	std::set<int> selected_aux;
	srandom( seed );
	int i = 0;
	while ( i < N && i < H ) {
		int x = random() % H;
		if ( selected_aux.find(x) != selected_aux.end() )
			continue;
		selected_aux.insert(x);
		selected.push_back(x);
		i++;
	}
}

int main(int argc, char *argv[]) {
    StringTable symbols(50, lowercase_map);
    bool        opt_debug_parser = false;
    bool        opt_print_plan = true;
    string      opt_planner = "ff";
    int         opt_time_bound = 3600;
    string      opt_prefix = "";
    float       start_time = Utils::read_time_in_seconds();
    string      opt_planner_path = "";
    string      opt_tmpfile_path = "";
    bool	opt_exhaustive = true;
    int		opt_samples = 100;
    int		opt_seed = time(nullptr);

    // initialize options
    for( const char **opt = &available_options[0]; *opt != 0; ++opt ) {
        const char *name = *opt++;
        const char *desc = *opt;
        options.add(name, desc);
    }

    // set default options
    options.enable("planner:remove-intermediate-files");
    options.enable("problem:action-compilation");
    options.enable("mvv:compile-static-observables");
    options.enable("kp:merge-drules");

    // check correct number of parameters
    const char *exec_name = argv[0];
    if( argc == 1 ) {
        print_usage(cout, exec_name, k_replanner_cmdline_options);
        exit(0);
    }

    int nfiles = 0;
    Parser* reader = new Parser(Parser::replanner, symbols, options);

    // parse options
    bool skip_options = false;
    for( int k = 1; k < argc; ++k ) {
        if( !skip_options && !strcmp(argv[k], "--help") ) {
            print_usage(cout, exec_name, k_replanner_cmdline_options);
            exit(0);
        } else if( !skip_options && !strcmp(argv[k], "--debug-parser") ) {
            opt_debug_parser = true;
        } else if( !skip_options && !strcmp(argv[k], "--max-time") ) {
            if( k == argc-1 ) {
                cout << Utils::error() << "not enough arguments for '" << argv[k] << "'." << endl;
                exit(-1);
            }
            opt_time_bound = atoi(argv[++k]);
        } else if( !skip_options && !strcmp(argv[k], "--no-print-plan") ) {
            opt_print_plan = false;
        } else if( !skip_options && !strcmp(argv[k], "--prefix") ) {
            if( k == argc-1 ) {
                cout << Utils::error() << "not enough arguments for '" << argv[k] << "'." << endl;
                exit(-1);
            }
            opt_prefix = argv[++k];
        } else if( !skip_options && !strcmp(argv[k], "--keep-intermediate-files") ) {
            options.clear("planner:remove-intermediate-files");
        } else if( !skip_options && !strcmp(argv[k], "--planner") ) {
            opt_planner = argv[++k];
        } else if( !skip_options && !strcmp(argv[k], "--planner-path") ) {
            opt_planner_path = argv[++k];
        } else if( !skip_options && !strcmp(argv[k], "--tmpfile-path") ) {
            opt_tmpfile_path = argv[++k];
	} else if ( !skip_options && !strcmp(argv[k], "--random" ) ) {
	    opt_exhaustive = false;
	} else if ( !skip_options && !strcmp(argv[k], "--num-samples" ) ) {
	    if( k == argc-1 ) {
                cout << Utils::error() << "not enough arguments for '" << argv[k] << "'." << endl;
                exit(-1);
            }
            opt_samples = atoi(argv[++k]);
	} else if ( !skip_options && !strcmp(argv[k], "--seed" ) ) {
	    if( k == argc-1 ) {
                cout << Utils::error() << "not enough arguments for '" << argv[k] << "'." << endl;
                exit(-1);
            }
            opt_seed = atoi(argv[++k]);
		
        } else if( !skip_options && !strncmp(argv[k], "--options=", 10) ) {
            const char *options = &argv[k][10];
            parse_options(options);
	   if( k == argc-1 ) {
                cout << Utils::error() << "not enough arguments for '" << argv[k] << "'." << endl;
                exit(-1);
            }
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

    // check that there is at least one input file
    if( nfiles == 0 ) {
        cout << Utils::error() << "need an input file." << endl;
        exit(-1);
    }

    // print file read by parser
    if( options.is_enabled("parser:print:raw") ) {
        reader->print(cout);
    }

    // perform necessary translations
    const PDDL_Base::variable_vec *multivalued_variables = 0;
    const list<const PDDL_Base::Effect*> *sensing_models = 0;
    const map<PDDL_Base::Atom, PDDL_Base::Atom> *sensing_enablers = 0;
    const map<PDDL_Base::Atom, set<PDDL_Base::unsigned_atom_set> > *pasive_sensors = 0;
    reader->do_translations(multivalued_variables, sensing_models, sensing_enablers, pasive_sensors);
    if( options.is_enabled("parser:print:translated") ) {
        reader->print(cout);
    }

    // get translation type: 0=no translation, 1=clg, 2=mvv
    int translation_type = reader->get_translation_type();

    // create fresh instance
    Instance instance(options);

    cout << "instantiating p.o. problem..." << endl;
    reader->emit_instance(instance);
    //delete reader;
    if( options.is_enabled("problem:print:raw") ) {
        instance.print(cout);
        instance.write_domain(cout);
        instance.write_problem(cout);
    }

    cout << "preprocessing p.o. problem..." << endl;
    Preprocessor prep(instance);
    prep.preprocess(true);
    if( options.is_enabled("problem:print:preprocessed") ) {
        //instance.print(cout);
        instance.write_domain(cout);
        instance.write_problem(cout);
    }

    cout << "creating KP translation..." << endl;
    KP_Instance *kp_instance = 0;
    if( translation_type == 0 ) {
        kp_instance = new Standard_KP_Instance(instance);
    } else if( translation_type == 1 ) {
        kp_instance = new CLG_Instance(instance);
    } else {
        assert(multivalued_variables != 0);
        kp_instance = new MVV2_Instance(instance, *multivalued_variables);
        //kp_instance = new MVV_Instance(instance, *multivalued_variables, *sensing_models, *sensing_enablers, *pasive_sensors);
    }

    if( options.is_enabled("kp:print:raw") ) {
        kp_instance->print(cout);
        kp_instance->write_domain(cout);
        kp_instance->write_problem(cout);
    }

    cout << "preprocessing KP translation..." << endl;
    Preprocessor kp_prep(*kp_instance);
    //kp_prep.preprocess(false);
    if( options.is_enabled("kp:print:preprocessed") ) {
        kp_instance->write_domain(cout);
        kp_instance->write_problem(cout);
    }
    kp_instance->print_stats(cout);
    float preprocessing_time = Utils::read_time_in_seconds() - start_time;

    // construct classical planner
    const ClassicalPlanner *planner = 0;
    if( opt_planner == "ff" ) {
        planner = new FF_Planner(*kp_instance, opt_tmpfile_path.c_str(), opt_planner_path.c_str());
    } else if( opt_planner == "lama" ) {
        planner = new LAMA_Planner(*kp_instance, opt_tmpfile_path.c_str(), opt_planner_path.c_str());
    } else if( opt_planner == "m" ) {
        planner = new M_Planner(*kp_instance, opt_tmpfile_path.c_str(), opt_planner_path.c_str());
    } else if( opt_planner == "mp" ) {
        planner = new MP_Planner(*kp_instance, opt_tmpfile_path.c_str(), opt_planner_path.c_str());
    } else if( opt_planner == "lama-server" ) {
        planner = new LAMA_Server_Planner(*kp_instance, opt_tmpfile_path.c_str(), opt_planner_path.c_str());
    } else if ( opt_planner == "bfs_f" ) {
	planner = new BFS_f_Planner( *kp_instance, opt_tmpfile_path.c_str() );
    } else if ( opt_planner == "siw" ) {
	SIW_Planner* concrete_planner = new SIW_Planner( *kp_instance, opt_tmpfile_path.c_str() );
	concrete_planner->set_classical_width_initial_bound( 1 );
	planner = concrete_planner;
    } else if ( opt_planner == "siw_plus" ) {
	SIW_plus_Planner* concrete_planner = new SIW_plus_Planner( *kp_instance, opt_tmpfile_path.c_str() );
	concrete_planner->set_classical_width_initial_bound( 1 );
	planner = concrete_planner;
    } else if ( opt_planner == "epistemic_siw" ) {
	Epistemic_SIW_Planner* concrete_planner = new Epistemic_SIW_Planner( *kp_instance, opt_tmpfile_path.c_str() );
	concrete_planner->set_classical_width_initial_bound( 1 );
	planner = concrete_planner;
    } else if ( opt_planner == "dfs_rpiw" ) {
	planner = new DFS_RPIW_Planner( *kp_instance, opt_tmpfile_path.c_str() );
    } else if ( opt_planner == "ff2" ) {
	planner = new FF2_Planner( *kp_instance, opt_tmpfile_path.c_str() ); 
    } else {
	std::cerr << "Unsupported planner " << opt_planner << " requested, bailing out!" << std::endl;
	std::exit(1);
    }

    std::vector<int> selected;
    if ( opt_exhaustive ) {
	for ( int k = 0; k < instance.num_hidden_states(); k++ ) 
	   selected.push_back(k);
    }
    else
	sample_population( selected, instance.num_hidden_states(), opt_samples, opt_seed );


    // solve problem
    cout << "solving problem for " << selected.size() << " hidden state(s)" << endl;
    for( int i = 0; i < selected.size(); ++i ) {
	int k = selected[i];
        float instance_start_time = Utils::read_time_in_seconds();
        vector<vector<int> > fired_sensors, sensed_literals;
        State hidden_initial_state;
        Instance::Plan plan;

        instance.set_hidden_state(k, hidden_initial_state);
        cout << "hidden[" << k << "]=";
        hidden_initial_state.print(cout, instance);
        cout << endl;

        planner->reset_stats();
        Solver solver(instance, *kp_instance, *planner, opt_time_bound);
        int status = solver.solve(hidden_initial_state, plan, fired_sensors, sensed_literals);
        assert(1+plan.size() == fired_sensors.size());

        if( status == Solver::SOLVED ) {
            if( opt_print_plan ) {
                cout << "PLAN: ";
                bool need_indent = false;

                if( options.is_enabled("solver:print:fired-sensors") ) {
                    const vector<int> &sensors = fired_sensors[0];
                    if( sensors.size() > 0 ) {
                        cout << "init*:" << flush;
                        for( int i = 0, isz = sensors.size(); i < isz; ++i ) {
                            cout << " " << instance.sensors_[sensors[i]]->name_;
                        }
                        cout << endl;
                        need_indent = true;
                    }
                }

                if( options.is_enabled("solver:print:sensed-literals") ) {
                    const vector<int> &sensed = sensed_literals[0];
                    if( sensed.size() > 0 ) {
                        if( need_indent ) cout << "      ";
                        cout << "init@:" << flush;
                        for( int i = 0, isz = sensed.size(); i < isz; ++i ) {
                            int atom = sensed[i] < 0 ? -sensed[i] - 1 : sensed[i] - 1;
                            cout << (sensed[i] < 0 ? " (not " : " ")
                                 << instance.atoms_[atom]->name_
                                 << (sensed[i] < 0 ? ")" : "");
                        }
                        cout << endl;
                        need_indent = true;
                    }
                }

                for( size_t k = 0; k < plan.size(); ++k ) {
                    if( need_indent ) cout << "      ";
                    cout << setw(4) << k << " : " << instance.actions_[plan[k]]->name_ << endl;
                    if( options.is_enabled("solver:print:fired-sensors") ) {
                        const vector<int> &sensors = fired_sensors[1+k];
                        if( sensors.size() > 0 ) {
                            cout << "      " << setw(4) << k << "*:";
                            for( int i = 0, isz = sensors.size(); i < isz; ++i ) {
                                cout << " " << instance.sensors_[sensors[i]]->name_;
                            }
                            cout << endl;
                        }
                    }
                    if( options.is_enabled("solver:print:sensed-literals") ) {
                        const vector<int> &sensed = sensed_literals[1+k];
                        if( sensed.size() > 0 ) {
                            cout << "      " << setw(4) << k << "@:";
                            for( int i = 0, isz = sensed.size(); i < isz; ++i ) {
                                int atom = sensed[i] < 0 ? -sensed[i] - 1 : sensed[i] - 1;
                                cout << (sensed[i] < 0 ? " (not " : " ")
                                     << instance.atoms_[atom]->name_
                                     << (sensed[i] < 0 ? ")" : "");
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
            plan_length += instance.is_original_action(instance.actions_[plan[k]]->name_->to_string()) ? 1 : 0;
        }

        // print some stats
        float current_time = Utils::read_time_in_seconds();
        cout << "stats: "
             << opt_planner << " (planner) "
             << (int)(status != Solver::SOLVED ? -1 : plan_length) << " (plan-size) "
             << planner->n_calls() << " (planner-calls) "
             << preprocessing_time << " (preprocessing-time) "
             << planner->get_time() << " (planner-time) "
             << planner->get_search_time() << " (planner-search-time) "
             << current_time - instance_start_time << " (instance-time) "
             << current_time - start_time << " (total-acc-time)"
             << endl << endl;
    }

    delete planner;
    return 0;
}

