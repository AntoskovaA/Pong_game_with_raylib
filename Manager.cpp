#include <raylib.h>
#include "Ball.h"
#include "Paddle.h"
#include "Manager.h"

Manager::Manager(Ball *b, Paddle *p, Paddle *c)
    : ball(b), player(p), other(c)
{
    menuBackground = LoadTexture("Graphics/background.png");

    vsBotBtn = new Button("Graphics/button.png", {30, 340}, 0.25);
    twoPlayersBtn = new Button("Graphics/button.png", {30, 500}, 0.25);

    currentState = MENU;
}

Manager::~Manager()
{
    UnloadTexture(menuBackground);
    delete vsBotBtn;
    delete twoPlayersBtn;
}

void Manager::CheckColision()
{
    if (CheckCollisionCircleRec(Vector2{ball->x, ball->y}, ball->radius, Rectangle{player->x, player->y, player->width, player->height}))
    {
        ball->speed_x *= -1;
        ball->x = player->x - ball->radius;
    }

    if (CheckCollisionCircleRec(Vector2{ball->x, ball->y}, ball->radius, Rectangle{other->x, other->y, other->width, other->height}))
    {
        ball->speed_x *= -1;
        ball->x = other->x + other->width + ball->radius;
    }
}

void Manager::Update()
{
    if (currentState == MENU)
    {
        if (vsBotBtn->isPressed(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))
        {
            currentState = GAME_PLAYER_VS_CPU;
        }
        if (twoPlayersBtn->isPressed(GetMousePosition(), IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))
        {
            currentState = GAME_PLAYER_VS_PLAYER;
        }
    }
    else
    {
        ball->Update();
        player->Update(KEY_UP, KEY_DOWN);

        if (currentState == GAME_PLAYER_VS_PLAYER) {
            other->Update(KEY_W, KEY_S); 
        } 
        else if (currentState == GAME_PLAYER_VS_CPU) {
            other->Update(ball->y);
        }

        CheckColision();
    }
}

void Manager::UpdateState()
{
    ball->Update();
    player->Update(KEY_UP, KEY_DOWN);
    other->Update(ball->y);
}

void Manager::DrawBackground()
{
    ClearBackground(ColorBrightness(PINK, 0.6));
    DrawRectangle(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), ColorBrightness(PINK, 0.5));
    DrawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, 130, ColorBrightness(WHITE, 1));

    DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), WHITE);
}

void Manager::DrawGame(int screen_w)
{
    DrawBackground();
    ball->Draw();
    other->Draw();
    player->Draw();
    DrawText(TextFormat("%i", ball->other_score), screen_w / 4 - 20, 20, 80, WHITE);
    DrawText(TextFormat("%i", ball->player_score), 3 * screen_w / 4 - 20, 20, 80, WHITE);
}

void Manager::DrawMenu()
{
    ClearBackground(BLACK);
    DrawTexture(menuBackground, 0, 0, WHITE);
    vsBotBtn->Draw();
    twoPlayersBtn->Draw();
    DrawText("VS Bot", 120, 380, 50, BLACK);
    DrawText("2 players", 100, 540, 50, BLACK);
}
void Manager::Draw()
{
    if (currentState == MENU)
    {
        DrawMenu();
    }
    else
    {
        DrawGame(GetScreenWidth());
    }
}
