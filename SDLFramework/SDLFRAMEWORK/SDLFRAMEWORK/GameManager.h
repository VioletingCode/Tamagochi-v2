#pragma once
#include "Window.h"
#include "SceneHandler.h"

class GameManager
{
public:
	GameManager();
	~GameManager();

	// instantiates game engine and returns true if successful
	bool OnCreate();
	void OnDestroy();
	void Run();

private:
	Window * window = nullptr;
	SceneHandler * sceneHandler = nullptr;
	bool isRunning;
};

