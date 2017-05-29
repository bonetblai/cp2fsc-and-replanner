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

#include <algorithm>
#include <cassert>
#include <fstream>
#include <fcntl.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "classical_planner.h"
#include "utils.h"

using namespace std;

ClassicalPlanner::ClassicalPlanner(const string &planner_name,
                                   const KP_Instance &kp_instance,
                                   const map<string, string> &options)
  : kp_instance_(kp_instance),
    planner_name_(planner_name),
    planner_path_(options.find("planner-path") != options.end() ? options.at("planner-path") : ""),
    tmpfile_path_(options.find("tmpfile-path") != options.end() ? options.at("tmpfile-path") : ""),
    remove_intermediate_files_(options.find("remove-intermediate-files") != options.end() ? options.at("remove-intermediate-files") != "false" : true),
    debug_(options.find("debug") != options.end() ? atoi(options.at("debug").c_str()) : 0),
    total_search_time_(0),
    total_time_(0),
    n_calls_(0) {
    // construct action map
    for( size_t k = 0; k < kp_instance_.n_actions(); ++k ) {
        const Instance::Action &act = *kp_instance_.actions_[k];
        action_map_.insert(make_pair(act.name(), k));
    }

    // construct parameters
    int pid = getpid();

    domain_fn_.clear();
    if( tmpfile_path_ != "" ) domain_fn_ += tmpfile_path_ + "/";
    domain_fn_ += string("gen-d") + Utils::to_string(pid) + ".pddl";

    problem_fn_.clear();
    if( tmpfile_path_ != "" ) problem_fn_ += tmpfile_path_ + "/";
    problem_fn_ += string("gen-p") + Utils::to_string(pid) + ".pddl";

    output_fn_.clear();
    if( tmpfile_path_ != "" ) output_fn_ += tmpfile_path_ + "/";
    output_fn_ += planner_name_ + ".output." + Utils::to_string(pid);

    tmp_fn_.clear();
    if( tmpfile_path_ != "" ) tmp_fn_ += tmpfile_path_ + "/";
    tmp_fn_ += planner_name_ + ".tmp." + Utils::to_string(pid);

    plan_fn_.clear();
    if( tmpfile_path_ != "" ) plan_fn_ += tmpfile_path_ + "/";
    plan_fn_ += planner_name_ + ".plan." + Utils::to_string(pid);
}

void ClassicalPlanner::generate_pddl_domain() const {
    ofstream ofs(domain_fn_);
    assert(ofs.is_open());
    kp_instance_.write_domain(ofs);
    ofs.close();
}

void ClassicalPlanner::generate_pddl_problem(const State &state) const {
    ofstream ofs(problem_fn_);
    assert(ofs.is_open());
    kp_instance_.write_problem(ofs, &state);
    ofs.close();
}

void ClassicalPlanner::remove_file(const string &filename) const {
    if( remove_intermediate_files_ )
        unlink(filename.c_str());
}

void ClassicalPlanner::reduce_plan(const KP_Instance::Plan &raw_plan, Instance::Plan &plan) const {
    plan.clear();
    for( Instance::Plan::const_iterator a = raw_plan.begin(); a != raw_plan.end(); ++a ) {
        if( kp_instance_.is_regular_action(*a) )
            plan.push_back(*a);
    }
}

int ClassicalPlanner::get_plan(const State &state, Instance::Plan &raw_plan, Instance::Plan &plan) const {
    int status = get_raw_plan(state, raw_plan);
    if( status == SOLVED ) {
        if( debug_ > 1 ) {
            cout << "Classical plan (raw):" << endl;
            int step = 0;
            for( Instance::Plan::const_iterator a = raw_plan.begin(); a != raw_plan.end(); ++a, ++step ) {
                cout << "    step " << step << ": "
                     << *a << "." << kp_instance_.actions_[*a]->name()
                     << endl;
            }
        }
        reduce_plan(raw_plan, plan);
        if( debug_ > 0 ) {
            cout << "Classical plan (reduced):" << endl;
            int step = 0;
            for( Instance::Plan::const_iterator a = plan.begin(); a != plan.end(); ++a, ++step ) {
                cout << "    step " << step << ": "
                     << *a << "." << kp_instance_.actions_[*a]->name()
                     << endl;
            }
        }
    }
    return status;
}

