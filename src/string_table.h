#ifndef STRING_TABLE_H
#define STRING_TABLE_H

#include <stdlib.h>
#include <vector>
#include <iostream>
//#include "vector.h"
#include "char_map.h"

//typedef lvector<char*,16> string_vec;
//typedef svector<char*,16> string_set;
//typedef lvector<void*,16> element_vec;

class string_vec : public std::vector<char*> { };
class element_vec : public std::vector<void*> { };

inline std::ostream& operator<<(std::ostream &os, const string_vec &vec) {
    os << '[';
    for( size_t k = 0; k < vec.size(); k++ ) {
        if( k > 0 ) os << ',';
        os << '"' << vec[k] << '"';
    }
    os << ']';
    return os;
}

class StringTable {
  public:
    struct Cell {
        size_t bin;
        char   *text;
        void   *val;
        Cell   *next;
        Cell(const char *s, char_map &map, size_t b, Cell *n)
          : bin(b), text(map.strdup(s)), val(0), next(n) {
        }
        Cell(const char *s, size_t len, char_map &map, size_t b, Cell *n) 
          : bin(b), text(map.strdup(s, len)), val(0), next(n) {
        }
        Cell(const char *s, char_map &map, void *v, size_t b, Cell *n)
          : bin(b), text(map.strdup(s)), val(v), next(n) {
        }
        Cell(const char *s, size_t len, char_map &map, void *v, size_t b, Cell *n)
          : bin(b), text(map.strdup(s, len)), val(v), next(n) { }
        ~Cell() { delete[] text; delete next; }
    };

  private:
    size_t   n_bin;
    char_map &map;
    Cell     **table;
    size_t   n_entries;

  public:
    StringTable(size_t b, char_map& cm);
    ~StringTable();
    StringTable::Cell* inserta(const char *str);
    StringTable::Cell* inserta(const char *str, size_t len);
    char* insert(const char *str);
    char* insert(const char *str, size_t len);
    char* set(const char *str, void *val);
    char* set(const char *str, size_t len, void *val);
    char* set(const char *str) { return set(str, (void*)0); }
    char* set(const char *str, size_t len) { return set(str, len, (void*)0); }
    const StringTable::Cell* find(const char *str) const;
    const StringTable::Cell* find(const char *str, size_t len) const;
    void* find_val(const char *str) const;
    void* find_val(const char *str, size_t len) const;
    const StringTable::Cell* first() const;
    const StringTable::Cell* next(const StringTable::Cell *c) const;
    string_vec* keys();
    element_vec* values();
    size_t table_bins() { return n_bin; }
    size_t table_entries() { return n_entries; }
    char_map& table_char_map() { return map; }
};

#endif
