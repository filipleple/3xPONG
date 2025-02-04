// ball.hpp
#ifndef BALL_HPP
#define BALL_HPP

class Ball {
public:
    float x, y;    // Position
    float vx, vy;  // Velocity

    Ball(float startX, float startY, float velX, float velY);
    void update();
};

#endif
