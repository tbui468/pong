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

	Paddle paddle(50, 50, 25, 100);
	Ball ball(500, 200, 25, 25);

	Coordinate c1 = { 2.0, 2.0 };
	Coordinate c2 = { 1.0 , 2.0 };
	Coordinate c3 = { 2.1, 2.9 };

	std::cout << (c1 == c2) << std::endl;
	std::cout << (c3 == c1) << std::endl;

	screen.draw_rectangle(paddle.get_start().x, paddle.get_start().y, paddle.get_end().x, paddle.get_end().y);
	screen.draw_rectangle(ball.get_start().x, ball.get_start().y, ball.get_end().x, ball.get_end().y);
	screen.update_screen();

	while (screen.process_events()) {

	}

	screen.close();

	return 0;
}