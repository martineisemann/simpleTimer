#ifndef _TIMER_H
#define _TIMER_H

#include <chrono>

class Timer {
  public:
    using clock = std::chrono::steady_clock;

    // Constructor starts timer immediately, similar to RAII
    Timer() = default;

    // either call the elapsed function to measure time since instantiation
    template <class T = std::chrono::milliseconds> long long elapsed() {
        return (std::chrono::duration_cast<T>(clock::now() - start_time_))
            .count();
    };

    // or measure a specific function
    template <class T = std::chrono::milliseconds, class F>
    static long long timeFunction(F const &function) {
        Timer t;
        function();
        return t.elapsed<T>();
    }

  private:
    clock::time_point start_time_ = clock::now();
};
#endif // _TIMER_H
