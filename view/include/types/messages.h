#pragma once

#include <vector>
#include <cstdint>
#include <string>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

namespace fv {

struct point_cloud {
    std::vector<glm::vec3> xyz;
    std::vector<float> intensity; // optional
};

struct image_rgba {
    int width{};
    int height{};
    std::vector<std::uint8_t> rgba; // 4*width*height
};

using diagnostics = std::vector<std::pair<std::string, std::string>>;

struct series {
    std::string name;
    std::vector<double> t; // seconds
    std::vector<double> y;
};

} // namespace fv