FF_Planner::~FF_Planner() {
    if( !first_call_ ) remove_file(domain_fn_);
}

int FF_Planner::get_raw_plan(const State &state, Instance::Plan &raw_plan) const {
    cout << "calling " << name() << " (n=" << 1+n_calls() << ", acc-time=" << get_time() << ")..." << endl;
    float start_time = Utils::read_time_in_seconds();
    ++n_calls_;

    if( first_call_ ) {
        generate_pddl_domain();
        first_call_ = false;
    }
    generate_pddl_problem(state);

    // call FF planner
    string cmd;
    if( planner_path_ != "" ) cmd += planner_path_ + "/";
    cmd += planner_name_ + " -o " + domain_fn_ + " -f " + problem_fn_ + " > " + output_fn_;
    int rv = system(cmd.c_str());
    remove_file(problem_fn_);

    if( rv != 0 ) {
        total_time_ += Utils::read_time_in_seconds() - start_time;
        remove_file(output_fn_);
        return ERROR;
    }

    // update search time
    cmd = string("grep \"seconds searching\" ") + output_fn_ + " | awk '{print $1;}' > " + tmp_fn_;
    rv = system(cmd.c_str());
    assert(rv == 0);
    ifstream ifs(tmp_fn_);
    float search_time;
    ifs >> search_time;
    total_search_time_ += search_time;
    ifs.close();

    // extract plan from output
    cmd = string("egrep -e [0-9]+: ") + output_fn_ + " > " + tmp_fn_;
    rv = system(cmd.c_str());
    remove_file(output_fn_);

    if( rv != 0 ) {
        total_time_ += Utils::read_time_in_seconds() - start_time;
        remove_file(tmp_fn_);
        return NO_SOLUTION;
    }

    cmd = string("cat ") + tmp_fn_ + " | awk '{print $NF;}' | tr \"[:upper:]\" \"[:lower:]\"  > " + plan_fn_;
    rv = system(cmd.c_str());
    remove_file(tmp_fn_);
    assert(rv == 0);

    // read plan from file
    raw_plan.clear();
    ifs.open(plan_fn_);
    char line[2048];
    while( !ifs.eof() ) {
        ifs.getline(line, 2048);
        if( line[0] != '\0' ) {
            map<string, size_t>::const_iterator it = action_map_.find(line);
            assert(it != action_map_.end());
            raw_plan.push_back(it->second);
        }
    }
    ifs.close();
    remove_file(plan_fn_);
    total_time_ += Utils::read_time_in_seconds() - start_time;
    return SOLVED;
}

M_Planner::~M_Planner() {
    if( !first_call_ ) remove_file(domain_fn_);
}

int M_Planner::get_raw_plan(const State &state, Instance::Plan &raw_plan) const {
    cout << "calling " << name() << " (n=" << 1+n_calls() << ", acc-time=" << get_time() << ")..." << endl;
    float start_time = Utils::read_time_in_seconds();
    ++n_calls_;

    if( first_call_ ) {
        generate_pddl_domain();
        first_call_ = false;
    }
    generate_pddl_problem(state);

    // call M/Mp planner. Flag '-W' sets the random seed using time.
    string cmd;
    if( planner_path_ != "" ) cmd += planner_path_ + "/";
    cmd += planner_name_ + " -W " + domain_fn_ + " " + problem_fn_ + " > " + output_fn_;
    int rv = system(cmd.c_str());
    remove_file(problem_fn_);

    if( rv != 0 ) {
        total_time_ += Utils::read_time_in_seconds() - start_time;
        remove_file(output_fn_);
        return ERROR;
    }

    // update search time
    cmd = string("grep \"total time\" ") + output_fn_ + " | awk '{print $3, $5;}' > " + tmp_fn_;
    rv = system(cmd.c_str());
    assert(rv == 0);
    ifstream ifs(tmp_fn_);
    float total_time, preprocess_time;
    ifs >> total_time >> preprocess_time;
    total_search_time_ += total_time - preprocess_time;
    ifs.close();
    remove_file(tmp_fn_);

    // extract plan from output
    cmd = string("cat ") + output_fn_
            + " | grep STEP | sed \"s/STEP .*: //\" | tr \" \" \"\\n\" | sed \"s/()//\" > "
            + plan_fn_;
    rv = system(cmd.c_str());
    remove_file(output_fn_);

    if( rv != 0 ) {
        total_time_ += Utils::read_time_in_seconds() - start_time;
        remove_file(plan_fn_);
        return ERROR;
    }

    // read plan from file
    raw_plan.clear();
    ifs.open(plan_fn_);
    char line[2048];
    while( !ifs.eof() ) {
        ifs.getline(line, 2048);
        if( line[0] != '\0' ) {
            map<string, size_t>::const_iterator it = action_map_.find(line);
            assert(it != action_map_.end());
            raw_plan.push_back(it->second);
        }
    }
    ifs.close();
    remove_file(plan_fn_);
    total_time_ += Utils::read_time_in_seconds() - start_time;
    return SOLVED;
}

