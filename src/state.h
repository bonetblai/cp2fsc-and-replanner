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

#ifndef STATE_H
#define STATE_H

#include "problem.h"
#include "index.h"
#include "utils.h"
#include <cassert>
#include <iostream>
#include <list>
#include <string>

#if __clang_major__ >= 5
#include <unordered_map>
#include <unordered_set>
#else
#include <tr1/unordered_map>
#include <tr1/unordered_set>
#endif

class StateHash;
class StateSet;

class State {
    size_t capacity_;
    size_t size_;
    unsigned *atoms_;
    void make_space(size_t n) {
        capacity_ = capacity_ ? capacity_ : 2;
        while( capacity_ < 2*n ) capacity_ *= 2;
        unsigned *atoms = new unsigned[capacity_+1];
        for( unsigned *p = atoms, *q = atoms_; *q; ) *p++ = *q++;
        atoms[size_] = 0;
        delete[] atoms_;
        atoms_ = atoms;
    }
  public:
    State(size_t n = 0) : capacity_(n), size_(0), atoms_(new unsigned[capacity_+1]) {
        atoms_[0] = 0;
    }
    State(const State &s) : capacity_(s.size_), size_(s.size_), atoms_(new unsigned[capacity_+1]) {
        for( unsigned *p = atoms_, *q = s.atoms_; *q; ) *p++ = *q++;
        atoms_[size_] = 0;
    }
    State(const index_set &s) : capacity_(s.size()), size_(0), atoms_(new unsigned[capacity_+1]) {
        atoms_[0] = 0;
        add(s);
    }
    virtual ~State() {
        delete[] atoms_;
    }

    void remap(State &state, index_vec &map) const {
        state.clear();
        for( unsigned *p = atoms_; *p; p++ ) {
            if( map[*p-1] != no_such_index )
                state.add(map[*p-1]);
        }
    }

    size_t size() const { return size_; }
    void clear() { atoms_[0] = 0; size_ = 0; }
    size_t hash() const { return 0; }

    bool satisfy(unsigned a, bool neg = false) const {
        ++a;
        for( unsigned *p = atoms_; *p && (*p <= a); p++ )
            if( *p == a ) return !neg;
        return neg;
    }
    bool satisfy(const index_set &pre) const {
        for( index_set::const_iterator p = pre.begin(); p != pre.end(); ++p ) {
            int idx = *p > 0 ? *p-1 : -*p-1;
            if( !satisfy(idx, *p<0) ) return false;
        }
        return true;
    }
    bool satisfy(const Instance::Clause &clause) const {
        for( size_t k = 0; k < clause.size(); ++k ) {
            int l = clause[k];
            int p = l < 0 ? -l : l;
            if( satisfy(p-1, l!=p) ) return true;
        }
        return false;
    }
    bool satisfy(const Instance::clause_vec &clauses) const {
        for( size_t k = 0; k < clauses.size(); ++k )
            if( !satisfy(clauses[k]) ) return false;
        return true;
    }

    void add(unsigned a) {
        ++a;
        make_space(size_ + 1);
        unsigned *p = atoms_;
        while( *p && (*p < a) ) ++p;
        if( !*p ) {
            ++size_;
            *p++ = a;
            *p = 0;
        } else if( *p != a ) {
            atoms_[size_+1] = 0;
            for( unsigned *q = &atoms_[size_]; q > p; q-- ) *q = *(q-1);
            *p = a;
            ++size_;
        }
    }
    void add(const index_set &s) {
        for( index_set::const_iterator si = s.begin(); si != s.end(); ++si )
            add(*si);
    }
    void add(const State &s) {
        for( const_iterator si = s.begin(); si != s.end(); ++si )
            add(*si);
    }
    void remove(size_t a) {
        ++a;
        unsigned *p;
        for( p = atoms_; *p && (*p < a); ++p );
        if( *p == a ) {
            do {
                *p = *(p+1);
                ++p;
            } while( *p );
            --size_;
        }
    }
    void remove(const index_set &s) {
        for( index_set::const_iterator si = s.begin(); si != s.end(); ++si )
            remove(*si);
    }

