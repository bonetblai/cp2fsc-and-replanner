#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include "classical_planner.h"
#include "utils.h"

using namespace std;

ClassicalPlanner::ClassicalPlanner(const char *planner_name, const Instance &instance)
  : planner_name_(planner_name), instance_(instance), total_search_time_(0), total_time_(0), n_calls_(0) {
    for( size_t k = 0; k < instance_.n_actions(); ++k ) {
        const Instance::Action &act = *instance_.actions[k];
        action_map_.insert(make_pair(act.name->to_string(), k));
    }

    int pid = getpid();
    ostringstream sstr("");
    sstr << "gen-d." << pid << ".pddl";
    domain_fn_ = strdup(sstr.str().c_str());
    sstr.str("");
    sstr << "gen-p." << pid << ".pddl";
    problem_fn_ = strdup(sstr.str().c_str());
    sstr.str("");
    sstr << planner_name_ << ".output." << pid;
    output_fn_ = strdup(sstr.str().c_str());
    sstr.str("");
    sstr << planner_name_ << ".tmp." << pid;
    tmp_fn_ = strdup(sstr.str().c_str());
    sstr.str("");
    sstr << planner_name_ << ".plan." << pid;
    plan_fn_ = strdup(sstr.str().c_str());
}

FF_Planner::~FF_Planner() {
    if( instance_.verbosity_mode.is_enabled("remove-intermediate-files") ) {
        if( !first_call_ ) unlink(domain_fn_);
    }
}

int FF_Planner::get_plan(const State &state, Instance::Plan &plan) const {

    cout << "calling " << name() << " (n=" << 1+n_calls() << ", acc-time=" << get_time() << ")..." << endl;
    float start_time = Utils::read_time_in_seconds();
    ++n_calls_;

    if( first_call_ ) {    
        // generate domain file
        ofstream ofs(domain_fn_);
        assert(ofs.is_open());
        instance_.write_domain(ofs);
        ofs.close();
        first_call_ = false;
    }

    // generate problem file
    ofstream ofs(problem_fn_);
    assert(ofs.is_open());
    instance_.write_problem(ofs, &state);
    ofs.close();

    // call FF planner
    ostringstream cmd("");
    cmd << "./ff -o " << domain_fn_ << " -f " << problem_fn_ << " > " << output_fn_;
    int rv = system(cmd.str().c_str());

    if( instance_.verbosity_mode.is_enabled("remove-intermediate-files") ) {
        unlink(problem_fn_);
    }

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

    if( instance_.verbosity_mode.is_enabled("remove-intermediate-files") ) {
        unlink(output_fn_);
    }

    if( rv != 0 ) {
        total_time_ += Utils::read_time_in_seconds() - start_time;
        if( instance_.verbosity_mode.is_enabled("remove-intermediate-files") ) {
            unlink(tmp_fn_);
        }
        return NO_SOLUTION;
    }

    cmd.str("");
    cmd << "cat " << tmp_fn_ << " | awk '{print $NF;}' | tr [:upper:] [:lower:]  > " << plan_fn_;
    rv = system(cmd.str().c_str());

    if( instance_.verbosity_mode.is_enabled("remove-intermediate-files") ) {
        unlink(tmp_fn_);
    }
    assert(rv == 0);

    // read plan from file
    plan.clear();
    ifs.open(plan_fn_);
    char line[2048];
    while( !ifs.eof() ) {
        ifs.getline(line, 1024);
        if( line[0] != '\0' ) {
            map<string, size_t>::const_iterator it = action_map_.find(line);
            assert(it != action_map_.end());
            plan.push_back(it->second);
        }
    }
    ifs.close();

    if( instance_.verbosity_mode.is_enabled("remove-intermediate-files") ) {
        unlink(plan_fn_);
    }

    total_time_ += Utils::read_time_in_seconds() - start_time;
    return SOLVED;
}

LAMA_Planner::~LAMA_Planner() {
}

LAMA_Planner::LAMA_Planner(const Instance &instance)
  : ClassicalPlanner("LAMA", instance), first_call_(true) {

    LAMA_path_ = "/home/bonet/LAMA/seq-sat-lama";
    solver_path_ = "/home/bonet/translator-X0+/source";

    ostringstream cmd;
    cmd << "(cd " << LAMA_path_ << "; ./plan "
        << solver_path_ << "/" << domain_fn_
        << " " << solver_path_ << "/" << problem_fn_
        << " " << solver_path_ << "/" << plan_fn_ << ")"
        << " > " << output_fn_;
    first_cmd_ = strdup(cmd.str().c_str());

    cmd.str("");
    cmd << "(cd " << LAMA_path_ << "; ./myplan output.sas"
        << " " << solver_path_ << "/" << plan_fn_ << ")"
        << " > " << output_fn_;
    other_cmd_ = strdup(cmd.str().c_str());

    for( size_t k = 0; k < instance_.n_atoms(); ++k ) {
        const Instance::Atom &atom = *instance_.atoms[k];
        string name = atom.name->to_string();
        for( size_t i = 0; i < name.length(); ++i )
            name[i] = tolower(name[i]);
        atom_map_.insert(make_pair(name.substr(1, name.length()-2), k));
    }
}

