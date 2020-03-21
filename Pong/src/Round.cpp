#include "Round.h"


Round::Round(Screen screen, int score_1, int score_2) : screen(screen), score_1(score_1), score_2(score_2) {

}

void Round::init() {

}

int Round::start() {

	double rand1 = (double)rand() / RAND_MAX;
	double rand2 = (double)rand() / RAND_MAX;
	int start = rand2 < .5 ? 75 : 700;

	Paddle* paddle = new Paddle(750, 250);
	Ball* ball = new Ball(start, 25 + rand1 * 550);
	Paddle* paddle2 = new Paddle(25, 250);



	unsigned int elapsed_time = SDL_GetTicks();
	unsigned int previous_time;



	while (true) {
		previous_time = elapsed_time;
		elapsed_time = SDL_GetTicks();
		std::array<int, 3>* actions = screen.process_events();
		int delta_time = elapsed_time - previous_time;

		//quits SDL if player clicks on close window button
		if ((*actions)[0] == 0)
			return Point_quit;

		paddle->move((*actions)[1], delta_time);
		paddle2->move((*actions)[2], delta_time);
		int point = ball->move(delta_time, paddle, paddle2);
		
		switch (point) {
		case Point_player_1:
			return point;
			break;
		case Point_player_2:
			return point;
			break;
		default:
			break;
		}

		//draw background, ball and paddles
		screen.set_color(0, 0, 0);
		screen.draw_background();

		screen.set_color(255, 255, 255);
		//draw center line of width
		int x_center = Screen::SCREEN_WIDTH / 2;
		for (int i = 0; i < 12; ++i) {
			screen.draw_rectangle(x_center - 2, i * 50 + 12, x_center + 2, i * 50 + 37);
		}

		screen.draw_char('0' + score_1, x_center - 64, 32);
		screen.draw_char('0' + score_2, x_center + 32, 32);

		screen.draw_rectangle(int(ball->get_start().x), int(ball->get_start().y), int(ball->get_end().x), int(ball->get_end().y));
		screen.draw_rectangle(paddle->get_start().x, paddle->get_start().y, paddle->get_end().x, paddle->get_end().y);
		screen.draw_rectangle(paddle2->get_start().x, paddle2->get_start().y, paddle2->get_end().x, paddle2->get_end().y);


		screen.update_screen();
	}
}