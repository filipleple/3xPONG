#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include "game_logic.hpp"

GameState *state = nullptr; 

GameLogic::GameLogic():
    p1(1, 50.0f, 250.0f),   // Player 1 (Left)
    p2(2, 550.0f, 250.0f),  // Player 2 (Right)
    ball(300.0f, 300.0f, 3.0f, 3.0f) {  // Ball (startX, startY, velX, velY)

    int fd = shm_open("/pong_shm", O_CREAT | O_RDWR, 0666);
    ftruncate(fd, sizeof(GameState));
    state = (GameState*) mmap(NULL, sizeof(GameState), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    // Initialize shared memory to 0
    if (state) {
        state->ball_x = 300.0f;
        state->ball_y = 300.0f;
        state->paddle1_y = 250.0f;
        state->paddle2_y = 250.0f;
    }
}

void GameLogic::update() {
    state->ball_x += 3;
    state->ball_y += 3;
}

void GameLogic::movePlayer(int playerNum, int direction) {
    float moveAmount = 10.0f * direction; // Move up (-1) or down (+1)

    if (playerNum == 1) {
        p1.y += moveAmount;
    } else if (playerNum == 2) {
        p2.y += moveAmount;
    }
}
