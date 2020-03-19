#pragma once
#include "SDL.h"
#include <array>


class Screen
{
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
	Uint32* m_buffer;
	Uint32 m_color = 0;
	std::array<int, 3>* actions;
public:
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;
private:
	void draw_pixel(int x, int y);
	bool inside_screen(int x, int y);
public:
	Screen();
	bool init();
	void update_screen();
	std::array<int, 3>* process_events();
	void set_color(unsigned char red, unsigned char green, unsigned char blue);
	void draw_rectangle(int x_start, int y_start, int x_end, int y_end);
	void draw_background();
	bool close();
};