MP_Planner::~MP_Planner() {
    if( !first_call_ ) remove_file(domain_fn_);
}

LAMA_Planner::LAMA_Planner(const KP_Instance &kp_instance,
                           const map<string, string> &options)
  : ClassicalPlanner("lama", kp_instance, options),
    first_call_(true) {
    for( size_t k = 0; k < kp_instance_.n_atoms(); ++k ) {
        const Instance::Atom &atom = *kp_instance_.atoms_[k];
        string name = atom.name();
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        atom_map_.insert(make_pair(name.substr(1, name.length() - 2), k));
    }
}

LAMA_Planner::~LAMA_Planner() {
    if( !first_call_ ) remove_file("output");
}

int LAMA_Planner::get_raw_plan(const State &state, Instance::Plan &raw_plan) const {
    cout << "calling " << name() << " (n=" << 1+n_calls() << ", acc-time=" << get_time() << ")..." << endl;
    float start_time = Utils::read_time_in_seconds();
    ++n_calls_;

    if( first_call_ ) {
        generate_pddl_domain();
        generate_pddl_problem(state);

        // translate domain + problem into SAS+ problem
        string cmd;
        if( planner_path_ != "" ) cmd += planner_path_ + "/src/search/";
        cmd += string("lama simple-conversion ") + domain_fn_ + " " + problem_fn_ + " >/dev/null";
        int rv = system(cmd.c_str());
        remove_file(domain_fn_);
        remove_file(problem_fn_);
        if( rv != 0 ) {
            total_time_ += Utils::read_time_in_seconds() - start_time;
            return ERROR;
        }

        // preprocess SAS+ problem
        cmd = "";
        if( planner_path_ != "" ) cmd += planner_path_ + "/src/search/";
        cmd += "lama preprocess output.sas >/dev/null";
        rv = system(cmd.c_str());
        remove_file("output.sas");
        if( rv != 0 ) {
            total_time_ += Utils::read_time_in_seconds() - start_time;
            return ERROR;
        }

        // read variables from 'output'
        ifstream ifs("output");
        read_variables(ifs);
        ifs.close();

        // determine position of begin-state in 'output'
        ifs.open("output");
        determine_seek_pos(ifs);
        ifs.close();

        // next time, don't do translation + preprocessing
        first_call_ = false;
    }

    // patch state in 'output'
    fstream iofs("output", ios::in | ios::out);
    assert(!iofs.fail());
    patch_state_in_sas(iofs, state);
    iofs.close();

    // solve SAS+ problem
    string cmd;
    if( planner_path_ != "" ) cmd += planner_path_ + "/src/search/";
    cmd += string("lama search seq-sat-lama-2011-single-plan output ") + plan_fn_ + " > " + output_fn_;
    int rv = system(cmd.c_str());
    if( rv != 0 ) {
        total_time_ += Utils::read_time_in_seconds() - start_time;
        remove_file(output_fn_);
        return ERROR;
    }

    // update search time
    cmd = "";
    cmd += string("grep \"Search time\" ") + output_fn_ + " | awk '{print $3;}' > " + tmp_fn_;
    rv = system(cmd.c_str());
    assert(rv == 0);
    ifstream ifs(tmp_fn_);
    float search_time;
    ifs >> search_time;
    total_search_time_ += search_time;
    ifs.close();

    // clean temporary files
    remove_file(output_fn_);
    remove_file(tmp_fn_);

    // read plan from file
    raw_plan.clear();
    ifs.open(plan_fn_);
    char line[2048];
    while( !ifs.eof() ) {
        ifs.getline(line, 2048);
        // remove any trailing blank inserted by LAMA
        for( char *p = &line[strlen(line)-1]; *p == ' '; *p-- = '\0' );
        if( line[0] != '\0' ) {
            map<string, size_t>::const_iterator it = action_map_.find(line);
            assert(it != action_map_.end());
            raw_plan.push_back(it->second);
        }
    }
    ifs.close();
    remove_file(plan_fn_);
    total_time_ += Utils::read_time_in_seconds() - start_time;
    return SOLVED;
}

