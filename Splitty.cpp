#include <iostream>
#include <gtkmm.h>
#include "view/SplitWindow.h"

int main(int argc, char* argv[]) {
    std::cout << "Hello, World!" << std::endl;

    auto app = Gtk::Application::create(argc, argv, "com.drewhoener.splitty");

    SplitWindow window;

    return app->run(window);
}