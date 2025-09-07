#pragma once

#include "core/timebase.h"
#include "core/registry.h"

namespace fv {

struct app_context {
    timebase time;
    panel_registry preg;
    renderer_registry rreg;
};

}

