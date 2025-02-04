// player.cpp
#include "player.hpp"

Player::Player(int num, float startX, float startY) : number(num), x(startX), y(startY), score(0) {}

void Player::moveUp() {
    y -= 5;  // Adjust movement speed
}

void Player::moveDown() {
    y += 5;
}
