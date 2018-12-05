#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include "Scene.h"

class Window
{
public:

	Window(std::string title_, int width_, int height_);

	~Window();

	bool OnCreate();

	inline SDL_Window* GetWindow() { return window; }
	inline SDL_Renderer* GetRenderer() { return renderer; }

private:
	std::string title;
	int width;
	int height;

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
};

