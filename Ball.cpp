#include <raylib.h>
#include "Ball.h"


int Ball::cpu_score = 0;
int Ball::player_score = 0;

Ball::Ball(float _x, float _y, int _speed_x, int _speed_y, int r, Color c)
{
    x = _x;
    y = _y;
    speed_x = _speed_x;
    speed_y = _speed_y;
    radius = r;
    color = c;
}

void Ball::Draw()
{
    DrawCircle(x, y, radius, color);
}

void Ball::Update()
{
    x += speed_x;
    y += speed_y;

    if (y + radius >= GetScreenHeight() || y - radius <= 0)
    {
        speed_y *= -1;
    }
    if (x + radius >= GetScreenWidth())
    {
        cpu_score++;
        ResetBall();
    }

    if (x - radius <= 0)
    {
        player_score++;
        ResetBall();
    }
}

void Ball::ResetBall()
{
    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;
    int speed_choices[2] = {-1, 1};
    speed_x *= speed_choices[GetRandomValue(0, 1)];
    speed_y *= speed_choices[GetRandomValue(0, 1)];
}
