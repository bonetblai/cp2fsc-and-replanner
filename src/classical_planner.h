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

#ifndef CLASSICAL_PLANNER_H
#define CLASSICAL_PLANNER_H

#include <unistd.h>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include "kp_problem.h"
#include "state.h"

class ClassicalPlanner {
  public:
    enum { SOLVED = 0, NO_SOLUTION = 1, ERROR = 2 };
  protected:
    const KP_Instance &kp_instance_;
    const std::string planner_name_;
    const std::string planner_path_;
    const std::string tmpfile_path_;
    const bool remove_intermediate_files_;
    const int debug_;

    std::map<std::string, size_t> action_map_;

    std::string domain_fn_;
    std::string problem_fn_;
    std::string output_fn_;
    std::string tmp_fn_;
    std::string plan_fn_;

    mutable float total_search_time_;
    mutable float total_time_;
    mutable size_t n_calls_;
  public:
    ClassicalPlanner(const std::string &planner_name, const KP_Instance &kp_instance, const std::map<std::string, std::string> &options);
    virtual ~ClassicalPlanner() { }
    virtual int get_raw_plan(const State &state, Instance::Plan &raw_plan) const = 0;
    const std::string& name() const { return planner_name_; }
    const std::string& planner_path() const { return planner_path_; }
    const std::string& planner_name() const { return planner_name_; }
    float get_search_time() const { return total_search_time_; }
    float get_time() const { return total_time_; }
    size_t n_calls() const { return n_calls_; }
    void reset_stats() const {
        total_search_time_ = 0;
        total_time_ = 0;
        n_calls_ = 0;
    }

    void generate_pddl_domain() const;
    void generate_pddl_problem(const State &state) const;
    void remove_file(const std::string &filename) const;
    void reduce_plan(const Instance::Plan &raw_plan, Instance::Plan &reduced_plan) const;
    int get_plan(const State &state, Instance::Plan &raw_plan, Instance::Plan &plan) const;
};

class FF_Planner : public ClassicalPlanner {
    mutable bool first_call_;
  public:
    FF_Planner(const KP_Instance &kp_instance, const std::map<std::string, std::string> &options)
      : ClassicalPlanner("ff", kp_instance, options),
        first_call_(true) {
    }
    virtual ~FF_Planner();
    virtual int get_raw_plan(const State &state, Instance::Plan &raw_plan) const;
};

class M_Planner : public ClassicalPlanner {
  protected:
    mutable bool first_call_;
  public:
    M_Planner(const KP_Instance &kp_instance, const std::map<std::string, std::string> &options, const std::string &planner_name = "M")
      : ClassicalPlanner(planner_name, kp_instance, options),
        first_call_(true) {
    }
    virtual ~M_Planner();
    virtual int get_raw_plan(const State &state, Instance::Plan &raw_plan) const;
};

class MP_Planner : public M_Planner {
  public:
    MP_Planner(const KP_Instance &kp_instance, const std::map<std::string, std::string> &options)
      : M_Planner(kp_instance, options, "Mp") {
    }
    virtual ~MP_Planner();
};

class LAMA_Planner : public ClassicalPlanner {
    mutable bool first_call_;
    mutable std::streampos begin_state_pos_;
    mutable std::vector<std::vector<int> > variables_;
    std::map<std::string, size_t> atom_map_;
  public:
    LAMA_Planner(const KP_Instance &kp_instance, const std::map<std::string, std::string> &options);
    virtual ~LAMA_Planner();
    virtual int get_raw_plan(const State &state, Instance::Plan &raw_plan) const;

    struct variable_order;
    void patch_state_in_sas(std::fstream &iofs, const State &state) const;
    void determine_seek_pos(std::ifstream &ifs) const;
    void read_variable(std::ifstream &ifs, std::vector<std::pair<int, std::vector<int> > > &variables) const;
    void read_variables(std::ifstream &ifs) const;
};

class LAMA_Server_Planner : public ClassicalPlanner {
    mutable bool first_call_;
    //mutable std::streampos begin_state_pos_;
    mutable std::vector<std::vector<int> > variables_;
    std::map<std::string, size_t> atom_map_;

    enum { PIPE_READ = 0, PIPE_WRITE = 1 };
    mutable int stdin_pipe_[2];
    mutable int stderr_pipe_[2];
    mutable int child_pid_;

  public:
    LAMA_Server_Planner(const KP_Instance &kp_instance, const std::map<std::string, std::string> &options);
    virtual ~LAMA_Server_Planner();
    virtual int get_raw_plan(const State &state, Instance::Plan &raw_plan) const;
    //void patch_state_in_sas(std::fstream &iofs, const State &state) const;
    //void determine_seek_pos(std::ifstream &ifs) const;

    struct variable_order;
    void read_variable(std::ifstream &ifs, std::vector<std::pair<int, std::vector<int> > > &variables) const;
    void read_variables(std::ifstream &ifs) const;
    int create_server_process(const std::string &base) const;
    int cat_file_to_server(const std::string &filename) const;
    int cat_state_to_server(const State &state) const;
    void exit_server() const;
    int get_server_status() const;
};

#endif

