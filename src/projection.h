#pragma once

#include <vector.hpp>

Vec3f projectCamera(const Vec3f& vertex, int screenWidth, int screenHeight, float fov = 90.0f, float near  = 1.0f);