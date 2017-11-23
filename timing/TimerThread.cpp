//
// Created by drew on 11/22/17.
//

#include "TimerThread.h"
#include "../view/SplitWindow.h"

TimerThread::TimerThread() : timer_(), mutex_() {
    timer_.reset();
}

TimerThread::~TimerThread() = default;

void TimerThread::pullData(Glib::ustring *str) {

    std::lock_guard<std::mutex> lock(mutex_);
    if (str)
        *str = this->curTime;
}

void TimerThread::loopTimer(SplitWindow *window) {
    while (!this->stopped_) {

        std::lock_guard<std::mutex> lock(this->mutex_);

        if ((timer_.elapsed() - lastTime_) > 30) {
            this->curTime = timer_.formatCurTime();
            lastTime_ = timer_.elapsed();
            window->emit();
        }
    }
    window->emit();
}

void TimerThread::stop() {

    std::lock_guard<std::mutex> lock(this->mutex_);
    this->stopped_ = true;
}

bool TimerThread::isStopped() const {
    std::lock_guard<std::mutex> lock(this->mutex_);
    return this->stopped_;
}

sw::Timer TimerThread::getTimer() {

    std::lock_guard<std::mutex> lock(mutex_);
    return timer_;
}
