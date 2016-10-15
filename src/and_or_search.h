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

  namespace Search {

    class Node {
      public:
        Node() { }
        virtual ~Node() { }
        virtual int f() const = 0;
        virtual void print(std::ostream &os) const = 0;
    };

    template<typename T>
    class API {
      public:
        API() { }
        virtual ~API() { }
        virtual void reset() const = 0;
        virtual const Node* make_root_node(const T *state) const = 0;
        virtual bool prune(const Node &node) const = 0;
        virtual bool is_goal(const Node &node) const = 0;
        virtual void expand(const Node &node, std::vector<const Node*> &successors) const = 0;
    };

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
        const API<T> &api_;

      public:
        bfs(const API<T> &api) : api_(api) { }
        virtual ~bfs() { }

        const Node* search(const T &init) const {
            std::cout << Utils::green() << "BEGIN-SEARCH:" << Utils::normal() << " init=" << init << std::endl;
            // reset api for performing new search
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
                    std::cout << Utils::green() << "END-SEARCH:" << Utils::normal() << " goal found!" << std::endl;
                    return n; // CHECK: should clear memory in use
                } else {
                    // expand node
                    std::vector<const Node*> successors;
                    api_.expand(*n, successors);
                    for( size_t i = 0; i < successors.size(); ++i )
                        q.push(successors[i]);
                }
            }
            std::cout << Utils::green() << "END-SEARCH:" << Utils::normal() << " queue exhausted!" << std::endl;
            return 0; // CHECK: should clear memory in use
        }
    };

  } // namespace Search

} // namespace AndOr

inline std::ostream& operator<<(std::ostream &os, const AndOr::Search::Node &node) {
    node.print(os);
    return os;
}

#endif

