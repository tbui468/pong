#include "Screen.h"
#include <iostream>

Screen::Screen() : m_window(nullptr), m_renderer(nullptr), m_texture(nullptr), m_buffer(nullptr) {

}

bool Screen::init() {
	//initialize SDL, window, renderer, 
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Failed to initialize SDL video" << std::endl;
		return false;
	}

	m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	if (m_window == NULL) {
		std::cout << "Failed to create window" << std::endl;
		return false;
	}


	return true;
}

bool Screen::close() {
	SDL_DestroyWindow(m_window);
	SDL_Quit();
	return true;
}