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

#include <cassert>
#include "string_table.h"

using namespace std;

StringTable::StringTable(const class char_map &cmap, size_t num_bins)
  : char_map_(cmap),
    num_bins_(num_bins),
    num_entries_(0),
    table_(nullptr) {
    table_ = new StringTable::Cell*[num_bins_];
    for( size_t k = 0; k < num_bins_; ++k )
        table_[k] = nullptr;
}

StringTable::~StringTable() {
    for( size_t k = 0; k < num_bins_; ++k )
        delete table_[k];
    delete[] table_;
}

void StringTable::keys(vector<const char*> &vec) const {
    vec.clear();
    for( const StringTable::Cell *sc = first(); sc; sc = next(sc) )
        vec.push_back(sc->text_);
}

void StringTable::values(vector<const void*> &vec) const {
    vec. clear();
    for( const StringTable::Cell *sc = first(); sc; sc = next(sc) ) {
        if( sc->value_ != nullptr )
            vec.push_back(sc->value_);
    }
}

const StringTable::Cell* StringTable::first() const {
    for( size_t k = 0; k < num_bins_; ++k ) {
        if( table_[k] != nullptr )
            return table_[k];
    }
    return nullptr;
}

const StringTable::Cell* StringTable::next(const StringTable::Cell *sc) const {
    if( sc->next_ != nullptr ) {
        return sc->next_;
    } else {
        for( size_t k = sc->bin_ + 1; k < num_bins_; ++k ) {
            if( table_[k] != nullptr )
                return table_[k];
        }
        return nullptr;
    }
}

StringTable::Cell* StringTable::find_and_insert(const char *str, size_t len, bool only_find) {
    size_t bin = char_map_.hash(str, len) % num_bins_;
    StringTable::Cell **sc = &(table_[bin]);
    while( true ) {
        if( *sc == nullptr ) {
            if( only_find ) {
                return nullptr;
            } else {
                *sc = new StringTable::Cell(str, len, char_map_, nullptr, bin, nullptr);
                ++num_entries_;
                return *sc;
            }
        } else {
            int d = char_map_.strcmp((*sc)->text_, str, len);
            if( d == 0 ) {
	        return *sc;
            } else if( d < 0 ) {
                sc = &(*sc)->next_;
            } else {
                if( only_find ) {
                    return nullptr;
                } else {
	            *sc = new StringTable::Cell(str, len, char_map_, nullptr, bin, *sc);
	            ++num_entries_;
	            return *sc;
                }
            }
        }
    }
}

#if 0
char* StringTable::insert_other(const char *str, size_t len) {
    StringTable::Cell *sc = insert(str, len);
    return sc->text_;
}

const char* StringTable::set(const char* str, size_t len, void* value) {
    StringTable::Cell *sc = insert(str, len);
    sc->value_ = value;
    return sc->text_;
}

const StringTable::Cell* StringTable::find(const char *str, size_t len) const {
    size_t bin = char_map_.hash(str, len) % num_bins_;
    const StringTable::Cell *sc = table_[bin];
    while( true ) {
        if( sc == nullptr )
            return nullptr;
        else {
            int d = char_map_.strcmp(sc->text_, str, len);
            if( d == 0 )
                return sc;
            else if( d < 0 )
                sc = sc->next_;
            else
                return nullptr;
        }
    }
}

void* StringTable::find_value(const char *str, size_t len) const {
    const StringTable::Cell *sc = find(str, len);
    return sc ? sc->value_ : nullptr;
}

StringTable::Cell* StringTable::insert(const char *symbol) {
    size_t bin = char_map_.hash(symbol) % num_bins_;
    StringTable::Cell **sc = &(table_[bin]);
    while( true ) {
        if( *sc == nullptr ) {
            *sc = new StringTable::Cell(symbol, char_map_, nullptr, bin, nullptr);
            ++num_entries_;
            return *sc;
        } else {
            int d = char_map_.strcmp((*sc)->text_, symbol);
            if( d == 0 ) {
	        return *sc;
            } else if( d < 0 ) {
                sc = &(*sc)->next_;
            } else {
	        *sc = new StringTable::Cell(symbol, char_map_, nullptr, bin, *sc);
	        ++num_entries_;
	        return *sc;
            }
        }
    }
}

char* StringTable::insert_other(const char *str) {
    StringTable::Cell *sc = insert(str);
    return sc->text_;
}

const char* StringTable::set(const char *symbol, void *value) {
    StringTable::Cell *sc = insert(symbol);
    sc->value_ = value;
    return sc->text_;
}

const StringTable::Cell* StringTable::find(const char *symbol) const {
    size_t bin = char_map_.hash(symbol) % num_bins_;
    const StringTable::Cell *sc = table_[bin];
    while( true ) {
        if( sc == nullptr )
            return nullptr;
        else {
            int d = char_map_.strcmp(sc->text_, symbol);
            if( d == 0 )
                return sc;
            else if( d < 0 )
                sc = sc->next_;
            else
                return nullptr;
        }
    }
}

void* StringTable::find_value(const char *symbol) const {
    const StringTable::Cell* sc = find(symbol);
    return sc ? sc->value_ : nullptr;
}
#endif

