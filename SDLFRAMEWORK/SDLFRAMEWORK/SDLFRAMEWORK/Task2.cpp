#include "Task2.h"


Task2::Task2(SDL_Window * window_, SDL_Renderer* renderer_)
{
	window = window_;
	renderer = renderer_;
}


Task2::~Task2()
{
}

void Task2::OnDestroy() {
	
}

bool Task2::OnCreate() {
	SDL_GetWindowSize(window, &w, &h);

	cout << "Task 2" << endl;

	return true;
}

void Task2::Update() {
	
}

void Task2::HandleEvents(const SDL_Event event) {
	
}

void Task2::Render() {

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);
}
