// ball.cpp
#include "include/config.hpp"
#include "ball.hpp"

Ball::Ball(float startX, float startY, float velX, float velY) : x(startX), y(startY), vx(velX), vy(velY) {}

void Ball::update() {
    x += vx;
    y += vy;

    // Bounce
    if (y <= 0 || y + BALL_SIZE >= WORLD_HEIGHT) {
        vy = -vy; // Reverse vertical direction
    }
}

void Ball::reset() {
    x = BALL_INIT_X;
    y = BALL_INIT_Y;
    vx = -vx;  // Reverse direction when a player scores
}
