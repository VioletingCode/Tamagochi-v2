#pragma once
#include "SceneHandler.h"
#include "HFiles.h"
#include "Tamagotchi.h"
#include <fstream>
#include <nlohmann/json.hpp>

// for convenience
using json = nlohmann::json;


class LoadLevel {
private:
	ifstream Level_file;
	Window * window;
	SDL_Renderer * renderer;
	json objects;
	string roomName;
	vector<Entity> EntityList;
	int WindowX;
	int WindowY;
public:
	int getWindowX();
	int getWindowY();
	string getRoomName();
	vector<Entity>& getEntity();
	void GetWindow(Window * window_);
	LoadLevel();
	~LoadLevel();
	void ReadIn();
};