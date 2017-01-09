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

#ifndef CHAR_MAP_H
#define CHAR_MAP_H

#include <string.h>

class char_map {
  public:
    static const unsigned int _CHAR_COUNT = 256;

  private:
    char _map[_CHAR_COUNT];

  public:
    char_map() {
        for( size_t k = 0; k < _CHAR_COUNT; k++ )
          _map[k] = k;
    }
    char_map(const char in[_CHAR_COUNT]) {
        for( size_t k = 0; k < _CHAR_COUNT; k++ )
            _map[k] = in[k];
    }

#if 0
    void identify(const char _c0, const char _c1) {
        _map[(unsigned char)_c1] = _c0;
        for( size_t k = 0; k < _CHAR_COUNT; k++ )
            if( _map[k] == _c1 )
                _map[k] = _c0;
    }
#endif

    char operator[](const char _in) const { return _map[(unsigned)_in]; }

#if 0
    void apply(char *s) const { for( ; *s; s++ ) *s = _map[(unsigned)*s]; }
    void apply(char *s, size_t len) const {
        for( size_t k = 0; k < len; s++, k++ )
            *s = _map[(unsigned)*s];
    }
#endif

    int strcmp(const char *s0, const char *s1) const {
        while( true ) {
            if( _map[(unsigned)*s0] < _map[(unsigned)*s1] ) {
                return -1;
            } else if( _map[(unsigned)*s0] > _map[(unsigned)*s1] ) {
                return 1;
            } else if( *s0 == (char)0 ) {
                return 0;
            } else {
                ++s0;
                ++s1;
            }
        }
    }
    int strcmp(const char *s0, const char *s1, size_t len) const {
        while( true ) {
            if( len == 0 ) {
                return *s0 == (char)0 ? 0 : 1;
            } else if( _map[(unsigned)*s0] < _map[(unsigned)*s1] ) {
                return -1;
            } else if( _map[(unsigned)*s0] > _map[(unsigned)*s1] ) {
                return 1;
            } else if( *s0 == (char)0 ) {
                return 0;
            } else {
                ++s0;
                ++s1;
                --len;
            }
        }
    }

#if 0
    const char* strchr(const char *s, char c) const {
        for( ; *s && (_map[(unsigned)*s] != _map[(unsigned)c]); s++ );
        return *s ? s : 0;
    }
    const char* strchr(const char *s, size_t len, char c) const {
        for( ; len && (_map[(unsigned)*s] != _map[(unsigned)c]); s++, len-- );
        return len ? s : 0;
    }
#endif

    char* strcpy(const char *s0, char *s1) const {
        char *r  = s1;
        while( *s0 ) *s1++ = _map[(unsigned)*s0++];
        *s1 = 0;
        return r;
    }
    char* strcpy(const char *s0, size_t len, char *s1) const {
        char *r  = s1;
        for( ; len ; --len ) *s1++ = _map[(unsigned)*s0++];
        *s1 = 0;
        return r;
    }

    char* strdup(const char *s0) const {
        char* r = new char[strlen(s0)+1];
        return strcpy(s0, r);
    }
    char* strdup(const char *s0, size_t len) const {
        char *r = new char[len+1];
        return strcpy(s0, len, r);
    }

    size_t hash(const char *s) const {
        size_t val = 0;
        char *v = (char*)&val;
        for( int k = 0; *s != '\0'; k++ )
            v[k % sizeof(size_t)] ^= _map[(unsigned)*(s++)];
        return val;
    }
    size_t hash(const char *s, size_t len) const {
        size_t val = 0;
        char *v = (char*)&val;
        for( size_t k = 0; k < len; k++ )
            v[k % sizeof(size_t)] ^= _map[(unsigned)*(s++)];
        return val;
    }
};

extern const char lowercase[char_map::_CHAR_COUNT];
extern char_map lowercase_map;

#endif

