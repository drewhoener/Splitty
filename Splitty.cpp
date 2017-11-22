#include <iostream>
#include <gtkmm.h>
#include <thread>
#include "util/Timer.h"

using namespace std::chrono_literals;

void timerTests();

int main(int argc, char* argv[]) {

    std::cout << "Hello, World!" << '\n';

    //auto app = Gtk::Application::create(argc, argv, "com.drewhoener.splitty");

    //SplitWindow window;

    timerTests();

    return 0;
    //return app->run(window);
}

void timerTests() {
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
}