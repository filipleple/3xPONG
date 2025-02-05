// renderer.hpp
#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "player.hpp"
#include "ball.hpp"

class Renderer {
private:
    SDL_Window *leftWindow, *middleWindow, *rightWindow;
    SDL_Renderer *leftRenderer, *middleRenderer, *rightRenderer;
    TTF_Font *font;

public:
    Renderer();
    ~Renderer();
    void render(const Player &p1, const Player &p2, const Ball &ball);
    void renderScore(SDL_Renderer *renderer, int x, int y, int score);
};

#endif
