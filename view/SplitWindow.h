//
// Created by drew on 11/20/17.
//

#ifndef SPLITTY_SPLIT_WINDOW_H
#define SPLITTY_SPLIT_WINDOW_H

#include <mutex>
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/grid.h>
#include <gtkmm/textview.h>
#include <thread>
#include <giomm.h>
#include "../timing/TimerThread.h"


class SplitWindow : public Gtk::Window {

public:
    SplitWindow();

    ~SplitWindow() override;

    void emit();

protected:
    bool on_key_press_event(GdkEventKey *key_event) override;

private:
    std::thread *counterThread_ = nullptr;
    TimerThread timerThread_;
    Glib::Dispatcher dispatcher_;

    Gtk::Grid mainGrid_; // Grid to pack elements into
    Gtk::Box headerBox_;// Packed at top of mainGrid_
    Gtk::Box tableBox_; // Packed in the middle, majority of space
    Gtk::Box footerBox_; // Packed at bottom of mainGrid_

    Gtk::Label stopwatchLabel_;

    void onDispatchEmit();

    void updateLabel();

};


#endif //SPLITTY_SPLIT_WINDOW_H
