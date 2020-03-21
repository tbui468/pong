#pragma once
#include "Screen.h"
#include "Entity.h"
#include "Paddle.h"
#include "Ball.h"
#include <cstdlib>
#include <ctime>

class Round
{
private:
	Screen screen;
	int score_1, score_2;
public:
	Round(Screen screen, int score_1, int score_2);
	void init();
	int start();
};

