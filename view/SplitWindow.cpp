//
// Created by drew on 11/20/17.
//

#include "SplitWindow.h"


SplitWindow::SplitWindow() {

    //set_size_request(350, 450);
    footerBox.set_size_request(350, 150);

    //Add grid to main window
    add(mainGrid);

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

    mainGrid.attach_next_to(headerBox, Gtk::POS_TOP, 1, 1);
    mainGrid.attach_next_to(tableBox, headerBox, Gtk::POS_BOTTOM, 1, 3);
    mainGrid.attach_next_to(footerBox, tableBox, Gtk::POS_BOTTOM, 1, 1);
}

SplitWindow::~SplitWindow() = default;
