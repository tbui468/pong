#include "Screen.h"
#include <iostream>

Screen::Screen() : m_window(nullptr), m_renderer(nullptr), m_texture(nullptr), m_buffer(nullptr), actions(new std::array<int, 3>) {
	(*actions).fill(0);
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


//return a vector of all user inputs that round
std::array<int, 3>* Screen::process_events() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT)
			(*actions)[0] = 0;
		else
			(*actions)[0] = 1;
		if (event.type == SDL_KEYDOWN) {
			int key = event.key.keysym.sym;
			if (key == SDLK_DOWN)
				(*actions)[1] = 1;
			if (key == SDLK_UP)
				(*actions)[1] = -1;
			if (key == SDLK_s)
				(*actions)[2] = 1;
			if (key == SDLK_w)
				(*actions)[2] = -1;
		}
		if (event.type == SDL_KEYUP) {
			int key = event.key.keysym.sym;
			if (key == SDLK_DOWN)
				(*actions)[1] = 0;
			if (key == SDLK_UP)
				(*actions)[1] = 0;
			if (key == SDLK_s)
				(*actions)[2] = 0;
			if (key == SDLK_w)
				(*actions)[2] = 0;
		}
	}
	return actions;
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

void Screen::draw_pixel(int x, int y) {
	if(inside_screen(x, y))
		m_buffer[SCREEN_WIDTH * y + x] = m_color;
}

bool Screen::inside_screen(int x, int y) {
	if (x < 0) return false;
	if (x >= SCREEN_WIDTH) return false;
	if (y < 0) return false;
	if (y >= SCREEN_HEIGHT) return false;
	return true;
}

void Screen::draw_background() {
	for (int i = 0; i < (SCREEN_WIDTH * SCREEN_HEIGHT); ++i) {
		m_buffer[i] = m_color;
	}
}

void Screen::draw_rectangle(int x_start, int y_start, int x_end, int y_end) {
	//swap start and end values to make start the top-left and end the bottom-right
	if (y_start > y_end) {
		int temp = y_start;
		y_start = y_end;
		y_end = temp;
	}
	if (x_start > x_end) {
		int temp = x_start;
		x_start = x_end;
		x_end = temp;
	}
	for (int row = y_start; row < y_end; ++row) {
		for (int col = x_start; col < x_end; ++col) {
			draw_pixel(col, row);
		}
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

//32x64 number
//width is 8 pixels
void Screen::draw_char(char character, int x, int y) {
	draw_rectangle(x, y, x + 32, y + 64);
	set_color(0, 0, 0);
	switch (character) {
	case 48: //0
		draw_rectangle(x + 8, y + 8, x + 24, y + 56);
		break;
	case 49: 
		draw_rectangle(x , y , x + 12, y + 64);
		draw_rectangle(x + 20, y, x + 32, y + 64);
		break;
	case 50:
		draw_rectangle(x, y + 8, x + 24, y + 28);
		draw_rectangle(x + 8, y + 36, x + 32, y + 56);
		break;
	case 51:
		draw_rectangle(x, y + 8, x + 24, y + 28);
		draw_rectangle(x, y + 36, x + 24, y + 56);
		break;
	case 52:
		draw_rectangle(x+8, y , x + 24, y + 28);
		draw_rectangle(x , y + 36, x + 24, y + 64);
		break;
	case 53:
		draw_rectangle(x+8, y + 8, x + 32, y + 28);
		draw_rectangle(x , y + 36, x + 24, y + 56);
		break;
	case 54:
		draw_rectangle(x + 8, y + 8, x + 32, y + 28);
		draw_rectangle(x+8, y + 36, x + 24, y + 56);
		break;
	case 55:
		draw_rectangle(x,  y + 8, x + 24, y + 64);
		break;
	case 56: //8
		draw_rectangle(x + 8, y + 8, x + 24, y + 28);
		draw_rectangle(x + 8, y + 36, x + 24, y + 56);
		break;
	case 57:
		draw_rectangle(x + 8, y + 8, x + 24, y + 28);
		draw_rectangle(x, y + 36, x + 24, y + 56);
		break;
	case 80: //'P'
		draw_rectangle(x + 8, y + 8, x + 24, y + 28);
		draw_rectangle(x + 8, y + 36, x + 32, y + 64);
		break;
	case 76: //'L'
		draw_rectangle(x + 8, y, x + 32, y + 56);
		break;
	case 65: //'A'
		draw_rectangle(x + 8, y + 8, x + 24, y + 28);
		draw_rectangle(x + 8, y + 36, x + 24, y + 64);
		break;
	case 89: //'Y'
		draw_rectangle(x + 8, y , x + 24, y + 28);
		draw_rectangle(x, y + 36, x + 12, y + 64);
		draw_rectangle(x + 20, y + 36, x + 32, y + 64);
		break;
	case 69: //'E'
		draw_rectangle(x + 8, y + 8, x + 32, y + 28);
		draw_rectangle(x + 8, y + 36, x + 32, y + 56);
		break;
	case 82: //'R'
		draw_rectangle(x + 8, y + 8, x + 24, y + 28);
		draw_rectangle(x + 8, y + 36, x + 16, y + 64);
		draw_rectangle(x + 24, y + 36, x + 32, y + 50);
		draw_rectangle(x + 16, y + 50, x + 24, y + 64 );
		break;
	case 83: //'S'
		draw_rectangle(x + 8, y + 8, x + 32, y + 28);
		draw_rectangle(x, y + 36, x + 24, y + 56);
		break;
	default:
		break;
	}
	set_color(255, 255, 255);
}

//128x128
//width: 24
//15 pixels between title letters
void Screen::draw_title(int x, int y) {
	set_color(255, 255, 255);
	draw_rectangle(x, y, x + 128, y + 128); //P
	draw_rectangle(x + 144, y, x + 272, y + 128); //O
	draw_rectangle(x + 288, y, x + 416, y + 128); //N
	draw_rectangle(x + 432, y, x + 560, y + 128); //G
	set_color(0, 0, 0);

	//P
	draw_rectangle(x + 24, y + 24, x + 104, y + 52 );
	draw_rectangle(x + 24, y + 76, x + 128, y + 128);
	//O
	draw_rectangle(x + 168, y + 24, x + 248, y + 104);
	//N
	draw_rectangle(x + 312, y + 24, x + 340, y + 128);
	draw_rectangle(x + 364, y , x + 392, y + 104);
	draw_rectangle(x + 340, y, x + 364, y + 24);
	draw_rectangle(x + 340, y + 104, x + 364, y + 128);
	//G
	draw_rectangle(x + 456, y + 24, x + 560, y + 52);
	draw_rectangle(x + 456, y + 76, x + 536, y + 104);
	draw_rectangle(x + 456, y + 24, x + 496, y + 104);
}
