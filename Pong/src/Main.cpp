#include <iostream>
#include "Screen.h"
#include "Entity.h"
#include "Paddle.h"
#include "Ball.h"
#include "Input.h"

/*
FEATURES TO ADD
****************
Delta time so that it runs at same speed regardless of system
Have ball react with paddle
get user input and move paddles
Choose to have AI control second paddle
*/

int main(int argc, char* args[]) {

	std::cout << "Let's play Pong!" << std::endl;

	Screen screen;

	screen.init();

	screen.set_color(150, 255, 255);
	screen.draw_background();

	screen.set_color(0, 0, 0);

	Paddle* paddle = new Paddle(400, 250);
	Ball* ball = new Ball(74, 200);

	std::cout << "Collision??: " << paddle->collision(ball) << std::endl;



	screen.draw_rectangle(paddle->get_start().x, paddle->get_start().y, paddle->get_end().x, paddle->get_end().y);
	screen.draw_rectangle(ball->get_start().x, ball->get_start().y, ball->get_end().x, ball->get_end().y);
	screen.update_screen();

	while (screen.process_events()) {
		ball->movement_loop();
		screen.set_color(0, 0, 0);
		screen.draw_background();
		screen.set_color(255, 255, 255);
		screen.draw_rectangle(ball->get_start().x, ball->get_start().y, ball->get_end().x, ball->get_end().y);
		screen.draw_rectangle(paddle->get_start().x, paddle->get_start().y, paddle->get_end().x, paddle->get_end().y);
		screen.update_screen();
		if (paddle->collision(ball)) std::cout << "Collision!!!" << std::endl;
	}

	screen.close();

	return 0;
}