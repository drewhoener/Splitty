//
// Created by drew on 11/20/17.
//

#include <iostream>
#include "SplitWindow.h"
#include "../util/SplitUtils.h"


SplitWindow::SplitWindow() :
        timerThread_(),
        headerBox_(Gtk::ORIENTATION_HORIZONTAL),
        tableBox_(Gtk::ORIENTATION_VERTICAL),
        footerBox_(Gtk::ORIENTATION_HORIZONTAL),
        stopwatchLabel_("00.000", true) {

    set_title("Splitty");

    //set_size_request(350, 450);
    footerBox_.set_size_request(300, 100);

    //Add grid to main window
    add(mainGrid_);

    /* ----------
     * | Title  |
     * |--------|
     * |        |
     * | Scroll |
     * |        |
     * |--------|
     * | Splits |
     * ----------
     */

    mainGrid_.attach_next_to(headerBox_, Gtk::POS_TOP, 1, 1);
    mainGrid_.attach_next_to(tableBox_, headerBox_, Gtk::POS_BOTTOM, 1, 3);
    mainGrid_.attach_next_to(footerBox_, tableBox_, Gtk::POS_BOTTOM, 1, 1);

    stopwatchLabel_.set_halign(Gtk::ALIGN_END);
    stopwatchLabel_.set_padding(7, 0);


    stopwatchLabel_.override_font(
            SpUtils::getFont("Liberation Mono", 40, Pango::STRETCH_ULTRA_EXPANDED, Pango::WEIGHT_ULTRABOLD));
    footerBox_.pack_end(stopwatchLabel_, true, true);

    dispatcher_.connect(sigc::mem_fun(*this, &SplitWindow::onDispatchEmit));

    add_events(Gdk::KEY_PRESS_MASK);

    show_all_children();
    set_keep_above(true);

}

SplitWindow::~SplitWindow() {
    timerThread_.stop();
    if (counterThread_ && counterThread_->joinable())
        counterThread_->join();
    delete counterThread_;
    std::cout << "Thread exited\n";
}

bool SplitWindow::on_key_press_event(GdkEventKey *key_event) {

    if (key_event->keyval == GDK_KEY_space) {
        if (!counterThread_) {

            timerThread_.start();
            counterThread_ = new std::thread([this] {
                timerThread_.loopTimer(this);
            });
            std::cout << "Starting thread...\n";
            return true;

        } else
            std::cout << "Thread already present!\n";
    } else if (key_event->keyval == GDK_KEY_BackSpace) {

        if (counterThread_) {
            timerThread_.stop();
        } else
            std::cout << "Thread not running!\n";
    }
    return Gtk::Window::on_key_press_event(key_event);
}

void SplitWindow::updateLabel() {
    Glib::ustring str;
    //std::cout << "Pulling Data\n";
    timerThread_.pullData(&str);

    //std::cout << str << "\n";

    if (str != stopwatchLabel_.get_text())
        stopwatchLabel_.set_text(str);
}

void SplitWindow::emit() {
    this->dispatcher_.emit();
}

void SplitWindow::onDispatchEmit() {

    if (counterThread_ && timerThread_.isStopped()) {

        //Done
        if (counterThread_->joinable())
            counterThread_->join();
        delete counterThread_;
        counterThread_ = nullptr;
        std::cout << "Thread deleted!\n";
    }
    updateLabel();
}
