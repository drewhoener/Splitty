//
// Created by drew on 11/21/17.
//

#include "Timer.h"

sw::Timer::Timer() = default;

void sw::Timer::start() {

    if (!started) {
        started = true;
        startTime = high_resolution_clock::now();
        lapStart = high_resolution_clock::now();
    }

}

unsigned long sw::Timer::elapsed() {
    updateTime();

    return static_cast<unsigned long>((seconds.count() * 1000));
}

void sw::Timer::updateTime() {
    if (started) {
        endTime = high_resolution_clock::now();
        seconds += (endTime - startTime);
        /*
        * Update startTime to endTime so if pause() is called after
        * elapsed(), the delta will be 0 instead of doubling the val
        */
        startTime = endTime;
    }
}

void sw::Timer::updateLap() {

    if (started) {
        lapEnd = high_resolution_clock::now();
        lapTime += (lapEnd - lapStart);

        lapStart = lapEnd;
    }

}

void sw::Timer::pause() {

    if (started) {

        updateTime();
        updateLap();
        started = false;
    }
}

unsigned long sw::Timer::lap() {

    updateLap();

    auto time = static_cast<unsigned long>(lapTime.count() * 1000);
    lapStart = high_resolution_clock::now();
    lapEnd = lapStart;
    lapTime.zero();

    return time;
}

unsigned long sw::Timer::stop() {
    pause();
    return elapsedTime;
}

void sw::Timer::reset() {

    started = false;
    elapsedTime = 0;
}
