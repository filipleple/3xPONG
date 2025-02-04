// game_logic.hpp
#ifndef GAME_LOGIC_HPP
#define GAME_LOGIC_HPP

#include "player.hpp"
#include "ball.hpp"

class GameLogic {
private:
    Player p1, p2;
    Ball ball;

public:
    GameLogic();
    void update();
};

struct GameState {
    float ball_x, ball_y;
    float paddle1_y, paddle2_y;
};

GameState *state;

#endif
 
