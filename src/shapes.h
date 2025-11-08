#pragma once

#include "vector.hpp"

struct Triangle {
    Vec3f v0, v1, v2;
    Triangle(Vec3i a, Vec3i b, Vec3i c) : v0(a), v1(b), v2(c) {}
    Triangle(Vec3f a, Vec3f b, Vec3f c) : v0(a), v1(b), v2(c) {}
};