#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include "game_logic.hpp"

GameLogic::GameLogic() {
    int fd = shm_open("/pong_shm", O_CREAT | O_RDWR, 0666);
    ftruncate(fd, sizeof(GameState));
    state = (GameState*) mmap(NULL, sizeof(GameState), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
}

void GameLogic::update() {
    state->ball_x += 3;
    state->ball_y += 3;
}