    void clear_non_primitive_fluents(const Instance &instance) {
        for( index_set::const_iterator it = instance.non_primitive_fluents_.begin(); it != instance.non_primitive_fluents_.end(); ++it ) {
            if( instance.given_stickies_.find(*it+1) == instance.given_stickies_.end() )
                remove(*it);
        }
    }

    void apply(int p, bool neg) { if( neg ) remove(p); else add(p); }
    void apply(const index_set &add_list, const index_set &del_list) {
        remove(del_list);
        add(add_list);
    }
    void apply(const index_set &effect) {
        for( index_set::const_iterator it = effect.begin(); it != effect.end(); ++it ) {
            if( *it > 0 )
                add(*it - 1);
            else
                remove(-*it - 1);
        }
    }
    void conditional_apply(const State &s, const index_set &cond, const index_set &add, const index_set &del) {
        if( s.satisfy(cond) ) apply(add, del);
    }
    void conditional_apply(const State &s, const index_set &cond, const index_set &effect) {
        if( s.satisfy(cond) ) apply(effect);
    }
    void apply(const Instance::Action &act) {
        State clone(*this);
        apply(act.effect());
        for( size_t j = 0; j < act.when().size(); ++j )
            conditional_apply(clone, act.when()[j].condition(), act.when()[j].effect());
    }
    void apply_axioms(const Instance &ins) {
#ifdef SMART
        for( Instance::owner_axiom_vec::const_iterator it = ins.axioms_.begin(); it != ins.axioms_.end(); ++it )
            conditional_apply(*this, (*it)->body(), (*it)->head());
#else
        for( Instance::axiom_vec::const_iterator it = ins.axioms_.begin(); it != ins.axioms_.end(); ++it )
            conditional_apply(*this, (*it)->body(), (*it)->head());
#endif
    }
    void apply(const Instance::Action &act, const Instance &ins) {
        clear_non_primitive_fluents(ins);
        apply(act);
        apply_axioms(ins);
    }

    bool is_goal(const Instance &ins) const {
        for( index_set::const_iterator p = ins.goal_literals_.begin(); p != ins.goal_literals_.end(); ++p ) {
            int idx = *p > 0 ? *p-1 : -*p-1;
            if( *p > 0 ) {
                if( !satisfy(idx) ) return false;
            } else {
                if( satisfy(idx) ) return false;
            }
        }
        return true;
        //return satisfy(ins.goal_cls);
    }
    bool applicable(const Instance::Action &act) const { return satisfy(act.precondition()); }

    bool operator==(const State &s) const {
        if( size_ != s.size_ ) return false;
        unsigned *p = atoms_, *q = s.atoms_;
        while( *p && (*p++ == *q++) );
        return *p == 0;
    }
    bool operator!=(const State &s) const { return !(*this == s); }
    bool operator<(const State &s) const {
        if( size_ != s.size_ ) return size_ < s.size_;
        for( unsigned *p = atoms_, *q = s.atoms_; *p; )
            if( *p++ != *q++ ) return *(p-1) < *(q-1);
        return false;
    }
    const State& operator=(const State &s) {
        make_space(s.size_);
        size_ = s.size_;
        for( unsigned *p = atoms_, *q = s.atoms_; *q; )
            *p++ = *q++;
        atoms_[size_] = 0;
        return *this;
    }
    bool operator()(const State *s1, const State *s2) const { return *s1 == *s2; }
    size_t operator()(const State *s) const { return s->hash(); }

    static std::string to_string(int literal, const Instance *ins = nullptr) {
        if( ins == nullptr ) {
            return Utils::to_string(literal);
        } else {
            std::string str;
            if( literal < 0 ) str += "(not ";
            //str += std::string("(") + ins->atoms_[literal < 0 ? -literal - 1 : literal - 1]->name_->to_string() + ")";
            str += std::string("(") + ins->atoms_[literal < 0 ? -literal - 1 : literal - 1]->name() + ")";
            if( literal < 0 ) str += ")";
            return str;
        }
    }

