//
// Created by drew on 11/21/17.
//

#ifndef SPLITTY_TIMER_H
#define SPLITTY_TIMER_H

#include <chrono>
#include <string>

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

        std::string formatTime(unsigned long millis);

        inline std::string formatCurTime() { return formatTime(static_cast<unsigned long>(durTime_.count() * 1000)); }

        inline std::string formatLapTime() { return formatTime(static_cast<unsigned long>(lapTime_.count() * 1000)); }

    private:
        bool started_ = false;
        std::chrono::duration<double> durTime_;
        time_point<high_resolution_clock, duration<double>> startTime_;
        time_point<high_resolution_clock, duration<double>> endTime_;

        std::chrono::duration<double> lapTime_;
        time_point<high_resolution_clock, duration<double>> lapStart_;
        time_point<high_resolution_clock, duration<double>> lapEnd_;

        void updateTime();

        void updateLap();
    };

}


#endif //SPLITTY_TIMER_H
