#include <iostream>
#include "Screen.h"
#include "Entity.h"
#include "Paddle.h"
#include "Ball.h"
#include "UserInput.h"

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

	UserInput user;
	
	while (true) {
		previous_time = elapsed_time;
		elapsed_time = SDL_GetTicks();
		int action = screen.process_events();
		int delta_time = elapsed_time - previous_time;

		int player1_action = user.get_input();
		switch (player1_action) {
		case Key_up:
			paddle2->move(-1, delta_time);
			break;
		case Key_down:
			paddle2->move(1, delta_time);
			break;
		}

		if (action == Event_quit)
			break;
		switch (action) {
		case Event_up_p1:
			paddle->move(-1, delta_time);
			break;
		case Event_down_p1:
			paddle->move(1, delta_time);
			break;
		default:
			break;
		}
		

		ball->move(delta_time, paddle, paddle2);
		screen.set_color(0,0,0);
		screen.draw_background();

		screen.set_color(255, 255, 255);
		screen.draw_rectangle(int(ball->get_start().x), int(ball->get_start().y), int(ball->get_end().x), int(ball->get_end().y));
		screen.draw_rectangle(paddle->get_start().x, paddle->get_start().y, paddle->get_end().x, paddle->get_end().y);
		screen.draw_rectangle(paddle2->get_start().x, paddle2->get_start().y, paddle2->get_end().x, paddle2->get_end().y);

		screen.update_screen();

		if (paddle->collision(ball)) std::cout << "Collision 1" << std::endl;
		if (paddle2->collision(ball)) std::cout << "Collision 2" << std::endl;



	}

	screen.close();

	return 0;
}