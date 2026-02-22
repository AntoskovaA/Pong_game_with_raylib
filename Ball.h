#pragma once

#include <raylib.h>
class Paddle;

class Ball
{
    private:
    Color color;

    public:
    float x, y;
    int speed_x, speed_y;
    int radius;
    static int other_score;
    static int player_score;

    void Draw();
    void Update();
    void ResetBall();
    Ball(float _x, float _y, int _speed_x, int _speed_y, int r, Color c);
};