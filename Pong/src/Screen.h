#pragma once
#include "SDL.h"

class Screen
{
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
	Uint32* m_buffer;
	Uint32 m_color = 0;
public:
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;
public:
	Screen();
	bool init();
	void update_screen();
	bool process_events();
	void set_color(unsigned char red, unsigned char green, unsigned char blue);
	void set_pixel_color(int x, int y);
	void set_background_color();
	bool close();
};