void LAMA_Planner::patch_state_in_sas(fstream &iofs, const State &state) const {
    assert(iofs.is_open());
    iofs.seekp(begin_state_pos_, ios_base::beg);
    for( size_t k = 0; k < variables_.size(); ++k ) {
        bool wrote = false;
        for( size_t j = 0; j < variables_[k].size(); ++j ) {
            int lit = variables_[k][j];
            int atom = lit > 0 ? lit - 1 : -lit - 1;
            if( ((lit > 0) && state.satisfy(atom)) || ((lit < 0) && !state.satisfy(atom)) ) {
                iofs << j << endl;
                wrote = true;
                break;
            }
        }
        if( !wrote ) iofs << variables_[k].size() << endl;
    }
}

void LAMA_Planner::determine_seek_pos(ifstream &ifs) const {
    assert(ifs.is_open());
    string token;
    while( token != "begin_state" ) ifs >> token;
    char c;
    ifs >> c;
    ifs.putback(c);
    begin_state_pos_ = ifs.tellg();
}

void LAMA_Planner::read_variable(ifstream &ifs, vector<pair<int, vector<int> > > &variables) const {
    string varname, type, atom, trailer;
    int axiom_layer, range, varno;
    ifs >> varname >> axiom_layer >> range;
    assert(strncmp(varname.c_str(), "var", 3) == 0);
    varno = atoi(varname.substr(3).c_str());
    //cout << "Variable #" << varno << " is " << varname << ": " << range << " value(s)" << endl;

    vector<int> variable;
    for( int i = 0; i < range; ++i ) {
        ifs >> type;
        assert((type == "Atom") || (type == "NegatedAtom") || (type == "<none"));
        if( (type == "Atom") || (type == "NegatedAtom") ) {
            bool negated = type == "NegatedAtom";
            ifs >> atom;
            transform(atom.begin(), atom.end(), atom.begin(), ::tolower);
            assert(atom.substr(atom.length() - 2, 2) == "()");
            atom.erase(atom.length() - 2, 2);
            map<string, size_t>::const_iterator it = atom_map_.find(atom);
            assert(it != atom_map_.end());
            variable.push_back(negated ? -(1 + it->second) : 1 + it->second);
            //cout << "    " << type << " " << atom << " " << it->second << endl;
        } else {
            ifs >> type;
            assert(type == "of");
            ifs >> type;
            assert(type == "those>");
            //cout << "    <none of those> -1" << endl;
        }
    }
    variables.push_back(make_pair(varno, variable));

    ifs >> trailer;
    assert(trailer == "end_variable");
}

struct LAMA_Planner::variable_order {
    bool operator()(const pair<int, vector<int> > &a, const pair<int, vector<int> > &b) const {
        return a.first < b.first;
    }
};

