#ifndef UTILS_H
#define UTILS_H

#include <sys/resource.h>
#include <sys/time.h>

namespace Utils {

static const char *red = "\x1B[31;1m";
static const char *blue = "\x1B[34;1m";
static const char *magenta = "\x1B[35;1m";
static const char *normal = "\x1B[0m";
static const char *error = "\x1B[31;1merror: \x1B[0m";
static const char *warning = "\x1B[33;1mwarning: \x1B[0m";

inline float read_time_in_seconds(bool add_stime = false) {
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

};

#endif
