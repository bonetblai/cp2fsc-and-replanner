#ifndef KS0_PROBLEM_H
#define KS0_PROBLEM_H

#include <vector>
#include "cp_problem.h"

class KS0_Instance : public Instance {
    size_t n_tags_;
    size_t tag0_; // empty tag
    std::vector<bool> tagged_;
    std::vector<int> tag_map_;
  public:
    KS0_Instance(const CP_Instance &instance, bool tag_all_literals = true);
    ~KS0_Instance();
    int n_tags() const { return n_tags_; }
};

#endif

