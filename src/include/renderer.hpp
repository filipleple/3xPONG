// renderer.hpp
#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL2/SDL.h>
#include "player.hpp"
#include "ball.hpp"

class Renderer {
private:
    SDL_Window *leftWindow, *middleWindow, *rightWindow;
    SDL_Renderer *leftRenderer, *middleRenderer, *rightRenderer;

public:
    Renderer();
    ~Renderer();
    void render(Player &p1, Player &p2, Ball &ball);
};

#endif
