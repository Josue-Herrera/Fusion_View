#pragma once

#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace fv {

class Layer; // fwd

class panel_registry {
public:
    using factory_t = std::function<Layer*()>;
    void register_factory(const std::string& id, factory_t f) { factories_[id] = std::move(f); }
    std::vector<std::string> ids() const {
        std::vector<std::string> out; out.reserve(factories_.size());
        for (auto& [k,_] : factories_) out.push_back(k);
        return out;
    }
    factory_t* find(const std::string& id) {
        auto it = factories_.find(id); if (it==factories_.end()) return nullptr; return &it->second;
    }
private:
    std::unordered_map<std::string, factory_t> factories_;
};

class renderer_registry {
public:
    using init_t = std::function<void()>;
    void register_init(const std::string& id, init_t fn) { inits_[id] = std::move(fn); }
    void init_all() { for (auto& [_,fn] : inits_) fn(); }
private:
    std::unordered_map<std::string, init_t> inits_;
};

} // namespace fv

