#include "UserInput.h"

UserInput::UserInput() {

}

int UserInput::get_input() {
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
			case SDLK_w:
				return Key_up;
				break;
			case SDLK_s:
				return Key_down;
				break;
			}
		}
	}
}