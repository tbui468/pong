#include <iostream>
//#include "Screen.h"
//#include "Round.h"
#include "Game.h"

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

Areas of Improvement
********************
-Use consistent naming convention (ClassName, method_name(), t_parameter, m_variable)
-Each class either contains ("has a") or inherits ("is a") another class.  Be sure to declare "contained" objects in class declaration
-Classes that inherit from a base class should have the same public interface.  Ball and Paddle should use a shared Entity interface
-Avoid passing arguments up multiple levels of class.  Game "has a" Round "has a" Ball.  Ball passes score info to Round, and 
	Round passes it to Game.  Next time, have Round keep track of Ball position, and the Round.loop returns a value (eg enum)
	to tell game to update score.
-Game is starting class. Contains Screeen, Input and Round.  Initializes Screen and Input.  Member variables include player 1 and 2 scores
	Game will loop round repeatedly until a player wins, or the close window button is pressed
-Round is the largest class.  Constructor parameters are Screen and Input.  Contains Screen, Input, Ball, Paddle1 and Paddle2. 
	When the round is over, it returns score information to Game, to update player 1 and 2 score.  
-Screen class is contained in both Game and Round.  In Game, Screen draws title.  In Round, screen draws ball, paddles and score.  
-Input class in contained in Round.  Round uses input.get_input(), and uses return data to move paddles 1 and 2.
-Ball and Paddle class inherit from Entity.  Round class takes in user input from Input object.  If move is valid based
	on ball.collision(x,y,paddle) and paddle.collision(x, y, ball), call ball.set_location(x, y) and paddle.set_location(x, y)
	Round classes calls Screen.draw(args) to draw Ball and Paddle.  Round class calls ball.collision(arg), paddle1.collision(arg), and 
	paddle2.collision(arg).  If collisions are detected, Round class calls ball.set_velocity(arg) and paddle1.set_velocity(arg), 
	and paddle2.set_velocity(arg).  
-Entity class is the base class of Paddle and Ball.  Member variables include x and y locations, width and height, horizontal and vertical
	velocity.  Methods include collision(x, y, object) set_location(x, y), set_velocity(arg).  

*/


//Main is the game class
int main(int argc, char* args[]) {

	srand((unsigned)time(NULL)); //create random seed


	Game game;
	game.init();
	game.loop();
	game.end();

	return 0;
}