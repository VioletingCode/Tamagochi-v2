#pragma once
#include "HFiles.h"
#include "Scene.h"


class Task2 : public Scene
{
public:
	Task2(SDL_Window * window_, SDL_Renderer* renderer_);
	~Task2();

	bool OnCreate();
	void OnDestroy();
	void Update();
	void HandleEvents(SDL_Event event);
	void Render();

private:
	int w, h;

	SDL_Renderer * renderer = nullptr;
	SDL_Window * window = nullptr;
};

