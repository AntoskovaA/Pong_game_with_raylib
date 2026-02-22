#include <raylib.h>
#include "Ball.h"
#include "Paddle.h"
#include "Manager.h"

Manager::Manager(Ball *b, Paddle *p, CPUPaddle *c)
    : ball(b), player(p), cpu(c)
{
    // ball = b;
    // player = p;
    // cpu = c;
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

void Manager::HandleGameState(int screen_wid)
{
    if (vsBotBtn->isPressed(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))
    {
        currentState = GAME_PLAYER_VS_CPU;
    }
    if (currentState == MENU)
    {
        DrawMenu(menuBackground, *vsBotBtn, *twoPlayersBtn);
    }
    else if (currentState == GAME_PLAYER_VS_CPU)
    {
        UpdateState();

        CheckColision();

        DrawGame(screen_wid);
    }
}

void Manager::UpdateState()
{
    ball->Update();
    player->Update(KEY_UP, KEY_DOWN);
    cpu->Update(ball->y);
}

void Manager::DrawBackground()
{
    ClearBackground(ColorBrightness(PINK, 0.6));
    DrawRectangle(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), ColorBrightness(PINK, 0.5));
    DrawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, 130, ColorBrightness(WHITE, 1));

    DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), WHITE);
}

void Manager::DrawStartpage()
{
    ClearBackground(ColorBrightness(PINK, 0.6));
}

void Manager::DrawGame(int screen_w)
{
    DrawBackground();
    ball->Draw();
    cpu->Draw();
    player->Draw();
    DrawText(TextFormat("%i", ball->cpu_score), screen_w / 4 - 20, 20, 80, WHITE);
    DrawText(TextFormat("%i", ball->player_score), 3 * screen_w / 4 - 20, 20, 80, WHITE);
}

void Manager::DrawMenu(Texture2D background, Button bot, Button tplayers)
{
    ClearBackground(BLACK);
    DrawTexture(background, 0, 0, WHITE);
    bot.Draw();
    tplayers.Draw();
    DrawText("VS Bot", 120, 380, 50, BLACK);
    DrawText("2 players", 100, 540, 50, BLACK);
}
