#include <raylib.h>
#include "Ball.h"
#include "Paddle.h"
#include "Manager.h"

Manager::Manager(Ball* b, Paddle* p, CPUPaddle* c)
: ball(b), player(p), cpu(c)
{
    //ball = b;
    //player = p;
    //cpu = c;
}

void Manager::CheckColision()
{
    if (CheckCollisionCircleRec(Vector2{ball->x, ball->y}, ball->radius, Rectangle{player->x, player->y, player->width, player->height}))
    {
        ball->speed_x *= -1;
        ball->x = player->x - ball->radius;
    }

    if (CheckCollisionCircleRec(Vector2{ball->x, ball->y}, ball->radius, Rectangle{cpu->x, cpu->y, cpu->width, cpu->height}))
    {
        ball->speed_x *= -1;
        ball->x = cpu->x + cpu->width + ball->radius;
    }
}

void Manager::UpdateState()
{
    ball->Update();
    player->Update();
    cpu->Update(ball->y);
}

void Manager::DrawBackground()
{
    ClearBackground(ColorBrightness(PINK, 0.6));
    DrawRectangle(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), ColorBrightness(PINK, 0.5));
    DrawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, 130, ColorBrightness(WHITE, 1));

    DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), WHITE);
}