void LAMA_Planner::read_variables(ifstream &ifs) const {
    assert(ifs.is_open());
    vector<pair<int, vector<int> > > unordered_variables;
    char line[2048];
    while( !ifs.eof() ) {
        ifs.getline(line, 2048);
        if( !strcmp(line, "begin_variable") )
            read_variable(ifs, unordered_variables);
    }

    // sort variables according to their index
    variables_.reserve(unordered_variables.size());
    //sort(unordered_variables.begin(), unordered_variables.end(), variable_order());
    for( size_t i = 0; i < unordered_variables.size(); ++i ) {
        //cout << "Variable #" << unordered_variables[i].first << endl;
        variables_.push_back(unordered_variables[i].second);
    }
}




LAMA_Server_Planner::LAMA_Server_Planner(const KP_Instance &kp_instance,
                                         const map<string, string> &options)
  : ClassicalPlanner("lama-server", kp_instance, options),
    first_call_(true) {
    for( size_t k = 0; k < kp_instance_.n_atoms(); ++k ) {
        const Instance::Atom &atom = *kp_instance_.atoms_[k];
        string name = atom.name();
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        atom_map_.insert(make_pair(name.substr(1, name.length() - 2), k));
    }
}

LAMA_Server_Planner::~LAMA_Server_Planner() {
    if( !first_call_ ) remove_file("output");
}

int LAMA_Server_Planner::get_raw_plan(const State &state, Instance::Plan &raw_plan) const {
    cout << "calling " << name() << " (n=" << 1+n_calls() << ", acc-time=" << get_time() << ")..." << endl;
    float start_time = Utils::read_time_in_seconds();
    ++n_calls_;

    string cmd;
    if( planner_path_ != "" ) cmd += planner_path_ + "/src/search/";
    cmd += string("lama simple-conversion ") + domain_fn_ + " " + problem_fn_ + " >/dev/null";

    if( first_call_ ) {
        generate_pddl_domain();
        generate_pddl_problem(state);

        // translate domain + problem into SAS+ problem
        string cmd;
        if( planner_path_ != "" ) cmd += planner_path_ + "/src/search/";
        cmd += string("lama simple-conversion ") + domain_fn_ + " " + problem_fn_ + " >/dev/null";
cout << "call" << cmd << endl;
        int rv = system(cmd.c_str());
        remove_file(domain_fn_);
        remove_file(problem_fn_);
        if( rv != 0 ) {
            total_time_ += Utils::read_time_in_seconds() - start_time;
            return ERROR;
        }

        // preprocess SAS+ problem
        cmd = "";
        if( planner_path_ != "" ) cmd += planner_path_ + "/src/search/";
        cmd += "lama preprocess output.sas >/dev/null";
        rv = system(cmd.c_str());
        remove_file("output.sas");
        if( rv != 0 ) {
            total_time_ += Utils::read_time_in_seconds() - start_time;
            return ERROR;
        }

        // read variables from 'output'
        ifstream ifs("output");
        read_variables(ifs);
        ifs.close();

        // create server process (child)
        int status = create_server_process("output");
        cout << "LAMA_Server: status=" << status << endl;
    }

    // solve SAS+ problem. If first call, it is enough to 'cat'
    // the 'output' file into the server process' stdin. Otherwise,
    // it's enough to 'cat' the current stae into the server process'
    // stdin. The output always from the server process' stderr
    // and it is stored in XXXX.
    if( first_call_ )
        cat_file_to_server("output");
    else
        cat_state_to_server(state);
    first_call_ = false;

    // get server status
    if( get_server_status() != 0 ) {
        total_time_ += Utils::read_time_in_seconds() - start_time;
        remove_file(output_fn_);
        return ERROR;
    }

    // read plan from file
    raw_plan.clear();
    //ifstream ifs(plan_fn_);
    ifstream ifs("sas_plan");
    char line[2048];
    while( !ifs.eof() ) {
        ifs.getline(line, 2048);
        // remove any trailing blank inserted by LAMA_Server
        for( char *p = &line[strlen(line)-1]; *p == ' '; *p-- = '\0' );
        if( line[0] != '\0' ) {
            line[strlen(line) - 1] = '\0';
            map<string, size_t>::const_iterator it = action_map_.find(&line[1]);
            assert(it != action_map_.end());
            raw_plan.push_back(it->second);
        }
    }
    ifs.close();
    //remove_file(plan_fn_);
    remove_file("sas_plan");


#if 0
    cat_state_to_server(state);
    assert(get_server_status() == 0);
    ifs.open("sas_plan");
    while( !ifs.eof() ) {
        ifs.getline(line, 2048);
        // remove any trailing blank inserted by LAMA_Server
        for( char *p = &line[strlen(line)-1]; *p == ' '; *p-- = '\0' );
        if( line[0] != '\0' ) {
            line[strlen(line) - 1] = '\0';
cout << "STEP: " << line << endl;
        }
    }
    ifs.close();
    //remove_file(plan_fn_);
    remove_file("sas_plan");

    cat_state_to_server(state);
    assert(get_server_status() == 0);
    ifs.open("sas_plan");
    while( !ifs.eof() ) {
        ifs.getline(line, 2048);
        // remove any trailing blank inserted by LAMA_Server
        for( char *p = &line[strlen(line)-1]; *p == ' '; *p-- = '\0' );
        if( line[0] != '\0' ) {
            line[strlen(line) - 1] = '\0';
cout << "sTEP: " << line << endl;
        }
    }
    ifs.close();
    //remove_file(plan_fn_);
    remove_file("sas_plan");
#endif

    total_time_ += Utils::read_time_in_seconds() - start_time;
    return SOLVED;
}

