#include <iostream>
#include <gtkmm.h>
#include <thread>
#include "timing/Timer.h"
#include "view/SplitWindow.h"

using namespace std::chrono_literals;

int timerTests();

int main(int argc, char* argv[]) {

    std::cout << "Hello, World!" << '\n';

    auto app = Gtk::Application::create(argc, argv, "com.drewhoener.splitty");

    SplitWindow window;

    //return timerTests();

    return app->run(window);
}

int timerTests() {
    sw::Timer t;
    t.start();

    std::this_thread::sleep_for(150ms);
    std::cout << t.elapsed() << '\n';
    t.pause();
    std::this_thread::sleep_for(5s);
    std::cout << t.elapsed() << '\n';
    t.start();
    std::this_thread::sleep_for(150ms);
    std::cout << t.elapsed() << '\n' << t.lap() << '\n';
    std::cout << t.formatTime(3601687350) << '\n';

    return 0;
}