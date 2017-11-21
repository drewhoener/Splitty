//
// Created by drew on 11/20/17.
//

#ifndef SPLITTY_SPLIT_WINDOW_H
#define SPLITTY_SPLIT_WINDOW_H


#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/grid.h>

class SplitWindow : public Gtk::Window {

public:
    SplitWindow();
    ~SplitWindow() override;

private:
    Gtk::Grid mainGrid; // Grid to pack elements into
    Gtk::Box headerBox;// Packed at top of mainGrid
    Gtk::Box tableBox; // Packed in the middle, majority of space
    Gtk::Box footerBox; // Packed at bottom of mainGrid


};


#endif //SPLITTY_SPLIT_WINDOW_H
