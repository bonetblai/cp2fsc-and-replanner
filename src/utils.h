#ifndef UTILS_H
#define UTILS_H

#include <sys/resource.h>
#include <sys/time.h>

namespace Utils {

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