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

	m_window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	if (m_window == nullptr) {
		std::cout << "Failed to create window" << std::endl;
		SDL_Quit();
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	if (m_renderer == nullptr) {
		std::cout << "Failed to create renderer" << std::endl;
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}

	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (m_texture == nullptr) {
		std::cout << "Failed to create texture" << std::endl;
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}

	m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
	memset(m_buffer, 0, sizeof(Uint32) * SCREEN_WIDTH * SCREEN_HEIGHT);
	update_screen();

	return true;
}

void Screen::update_screen() {
	SDL_UpdateTexture(m_texture, nullptr, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, nullptr, nullptr);
	SDL_RenderPresent(m_renderer);
}

bool Screen::process_events() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if(event.type == SDL_QUIT)
		return false;
	}
	return true;
}

void Screen::set_color(unsigned char red, unsigned char green, unsigned char blue) {
	m_color = red;
	m_color <<= 8;
	m_color += green;
	m_color <<= 8;
	m_color += blue;
	m_color <<= 8;
	m_color += 0xff;
}

void Screen::set_pixel_color(int x, int y) {
	m_buffer[SCREEN_WIDTH * y + x] = m_color;
}

void Screen::set_background_color() {
	for (int i = 0; i < (SCREEN_WIDTH * SCREEN_HEIGHT); ++i) {
		m_buffer[i] = m_color;
	}
}

bool Screen::close() {
	if(m_buffer != nullptr) delete[] m_buffer;
	if(m_texture != nullptr) SDL_DestroyTexture(m_texture);
	if(m_renderer != nullptr) SDL_DestroyRenderer(m_renderer);
	if(m_window != nullptr) SDL_DestroyWindow(m_window);
	SDL_Quit();
	return true;
}