int LAMA_Planner::get_plan(const State &state, Instance::Plan &plan) const {

    cout << "calling " << name() << " (n=" << 1+n_calls() << ", acc-time=" << get_time() << ")..." << endl;
    float start_time = Utils::read_time_in_seconds();
    ++n_calls_;
  
    ostringstream fname; 
    if( first_call_ ) { 
        // generate domain file
        ofstream ofs(domain_fn_);
        assert(ofs.is_open());
        instance_.write_domain(ofs);
        ofs.close();

        // generate problem file
        ofs.open(problem_fn_);
        assert(ofs.is_open());
        instance_.write_problem(ofs, &state);
        ofs.close();

        // call LAMA planner including translation, preprocessing and search
        int rv = system(first_cmd_);

        if( instance_.verbosity_mode.is_enabled("remove-intermediate-files") ) {
            unlink(domain_fn_);
            unlink(problem_fn_);
        }

        if( rv != 0 ) {
            total_time_ += Utils::read_time_in_seconds() - start_time;
            return ERROR;
        }

        // update search time
        ostringstream cmd;
        cmd << "grep \"Search time\" " << output_fn_ << " | awk '{print $3;}' > " << tmp_fn_;
        rv = system(cmd.str().c_str());
        assert(rv == 0);
        ifstream ifs(tmp_fn_);
        float search_time;
        ifs >> search_time;
        total_search_time_ += search_time;
        ifs.close();

        if( instance_.verbosity_mode.is_enabled("remove-intermediate-files") ) {
            unlink(output_fn_);
            unlink(tmp_fn_);
        }

        // save result from translation: output.sas, all.groups, test.groups
        //system("cp ~/software/seq-sat-lama/output.sas output.sas");
        //system("cp ~/software/seq-sat-lama/all.groups all.groups");

        // read variables from file 'test.groups'
        fname.str("");
        fname << LAMA_path_ << "/test.groups";
        ifs.open(fname.str().c_str());
        read_variables(ifs);
        ifs.close();

        // determine position of begin-state in output.sas
        fname.str("");
        fname << LAMA_path_ << "/output.sas";
        ifs.open(fname.str().c_str());
        determine_seek_pos(ifs);
        ifs.close();

        // next time, don't do translation
        first_call_ = false;
    } else {
        // modify output.sas according to given state
        fname.str("");
        fname << LAMA_path_ << "/output.sas";
        fstream iofs(fname.str().c_str(), ios::in|ios::out);
        assert(!iofs.fail());
        patch_output_sas(iofs, state);
        iofs.close();

        // restore needed files
        //system("cp output.sas ~/software/seq-sat-lama/output.sas");
        //system("cp all.groups  ~/software/seq-sat-lama/all.groups");
        //system("cp test.groups ~/software/seq-sat-lama/test.groups");

        // call partial LAMA that only includes preprocessing and search
        int rv = system(other_cmd_);
        if( rv != 0 ) {
            total_time_ += Utils::read_time_in_seconds() - start_time;
            return ERROR;
        }

        // update search time
        ostringstream cmd;
        cmd << "grep \"Search time\" " << output_fn_ << " | awk '{print $3;}' > " << tmp_fn_;
        rv = system(cmd.str().c_str());
        assert(rv == 0);
        ifstream ifs(tmp_fn_);
        float search_time;
        ifs >> search_time;
        total_search_time_ += search_time;
        ifs.close();

        if( instance_.verbosity_mode.is_enabled("remove-intermediate-files") ) {
            unlink(output_fn_);
            unlink(tmp_fn_);
        }
    }

    // read plan from file
    plan.clear();
    fname.str("");
    fname << plan_fn_ << ".1";
    ifstream ifs(fname.str().c_str());
    char line[2048];
    while( !ifs.eof() ) {
        ifs.getline(line, 1024);
        // remove any trailing blank inserted by LAMA
        for( char *p = &line[strlen(line)-1]; *p == ' '; *p-- = '\0' );
        if( line[0] != '\0' ) {
            map<string, size_t>::const_iterator it = action_map_.find(line);
            assert(it != action_map_.end());
            plan.push_back(it->second);
        }
    }
    ifs.close();

    if( instance_.verbosity_mode.is_enabled("remove-intermediate-files") ) {
        unlink(fname.str().c_str());
    }

    total_time_ += Utils::read_time_in_seconds() - start_time;
    return SOLVED;
}

