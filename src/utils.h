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

#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <sys/resource.h>
#include <sys/time.h>

namespace Utils {

inline float read_time_in_seconds(bool add_stime = true) {
    struct rusage r_usage;
    float time = 0;

    getrusage(RUSAGE_SELF, &r_usage);
    time += (float)r_usage.ru_utime.tv_sec +
            (float)r_usage.ru_utime.tv_usec / (float)1000000;
    if( add_stime ) {
        time += (float)r_usage.ru_stime.tv_sec +
                (float)r_usage.ru_stime.tv_usec / (float)1000000;
    }

    getrusage(RUSAGE_CHILDREN, &r_usage);
    time += (float)r_usage.ru_utime.tv_sec +
            (float)r_usage.ru_utime.tv_usec / (float)1000000;
    if( add_stime ) {
        time += (float)r_usage.ru_stime.tv_sec +
                (float)r_usage.ru_stime.tv_usec / (float)1000000;
    }

    return time;
}

inline std::string normal() { return "\x1B[0m"; }
inline std::string red() { return "\x1B[31;1m"; }
inline std::string green() { return "\x1B[32;1m"; }
inline std::string yellow() { return "\x1B[33;1m"; }
inline std::string blue() { return "\x1B[34;1m"; }
inline std::string magenta() { return "\x1B[35;1m"; }
inline std::string cyan() { return "\x1B[36;1m"; }
inline std::string error() { return "\x1B[31;1merror: \x1B[0m"; }
inline std::string warning() { return "\x1B[35;1mwarning: \x1B[0m"; }
inline std::string internal_error() { return "\x1B[31;1minternal error: \x1B[0m"; }

inline std::string cmdline(int argc, const char *argv[]) {
    std::string cmd = argv[0];
    for( int j = 1; j < argc; ++j )
        cmd += std::string(" ") + argv[j];
    return cmd;
}

inline std::string to_string(int n) {
#if 1
    return std::to_string(n);
#else
    char buff[256];
    sprintf(buff, "%d", n);
    return std::string(buff);
#endif
}

inline std::string replace_all(std::string str, const std::string &from, const std::string &to) {
    size_t start_pos = 0;
    while( (start_pos = str.find(from, start_pos)) != std::string::npos ) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}

};

#endif
