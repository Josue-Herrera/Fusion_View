#pragma once

#include <cstdint>

namespace fv {

class timebase {
public:
    void play() { playing_ = true; }
    void pause() { playing_ = false; }
    void toggle() { playing_ = !playing_; }
    bool playing() const { return playing_; }

    void set_speed(double s) { speed_ = s; }
    double speed() const { return speed_; }

    void seek_ns(int64_t t) { cursor_ns_ = t; }
    int64_t cursor_ns() const { return cursor_ns_; }

    void tick(double dt_seconds) {
        if (!playing_) return;
        cursor_ns_ += static_cast<int64_t>(dt_seconds * speed_ * 1e9);
    }

private:
    double speed_ {1.0};
    int64_t cursor_ns_ {0};
    bool playing_ {false};
};

} // namespace fv

