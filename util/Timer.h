//
// Created by drew on 11/21/17.
//

#ifndef SPLITTY_TIMER_H
#define SPLITTY_TIMER_H

#include <chrono>

namespace sw {

    using namespace std::chrono;

    class Timer {

    public:
        Timer();

        void start();

        unsigned long elapsed();

        void pause();

        unsigned long lap();

        unsigned long stop();

        void reset();

    private:
        bool started = false;
        unsigned long elapsedTime;
        std::chrono::duration<double> seconds;
        time_point<high_resolution_clock, duration<double>> startTime;
        time_point<high_resolution_clock, duration<double>> endTime;

        std::chrono::duration<double> lapTime;
        time_point<high_resolution_clock, duration<double>> lapStart;
        time_point<high_resolution_clock, duration<double>> lapEnd;

        void updateTime();

        void updateLap();
    };

}


#endif //SPLITTY_TIMER_H
