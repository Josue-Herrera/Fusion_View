#pragma once

#include <cstdint>
#include <vector>
#include <mutex>

namespace fv {

template <class T>
struct message {
    int64_t stamp_ns{};
    T payload{};
};

template <class T>
class topic_store {
public:
    void push(message<T>&& m) {
        std::lock_guard<std::mutex> lk(mu_);
        data_.emplace_back(std::move(m));
    }

    const message<T>* sample_at(int64_t t) const {
        std::lock_guard<std::mutex> lk(mu_);
        if (data_.empty()) return nullptr;
        for (auto it = data_.rbegin(); it != data_.rend(); ++it) {
            if (it->stamp_ns <= t) return &*it;
        }
        return nullptr;
    }

    const std::vector<message<T>>& all() const { return data_; }

private:
    mutable std::mutex mu_;
    std::vector<message<T>> data_;
};

} // namespace fv

