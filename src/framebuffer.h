#include <cstdint> 
#include <vector>

uint32_t BLACK = 0x000000FF;
uint32_t WHITE = 0xFFFFFFFF;

uint32_t ToRGB888(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255){
    return (r << 24) | (g << 16) | (b << 8) | a;
}

class Framebuffer {
public:
    Framebuffer(int w_, int h_) :  w(w_), h(h_), pixels(h_ * w_) {}

    ~Framebuffer() {}

    u_int32_t* getPixelsRaw() { return pixels.data(); }
    std::vector<uint32_t>* getPixelsRawVector() { return &pixels; }
    int getHeight() const { return h; }
    int getWidth() const { return w; }

    void setPixel(int x, int y, uint32_t color) {
        if (x < 0 || x >= w || y < 0 || y >= h) return;
        pixels[y * w + x] = color;
    }

    void setPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
        if (x < 0 || x >= w || y < 0 || y >= h) return;
        pixels[y * w + x] = ToRGB888(r, g, b, a);
    }

    void clear() {
        for(int i = 0; i < h * w; i++){
            pixels[i] = BLACK;
        }
    }

private:
    std::vector<uint32_t> pixels;
    int h = 0;
    int w = 0;
};