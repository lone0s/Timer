#ifndef CHRONO_CHRONO_H
#define CHRONO_CHRONO_H


#include <ctime>
#include <stdio.h>

class Chrono {
public:
    double secondsPassed;
    clock_t clock;
    bool clockIsRunning;

    Chrono();
    void start();
    void end();
    void calculateTimePassed(const clock_t &start, const clock_t &end);
    std::string howMuchTimePassed() const;
};


#endif //CHRONO_CHRONO_H
