#ifndef INCLUDE_SRC_TIMER_H_
#define INCLUDE_SRC_TIMER_H_

#include <chrono>

class Timer {
  public:
    using clock = std::chrono::steady_clock;

    // Constructor starts timer immediately, similar to RAII
    Timer() : start_time_{clock::now()}, end_time_{}, stopped_{false} {}

    // Stops the timer
    void stop() {
        if (!stopped_) {
            end_time_ = clock::now();
            stopped_ = true;
        }
    }

    double elapsed_time_in_milliseconds() const {
        return std::chrono::duration<double, std::milli>(elapsed()).count();
    }

    double elapsed_time_in_seconds() const {
        return std::chrono::duration<double>(elapsed()).count();
    }

    double elapsed_time_in_minutes() const {
        return std::chrono::duration<double, std::ratio<60>>(elapsed()).count();
    }

    double elapsed_time_in_hours() const {
        return std::chrono::duration<double, std::ratio<3600>>(elapsed())
            .count();
    }

    void reset() {
        start_time_ = clock::now();
        stopped_ = false;
    }

  private:
    clock::duration elapsed() const {
        if (stopped_) {
            return end_time_ - start_time_;
        } else {
            return clock::now() - start_time_;
        }
    }

    clock::time_point start_time_;
    clock::time_point end_time_;
    bool stopped_;
};
#endif // INCLUDE_SRC_TIMER_H_
