// player.hpp
#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player {
public:
    int number;  // 1 = left, 2 = right
    float x, y;  // Position
    int score;   // Player score

    Player(int num, float startX, float startY);
    void moveUp();
    void moveDown();
};

#endif
