//
// Created by drew on 11/21/17.
//

#include <sstream>
#include "Timer.h"

sw::Timer::Timer() = default;

void sw::Timer::start() {

    if (!started_) {
        started_ = true;
        startTime_ = high_resolution_clock::now();
        lapStart_ = high_resolution_clock::now();
    }

}

unsigned long sw::Timer::elapsed() {
    updateTime();

    return static_cast<unsigned long>((durTime_.count() * 1000));
}

void sw::Timer::updateTime() {
    if (started_) {
        endTime_ = high_resolution_clock::now();
        durTime_ += (endTime_ - startTime_);
        /*
        * Update startTime_ to endTime_ so if pause() is called after
        * elapsed(), the delta will be 0 instead of doubling the val
        */
        startTime_ = endTime_;
    }
}

void sw::Timer::updateLap() {

    if (started_) {
        lapEnd_ = high_resolution_clock::now();
        lapTime_ += (lapEnd_ - lapStart_);

        lapStart_ = lapEnd_;
    }

}

void sw::Timer::pause() {

    if (started_) {

        updateTime();
        updateLap();
        started_ = false;
    }
}

unsigned long sw::Timer::lap() {

    updateLap();

    auto time = static_cast<unsigned long>(lapTime_.count() * 1000);
    lapStart_ = high_resolution_clock::now();
    lapEnd_ = lapStart_;
    lapTime_.zero();

    return time;
}

unsigned long sw::Timer::stop() {
    pause();
    return static_cast<unsigned long>((durTime_.count() * 1000));
}

void sw::Timer::reset() {

    started_ = false;
    durTime_.zero();
    lapTime_.zero();
}

std::string sw::Timer::formatTime(unsigned long millis) {

    std::string str;

    std::string remMillis = std::to_string(millis % 1000);
    millis /= 1000;
    std::string seconds = std::to_string(millis % 60);
    millis /= 60;
    std::string mins = std::to_string(millis % 60);
    millis /= 60;
    std::string hours = std::to_string(millis);

    return (hours + ":" + mins + ":" + seconds + "." + remMillis);
}