void LAMA_Planner::patch_output_sas(fstream &iofs, const State &state) const {
    assert(iofs.is_open());
    iofs.seekp(begin_state_pos_, ios_base::beg);
    for( size_t k = 0; k < variables_.size(); ++k ) {
        bool wrote = false;
        for( size_t j = 0; j < variables_[k].size(); ++j ) {
            int atom = variables_[k][j];
            if( (atom >= 0) && state.satisfy(atom) ) {
                iofs << j << endl;
                wrote = true;
                break;
            }
        }
        if( !wrote )
            iofs << variables_[k].size()-1 << endl;
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

void LAMA_Planner::read_variables(ifstream &ifs) const {
    assert(ifs.is_open());
    string var, token, dummy, atom;
    ifs >> var;
    while( !ifs.eof() ) {
        assert(strncmp(var.c_str(), "var", 3) == 0);
        vector<int> variable;
        //cout << "VAR=" << var << endl;
        ifs >> token;
        //cout << "TOKEN=" << token << endl;
        while( !ifs.eof() && isdigit(token.c_str()[0]) ) {
            ifs >> dummy >> atom;
            //cout << "DUMMY=" << dummy << endl;
            //cout << "ATOM=" << atom << endl;
            if( dummy == "Atom" ) {
                atom.erase(atom.length()-2, 2);
                map<string, size_t>::const_iterator it = atom_map_.find(atom);
                assert(it != atom_map_.end());
                variable.push_back(it->second);
                //cout << "ATOM=" << atom << ", IDX=" << it->second << endl;
            } else {
                assert(dummy == "<none");
                assert(atom == "of");
                ifs >> dummy;
                variable.push_back(-1);
            }
            ifs >> token;
            //cout << "TOKEN=" << token << endl;
        }
        variables_.push_back(variable);
        var = token;
    }
}

M_Planner::~M_Planner() {
    if( instance_.verbosity_mode.is_enabled("remove-intermediate-files") ) {
        if( !first_call_ ) unlink(domain_fn_);
    }
}

int M_Planner::get_plan(const State &state, Instance::Plan &plan) const {

    cout << "calling " << name() << " (n=" << 1+n_calls() << ", acc-time=" << get_time() << ")..." << endl;
    float start_time = Utils::read_time_in_seconds();
    ++n_calls_;

    if( first_call_ ) {    
        // generate domain file
        ofstream ofs(domain_fn_);
        assert(ofs.is_open());
        instance_.write_domain(ofs);
        ofs.close();
        first_call_ = false;
    }

    // generate problem file
    ofstream ofs(problem_fn_);
    assert(ofs.is_open());
    instance_.write_problem(ofs, &state);
    ofs.close();

    // call MP planner
    ostringstream cmd("");
    cmd << "./" << planner_name_ << " " << domain_fn_ << " " << problem_fn_ << " > " << output_fn_;
    int rv = system(cmd.str().c_str());

    if( instance_.verbosity_mode.is_enabled("remove-intermediate-files") ) {
        unlink(problem_fn_);
    }

    if( rv != 0 ) {
        total_time_ += Utils::read_time_in_seconds() - start_time;
        if( instance_.verbosity_mode.is_enabled("remove-intermediate-files") ) {
            unlink(output_fn_);
        }
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

    if( instance_.verbosity_mode.is_enabled("remove-intermediate-files") ) {
        unlink(tmp_fn_);
    }

    // extract plan from output
    cmd.str("");
    cmd << "cat " << output_fn_
        << " | grep STEP | sed \"s/STEP .*: //\" | tr \" \" \"\\n\" | sed \"s/()//\" > "
        << plan_fn_;
    rv = system(cmd.str().c_str());

    if( instance_.verbosity_mode.is_enabled("remove-intermediate-files") ) {
        unlink(output_fn_);
    }

    if( rv != 0 ) {
        total_time_ += Utils::read_time_in_seconds() - start_time;
        if( instance_.verbosity_mode.is_enabled("remove-intermediate-files") ) {
            unlink(plan_fn_);
        }
        return ERROR;
    }

    // read plan from file
    plan.clear();
    ifs.open(plan_fn_);
    char line[2048];
    while( !ifs.eof() ) {
        ifs.getline(line, 1024);
        if( line[0] != '\0' ) {
            map<string, size_t>::const_iterator it = action_map_.find(line);
            assert(it != action_map_.end());
            plan.push_back(it->second);
        }
    }
    ifs.close();

    if( instance_.verbosity_mode.is_enabled("remove-intermediate-files") ) {
        unlink(plan_fn_);
    }

    total_time_ += Utils::read_time_in_seconds() - start_time;
    return SOLVED;
}

MP_Planner::~MP_Planner() {
    if( instance_.verbosity_mode.is_enabled("remove-intermediate-files") ) {
        if( !first_call_ ) unlink(domain_fn_);
    }
}

