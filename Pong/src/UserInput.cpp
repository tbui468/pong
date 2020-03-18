#include "UserInput.h"

UserInput::UserInput() {

}

int UserInput::get_input() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYDOWN) {
			int key = event.key.keysym.sym;
			switch (key) {
			case SDLK_a:
				return Key_up;
				break;
			case SDLK_b:
				return Key_down;
				break;
			}
		}
	}
	return Key_nothing;
}