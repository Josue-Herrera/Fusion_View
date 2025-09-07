#pragma once

namespace fv {
class renderer {
public:
    virtual ~renderer() = default;
    virtual void draw() {}
};
}

