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

#ifndef AND_OR_SEARCH_H
#define AND_OR_SEARCH_H

#include <cassert>
#include <iostream>
#include "utils.h"

namespace AndOr {

template<typename API, typename NODE>
class bfs {
  protected:
    struct compare_t {
      bool operator()(const NODE *lhs, const NODE *rhs) const {
          return lhs->f() < rhs->f();
      }
    };
    typedef typename std::priority_queue<const NODE*, std::vector<const NODE*>, compare_t> priority_queue;

  protected:
    const API &api_;

  public:
    bfs(const API &api) : api_(api) { }
    virtual ~bfs() { }

    const NODE* search(const NODE &init) const {
        priority_queue q;
        q.insert(api_.make_root_node(init));
        while( !q.empty() ) {
            const NODE *n = q.top();
            q.pop();

            assert(n != 0);
            if( api_.prune(*n) ) {
                continue;
            } else if( api_.is_goal(*n) ) {
                return n; // CHECK: should clear memory in use
            } else {
                // expand node
                std::vector<const NODE*> successors;
                api_.expand(*n, successors);
                for( size_t i = 0; i < successors.size(); ++i )
                    q.insert(successors[i]);
            }
        }
        return 0; // CHECK: should clear memory in use
    }
};

}

#endif

