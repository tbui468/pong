#include <iostream>
#include "Screen.h"
#include "Entity.h"
#include "Paddle.h"
#include "Ball.h"

/*
FEATURES TO ADD/FIX
********************
-Add score when ball moves past paddle.  Have ball respawn on one side
-draw walls and center line
-create a list of criteria for good code (using Code Complete Guidelines).  
-Look at list below.  Rate each item from (poor, average, good) (0, 1, 2 pts)
-Rate the program out of 20

THE LIST (limit to only 10)
*********
1. member variables prefixed with m_.  Classes capitalized.  
2. Object coupling (draw a diagram of the connections of all classes)
3. Inheritance (Is the Entity class and Paddle and Ball class interfaces the same???)
4. Magic numbers inside the code??
5. Making use of containers or inheritance?  Would one or the other been a better choice?
6. Any unneccesary copying of large objects of data structures?
7. Class abstraction and routine names (are the class routines and their names self-explanatory?  Is the class cohesive?)
8. Superfluous code?  Am I programming for the future, or the actual specifications?
9. Using modern C++?  Smart pointers?  For each loops?  
10. Style.  Subjective.  Is it easy to follow?  naming conventions clear and consistent?  No crazy nested ifs/loops?  Repeated code
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
		std::array<int, 3>* actions = screen.process_events();
		int delta_time = elapsed_time - previous_time;
		if ((*actions)[0] == 0)
			break;
		paddle->move((*actions)[1], delta_time);
		paddle2->move((*actions)[2], delta_time);

		

		ball->move(delta_time, paddle, paddle2);
		screen.set_color(0,0,0);
		screen.draw_background();

		screen.set_color(255, 255, 255);
		screen.draw_rectangle(int(ball->get_start().x), int(ball->get_start().y), int(ball->get_end().x), int(ball->get_end().y));
		screen.draw_rectangle(paddle->get_start().x, paddle->get_start().y, paddle->get_end().x, paddle->get_end().y);
		screen.draw_rectangle(paddle2->get_start().x, paddle2->get_start().y, paddle2->get_end().x, paddle2->get_end().y);

		screen.update_screen();





	}

	screen.close();

	return 0;
}