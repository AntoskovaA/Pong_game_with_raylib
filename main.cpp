#include <iostream>
#include <raylib.h>
#include "Ball.h"
#include "Paddle.h"
#include "Manager.h"

int main () {
    const int screen_width = 1280;
    const int screen_height = 800;

    InitWindow(screen_width, screen_height, "My Pong Game!");
    SetTargetFPS(60);

    int centerX = screen_width / 2;
    int centerY = screen_height / 2;
    Color Rose = Color{243, 58, 106, 255};
    Color Raspberry = Color{227, 11, 92, 255};

    Ball* ball = new Ball(centerX, centerY, 7, 7, 18, Rose);
    Paddle player;
    CPUPaddle cpu;

    Manager gameManager(ball, &player, &cpu);

    player.color = Raspberry;
    player.width = 25;
    player.height = 120;
    player.x = screen_width - player.width - 10;
    player.y = centerY - player.height / 2;
    player.speed = 6;

    cpu.color = Raspberry;
    cpu.width = 25;
    cpu.height = 120;
    cpu.x = 10;
    cpu.y = centerY - cpu.height / 2;
    cpu.speed = 6;

    while (WindowShouldClose() == false)
    {
        gameManager.Update();

        BeginDrawing();
            gameManager.Draw();
        EndDrawing();
    }

    CloseWindow();
    delete ball;

    return 0;
}