    static void print_literal(std::ostream &os, int literal, const Instance *ins = nullptr) {
        os << to_string(literal, ins);
    }

    static bool is_special(int literal, const Instance *ins = nullptr) {
        std::string literal_name = to_string(literal, ins);
        if (literal_name.find("need-start") != std::string::npos or
            literal_name.find("normal-execution") != std::string::npos or
            literal_name.find("normal-execution") != std::string::npos or
            literal_name.find("sensing") != std::string::npos) {
            return true;
        }
        return false;
    }

    void print(std::ostream &os, const Instance *ins = nullptr) const {
        os << "{";
        for( unsigned *p = atoms_; *p; ++p ) {
            assert(*p > 0);
            State::print_literal(os, *p, ins);
            os << (*(p+1) ? "," : "");
        }
        os << "}";
    }
    void print(std::ostream &os, const Instance &ins) const {
        print(os, &ins);
    }

    //struct ptr_map_fun {
    //    bool operator()(const State *p1, const State *p2) const { return (*p1) < (*p2); }
    //};

    // iterators
    struct const_iterator {
        const unsigned *p_;
        const_iterator(const unsigned *p = nullptr) : p_(p) { }
        const_iterator operator++() { return ++p_; }
        unsigned operator*() const { return *p_ - 1; }
        bool operator!=(const const_iterator &i) const { return p_ != i.p_; }
    };
    const_iterator begin() const { return atoms_; }
    const_iterator end() const { return &atoms_[size_]; }
};

inline std::ostream& operator<<(std::ostream &os, const State &s) {
    s.print(os);
    return os;
}

namespace Hash {

  template<typename T> class hash {
    public:
      size_t operator()(const T &s) const { return s.hash(); }
  };

  template<typename T> class equal_to {
    public:
      size_t operator()(const T &s1, const T &s2) const { return s1 == s2; }
  };

  class Data {
      size_t action_;
      mutable size_t marks_;
      mutable size_t scc_low_;
      mutable size_t scc_idx_;
    public:
      Data( size_t action = UINT_MAX, size_t marks = 0 )
        : action_(action), marks_(marks), scc_low_(UINT_MAX), scc_idx_(UINT_MAX) { }
      size_t action() const { return action_; }
      void set_action(size_t action) { action_ = action; }
      bool marked() const { return marks_ & 0x1; }
      void mark() { marks_ |= 0x1; }
      bool solved() const { return marks_ & 0x2; }
      void solve() { marks_ |= 0x2; }
      size_t scc_low() const { return scc_low_; }
      void set_scc_low(size_t low) const { scc_low_ = low; }
      size_t scc_idx() const { return scc_idx_; }
      void set_scc_idx(size_t idx) const { scc_idx_ = idx; }
      void write(std::ostream &os) const { os << "{" << action_ << "," << marks_ << "}"; }
  };

};

inline std::ostream& operator<<(std::ostream &os, const Hash::Data &d) {
    d.write(os);
    return os;
}

#if __clang_major__ >= 5
template<typename T, typename F=Hash::hash<T>, typename E=Hash::equal_to<T> > class Hash_set : public std::unordered_set<T, F, E> { };

