#include "renderer.hpp"
#include "game_logic.hpp"
#include <SDL2/SDL.h>

int main() {
    Renderer renderer;
    GameLogic game;

    bool running = true;
    SDL_Event event;

    while (running) {
        // ✅ Handle events (close window, process input)
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_w:   // Player 1 Up
                        game.movePlayer(1, -1);
                        break;
                    case SDLK_s:   // Player 1 Down
                        game.movePlayer(1, 1);
                        break;
                    case SDLK_UP:  // Player 2 Up
                        game.movePlayer(2, -1);
                        break;
                    case SDLK_DOWN: // Player 2 Down
                        game.movePlayer(2, 1);
                        break;
                }
            }
        }

        game.update();  // Update game logic
        renderer.render(game.getPlayer1(), game.getPlayer2(), game.getBall());  // Render frame
        
        SDL_Delay(16);  // ~60 FPS
    }

    return 0;
}