void LAMA_Server_Planner::read_variable(ifstream &ifs, vector<pair<int, vector<int> > > &variables) const {
    string varname, type, atom, trailer;
    int axiom_layer, range, varno;
    ifs >> varname >> axiom_layer >> range;
    assert(strncmp(varname.c_str(), "var", 3) == 0);
    varno = atoi(varname.substr(3).c_str());
    //cout << "Variable #" << varno << " is " << varname << ": " << range << " value(s)" << endl;

    vector<int> variable;
    for( int i = 0; i < range; ++i ) {
        ifs >> type;
        assert((type == "Atom") || (type == "NegatedAtom") || (type == "<none"));
        if( (type == "Atom") || (type == "NegatedAtom") ) {
            bool negated = type == "NegatedAtom";
            ifs >> atom;
            transform(atom.begin(), atom.end(), atom.begin(), ::tolower);
            assert(atom.substr(atom.length() - 2, 2) == "()");
            atom.erase(atom.length() - 2, 2);
            map<string, size_t>::const_iterator it = atom_map_.find(atom);
            assert(it != atom_map_.end());
            variable.push_back(negated ? -(1 + it->second) : 1 + it->second);
            //cout << "    " << type << " " << atom << " " << it->second << endl;
        } else {
            ifs >> type;
            assert(type == "of");
            ifs >> type;
            assert(type == "those>");
            //cout << "    <none of those> -1" << endl;
        }
    }
    variables.push_back(make_pair(varno, variable));

    ifs >> trailer;
    assert(trailer == "end_variable");
}

struct LAMA_Server_Planner::variable_order {
    bool operator()(const pair<int, vector<int> > &a, const pair<int, vector<int> > &b) const {
        return a.first < b.first;
    }
};

void LAMA_Server_Planner::read_variables(ifstream &ifs) const {
    assert(ifs.is_open());
    vector<pair<int, vector<int> > > unordered_variables;
    char line[2048];
    while( !ifs.eof() ) {
        ifs.getline(line, 2048);
        if( !strcmp(line, "begin_variable") )
            read_variable(ifs, unordered_variables);
    }

    // sort variables according to their index
    variables_.reserve(unordered_variables.size());
    //sort(unordered_variables.begin(), unordered_variables.end(), variable_order());
    for( size_t i = 0; i < unordered_variables.size(); ++i ) {
        //cout << "Variable #" << unordered_variables[i].first << endl;
        variables_.push_back(unordered_variables[i].second);
    }
}

