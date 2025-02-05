// renderer.cpp
#include "renderer.hpp"
#include "game_logic.hpp"
#include "config.hpp"
#include <string>

Renderer::Renderer() {
    SDL_Init(SDL_INIT_VIDEO);

    TTF_Init();

    font = TTF_OpenFont("3rd-party/medodica.ttf", 48);  // Load retro font (use any pixel font)
    if (!font) {
        // std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
    }
    
    leftWindow = SDL_CreateWindow("Player 1", 100, 100, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    middleWindow = SDL_CreateWindow("Center", 400, 100, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    rightWindow = SDL_CreateWindow("Player 2", 700, 100, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

    leftRenderer = SDL_CreateRenderer(leftWindow, -1, SDL_RENDERER_ACCELERATED);
    middleRenderer = SDL_CreateRenderer(middleWindow, -1, SDL_RENDERER_ACCELERATED);
    rightRenderer = SDL_CreateRenderer(rightWindow, -1, SDL_RENDERER_ACCELERATED);
}

Renderer::~Renderer() {
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(leftRenderer);
    SDL_DestroyRenderer(middleRenderer);
    SDL_DestroyRenderer(rightRenderer);
    SDL_DestroyWindow(leftWindow);
    SDL_DestroyWindow(middleWindow);
    SDL_DestroyWindow(rightWindow);
    SDL_Quit();
}

void Renderer::render(const Player &p1, const Player &p2, const Ball &ball) {
    // Set background color (black) and clear all renderers
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
    SDL_Rect paddle1 = { PADDLE_MARGIN, state->paddle1_y, PADDLE_WIDTH, PADDLE_HEIGHT };
    SDL_RenderFillRect(leftRenderer, &paddle1);

    // Render Player 2 Paddle in Right Window
    SDL_Rect paddle2 = { WINDOW_WIDTH - PADDLE_MARGIN - PADDLE_WIDTH, state->paddle2_y, PADDLE_WIDTH, PADDLE_HEIGHT };
    SDL_RenderFillRect(rightRenderer, &paddle2);

    // Set ball color (white)
    SDL_SetRenderDrawColor(middleRenderer, 255, 255, 255, 255);
    SDL_SetRenderDrawColor(leftRenderer, 255, 255, 255, 255);
    SDL_SetRenderDrawColor(rightRenderer, 255, 255, 255, 255);

    // Determine which window should render the ball
    int ball_x = static_cast<int>(state->ball_x);
    int ball_y = static_cast<int>(state->ball_y);

    SDL_Rect ballRect = { ball_x % WINDOW_WIDTH, ball_y, BALL_SIZE, BALL_SIZE };

    if (ball_x < WINDOW_WIDTH) {
        SDL_RenderFillRect(leftRenderer, &ballRect);
    } else if (ball_x < 2 * WINDOW_WIDTH) {
        SDL_RenderFillRect(middleRenderer, &ballRect);
    } else {
        SDL_RenderFillRect(rightRenderer, &ballRect);
    }
    
    renderScore(leftRenderer, 10, 10, state->score_p1);
    renderScore(rightRenderer, 10, 10, state->score_p2);

    // Present the renders
    SDL_RenderPresent(leftRenderer);
    SDL_RenderPresent(middleRenderer);
    SDL_RenderPresent(rightRenderer);
}

void Renderer::renderScore(SDL_Renderer *renderer, int x, int y, int score) {
    SDL_Color white = {255, 255, 255, 255};
    std::string scoreText = "Score: " + std::to_string(score);

    SDL_Surface* surface = TTF_RenderText_Solid(font, scoreText.c_str(), white);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Rect dest = {x, y, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &dest);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

