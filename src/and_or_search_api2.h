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

#ifndef AND_OR_SEARCH_API2_H
#define AND_OR_SEARCH_API2_H

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#include "and_or3.h"
#include "lw1_problem.h"

#define DEBUG

namespace AndOr3 {

  namespace Search {

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
        virtual OrNode<T>* make_root_node(const T *state) const = 0;
        virtual bool prune(const OrNode<T> &node, bool verbose = false) const = 0;
        virtual bool is_goal(const T *state) const = 0;
        virtual void expand(const OrNode<T> &node, std::vector<AndNode<T>*> &successors) const = 0;
        virtual void compute_features(const OrNode<T> &root, const std::vector<OrNode<T>*> &fringe, bool verbose = false) const = 0;
        virtual void register_features(const OrNode<T> &node, bool verbose = false) const = 0;

        bool is_goal(const OrNode<T> &node) const {
            return node.is_goal();
        }
        bool has_solution(const OrNode<T> &node, bool explore = false) const {
            if( node.is_goal() ) {
                return true;
            } else {
                if( explore ) {
                    for( size_t k = 0; k < node.children().size(); ++k ) {
                        const AndNode<T> &child = *node.child(k);
                        if( has_solution(child, explore) ) {
                            node.set_best_child(k);
                            break;
                        }
                    }
                }
                return node.best_child() != -1;
            }
        }
        bool has_solution(const AndNode<T> &node, bool explore = false) const {
            if( explore ) {
                bool node_has_solution = true;
                for( size_t k = 0; k < node.children().size(); ++k ) {
                    const OrNode<T> &child = *node.child(k);
                    if( !has_solution(child, explore) ) {
                        node_has_solution = false;
                        break;
                    }
                }
                node.set_has_solution(node_has_solution);
            }
            return node.has_solution();
        }
        void compute_subtree_solution(const OrNode<T> &node) const {
            has_solution(node, true);
        }
        void compute_subtree_solution(const AndNode<T> &node) const {
            has_solution(node, true);
        }
        void propagate_subtree_solution_upwards(const OrNode<T> &node) const {
            if( has_solution(node) && (node.parent() != 0) ) {
                const AndNode<T> &parent = *node.parent();
                assert(!has_solution(parent));
                bool parent_has_solution = true;
                for( size_t k = 0; k < parent.children().size(); ++k ) {
                    const OrNode<T> &child = *parent.child(k);
                    if( !has_solution(child) ) {
                        parent_has_solution = false;
                        break;
                    }
                }
                parent.set_has_solution(parent_has_solution);
                propagate_subtree_solution_upwards(parent);
            }
        }
        void propagate_subtree_solution_upwards(const AndNode<T> &node) const {
            if( has_solution(node) && (node.parent() != 0) ) {
                const OrNode<T> &parent = *node.parent();
                assert(!has_solution(parent));
                for( size_t k = 0; k < parent.children().size(); ++k ) {
                    const AndNode<T> &child = *parent.child(k);
                    if( !has_solution(child) ) {
                        parent.set_best_child(k);
                        break;
                    }
                }
                propagate_subtree_solution_upwards(parent);
            }
        }
    };

  } // namespace Search

} // namespace AndOr

#undef DEBUG

#endif

