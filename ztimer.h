#ifndef ZTIMER
#define ZTIMER

#include <sys/stat.h>
#ifndef _MSC_VER
#include <sys/time.h>
#endif
#include <sys/types.h>

class ZTimer
{
public:
    struct timeval t1, t2;
public:
    ZTimer() { gettimeofday(&t1,0); t2 = t1; }
    void reset() {gettimeofday(&t1,0); t2 = t1;}
    int elapsed() { return (t2.tv_sec * 1000 + t2.tv_usec / 1000) - (t1.tv_sec * 1000 + t1.tv_usec / 1000); }
    int split() { gettimeofday(&t2,0); return elapsed(); }
};

#endif

