//
// Created by drew on 11/22/17.
//

#ifndef SPLITTY_TIMERTHREAD_H
#define SPLITTY_TIMERTHREAD_H

#include <mutex>
#include <glibmm/ustring.h>
#include "Timer.h"

class SplitWindow;

class TimerThread {

public:
    TimerThread();

    ~TimerThread();

    void pullData(Glib::ustring *str);

    void loopTimer(SplitWindow *window);

    void stop();

    bool isStopped() const;

    sw::Timer getTimer();


private:
    mutable std::mutex mutex_;
    bool stopped_ = false;
    sw::Timer timer_;
    std::string curTime;
    unsigned long lastTime_ = 0;
};


#endif //SPLITTY_TIMERTHREAD_H
