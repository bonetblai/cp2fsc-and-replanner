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

