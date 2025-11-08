#include "framebuffer.h"
#include "vector.hpp"
#include "shapes.h"

void plotLineLow(Framebuffer* fb, int x0, int y0, int x1, int y1, uint32_t color);

void plotLineHigh(Framebuffer* fb, int x0, int y0, int x1, int y1, uint32_t color);

void drawLine(Framebuffer* fb, Vec3f& p0, Vec3f& p1, uint32_t color);

void drawTriangleWF(Framebuffer* fb, Triangle& tr, uint32_t color);