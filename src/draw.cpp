#include "draw.h"
#include "projection.h"

void plotLineLow(Framebuffer* fb, int x0, int y0, int x1, int y1, uint32_t color) 
{

}

void plotLineHigh(Framebuffer* fb, int x0, int y0, int x1, int y1, uint32_t color)
{

}

// integer precision for now
void drawLine(Framebuffer* fb, Vec3f &p0, Vec3f &p1, uint32_t color)
{
    // Bresenham's
    int x0 = p0.x;
    int x1 = p1.x;
    int y0 = p0.y;
    int y1 = p1.y;

    if (abs(y1 - y0) < abs(x1 - x0)){
        if(x0 > x1)
            plotLineLow(fb, x1, y1, x0, y0, color);
        else   
            plotLineLow(fb, x0, y0, x1, y1, color);
    }
    else{
        if(y0 > y1)
            plotLineHigh(fb, x1, y1, x0, y0, color);
        else 
            plotLineHigh(fb, x0, y0, x1, y1, color);
    }   

    
}

void drawTriangleWF(Framebuffer* fb, Triangle &tr, uint32_t color)
{
    Vec3f p0 = projectCamera(tr.v0, fb->getWidth(), fb->getHeight());
    Vec3f p1 = projectCamera(tr.v1, fb->getWidth(), fb->getHeight());
    Vec3f p2 = projectCamera(tr.v2, fb->getWidth(), fb->getHeight());

    drawLine(fb, p0, p1, WHITE);
    drawLine(fb, p1, p2, WHITE);
    drawLine(fb, p2, p0, WHITE);
}
