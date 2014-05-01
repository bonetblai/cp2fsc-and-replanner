#ifndef INDEX_H
#define INDEX_H

#include <set>
#include <vector>
#include <limits.h>

#define no_such_index INT_MAX

class index_vec : public std::vector<int> {
  public:
    index_vec(size_t n = 0, int i = 0) : std::vector<int>(n,i) { }
    void remap(const index_vec &map) {
        index_vec nvec;
        for( const_iterator si = begin(); si != end(); ++si ) {
            if( map[*si] != no_such_index )
                nvec.push_back(map[*si]);
        }
        *this = nvec;
    }
    void signed_remap(const index_vec &map) {
        index_vec nvec;
        for( const_iterator si = begin(); si != end(); ++si ) {
            int idx = (*si < 0 ? -*si : *si) - 1;
            if( map[idx] != no_such_index ) {
                int nidx = (*si < 0 ? -1 : 1) * (map[idx]+1);
                nvec.push_back(nidx);
            }
        }
        *this = nvec;
    }
};

class bool_vec : public std::vector<bool> {
  public:
    bool_vec(size_t n = 0, bool b = false) : std::vector<bool>(n,b) { }
    void bitwise_complement() {
        for( size_t k = 0; k < size(); ++k )
            (*this)[k] = !(*this)[k];
    }
    void bitwise_or(const bool_vec &b) {
        for( size_t k = 0; (k < b.size()) && (k < size()); ++k )
            (*this)[k] = (*this)[k] || b[k];
    }
    void bitwise_and(const bool_vec &b) {
        for( size_t k = 0; (k < b.size()) && (k < size()); ++k )
            (*this)[k] = (*this)[k] && b[k];
    }
};

class index_set : public std::set<int> {
  public:
    bool intersect(const index_set &s) const {
        for( const_iterator si = s.begin(); si != s.end(); ++si )
            if( find( *si ) != end() ) return true;
        return false;
    }
    bool contains(int e) const { return find(e) != end(); }
    bool contains(const index_set &s) const {
        for( const_iterator si = s.begin(); si != s.end(); ++si )
            if( !contains(*si) ) return false;
        return true;
    }
    void remap(const index_vec &map) {
        index_set nset;
        for( const_iterator si = begin(); si != end(); ++si ) {
            if( map[*si] != no_such_index )
                nset.insert(map[*si]);
        }
        *this = nset;
    }
    void signed_remap(const index_vec &map) {
        index_set nset;
        for( const_iterator si = begin(); si != end(); ++si ) {
            int idx = (*si < 0 ? -*si : *si) - 1;
            if( map[idx] != no_such_index ) {
                int nidx = (*si < 0 ? -1 : 1) * (map[idx]+1);
                nset.insert(nidx);
            }
        }
        *this = nset;
    }
};

#endif

