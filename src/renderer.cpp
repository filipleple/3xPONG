// renderer.cpp
#include "renderer.hpp"
#include "config.hpp"

Renderer::Renderer() {
    SDL_Init(SDL_INIT_VIDEO);
    leftWindow = SDL_CreateWindow("Player 1", 100, 100, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    middleWindow = SDL_CreateWindow("Center", 400, 100, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    rightWindow = SDL_CreateWindow("Player 2", 700, 100, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

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

void Renderer::render(const Player &p1, const Player &p2, const Ball &ball) {
    // Set background color (black)
    SDL_SetRenderDrawColor(leftRenderer, 0, 0, 0, 255);
    SDL_RenderClear(leftRenderer);
    SDL_SetRenderDrawColor(middleRenderer, 0, 0, 0, 255);
    SDL_RenderClear(middleRenderer);
    SDL_SetRenderDrawColor(rightRenderer, 0, 0, 0, 255);
    SDL_RenderClear(rightRenderer);

    // Set paddle color (white)
    SDL_SetRenderDrawColor(leftRenderer, 255, 255, 255, 255);
    SDL_SetRenderDrawColor(rightRenderer, 255, 255, 255, 255);

    // Render Player 1 Paddle in Left Window
    SDL_Rect paddle1 = { 50, static_cast<int>(p1.y), PADDLE_WIDTH, PADDLE_HEIGHT};
    SDL_RenderFillRect(leftRenderer, &paddle1);

    // Render Player 2 Paddle in Right Window
    SDL_Rect paddle2 = { 50, static_cast<int>(p2.y), PADDLE_WIDTH, PADDLE_HEIGHT};
    SDL_RenderFillRect(rightRenderer, &paddle2);

    // Render Ball in Middle Window
    SDL_SetRenderDrawColor(middleRenderer, 255, 255, 255, 255);
    SDL_Rect ballRect = { static_cast<int>(ball.x), static_cast<int>(ball.y), BALL_SIZE, BALL_SIZE };
    SDL_RenderFillRect(middleRenderer, &ballRect);

    // Present the renders
    SDL_RenderPresent(leftRenderer);
    SDL_RenderPresent(middleRenderer);
    SDL_RenderPresent(rightRenderer);
}
