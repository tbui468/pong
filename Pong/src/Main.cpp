#include <iostream>
#include "Screen.h"
#include "Entity.h"
#include "Paddle.h"
#include "Ball.h"
#include "Input.h"


int main(int argc, char* args[]) {

	std::cout << "Let's play Pong!" << std::endl;

	Screen screen;

	screen.init();

	screen.set_color(150, 255, 255);
	screen.draw_background();

	screen.set_color(0, 0, 0);

	screen.draw_rectangle(100, 100, 500, 200);
	screen.update_screen();

	while (screen.process_events()) {

	}

	screen.close();

	return 0;
}