#include <iostream>
#include "Screen.h"
#include "Round.h"
#include <thread>
#include <chrono>

/*
FEATURES TO ADD/FIX
********************
-Add score when ball moves past paddle.  Have ball respawn on one side
-draw score on screen (0 - 10) 
-wrap game in round class, and wrap that in game class
-title screen class(title, creator, 1 player or 2 player game)
-getting to 10 points removes ball, and then sends player back to title screen after 3 seconds
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


//Main is the game class
int main(int argc, char* args[]) {

	srand((unsigned)time(NULL));

	std::cout << "Let's play Pong!" << std::endl;


	Screen screen;

	screen.init();

	using namespace std::literals::chrono_literals;


	//std::thread worker(print_numbers, 100);
	//std::thread worker2(print_numbers, 10);



	//draw menu screen here
	bool play = true;
	
	while (play) {
		screen.set_color(0, 0, 0);
		screen.draw_background();
		screen.draw_title(125, 200);
		screen.update_screen();
		std::this_thread::sleep_for(1.5s);


		int score_1 = 0;
		int score_2 = 0;

		while (play) {
			Round round(screen, score_1, score_2);
			int point = round.start();
			switch (point) {
			case Point_player_1:
				score_1++;
				break;
			case Point_player_2:
				score_2++;
				break;
			case Point_quit:
				play = false;
				break;
			default:
				break;
			}
			std::this_thread::sleep_for(.2s);
			if (score_1 > 9 || score_2 > 9)
				break;

		}
	}

	

	screen.close();

	return 0;
}