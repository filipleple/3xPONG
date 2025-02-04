#include "renderer.hpp"
#include "game_logic.hpp"

int main() {
    Renderer renderer;
    GameLogic game;

    bool running = true;
    while (running) {
        game.update();
        renderer.render(game.p1, game.p2, game.ball);
        SDL_Delay(16);
    }

    return 0;
}
