#pragma once

#include <raylib.h>
#include "Ball.h"
#include "Paddle.h"

class Manager
{
    public:
    Ball* ball;
    Paddle* player;
    CPUPaddle* cpu;

    Manager(Ball* b, Paddle* p, CPUPaddle* c);

    void CheckColision();

    void UpdateState();
    void DrawBackground();
};
