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
            std::cout << Utils::red() << "BEGIN-SEARCH:" << Utils::normal() << " init=";
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
                root->pretty_print(std::cout, false, lw1_instance_, Utils::cyan());
                compute_features_and_select_nodes_for_expansion(*root, q, fringe);

#ifdef DEBUG
                std::cout << Utils::red() << "EXPAND FRINGE: size=" << fringe.size() << Utils::normal() << std::endl;
#endif

                // expand current fringe
                bool new_solved_node = false;
                for( size_t k = 0; (k < fringe.size()) && !api_.has_solution(*root); ++k ) {
                    OrNode<T> &n = *fringe[k];
                    assert(!api_.is_goal(n));
                    assert(!n.dead_by_feature());

                    // node may be pruned by solved ancestor
                    if( n.dead_by_label() ) {
                        std::cout << Utils::magenta() << "pruned by solved ancestor: node=" << n << Utils::normal() << std::endl;
                        continue;
                    }

                    // register features of node to be expanded
                    api_.register_features(n);

                    // expand node
                    std::vector<AndNode<T>*> successors;
                    api_.expand(n, successors);
                    ++num_expansions;
                    for( size_t i = 0; i < successors.size(); ++i ) {
                        AndNode<T> &succ = *successors[i];
                        for( size_t j = 0; j < succ.children().size(); ++j ) {
                            OrNode<T> &child = *const_cast<OrNode<T>*>(succ.child(j));
                            q.push_back(&child);
                        }

                        // link child with parent node
                        succ.set_parent(&n);
                        n.add_child(&succ);
                    }
                    api_.compute_subtree_solution(n);
                    new_solved_node = new_solved_node || api_.has_solution(n);
                    api_.propagate_subtree_solution_upwards(n);
                }
                fringe.clear();

                // if there is a new solved node, then the set of achieved features
                // may have changed. Clear all dead-by-feature flags. New flags will
                // be recomputed as nodes are selected for expansion
                if( new_solved_node ) {
                    clear_all_dead_by_feature_nodes(*root);
#ifdef DEBUG
                    std::cout << Utils::red() << "All dead-by-feature flags cleared!" << std::endl;
                    //root->pretty_print(std::cout, false, lw1_instance_, Utils::green());
#endif

                    // recompute queue
                    q.clear();
                    recompute_queue(*root, q);
                 }
            }
            return root;
        }

        void compute_features_and_select_nodes_for_expansion(const OrNode<T> &root, std::deque<OrNode<T>*> &in, std::vector<OrNode<T>*> &out) const {
#ifdef DEBUG
            std::cout << Utils::red() << "COMPUTE FEATURES: fringe-size=" << in.size() << Utils::normal() << std::endl;
#endif
            assert(!in.empty() && out.empty());
            while( !in.empty() ) {
                assert(in.front() != nullptr);
                OrNode<T> &n = *in.front();
                in.pop_front();
                if( !api_.is_goal(n) )
                    out.push_back(&n);
            }

            api_.compute_features(root, out);

            // mark nodes
            for( size_t k = 0; k < out.size(); ++k ) {
                const OrNode<T> &n = *out[k];
                if( !n.dead() && api_.prune(n, true) )
                    kill_by_feature(n);
            }

            // remove pruned nodes
            for( size_t k = 0; k < out.size(); ++k ) {
                while( (k < out.size()) && out[k]->dead() ) {
                    out[k] = out.back();
                    out.pop_back();
                }
            }
#ifdef DEBUG
            std::cout << Utils::red() << "COMPUTE FEATURES: DONE" << Utils::normal() << std::endl;
#endif
        }

        void kill_by_feature(const OrNode<T> &node) const {
            if( node.parent() != nullptr ) kill_by_feature(*node.parent());
            kill_node_and_descendants_by_feature(node);
        }
        void kill_by_feature(const AndNode<T> &node) const {
            assert(node.parent() != nullptr);
            bool kill_parent = true;
            for( size_t k = 0; k < node.parent()->children().size(); ++k ) {
                const AndNode<T> &child = *node.parent()->child(k);
                if( (&child != &node) && !child.dead() ) {
                    kill_parent = false;
                    break;
                }
            }
            if( kill_parent ) kill_by_feature(*node.parent());
            kill_node_and_descendants_by_feature(node);
        }

        void kill_node_and_descendants_by_feature(const OrNode<T> &node) const {
            if( !node.dead() ) {
                node.kill_by_feature();
                for( size_t k = 0; k < node.children().size(); ++k )
                    kill_node_and_descendants_by_feature(*node.child(k));
            }
        }
        void kill_node_and_descendants_by_feature(const AndNode<T> &node) const {
            if( !node.dead() ) {
                node.kill_by_feature();
                for( size_t k = 0; k < node.children().size(); ++k )
                    kill_node_and_descendants_by_feature(*node.child(k));
            }
        }

        void clear_all_dead_by_feature_nodes(const OrNode<T> &node) const {
            node.clear_dead_by_feature();
            for( size_t k = 0; k < node.children().size(); ++k )
                clear_all_dead_by_feature_nodes(*node.child(k));
        }
        void clear_all_dead_by_feature_nodes(const AndNode<T> &node) const {
            node.clear_dead_by_feature();
            for( size_t k = 0; k < node.children().size(); ++k )
                clear_all_dead_by_feature_nodes(*node.child(k));
        }

        void recompute_queue(OrNode<T> &node, deque_t &q) const {
            assert(!node.dead_by_feature());
            if( !node.dead() ) {
                if( node.children().empty() )
                    q.push_back(&node);
                for( size_t k = 0; k < node.children().size(); ++k )
                    recompute_queue(*const_cast<AndNode<T>*>(node.child(k)), q);
            }
        }
        void recompute_queue(AndNode<T> &node, deque_t &q) const {
            assert(!node.dead_by_feature());
            if( !node.dead() ) {
                for( size_t k = 0; k < node.children().size(); ++k )
                    recompute_queue(*const_cast<OrNode<T>*>(node.child(k)), q);
            }
        }
    };

  } // namespace Search

} // namespace AndOr3

#undef DEBUG

#endif

