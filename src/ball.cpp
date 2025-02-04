// ball.cpp
#include "ball.hpp"

Ball::Ball(float startX, float startY, float velX, float velY) : x(startX), y(startY), vx(velX), vy(velY) {}

void Ball::update() {
    x += vx;
    y += vy;
}
