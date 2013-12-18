#include <algorithm>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include "classical_planner.h"
#include "utils.h"

using namespace std;

ClassicalPlanner::ClassicalPlanner(const char *name,
                                   const char *tmpfile_path,
                                   const char *planner_path,
                                   const char *planner_name,
                                   const Instance &instance)
  : name_(name), tmpfile_path_(tmpfile_path), planner_path_(planner_path), planner_name_(planner_name),
    instance_(instance), total_search_time_(0), total_time_(0), n_calls_(0) {
    for( size_t k = 0; k < instance_.n_actions(); ++k ) {
        const Instance::Action &act = *instance_.actions_[k];
        action_map_.insert(make_pair(act.name_->to_string(), k));
    }

    int pid = getpid();

    ostringstream sstr;
    if( tmpfile_path_ != "" ) sstr << tmpfile_path_ << "/";
    sstr << "gen-d." << pid << ".pddl";
    domain_fn_ = strdup(sstr.str().c_str());

    sstr.str("");
    if( tmpfile_path_ != "" ) sstr << tmpfile_path_ << "/";
    sstr << "gen-p." << pid << ".pddl";
    problem_fn_ = strdup(sstr.str().c_str());

    sstr.str("");
    if( tmpfile_path_ != "" ) sstr << tmpfile_path_ << "/";
    sstr << planner_name_ << ".output." << pid;
    output_fn_ = strdup(sstr.str().c_str());

    sstr.str("");
    if( tmpfile_path_ != "" ) sstr << tmpfile_path_ << "/";
    sstr << planner_name_ << ".tmp." << pid;
    tmp_fn_ = strdup(sstr.str().c_str());

    sstr.str("");
    if( tmpfile_path_ != "" ) sstr << tmpfile_path_ << "/";
    sstr << planner_name_ << ".plan." << pid;
    plan_fn_ = strdup(sstr.str().c_str());
}

ClassicalPlanner::~ClassicalPlanner() {
    free((char*)plan_fn_);
    free((char*)tmp_fn_);
    free((char*)output_fn_);
    free((char*)problem_fn_);
    free((char*)domain_fn_);
}

void ClassicalPlanner::generate_pddl_domain() const {
    ofstream ofs(domain_fn_);
    assert(ofs.is_open());
    instance_.write_domain(ofs);
    ofs.close();
}

void ClassicalPlanner::generate_pddl_problem(const State &state) const {
    ofstream ofs(problem_fn_);
    assert(ofs.is_open());
    instance_.write_problem(ofs, &state);
    ofs.close();
}

void ClassicalPlanner::remove_file(const char *filename) const {
    if( instance_.options_.is_enabled("solver:remove-intermediate-files") )
        unlink(filename);
}

FF_Planner::~FF_Planner() {
    if( !first_call_ ) remove_file(domain_fn_);
}

