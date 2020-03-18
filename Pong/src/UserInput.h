#pragma once
#include "SDL.h"

enum Keys { Key_up = 0, Key_down };

class UserInput
{

private:
	SDL_Event event;
public:
	UserInput();
	int get_input();
};

