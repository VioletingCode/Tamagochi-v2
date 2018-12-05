#include "Window.h"
#include <SDL_image.h>


Window::Window(std::string title_, int width_, int height_)
{
	title = title_;
	width = width_;
	height = height_;

	window = nullptr;
	renderer = nullptr;
}


Window::~Window()
{
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

bool Window::OnCreate() {

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cerr << "Failed to initialize SDL.\n";
		return false;
	}

	if (TTF_Init() != 0) {
		std::cerr << "Fatal error occured. Failed to initialize TTF.\n";
	}

	//if (!IMG_Init(IMG_INIT_PNG)) {
	//	std::cerr << "Failed to intialize SDL image. \n";
	//	return false;
	//}

	IMG_Init(IMG_INIT_PNG);

	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

	if (window == nullptr) {
		std::cerr << "Failed to create window.\n";
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == nullptr) {
		std::cerr << "Failed to create renderer.\n";
		return false;
	}

	return true;
}
