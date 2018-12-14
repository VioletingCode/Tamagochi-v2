#pragma once
#include "Window.h"
#include "LoadLevel.h"
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
	LoadLevel * LevelLoader = nullptr;
	Window * window = nullptr;
	SceneHandler * sceneHandler = nullptr;
	bool isRunning;
};

