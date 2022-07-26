#pragma once

#include <SDL.h>

class Engine
{
public:
	void init();
	void processInput();
	void update();
	void render();

	bool getIsRunning();

private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;

	bool _isRunning;
	unsigned int _lastFrameTicks;
};