#pragma once

#include <raylib.h>

class Paddle {

    private:
    void LimitMovement();
    public:
    float x, y;
    float width, height;
    int speed;
    Color color;

    void Draw();

    void Update(KeyboardKey up, KeyboardKey down);
    void Update(int ball_y);
    public:
    Paddle();
};
