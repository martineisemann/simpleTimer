#include <iostream>
#include <thread>

#include "Timer.h"

int main() {
    Timer t; // timer starts here
    std::this_thread::sleep_for(std::chrono::seconds(2));
    t.stop(); // stop timer

    std::cout << "Millisec.: " << t.elapsed_time_in_milliseconds() << "\n"
              << "Seconds: " << t.elapsed_time_in_seconds() << "\n"
              << "Minutes: " << t.elapsed_time_in_minutes() << "\n"
              << "Hours: " << t.elapsed_time_in_hours() << "\n";
    return 0;
}
