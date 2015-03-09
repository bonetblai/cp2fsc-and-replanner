#ifndef UTILS_H
#define UTILS_H

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

inline const char *normal() { return "\x1B[0m"; }
inline const char *red() { return "\x1B[31;1m"; }
inline const char *green() { return "\x1B[32;1m"; }
inline const char *yellow() { return "\x1B[33;1m"; }
inline const char *blue() { return "\x1B[34;1m"; }
inline const char *magenta() { return "\x1B[35;1m"; }
inline const char *cyan() { return "\x1B[36;1m"; }
inline const char *error() { return "\x1B[31;1merror: \x1B[0m"; }
inline const char *warning() { return "\x1B[32;1mwarning: \x1B[0m"; }

};

#endif
