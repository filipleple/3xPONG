#include "renderer.hpp"
#include "game_logic.hpp"
#include <SDL2/SDL.h>

int main() {
    Renderer renderer;
    GameLogic game;

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    // Player 1 
                    case SDLK_w:   
                        game.movePlayer(1, -1);
                        break;
                    case SDLK_s:  
                        game.movePlayer(1, 1);
                        break;

                    // Player 2 
                    case SDLK_UP:
                        game.movePlayer(2, -1);
                        break;
                    case SDLK_DOWN:
                        game.movePlayer(2, 1);
                        break;
                }
            }
        }

        game.update(); 
        renderer.render(game.getPlayer1(), game.getPlayer2(), game.getBall());
        
        SDL_Delay(16);  // ~60 FPS
    }

    return 0;
}

