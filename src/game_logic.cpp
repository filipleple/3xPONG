#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include "game_logic.hpp"
#include "include/config.hpp"

GameState *state = nullptr; 

GameLogic::GameLogic():
    p1(1, PADDLE_MARGIN, PADDLE_INIT_Y),   // Player 1 (Left)
    p2(2, WORLD_WIDTH - PADDLE_MARGIN, PADDLE_INIT_Y),  // Player 2 (Right)
    ball(BALL_INIT_X, BALL_INIT_Y, BALL_SPEED_X, BALL_SPEED_Y) {  // Ball (startX, startY, velX, velY)

    int fd = shm_open("/pong_shm", O_CREAT | O_RDWR, 0666);
    ftruncate(fd, sizeof(GameState));
    state = (GameState*) mmap(NULL, sizeof(GameState), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    // Initialize shared memory to 0
    if (state) {
        state->ball_x = BALL_INIT_X;
        state->ball_y = BALL_INIT_Y;
        state->paddle1_y = PADDLE_INIT_Y;
        state->paddle2_y = PADDLE_INIT_Y;
    }
}

void GameLogic::update() {
    state->ball_x += BALL_SPEED_X;
    state->ball_y += BALL_SPEED_Y;
}

void GameLogic::movePlayer(int playerNum, int direction) {
    float moveAmount = PADDLE_SPEED * direction; // Move up (-1) or down (+1)

    if (playerNum == 1) {
        p1.y += moveAmount;
    } else if (playerNum == 2) {
        p2.y += moveAmount;
    }
}
