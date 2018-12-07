#pragma once
#include "HFiles.h"
#include "Scene.h"
#include "UI_Factory.h"

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

	//shared_ptr for abstract UI
	shared_ptr<UI> UI;
	//shared_ptr for UI_Factory
	shared_ptr<UI_Factory> factory;

	Matrix4 projectionMatrix;

	SDL_Renderer * renderer = nullptr;
	SDL_Window * window = nullptr;
};

