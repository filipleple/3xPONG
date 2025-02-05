// game_logic.hpp
//
// 
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
    void movePlayer(int playerNum, int direction);
    void resetBall();

    const Player& getPlayer1() const { return p1; }
    const Player& getPlayer2() const { return p2; }
    const Ball& getBall() const { return ball; }
};

struct GameState {
    float ball_x, ball_y;
    float paddle1_y, paddle2_y;
    float sound_pos, sound_speed;
    int score_p1, score_p2;
};

extern GameState *state;

#endif
 
