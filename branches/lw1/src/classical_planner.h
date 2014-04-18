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
    std::string name_;
    std::string tmpfile_path_;
    std::string planner_path_;
    std::string planner_name_;
    const KP_Instance &kp_instance_;
    std::map<std::string, size_t> action_map_;

    const char *domain_fn_;
    const char *problem_fn_;
    const char *output_fn_;
    const char *tmp_fn_;
    const char *plan_fn_;

    mutable float total_search_time_;
    mutable float total_time_;
    mutable size_t n_calls_;
  public:
    ClassicalPlanner(const char *name, const char *tmpfile_path, const char *planner_path, const char *planner_name, const KP_Instance &instance);
    virtual ~ClassicalPlanner();
    virtual int get_raw_plan(const State &state, Instance::Plan &raw_plan) const = 0;
    const char* name() const { return planner_name_.c_str(); }
    const char* planner_path() const { return planner_path_.c_str(); }
    const char* planner_name() const { return planner_name_.c_str(); }
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
    void remove_file(const char *filename) const;
    void reduce_plan(const Instance::Plan &raw_plan, Instance::Plan &reduced_plan) const;
    int get_plan(const State &state, Instance::Plan &raw_plan, Instance::Plan &plan) const;
};

class FF_Planner : public ClassicalPlanner {
    mutable bool first_call_;
  public:
    FF_Planner(const KP_Instance &instance, const char *tmpfile_path, const char *planner_path)
      : ClassicalPlanner("FF", tmpfile_path, planner_path, "ff", instance), first_call_(true) { }
    virtual ~FF_Planner();
    virtual int get_raw_plan(const State &state, Instance::Plan &raw_plan) const;
};

class M_Planner : public ClassicalPlanner {
  protected:
    mutable bool first_call_;
  public:
    M_Planner(const KP_Instance &instance, const char *tmpfile_path, const char *planner_path, const char *planner_name = "M")
      : ClassicalPlanner(planner_name, tmpfile_path, planner_path, planner_name, instance), first_call_(true) { }
    virtual ~M_Planner();
    virtual int get_raw_plan(const State &state, Instance::Plan &raw_plan) const;
};

class MP_Planner : public M_Planner {
  public:
    MP_Planner(const KP_Instance &instance, const char *tmpfile_path, const char *planner_path)
      : M_Planner(instance, tmpfile_path, planner_path, "Mp") { }
    virtual ~MP_Planner();
};

class LAMA_Planner : public ClassicalPlanner {
    mutable bool first_call_;
    mutable std::streampos begin_state_pos_;
    mutable std::vector<std::vector<int> > variables_;
    std::map<std::string, size_t> atom_map_;
  public:
    LAMA_Planner(const KP_Instance &instance, const char *tmpfile_path, const char *planner_path);
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
    LAMA_Server_Planner(const KP_Instance &instance, const char *tmpfile_path, const char *planner_path);
    virtual ~LAMA_Server_Planner();
    virtual int get_raw_plan(const State &state, Instance::Plan &raw_plan) const;
    //void patch_state_in_sas(std::fstream &iofs, const State &state) const;
    //void determine_seek_pos(std::ifstream &ifs) const;

    struct variable_order;
    void read_variable(std::ifstream &ifs, std::vector<std::pair<int, std::vector<int> > > &variables) const;
    void read_variables(std::ifstream &ifs) const;
    int create_server_process(const char *base) const;
    int cat_file_to_server(const char *filename) const;
    int cat_state_to_server(const State &state) const;
    void exit_server() const;
    int get_server_status() const;
};

#endif

