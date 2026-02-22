#include <iostream>
#include <raylib.h>
#include "Ball.h"
#include "Paddle.h"
#include "Manager.h"
#include "Button.h"

int main () {

    const int screen_width = 1280;
    const int screen_height = 800;

    int x = screen_width / 2;
    int y = screen_height / 2;

    Color Raspberry = Color{227, 11, 92, 255};
    Color Rose = Color{243, 58, 106, 255};

    Ball* ball = new Ball(x, y, 7, 7, 18, Rose);
    //Ball* new_ball(x, y, 7, 7, 18, Rose);
    Paddle player;
    CPUPaddle cpu;
    Manager GameManager(ball, &player, &cpu);
    GameManager.ball = ball;

    //InitWindow(width, height, title)
    InitWindow(screen_width, screen_height, "My pong game!");
    SetTargetFPS(60);

    Texture2D background = LoadTexture("Graphics/background.png");
    Button VsBot("Graphics/button.png", {30, 340}, 0.25);
    Button two_players("Graphics/button.png", {30, 500}, 0.25);
    
    player.color = Raspberry;
    player.width = 25;
    player.height = 120;
    player.x = screen_width - player.width - 10;
    player.y = screen_height / 2 - player.height / 2;
    player.speed = 6;

    cpu.color = Raspberry;
    cpu.height = 120;
    cpu.width = 25;
    cpu.x = 10;
    cpu.y = screen_height / 2 - cpu.height / 2;
    cpu.speed = 6;

    while(WindowShouldClose() == false)
    {
        
        //640, 400
        BeginDrawing();
        GameManager.HandleGameState(screen_width);

        EndDrawing();
    }
    CloseWindow();
    delete ball;

    return 0;
}