#include <iostream>
#include <raylib.h>
#include "Ball.h"
#include "Paddle.h"
#include "Manager.h"

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

        GameManager.UpdateState();

        GameManager.CheckColision();

        GameManager.DrawBackground();

        ball->Draw();
        cpu.Draw();
        player.Draw();
        DrawText(TextFormat("%i", ball->cpu_score), screen_width/4 - 20 ,20 ,80,WHITE);
        DrawText(TextFormat("%i", ball->player_score), 3 *screen_width/4 - 20 ,20 ,80,WHITE);

        EndDrawing();
    }
    CloseWindow();

    return 0;
}