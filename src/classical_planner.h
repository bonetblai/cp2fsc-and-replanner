#ifndef CLASSICAL_PLANNER_H
#define CLASSICAL_PLANNER_H

#include <fstream>
#include <map>
#include <string>
#include <vector>
#include "problem.h"
#include "state.h"

class ClassicalPlanner {
  public:
    enum { SOLVED = 0, NO_SOLUTION = 1, ERROR = 2 };
  protected:
    std::string name_;
    std::string planner_path_;
    std::string planner_name_;
    const Instance &instance_;
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
    ClassicalPlanner(const char *name, const char *planner_path, const char *planner_name, const Instance &instance);
    virtual ~ClassicalPlanner() { }
    virtual int get_plan(const State &state, Instance::Plan &plan) const = 0;
    const char* name() const { return planner_name_.c_str(); }
    const char* planner_path() const { return planner_path_.c_str(); }
    const char* planner_name() const { return planner_name_.c_str(); }
    float get_search_time() const { return total_search_time_; }
    float get_time() const { return total_time_; }
    size_t n_calls() const { return n_calls_; }
};

class FF_Planner : public ClassicalPlanner {
    mutable bool first_call_;
  public:
    FF_Planner(const Instance &instance, const char *planner_path)
      : ClassicalPlanner("FF", planner_path, "ff", instance), first_call_(true) { }
    virtual ~FF_Planner();
    virtual int get_plan(const State &state, Instance::Plan &plan) const;
};

class LAMA_Planner : public ClassicalPlanner {
    const char *LAMA_path_;
    const char *solver_path_;
    const char *first_cmd_;
    const char *other_cmd_;
    mutable bool first_call_;
    mutable std::streampos begin_state_pos_;
    mutable std::vector<std::vector<int> > variables_;
    std::map<std::string, size_t> atom_map_;
  public:
    LAMA_Planner(const Instance &instance, const char *planner_path);
    virtual ~LAMA_Planner();
    virtual int get_plan(const State &state, Instance::Plan &plan) const;
    void patch_output_sas(std::fstream &iofs, const State &state) const;
    void determine_seek_pos(std::ifstream &ifs) const;
    void read_variables(std::ifstream &ifs) const;
};

class M_Planner : public ClassicalPlanner {
  protected:
    mutable bool first_call_;
  public:
    M_Planner(const Instance &instance, const char *planner_path, const char *planner_name = "M")
      : ClassicalPlanner(planner_name, planner_path, planner_name, instance), first_call_(true) { }
    virtual ~M_Planner();
    virtual int get_plan(const State &state, Instance::Plan &plan) const;
};

class MP_Planner : public M_Planner {
  public:
    MP_Planner(const Instance &instance, const char *planner_path)
      : M_Planner(instance, planner_path, "Mp") { }
    virtual ~MP_Planner();
};

#endif

