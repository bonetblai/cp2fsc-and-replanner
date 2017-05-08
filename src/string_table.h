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

#ifndef STRING_TABLE_H
#define STRING_TABLE_H

#include <stdlib.h>
#include <cassert>
#include <vector>

#include "char_map.h"

class StringTable {
  public:
    struct Cell {
        size_t bin_;
        char   *text_;
        void   *value_;
        Cell   *next_;

        Cell(const char *str, const char_map &cmap, size_t bin, Cell *next)
          : bin_(bin), text_(cmap.strdup(str)), value_(0), next_(next) {
        }
        Cell(const char *str, size_t len, const char_map &cmap, size_t bin, Cell *next)
          : bin_(bin), text_(cmap.strdup(str, len)), value_(0), next_(next) {
        }
        Cell(const char *str, const char_map &cmap, void *value, size_t bin, Cell *next)
          : bin_(bin), text_(cmap.strdup(str)), value_(value), next_(next) {
        }
        Cell(const char *str, size_t len, const char_map &cmap, void *value, size_t bin, Cell *next)
          : bin_(bin), text_(cmap.strdup(str, len)), value_(value), next_(next) {
        }
        ~Cell() {
            delete[] text_;
            delete next_;
        }
    };

  protected:
    const char_map& char_map_;
    size_t          num_bins_;
    size_t          num_entries_;
    Cell            **table_;

  public:
    StringTable(const char_map &cmap, size_t num_bins);
    ~StringTable();

    size_t num_bins() const {
        return num_bins_;
    }
    size_t num_entries() const {
        return num_entries_;
    }
    const char_map& get_char_map() const {
        return char_map_;
    }

    void keys(std::vector<const char*> &vec) const;
    void values(std::vector<const void*> &values) const;

    const Cell* first() const;
    const Cell* next(const Cell *c) const;
    Cell* find_and_insert(const char *str, size_t len, bool only_find = false);

    Cell* insert(const char *str, size_t len) {
        return find_and_insert(str, len, false);
    }
    const char* set(const char *str, size_t len, void *value = 0) {
        Cell *sc = find_and_insert(str, len);
        sc->value_ = value;
        return sc->text_;
    }
    const Cell* find(const char *str, size_t len) const {
        return const_cast<StringTable*>(this)->find_and_insert(str, len, true);
    }
    void* find_value(const char *str, size_t len) const {
        const Cell *sc = find(str, len);
        return sc == 0 ? 0 : sc->value_;
    }

    Cell* find_and_insert(const char *symbol, bool only_find = false) {
        assert(symbol != 0);
        return find_and_insert(symbol, strlen(symbol), only_find);
    }
    Cell* insert(const char *symbol) {
        return find_and_insert(symbol, false);
    }
    const char* set(const char *symbol, void *value = 0) {
        assert(symbol != 0);
        return set(symbol, strlen(symbol), value);
    }
    const Cell* find(const char *symbol) const {
        assert(symbol != 0);
        return find(symbol, strlen(symbol));
    }
    void* find_value(const char *symbol) const {
        assert(symbol != 0);
        return find_value(symbol, strlen(symbol));
    }
};

#endif