int FF_Planner::get_plan(const State &state, Instance::Plan &plan) const {

    cout << "calling " << name() << " (n=" << 1+n_calls() << ", acc-time=" << get_time() << ")..." << endl;
    float start_time = Utils::read_time_in_seconds();
    ++n_calls_;

    if( first_call_ ) {    
        generate_pddl_domain();
        first_call_ = false;
    }
    generate_pddl_problem(state);

    // call FF planner
    ostringstream cmd;
    if( planner_path_ != "" ) cmd << planner_path_ << "/";
    cmd << planner_name_ << " -o " << domain_fn_ << " -f " << problem_fn_ << " > " << output_fn_;
    int rv = system(cmd.str().c_str());
    remove_file(problem_fn_);

    if( rv != 0 ) {
        total_time_ += Utils::read_time_in_seconds() - start_time;
        return ERROR;
    }

    // update search time
    cmd.str("");
    cmd << "grep \"seconds searching\" " << output_fn_ << " | awk '{print $1;}' > " << tmp_fn_;
    rv = system(cmd.str().c_str());
    assert(rv == 0);
    ifstream ifs(tmp_fn_);
    float search_time;
    ifs >> search_time;
    total_search_time_ += search_time;
    ifs.close();

    // extract plan from output
    cmd.str("");
    cmd << "egrep -e [0-9]+: " << output_fn_ << " > " << tmp_fn_;
    rv = system(cmd.str().c_str());
    remove_file(output_fn_);

    if( rv != 0 ) {
        total_time_ += Utils::read_time_in_seconds() - start_time;
        remove_file(tmp_fn_);
        return NO_SOLUTION;
    }

    cmd.str("");
    cmd << "cat " << tmp_fn_ << " | awk '{print $NF;}' | tr \"[:upper:]\" \"[:lower:]\"  > " << plan_fn_;
    rv = system(cmd.str().c_str());
    remove_file(tmp_fn_);
    assert(rv == 0);

    // read plan from file
    plan.clear();
    ifs.open(plan_fn_);
    char line[2048];
    while( !ifs.eof() ) {
        ifs.getline(line, 2048);
        if( line[0] != '\0' ) {
            map<string, size_t>::const_iterator it = action_map_.find(line);
            assert(it != action_map_.end());
            plan.push_back(it->second);
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

int M_Planner::get_plan(const State &state, Instance::Plan &plan) const {

    cout << "calling " << name() << " (n=" << 1+n_calls() << ", acc-time=" << get_time() << ")..." << endl;
    float start_time = Utils::read_time_in_seconds();
    ++n_calls_;

    if( first_call_ ) {    
        generate_pddl_domain();
        first_call_ = false;
    }
    generate_pddl_problem(state);

    // call M/Mp planner. Flag '-W' sets the random seed using time.
    ostringstream cmd;
    if( planner_path_ != "" ) cmd << planner_path_ << "/";
    cmd << planner_name_ << " -W " << domain_fn_ << " " << problem_fn_ << " > " << output_fn_;
    int rv = system(cmd.str().c_str());
    remove_file(problem_fn_);

    if( rv != 0 ) {
        total_time_ += Utils::read_time_in_seconds() - start_time;
        return ERROR;
    }

    // update search time
    cmd.str("");
    cmd << "grep \"total time\" " << output_fn_ << " | awk '{print $3, $5;}' > " << tmp_fn_;
    rv = system(cmd.str().c_str());
    assert(rv == 0);
    ifstream ifs(tmp_fn_);
    float total_time, preprocess_time;
    ifs >> total_time >> preprocess_time;
    total_search_time_ += total_time - preprocess_time;
    ifs.close();
    remove_file(tmp_fn_);

    // extract plan from output
    cmd.str("");
    cmd << "cat " << output_fn_
        << " | grep STEP | sed \"s/STEP .*: //\" | tr \" \" \"\\n\" | sed \"s/()//\" > "
        << plan_fn_;
    rv = system(cmd.str().c_str());
    remove_file(output_fn_);

    if( rv != 0 ) {
        total_time_ += Utils::read_time_in_seconds() - start_time;
        remove_file(plan_fn_);
        return ERROR;
    }

    // read plan from file
    plan.clear();
    ifs.open(plan_fn_);
    char line[2048];
    while( !ifs.eof() ) {
        ifs.getline(line, 2048);
        if( line[0] != '\0' ) {
            map<string, size_t>::const_iterator it = action_map_.find(line);
            assert(it != action_map_.end());
            plan.push_back(it->second);
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

LAMA_Planner::LAMA_Planner(const Instance &instance, const char *tmpfile_path, const char *planner_path)
  : ClassicalPlanner("LAMA", tmpfile_path, planner_path, "lama", instance), first_call_(true) {
    for( size_t k = 0; k < instance_.n_atoms(); ++k ) {
        const Instance::Atom &atom = *instance_.atoms_[k];
        string name = atom.name_->to_string();
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        atom_map_.insert(make_pair(name.substr(1, name.length() - 2), k));
    }
}

LAMA_Planner::~LAMA_Planner() {
    if( !first_call_ ) remove_file("output");
}

int LAMA_Planner::get_plan(const State &state, Instance::Plan &plan) const {

    cout << "calling " << name() << " (n=" << 1+n_calls() << ", acc-time=" << get_time() << ")..." << endl;
    float start_time = Utils::read_time_in_seconds();
    ++n_calls_;
  
    ostringstream fname; 
    if( first_call_ ) {
        generate_pddl_domain();
        generate_pddl_problem(state);

        // translate domain + problem into SAS+ problem
        string cmd;
        if( planner_path_ != "" ) cmd += planner_path_ + "/";
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
        if( planner_path_ != "" ) cmd += planner_path_ + "/";
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
    if( planner_path_ != "" ) cmd += planner_path_ + "/";
    cmd += string("lama search seq-sat-lama-2011-single-plan output ") + plan_fn_ + " > " + output_fn_;
    int rv = system(cmd.c_str());
    if( rv != 0 ) {
        total_time_ += Utils::read_time_in_seconds() - start_time;
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
    plan.clear();
    ifs.open(plan_fn_);
    char line[2048];
    while( !ifs.eof() ) {
        ifs.getline(line, 2048);
        // remove any trailing blank inserted by LAMA
        for( char *p = &line[strlen(line)-1]; *p == ' '; *p-- = '\0' );
        if( line[0] != '\0' ) {
            map<string, size_t>::const_iterator it = action_map_.find(line);
            assert(it != action_map_.end());
            plan.push_back(it->second);
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

struct variable_order {
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

