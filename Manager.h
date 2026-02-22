#pragma once

#include <raylib.h>
#include "Ball.h"
#include "Paddle.h"
#include "Button.h"

class Manager
{
public:
    Ball *ball;
    Paddle *player;
    Paddle *other;
    enum GameScreen
    {
        MENU,
        GAME_PLAYER_VS_CPU,
        GAME_PLAYER_VS_PLAYER
    };
    GameScreen currentState;
    Button *vsBotBtn;
    Button *twoPlayersBtn;
    Texture2D menuBackground;

    Manager(Ball *b, Paddle *p, Paddle *c);
    ~Manager();

    void CheckColision();

    void UpdateState();
    void DrawBackground();
    void DrawGame(int screen_w);
    void DrawMenu();
    void Update();
    void Draw();
    void SetupEntities();
};
