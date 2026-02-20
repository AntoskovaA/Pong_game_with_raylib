#include <raylib.h>
#include "Paddle.h"

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
    // DrawRectangle(x, y, width, height, WHITE);
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

void CPUPaddle::Update(int ball_y)
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