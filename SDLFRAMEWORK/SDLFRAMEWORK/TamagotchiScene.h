#pragma once
#include "Scene.h"
#include <vector>
#include "HFiles.h"
#include "Entity.h"
#include "Tamagotchi.h"
#include "UI_Factory.h"

class TamagotchiScene :
	public Scene
{
private:
	int w, h;
	SDL_Renderer * renderer;
	SDL_Window * window;
	SDL_Texture * texture;
	SDL_Surface * roomimage;
	SDL_Rect * rect;
	vector<Entity>* EntityList;
	const char* roomImageName;

	//shared_ptr for abstract UI
	shared_ptr<UI> UI;
	//shared_ptr for UI_Factory
	shared_ptr<UI_Factory> factory;

	Matrix4 projectionMatrix;
public:	
	TamagotchiScene(SDL_Window* window_, SDL_Renderer* renderer_, vector<Entity>* EntityList_, string RoomImage_);
	bool OnCreate();
	void Update();
	void HandleEvents(SDL_Event event);
	void OnDestroy();
	void Render();
	
	~TamagotchiScene();
};

