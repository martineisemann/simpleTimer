#include <chrono>
#include <iostream>
#include <thread>

#include "Timer.h"

void sleep() { std::this_thread::sleep_for(std::chrono::seconds(2)); }

int main() {
    Timer t; // timer starts here
    sleep();

    std::cout << "Millisec.: " << t.elapsed<std::chrono::milliseconds>() << "\n"
              << "Seconds: " << t.elapsed<std::chrono::seconds>() << "\n"
              << "Minutes: " << t.elapsed<std::chrono::minutes>() << "\n"
              << "Hours: " << t.elapsed<std::chrono::hours>() << "\n";

    std::cout << "Function took: " << Timer::timeFunction(sleep) << std::endl;

    return 0;
}
