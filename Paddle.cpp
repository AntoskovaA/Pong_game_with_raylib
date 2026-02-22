#include <raylib.h>
#include "Paddle.h"

Paddle::Paddle() {
    width = 25;
    height = 120;
    speed = 6;
    color = {227, 11, 92, 255};
}

void Paddle::LimitMovement()
{
    if (y <= 0)
    {
        y = 0;
    }
    if (y + height >= GetScreenHeight())
    {
        y = GetScreenHeight() - height;
    }
}

void Paddle::Draw()
{
    DrawRectangleRounded(Rectangle{x, y, width, height}, 1, 3, color);
}

void Paddle::Update(KeyboardKey up, KeyboardKey down)
{
    if (IsKeyDown(up))
    {
        y = y - speed;
    }
    if (IsKeyDown(down))
    {
        y = y + speed;
    }

    LimitMovement();
}

void Paddle::Update(int ball_y)
{
    if (y + height / 2 > ball_y)
    {
        y = y - speed;
    }
    if (y + height / 2 < ball_y)
    {
        y = y + speed;
    }
    LimitMovement();
}