int LAMA_Server_Planner::create_server_process(const string &base) const {
    // create pipes for redirection of stdin and stderr
    if( pipe(stdin_pipe_) < 0 ) {
        perror((Utils::error() + "allocating pipe for child input redirect stdin").c_str());
        return -1;
    }
    if( pipe(stderr_pipe_) < 0 ) {
        close(stdin_pipe_[PIPE_READ]);
        close(stdin_pipe_[PIPE_WRITE]);
        perror((Utils::error() + "allocating pipe for child output redirect of stderr").c_str());
        return -1;
    }

    // fork child process
    child_pid_ = fork();
    if( child_pid_ == 0 ) {
        // we are in child process

        // redirect stdin and stderr
        if( dup2(stdin_pipe_[PIPE_READ], STDIN_FILENO) == -1 ) {
            perror((Utils::error() + "redirecting stdin").c_str());
            return -1;
        }
        if( dup2(stderr_pipe_[PIPE_WRITE], STDERR_FILENO) == -1 ) {
            perror((Utils::error() + "redirecting stderr").c_str());
            return -1;
        }

        // closed unused pipe ends
        close(stdin_pipe_[PIPE_READ]);
        close(stdin_pipe_[PIPE_WRITE]);
        close(stderr_pipe_[PIPE_READ]);
        close(stderr_pipe_[PIPE_WRITE]);

        // run child process image
        string cmd;
        if( planner_path_ != "" ) cmd += planner_path_ + "/src/search/downward-server";
        const char *argv[4];
        argv[0] = "downward-server";
        argv[1] = "seq-sat-lama-2011-single-plan";
        argv[2] = base.c_str();
        argv[3] = 0;
        int status = execve(cmd.c_str(), (char **)argv, 0);

        // if we get here at all, an error occurred, but we are in the child
        // process, so just exit
        perror((Utils::error() + "exec of the child process").c_str());
        exit(status);
    } else if( child_pid_ > 0 ) {
        // we are in father process
        cout << "LAMA_Server: child-pid=" << child_pid_ << endl;

        // close unused file descriptors, these are for child only
        close(stdin_pipe_[PIPE_READ]);
        close(stderr_pipe_[PIPE_WRITE]);

        // successful creation of child process
        return 0;
    } else {
        // failed to create child
        close(stdin_pipe_[PIPE_READ]);
        close(stdin_pipe_[PIPE_WRITE]);
        close(stderr_pipe_[PIPE_READ]);
        close(stderr_pipe_[PIPE_WRITE]);
        return -1;
    }
}

int LAMA_Server_Planner::cat_file_to_server(const string &filename) const {
    int fd = open(filename.c_str(), O_RDONLY);
    char buff[1024];
    int readsz = 0;
    while( (readsz = read(fd, buff, 1024)) > 0 )
        write(stdin_pipe_[PIPE_WRITE], buff, readsz);
    close(fd);
    return 0;
}

int LAMA_Server_Planner::cat_state_to_server(const State &state) const {
    write(stdin_pipe_[PIPE_WRITE], "state\n", 6);
    write(stdin_pipe_[PIPE_WRITE], "begin_state\n", 12);
    for( size_t k = 0; k < variables_.size(); ++k ) {
        string value;
        bool wrote = false;
        for( size_t j = 0; j < variables_[k].size(); ++j ) {
            int lit = variables_[k][j];
            int atom = lit > 0 ? lit - 1 : -lit - 1;
            if( ((lit > 0) && state.satisfy(atom)) || ((lit < 0) && !state.satisfy(atom)) ) {
                value += to_string(j);
                wrote = true;
                break;
            }
        }
        if( !wrote ) value += to_string(variables_[k].size());
        write(stdin_pipe_[PIPE_WRITE], value.c_str(), strlen(value.c_str()));
        write(stdin_pipe_[PIPE_WRITE], "\n", 1);
    }
    write(stdin_pipe_[PIPE_WRITE], "end_state\n", 10);
    return 0;
}

void LAMA_Server_Planner::exit_server() const {
    write(stdin_pipe_[PIPE_WRITE], "exit\n", 5);
}

int LAMA_Server_Planner::get_server_status() const {
    char buff[256];;
    read(stderr_pipe_[PIPE_READ], buff, 1);
    cout << "C=" << buff[0] << endl;
    return buff[0] == 'S' ? 0 : 1;
}

