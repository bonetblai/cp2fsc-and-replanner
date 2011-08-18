#include <iostream>
#include <iomanip>
#include <libgen.h>
#include "cp_problem.h"
#include "ks0_problem.h"
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

void usage(ostream &os, const char *exec_name) {
    char *tmp_name = strdup(exec_name);
    os << "usage: " << basename(tmp_name)
       << " [--compound-obs-as-fluents]"
       << " [--fsc-states <n>]"
       << " [--help]"
       << " [--no-forbid-inconsistent-tuples]"
       << " [--output-metadata <filename>]"
       << " [--prefix <prefix>]"
       << " [--tag-all-literals]"
       << " [--verbose:<option>]"
       << " <pddl-files>"
       << endl;
    free(tmp_name);
}

int main(int argc, char *argv[]) {
    StringTable symbols(50, lowercase_map);
    int         opt_fsc_states = 1;
    bool        opt_forbid_inconsistent_tuples = true;
    bool        opt_compound_obs_as_fluents = false;
    string      opt_prefix = "";
    bool        opt_tag_all_literals = false;
    string      opt_metadata_filename = "";
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
        if( !skip_options && !strcmp(argv[k], "--compound-obs-as-fluents") ) {
            opt_compound_obs_as_fluents = true;
            cout << "error: '" << argv[k] << "' is currently not implemented." << endl;
            exit(-1);
        } else if( !skip_options && !strcmp(argv[k], "--fsc-states") ) {
            if( k == argc-1 ) {
                cout << "error: not enough arguments for '" << argv[k] << "'." << endl;
                exit(-1);
            }
            opt_fsc_states = atoi(argv[++k]);
        } else if( !skip_options && !strcmp(argv[k], "--help") ) {
            usage(cerr, exec_name);
            exit(0);
        } else if( !skip_options && !strcmp(argv[k], "--no-forbid-inconsistent-tuples") ) {
            opt_forbid_inconsistent_tuples = false;
        } else if( !skip_options && !strcmp(argv[k], "--output-metadata") ) {
            if( k == argc-1 ) {
                cout << "error: not enough arguments for '" << argv[k] << "'." << endl;
                exit(-1);
            }
            opt_metadata_filename = argv[++k];
        } else if( !skip_options && !strcmp(argv[k], "--prefix") ) {
            if( k == argc-1 ) {
                cout << "error: not enough arguments for '" << argv[k] << "'." << endl;
                exit(-1);
            }
            opt_prefix = argv[++k];
        } else if( !skip_options && !strcmp(argv[k], "--tag-all-literals") ) {
            opt_tag_all_literals = true;
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

    cout << "instantiating control problem..." << endl;
    reader->instantiate(instance);
    delete reader;
    if( output_mode.is_enabled("print:problem:raw") ) {
        instance.print(cout);
        instance.write_domain(cout);
        instance.write_problem(cout);
    }

    cout << "preprocessing control problem..." << endl;
    Preprocessor prep(instance, output_mode);
    prep.preprocess();
    if( output_mode.is_enabled("print:problem:preprocessed") ) {
        instance.print(cout);
        instance.write_domain(cout);
        instance.write_problem(cout);
    }

    cout << "creating CP translation..." << endl;
    CP_Instance cp_instance(instance, opt_fsc_states,
                            opt_forbid_inconsistent_tuples, opt_compound_obs_as_fluents);
    if( output_mode.is_enabled("print:cp-translation:raw") ) {
        cp_instance.write_domain(cout);
        cp_instance.write_problem(cout);
    }

    cout << "preprocessing CP translation..." << endl;
    Preprocessor cp_prep(cp_instance, output_mode);
    cp_prep.preprocess(opt_tag_all_literals);
    if( output_mode.is_enabled("print:cp-translation:preprocessed") ) {
        cp_instance.write_domain(cout);
        cp_instance.write_problem(cout);
    }

    cout << "creating KS0 translation..." << endl;
    KS0_Instance ks0_instance(cp_instance, output_mode, opt_tag_all_literals);
    if( output_mode.is_enabled("print:ks0-translation:raw") ) {
        ks0_instance.write_domain(cout);
        ks0_instance.write_problem(cout);
    }

    cout << "preprocessing KS0 translation..." << endl;
    Preprocessor ks0_prep(ks0_instance, output_mode);
    ks0_prep.preprocess(true);
    if( output_mode.is_enabled("print:ks0-translation:preprocessed") ) {
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

