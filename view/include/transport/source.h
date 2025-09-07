#pragma once

namespace fv {
class app_context; // fwd

class source {
public:
    virtual ~source() = default;
    virtual void start(app_context&) {}
    virtual void stop() {}
};
}

