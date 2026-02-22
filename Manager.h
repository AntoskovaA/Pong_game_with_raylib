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
    CPUPaddle *cpu;
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

    Manager(Ball *b, Paddle *p, CPUPaddle *c);
    ~Manager();

    void CheckColision();

    void HandleGameState(int screen_wid);
    void UpdateState();
    void DrawBackground();
    void DrawStartpage();
    void DrawGame(int screen_w);
    void DrawMenu();
    void Update();
    void Draw();
};
