#include <iostream>
#include <iomanip>
#include <libgen.h>
#include "problem.h"
#include "preprocess.h"
#include "parser.h"
#include "state.h"
#include "solver.h"
#include "verbosity.h"
#include "utils.h"

using namespace std;

Verbosity::Mode output_mode;
const char *output_modes[] = {
    // problem options
    "print:atom:creation",
    "print:action:creation",
    "print:action:removal",
    "print:sensor:creation",
    "print:sensor:removal",
    "print:axiom:creation",
    "print:axiom:removal",

    // preprocessor options
    "print:preprocess:stage",
    "print:atom:unreachable",
    "print:atom:static",
    "print:action:unreachable",
    "print:action:inconsistent",
    "print:action:useless",
    "print:sensor:unreachable",
    "print:axiom:unreachable",

    // ks0-translation options
    "print:ks0-translation:raw",
    "print:ks0-translation:preprocessed",
    "print:ks0-translation:reachable",
    "print:ks0-translation:tag:must",
    "print:ks0-translation:tag:atom:creation",
    "print:ks0-translation:action",
    "print:ks0-translation:merge:literals",
    "print:ks0-translation:merge:action",

    // cp2fsc/k_replanner options
    "print:parser:raw",
    "print:problem:raw",
    "print:problem:preprocessed",
    "print:cp-translation:raw",
    "print:cp-translation:preprocessed",
    "print:kp-translation:raw",
    "print:kp-translation:preprocessed",

    0
};

const char *planner_name[] = { "ff", "lama", "m", "mp" };

void usage(ostream &os, const char *exec_name) {
    char *tmp_name = strdup(exec_name);
    os << "usage: " << basename(tmp_name)
       << " [--help]"
       << " [--max-time <time>]"
       << " [--no-print-plan"
       << " [--prefix <prefix>]"
       << " [--use-{ff|lama|m|mp}]"
       << " [--verbose:<option>]"
       << " <pddl-files>"
       << endl;
    free(tmp_name);
}


int main(int argc, char *argv[]) {
    StringTable symbols(50, lowercase_map);
    bool        opt_print_plan = true;
    int         opt_planner = 0;
    int         opt_time_bound = 3600;
    string      opt_prefix = "";
    float       start_time = Utils::read_time_in_seconds();

    // initialize verbosity mode
    for( const char **opt = &output_modes[0]; *opt != 0; ++opt ) {
        output_mode.add(*opt);
    }

    // check correct number of parameters
    const char *exec_name = argv[0];
    if( argc == 1 ) {
        usage(cerr, exec_name);
        exit(0);
    }

    int nfiles = 0;
    Parser* reader = new Parser(symbols);

    // parse options
    bool skip_options = false;
    for( int k = 1; k < argc; ++k ) {
        if( !skip_options && !strcmp(argv[k], "--help") ) {
            usage(cerr, exec_name);
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
        } else if( !skip_options && !strcmp(argv[k], "--use-ff") ) {
            opt_planner = 0;
        } else if( !skip_options && !strcmp(argv[k], "--use-lama") ) {
            opt_planner = 1;
        } else if( !skip_options && !strcmp(argv[k], "--use-m") ) {
            opt_planner = 2;
        } else if( !skip_options && !strcmp(argv[k], "--use-mp") ) {
            opt_planner = 3;
        } else if( !skip_options && !strncmp(argv[k], "--verbose:", 10) ) {
            const char *opt = &argv[k][10];
            if( !output_mode.enable(opt) )
                cout << "warning: unrecognized option '" << opt << "'. Ignored." << endl;

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
    if( output_mode.is_enabled("print:parser:raw") ) {
        reader->print(cout);
    }

    Instance instance(output_mode);

    cout << "instantiating p.o. problem..." << endl;
    reader->instantiate(instance);
    delete reader;
    if( output_mode.is_enabled("print:problem:raw") ) {
        instance.print(cout);
        instance.write_domain(cout);
        instance.write_problem(cout);
    }

    cout << "preprocessing p.o. problem..." << endl;
    Preprocessor prep(instance, output_mode);
    prep.preprocess();
    if( output_mode.is_enabled("print:problem:preprocessed") ) {
        instance.print(cout);
        instance.write_domain(cout);
        instance.write_problem(cout);
    }

    cout << "creating KP translation..." << endl;
    KP_Instance kp_instance(instance);
    if( output_mode.is_enabled("print:kp-translation:raw") ) {
        kp_instance.print(cout);
        kp_instance.write_domain(cout);
        kp_instance.write_problem(cout);
    }

    cout << "preprocessing KP translation..." << endl;
    Preprocessor kp_prep(kp_instance, output_mode);
    kp_prep.preprocess(false);
    if( output_mode.is_enabled("print:kp-translation:preprocessed") ) {
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
    vector<int> plan;
    State hidden_initial_state;
    instance.set_hidden_state(hidden_initial_state);
    int status = solver.solve(hidden_initial_state, plan);
    if( status == Solver::SOLVED ) {
        if( opt_print_plan ) {
            cout << "PLAN: ";
            for( size_t k = 0; k < plan.size(); ++k ) {
                if( k > 0 ) cout << "      ";
                cout << setw(3) << k << ": " << instance.actions[plan[k]]->name << endl;
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

