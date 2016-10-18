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

#include "and_or_search_api.h"
#include "utils.h"

#define DEBUG

namespace AndOr {

  namespace Search {

    template<typename T>
    class bfs {
      protected:
        struct compare_t {
            bool operator()(const Node *lhs, const Node *rhs) const {
                    return lhs->f() < rhs->f();
            }
        };
        typedef typename std::priority_queue<const Node*, std::vector<const Node*>, compare_t> priority_queue;

      protected:
        const LW1_Instance &lw1_instance_;
        const API<T> &api_;

      public:
        bfs(const LW1_Instance &lw1_instance, const API<T> &api)
          : lw1_instance_(lw1_instance), api_(api) {
        }
        virtual ~bfs() { }

        const Node* search(const T &init) const {
#ifdef DEBUG
            std::cout << Utils::green() << "BEGIN-SEARCH:" << Utils::normal()
                      << " init=";
            init.print(std::cout, &lw1_instance_);
            std::cout << std::endl;
#endif

            // reset api when performing new search
            api_.reset();
            
            priority_queue q;
            q.push(api_.make_root_node(&init));
            while( !q.empty() ) {
                const Node *n = q.top();
                assert(n != 0);
                q.pop();

                if( api_.prune(*n) ) {
                    continue;
                } else if( api_.is_goal(*n) ) {
#ifdef DEBUG
                    std::cout << Utils::green() << "END-SEARCH:" << Utils::normal()
                              << " goal found!"
                              << std::endl;
#endif
                    return n; // CHECK: should clear memory in use
                } else {
                    // expand node
                    std::vector<const Node*> successors;
                    api_.expand(*n, successors);
                    for( size_t i = 0; i < successors.size(); ++i )
                        q.push(successors[i]);
                }
            }
#ifdef DEBUG
            std::cout << Utils::green() << "END-SEARCH:" << Utils::normal()
                      << " queue exhausted!"
                      << std::endl;
#endif
            return 0; // CHECK: should clear memory in use
        }
    };

  } // namespace Search

} // namespace AndOr

#undef DEBUG

#endif

