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

#ifndef AND_OR_SEARCH2_H
#define AND_OR_SEARCH2_H

#include <cassert>
#include <iostream>

#include "and_or_search_api2.h"
#include "utils.h"

#define DEBUG

namespace AndOr3 {

  namespace Search {

    template<typename T>
    class bfs {
      protected:
#if 0
        struct compare_t {
            bool operator()(const Node *lhs, const Node *rhs) const {
                    return lhs->f() > rhs->f();
            }
        };
#endif
        typedef typename std::deque<OrNode<T>*> deque_t;

      protected:
        const LW1_Instance &lw1_instance_;
        const API<T> &api_;

      public:
        bfs(const LW1_Instance &lw1_instance, const API<T> &api)
          : lw1_instance_(lw1_instance), api_(api) {
        }
        virtual ~bfs() { }

        const OrNode<T>* search(const T &init) const {
#ifdef DEBUG
            std::cout << Utils::green() << "BEGIN-SEARCH:" << Utils::normal()
                      << " init=";
            init.print(std::cout, &lw1_instance_);
            std::cout << std::endl;
#endif

            // reset api and initialize queue
            api_.reset();
            deque_t q;
            OrNode<T> *root = api_.make_root_node(&init);
            q.push_back(root);
            api_.compute_subtree_solution(*root);

            // do search
            size_t num_expansions = 0;
            std::vector<OrNode<T>*> fringe;
            while( !q.empty() && !api_.has_solution(*root) ) {
#ifdef DEBUG
                std::cout << "EXPANDING FRONTIER: size=" << q.size() << std::endl;
#endif
                compute_features_and_select_nodes_for_expansion(*root, q, fringe);

                // expand all current frontier
                for( size_t k = 0; k < fringe.size(); ++k ) {
                    const OrNode<T> &n = *fringe[k];
                    assert(!api_.is_goal(n));

                    // register features of node to be expanded
                    api_.register_features(n);

                    // expand node
                    std::vector<AndNode<T>*> successors;
                    api_.expand(n, successors);
                    ++num_expansions;
                    for( size_t i = 0; i < successors.size(); ++i ) {
                        const AndNode<T> *succ = successors[i];
                        for( size_t j = 0; j < succ->children().size(); ++j ) {
                            OrNode<T> &child = *const_cast<OrNode<T>*>(succ->child(j));
                            q.push_back(&child);
                        }
                    }
                    api_.compute_subtree_solution(n);
                    api_.propagate_subtree_solution_upwards(n);
                }
                fringe.clear();
            }
            return root;
        }

        void compute_features_and_select_nodes_for_expansion(const OrNode<T> &root, std::deque<OrNode<T>*> &in, std::vector<OrNode<T>*> &out) const {
            assert(!in.empty() && out.empty());
            while( !in.empty() ) {
                assert(in.front() != 0);
                OrNode<T> &n = *in.front();
                in.pop_front();
                if( !api_.is_goal(n) )
                    out.push_back(&n);
            }

            api_.compute_features(root, out);
            for( size_t k = 0; k < out.size(); ) {
                const OrNode<T> &n = *out[k++];
                if( api_.prune(n) ) {
                    assert(k > 0);
                    out[--k] = out.back();
                    out.pop_back();
                }
            }
        }
    };

  } // namespace Search

} // namespace AndOr3

#undef DEBUG

#endif

