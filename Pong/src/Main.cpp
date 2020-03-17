#include <iostream>
#include "Screen.h"
#include "Entity.h"
#include "Paddle.h"
#include "Ball.h"

/*
FEATURES TO ADD
****************
-wall stops ball and paddle, not have padde bounce if adjacent to wall
-Have ball react with paddle
-Choose to have AI control second paddle
-BUG: ball gets stuck in wall, fix bounce algorithm
-extra feature: smooth out the motion
*/



int main(int argc, char* args[]) {

	std::cout << "Let's play Pong!" << std::endl;

	

	Screen screen;

	screen.init();


	Paddle* paddle = new Paddle(750, 250);
	Ball* ball = new Ball(74, 200);
	Paddle* paddle2 = new Paddle(25, 300);



	unsigned int elapsed_time = SDL_GetTicks();
	unsigned int previous_time;
	
	while (true) {
		previous_time = elapsed_time;
		elapsed_time = SDL_GetTicks();
		int action = screen.process_events();
		int delta_time = elapsed_time - previous_time;
		if (action == Event_quit)
			break;
		switch (action) {
		case Event_up:
			paddle->move(-1, delta_time);
			break;
		case Event_down:
			paddle->move(1, delta_time);
			break;
		default:
			break;
		}

		
		std::cout << elapsed_time << std::endl;
		ball->move(delta_time);
		screen.set_color(0,0,0);
		screen.draw_background();

		screen.set_color(255, 255, 255);
		screen.draw_rectangle(int(ball->get_start().x), int(ball->get_start().y), int(ball->get_end().x), int(ball->get_end().y));
		screen.draw_rectangle(paddle->get_start().x, paddle->get_start().y, paddle->get_end().x, paddle->get_end().y);
		screen.draw_rectangle(paddle2->get_start().x, paddle2->get_start().y, paddle2->get_end().x, paddle2->get_end().y);

		screen.update_screen();

		if (paddle->collision(ball)) std::cout << "Collision!!!" << std::endl;



	}

	screen.close();

	return 0;
}