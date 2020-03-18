#pragma once
#include "SDL.h"

enum Keys { Key_up = 0, Key_down , Key_nothing};

class UserInput
{

private:
public:
	UserInput();
	int get_input();
};

