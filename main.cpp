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

    Ball ball(centerX, centerY, 7, 7, 18, Rose);
    Paddle player;
    Paddle other;

    Manager gameManager(&ball, &player, &other);

    while (WindowShouldClose() == false)
    {
        gameManager.Update();

        BeginDrawing();
            gameManager.Draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}