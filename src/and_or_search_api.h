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

#ifndef AND_OR_SEARCH_API_H
#define AND_OR_SEARCH_API_H

#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include "lw1_problem.h"

#define DEBUG

namespace AndOr {

  namespace Search {

    class Node {
      public:
        Node() { }
        virtual ~Node() { }
        virtual int f() const = 0;
        virtual std::string to_string() const = 0;
        void print(std::ostream &os) const {
            os << to_string() << std::flush;
        }
    };

    template<typename T>
    class API {
      protected:
        const LW1_Instance &lw1_instance_;

      public:
        API(const LW1_Instance &lw1_instance)
          : lw1_instance_(lw1_instance) {
        }
        virtual ~API() { }

        const LW1_Instance& lw1_instance() const {
            return lw1_instance_;
        }

        virtual void reset() const = 0;
        virtual const Node* make_root_node(const T *state) const = 0;
        virtual bool prune(const Node &node) const = 0;
        virtual bool is_goal(const Node &node) const = 0;
        virtual void expand(const Node &node, std::vector<const Node*> &successors) const = 0;
    };

  } // namespace Search

} // namespace AndOr

inline std::ostream& operator<<(std::ostream &os, const AndOr::Search::Node &node) {
    node.print(os);
    return os;
}

#undef DEBUG

#endif

