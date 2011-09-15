#include <iostream>
#include <iomanip>
#include <libgen.h>
#include "problem.h"
#include "preprocess.h"
#include "parser.h"
#include "state.h"
#include "solver.h"
#include "options.h"
#include "available_options.h"
#include "utils.h"

using namespace std;

Options::Mode options;
const char *planner_name[] = { "ff", "lama", "m", "mp" };

void parse_options(const char *options_str) {
    char *opts = strdup(options_str);
    char *opt = strtok(opts, ",");
    while( opt != 0 ) {
        if( !options.enable(opt) )
            cout << "warning: unrecognized option '" << opt << "' (ignored)." << endl;
        opt = strtok(0, ",");
    }
    free(opts);
}

void print_usage(ostream &os, const char *exec_name, const char **cmdline_options) {
    char *tmp = strdup(exec_name);
    const char *base_name = basename(tmp);
    int indent = strlen("usage: ") + strlen(base_name) + 1;
    os << "usage: " << base_name << " ";
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
        os << "  " << left << setw(35) << opt.name() << "  " << opt.desc() << endl;
    }
    os << endl;

    os << "The components {cp,ks0} belong to cp2fsc while {kp} to k_replanner."
       << endl << endl;
}

int main(int argc, char *argv[]) {
    StringTable symbols(50, lowercase_map);
    bool        opt_print_plan = true;
    int         opt_planner = 0;
    int         opt_time_bound = 3600;
    string      opt_prefix = "";
    float       start_time = Utils::read_time_in_seconds();

    // initialize options
    for( const char **opt = &available_options[0]; *opt != 0; ++opt ) {
        const char *name = *opt++;
        const char *desc = *opt;
        options.add(name, desc);
    }
    options.enable("remove-intermediate-files");

    // check correct number of parameters
    const char *exec_name = argv[0];
    if( argc == 1 ) {
        print_usage(cout, exec_name, k_replanner_cmdline_options);
        exit(0);
    }

    int nfiles = 0;
    Parser* reader = new Parser(symbols);

    // parse options
    bool skip_options = false;
    for( int k = 1; k < argc; ++k ) {
        if( !skip_options && !strcmp(argv[k], "--help") ) {
            print_usage(cout, exec_name, k_replanner_cmdline_options);
            exit(0);
        } else if( !skip_options && !strcmp(argv[k], "--max-time") ) {
            if( k == argc-1 ) {
                cout << "error: not enough arguments for '" << argv[k] << "'." << endl;
                exit(-1);
            }
            opt_time_bound = atoi(argv[++k]);
        } else if( !skip_options && !strcmp(argv[k], "--no-print-plan") ) {
            opt_print_plan = false;
        } else if( !skip_options && !strcmp(argv[k], "--prefix") ) {
            if( k == argc-1 ) {
                cout << "error: not enough arguments for '" << argv[k] << "'." << endl;
                exit(-1);
            }
            opt_prefix = argv[++k];
        } else if( !skip_options && !strcmp(argv[k], "--no-remove-intermediate-files") ) {
            options.clear("remove-intermediate-files");
        } else if( !skip_options && !strcmp(argv[k], "--use-ff") ) {
            opt_planner = 0;
        } else if( !skip_options && !strcmp(argv[k], "--use-lama") ) {
            opt_planner = 1;
        } else if( !skip_options && !strcmp(argv[k], "--use-m") ) {
            opt_planner = 2;
        } else if( !skip_options && !strcmp(argv[k], "--use-mp") ) {
            opt_planner = 3;
        } else if( !skip_options && !strncmp(argv[k], "--options=", 10) ) {
            const char *options = &argv[k][10];
            parse_options(options);

        // if '--', stop parsing options. Remaining fields are file names.
        } else if( !skip_options && !strcmp(argv[k], "--") ) {
            skip_options = true;

        // unrecognized option.
        } else if( !skip_options && argv[k][0] == '-' ) {
            cout << "error: unrecognized option '" << argv[k] << "'." << endl;
            exit(-1);

        // read input file
        } else if( *argv[k] != '-' ) {
            cout << "reading " << argv[k] << "..." << endl;
            reader->read(argv[k], false);
            ++nfiles;
        } else {
            cout << argv[k] << endl;
            cout << "error: reading from stdin not yet implemented." << endl;
            exit(-1);
        }
    }

    // check that there is at least one input file
    if( nfiles == 0 ) {
        cout << "error: need an input file." << endl;
        exit(-1);
    }

    // print file read by parser
    if( options.is_enabled("print:parser:raw") ) {
        reader->print(cout);
    }

    Instance instance(options);

    cout << "instantiating p.o. problem..." << endl;
    reader->instantiate(instance);
    delete reader;
    if( options.is_enabled("print:problem:raw") ) {
        instance.print(cout);
        instance.write_domain(cout);
        instance.write_problem(cout);
    }

    cout << "preprocessing p.o. problem..." << endl;
    Preprocessor prep(instance, options);
    prep.preprocess();
    if( options.is_enabled("print:problem:preprocessed") ) {
        instance.print(cout);
        instance.write_domain(cout);
        instance.write_problem(cout);
    }

    cout << "creating KP translation..." << endl;
    KP_Instance kp_instance(instance, options);
    if( options.is_enabled("print:kp-translation:raw") ) {
        kp_instance.print(cout);
        kp_instance.write_domain(cout);
        kp_instance.write_problem(cout);
    }

    cout << "preprocessing KP translation..." << endl;
    Preprocessor kp_prep(kp_instance, options);
    kp_prep.preprocess(false);
    if( options.is_enabled("print:kp-translation:preprocessed") ) {
        kp_instance.write_domain(cout);
        kp_instance.write_problem(cout);
    }

    // solve problem
    cout << "solving problem..." << endl;
    const ClassicalPlanner *planner = 0;
    if( opt_planner == 0 ) {
        planner = new FF_Planner(kp_instance);
    } else if( opt_planner == 1 ) {
        planner = new LAMA_Planner(kp_instance);
    } else if( opt_planner == 2 ) {
        planner = new M_Planner(kp_instance);
    } else if( opt_planner == 3 ) {
        planner = new MP_Planner(kp_instance);
    }
    Solver solver(instance, kp_instance, *planner, opt_time_bound);
    Instance::Plan plan;
    vector<vector<int> > fired_sensors;
    State hidden_initial_state;
    instance.set_hidden_state(hidden_initial_state);
    int status = solver.solve(hidden_initial_state, plan, fired_sensors);
    assert(1+plan.size() == fired_sensors.size());

    if( status == Solver::SOLVED ) {
        if( opt_print_plan ) {
            cout << "PLAN: ";
            bool need_indent = false;

            if( options.is_enabled("print:fired-sensors") ) {
                const vector<int> &sensors = fired_sensors[0];
                if( sensors.size() > 0 ) {
                    cout << "init*:";
                    for( int i = 0, isz = sensors.size(); i < isz; ++i ) {
                        cout << " " << instance.sensors[sensors[i]]->name;
                    }
                    cout << endl;
                    need_indent = true;
                }
            }

            for( size_t k = 0; k < plan.size(); ++k ) {
                if( need_indent ) cout << "      ";
                cout << setw(4) << k << " : " << instance.actions[plan[k]]->name << endl;
                if( options.is_enabled("print:fired-sensors") ) {
                    const vector<int> &sensors = fired_sensors[1+k];
                    if( sensors.size() > 0 ) {
                        cout << "      " << setw(4) << k << "*:";
                        for( int i = 0, isz = sensors.size(); i < isz; ++i ) {
                            cout << " " << instance.sensors[sensors[i]]->name;
                        }
                        cout << endl;
                    }
                }
                need_indent = true;
            }
        }
    } else {
        plan.clear();
        if( status == Solver::NO_SOLUTION ) {
            cout << "problem has no solution!" << endl;
        } else if( status == Solver::TIME ) {
            cout << "expired time!" << endl;
        } else if( status == Solver::ERROR ) {
            cout << "error!" << endl;
        } else  {
            assert(0);
        }
    }

    // print some stats
    cout << "stats: "
         << planner_name[opt_planner] << " (planner) "
         << plan.size() << " (plan size) "
         << planner->n_calls() << " (planner calls) "
         << planner->get_time() << " (planner total time) "
         << planner->get_search_time() << " (planner total search time) "
         << Utils::read_time_in_seconds() - start_time << " (total time)"
         << endl;
    delete planner;

    return 0;
}

