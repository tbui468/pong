#pragma once
#include <thread>
#include <chrono>
#include "SDL.h"
#include "Screen.h"
#include "Round.h"

class Game
{
private:
	Screen* m_screen;
	Round* m_round;
	int m_player1_score, m_player2_score;
	bool m_play;
public:
	Game();
	void init();
	void loop();
	void end();
};

