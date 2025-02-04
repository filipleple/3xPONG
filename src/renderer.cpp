// renderer.cpp
#include "renderer.hpp"

Renderer::Renderer() {
    SDL_Init(SDL_INIT_VIDEO);
    leftWindow = SDL_CreateWindow("Player 1", 100, 100, 300, 600, SDL_WINDOW_SHOWN);
    middleWindow = SDL_CreateWindow("Center", 400, 100, 300, 600, SDL_WINDOW_SHOWN);
    rightWindow = SDL_CreateWindow("Player 2", 700, 100, 300, 600, SDL_WINDOW_SHOWN);

    leftRenderer = SDL_CreateRenderer(leftWindow, -1, SDL_RENDERER_ACCELERATED);
    middleRenderer = SDL_CreateRenderer(middleWindow, -1, SDL_RENDERER_ACCELERATED);
    rightRenderer = SDL_CreateRenderer(rightWindow, -1, SDL_RENDERER_ACCELERATED);
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(leftRenderer);
    SDL_DestroyRenderer(middleRenderer);
    SDL_DestroyRenderer(rightRenderer);
    SDL_DestroyWindow(leftWindow);
    SDL_DestroyWindow(middleWindow);
    SDL_DestroyWindow(rightWindow);
    SDL_Quit();
}

void Renderer::render(Player &p1, Player &p2, Ball &ball) {
    SDL_SetRenderDrawColor(leftRenderer, 0, 0, 0, 255);
    SDL_RenderClear(leftRenderer);
    
    SDL_SetRenderDrawColor(middleRenderer, 0, 0, 0, 255);
    SDL_RenderClear(middleRenderer);
    
    SDL_SetRenderDrawColor(rightRenderer, 0, 0, 0, 255);
    SDL_RenderClear(rightRenderer);

    // Map world coordinates to the correct window coordinates

    SDL_RenderPresent(leftRenderer);
    SDL_RenderPresent(middleRenderer);
    SDL_RenderPresent(rightRenderer);
}
