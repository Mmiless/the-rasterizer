#include <SDL2/SDL.h>
#include <iostream>
#include "vector.hpp"
#include "framebuffer.h"
#include "draw.h"

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL init failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "Rasterizer",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        600,
        SDL_WINDOW_SHOWN
    );

    if (!window) {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Texture* texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_STREAMING,
        800,
        600
    );

    Framebuffer framebuffer(800, 600);
    framebuffer.clear();

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Draw triangle
        Vec3i v0(-1, 1, -5);
        Vec3i v1(-1, -1, -5);
        Vec3i v2(1, 0, -5);
        Triangle t(v0, v1, v2);

        drawTriangleWF(&framebuffer, t, WHITE);

        SDL_UpdateTexture(texture, NULL, framebuffer.getPixelsRaw(), 800 * sizeof(uint32_t));
        SDL_RenderCopy(renderer, texture, NULL, NULL);

        SDL_RenderPresent(renderer);

        SDL_Delay(16);
    }


    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
