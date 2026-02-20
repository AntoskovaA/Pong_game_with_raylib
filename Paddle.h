#pragma once

#include <raylib.h>

class Paddle {

    protected:
    void LimitMovement();
    public:
    float x, y;
    float width, height;
    int speed;
    Color color;

    void Draw();

    void Update(KeyboardKey up, KeyboardKey down);
};

class CPUPaddle: public Paddle
{
    public:
    void Update(int ball_y);

};