template<typename T, typename F=Hash::hash<T>, typename E=Hash::equal_to<T> > class Hash_map : public std::unordered_map<T, Hash::Data*, F, E> {
      typedef std::unordered_map<T, Hash::Data*, F, E> base_;

    public:
      typedef typename std::unordered_map<T, Hash::Data*, F, E>::iterator iterator;
      typedef typename std::unordered_map<T, Hash::Data*, F, E>::const_iterator const_iterator;
#else
template<typename T, typename F=Hash::hash<T>, typename E=Hash::equal_to<T> > class Hash_set : public std::tr1::unordered_set<T, F, E> { };

template<typename T, typename F=Hash::hash<T>, typename E=Hash::equal_to<T> > class Hash_map : public std::tr1::unordered_map<T, Hash::Data*, F, E> {
      typedef std::tr1::unordered_map<T, Hash::Data*, F, E> base_;

    public:
      typedef typename std::tr1::unordered_map<T, Hash::Data*, F, E>::iterator iterator;
      typedef typename std::tr1::unordered_map<T, Hash::Data*, F, E>::const_iterator const_iterator;
#endif
      const_iterator begin() const { return base_::begin(); }
      const_iterator end() const { return base_::end(); }
      iterator begin() { return base_::begin(); }
      iterator end() { return base_::end(); }

    protected:
      Hash::Data* push(const T &s, Hash::Data *d) {
          std::pair<iterator, bool> p = insert(std::make_pair(s, d));
          return d;
      }
      iterator lookup(const T &s) { return find(s); }
      const_iterator lookup(const T &s) const { return find(s); }

    public:
      Hash_map() { }
      virtual ~Hash_map() {
          for( iterator hi = begin(); hi != end(); ++hi )
              delete (*hi).second;
      }

      Hash::Data* data_ptr(const T &s) {
          iterator di = lookup(s);
          return di == end() ? push(s, new Hash::Data) : (*di).second;
      }
      bool marked(const T &s) const {
          const_iterator di = lookup(s);
          return di == end() ? false : (*di).second->marked();
      }
      void mark(const T &s) {
          iterator di = lookup(s);
          if( di == end() )
              push(s, new Hash::Data(UINT_MAX, 1));
          else
              (*di).second->mark();
      }
      bool solved(const T &s) const {
          const_iterator di = lookup(s);
          return di == end() ? false : (*di).second->solved();
      }
      void solve(const T &s) {
          iterator di = lookup(s);
          if( di == end() )
              push(s, new Hash::Data(UINT_MAX, 2));
          else
              (*di).second->solve();
      }
      size_t action(const T &s) const {
          const_iterator di = lookup(s);
          return di == end() ? UINT_MAX : (*di).second->action();
      }
      void set_action(const T &s, size_t action) {
          iterator di = lookup(s);
          if( di == end() )
              push(s, new Hash::Data(action, false));
          else
              (*di).second->set_action(action);
      }
      void dump(std::ostream &os) const {
          for( const_iterator di = begin(); di != end(); ++di )
              os << (*di).first << " : " << *(*di).second << std::endl;
      }
};

class StateHash : public Hash_map<const State*, State, State> { };
class StateSet : public Hash_set<const State*, State, State> { };

#if 0
inline void State::apply(const Instance::Action &act, StateSet &bel) const {
    static State t;

    t = *this;
    t.apply(act);

    int i = 0, j = 0;
    std::vector<int> stack, restore;
    while( true ) {
        assert(stack.size() == restore.size());
        if( i == act.oneof.size() ) {
            if( t.satisfy(act.cls) ) {
                State *x = new State(t);
                bel.insert(x);
            }
            if( i == 0 ) break;
            int l = restore.back(), p = l < 0 ? -l : l;
            j = stack.back();
            if( l != INT_MAX ) t.apply(p-1, p!=l);
            restore.pop_back();
            stack.pop_back();
            --i;
            continue;
        }
        if( j == act.oneof[i].size() ) {
            if( i == 0 ) break;
            int l = restore.back(), p = l < 0 ? -l : l;
            j = stack.back();
            if( l != INT_MAX ) t.apply(p-1, p!=l);
            restore.pop_back();
            stack.pop_back();
            --i;
            continue;
        }
        int l = act.oneof[i][j], p = l < 0? -l : l;
        restore.push_back(t.satisfy(p-1, p==l) ? -l : INT_MAX);
        t.apply(p-1, p!=l);
        stack.push_back(1+j);
        ++i;
        j = 0;
    }
}
#endif

#endif

