#include "string_table.h"

StringTable::StringTable(size_t b, char_map &cm)
  : n_bin(b), map(cm), table(0), n_entries(0) {
    table = new StringTable::Cell*[n_bin];
    for( size_t k = 0; k < n_bin; k++ )
        table[k] = 0;
}

StringTable::~StringTable() {
    for( size_t k = 0; k < n_bin; k++ )
        delete table[k];
    delete[] table;
}

StringTable::Cell* StringTable::inserta(const char *str) {
    size_t l = map.hash(str) % n_bin;
    StringTable::Cell **sc = &(table[l]);
    while( true ) {
        if( !*sc ) {
            *sc = new StringTable::Cell(str, map, 0, l, 0);
            n_entries += 1;
            return *sc;
        } else {
            int d = map.strcmp((*sc)->text, str);
            if( d == 0 )
	        return *sc;
            else if( d < 0 )
                sc = &((*sc)->next);
            else {
	        *sc = new StringTable::Cell(str, map, 0, l, *sc);
	        n_entries += 1;
	        return *sc;
            }
        }
    }
}

StringTable::Cell* StringTable::inserta(const char *str, size_t len) {
    size_t l = map.hash(str, len) % n_bin;
    StringTable::Cell **sc = &(table[l]);
    while( true ) {
        if( !*sc ) {
            *sc = new StringTable::Cell(str, map, 0, l, 0);
            n_entries += 1;
            return *sc;
        } else {
            int d = map.strcmp((*sc)->text, str, len);
            if( d == 0 )
	        return *sc;
            else if( d < 0 )
                sc = &((*sc)->next);
            else {
	        *sc = new StringTable::Cell(str, len, map, 0, l, *sc);
	        n_entries += 1;
	        return *sc;
            }
        }
    }
}

char* StringTable::insert(const char *str) {
    StringTable::Cell *sc = inserta(str);
    return sc->text;
}

char* StringTable::insert(const char *str, size_t len) {
    StringTable::Cell *sc = inserta(str, len);
    return sc->text;
}

char* StringTable::set(const char *str, void *val) {
    StringTable::Cell *sc = inserta(str);
    sc->val = val;
    return sc->text;
}

char* StringTable::set(const char* str, size_t len, void* val) {
    StringTable::Cell *sc = inserta(str, len);
    sc->val = val;
    return sc->text;
}

const StringTable::Cell* StringTable::find(const char *str) const {
    size_t l = map.hash(str) % n_bin;
    StringTable::Cell **sc = &(table[l]);
    while( true ) {
        if( !*sc )
            return 0;
        else {
            int d = map.strcmp((*sc)->text, str);
            if(d == 0 )
                return *sc;
            else if( d < 0 )
                sc = &((*sc)->next);
            else
                return 0;
        }
    }
}

const StringTable::Cell* StringTable::find(const char *str, size_t len) const {
    size_t l = map.hash(str, len) % n_bin;
    StringTable::Cell **sc = &(table[l]);
    while( true ) {
        if( !*sc )
            return 0;
        else {
            int d = map.strcmp((*sc)->text, str, len);
            if( d == 0 )
                return *sc;
            else if( d < 0 )
                sc = &((*sc)->next);
            else
                return 0;
        }
    }
}

void* StringTable::find_val(const char* str) const {
    const StringTable::Cell* sc = find(str);
    return sc ? sc->val : (void*)0;
}

void* StringTable::find_val(const char *str, size_t len) const {
    const StringTable::Cell *sc = find(str, len);
    return sc ? sc->val : (void*)0;
}

const StringTable::Cell* StringTable::first() const {
    for( size_t k = 0; k < n_bin; k++ )
        if( table[k] )
            return table[k];
    return 0;
}

const StringTable::Cell* StringTable::next(const StringTable::Cell* c) const {
    if( c->next ) return c->next;
    for( size_t k = c->bin + 1; k < n_bin; k++ )
        if( table[k] )
            return table[k];
    return 0;
}

string_vec* StringTable::keys() {
    string_vec* vec = new string_vec;
    for( const StringTable::Cell *sc = first(); sc; sc = next(sc) )
        vec->push_back((char*)sc->text);
    return vec;
}

element_vec* StringTable::values() {
    element_vec *vec = new element_vec;
    for( const StringTable::Cell *sc = first(); sc; sc = next(sc) )
        if( sc->val )
            vec->push_back((void*)sc->val);
    return vec;
}

