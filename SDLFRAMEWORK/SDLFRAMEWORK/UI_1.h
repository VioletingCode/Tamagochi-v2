#ifndef UI_1_H
#define UI_1_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <vector>
#include "MMath.h"
#include "UI.h"
#include "Body.h"
#include <memory>

using namespace std;

//Inherit from abstract Base UI
class UI_1 : public UI
{
public:
	//Vector bodies to create memory space
	vector<Body*> vBodies;
private:
	SDL_Renderer * renderer = nullptr;
    SDL_Window * window = nullptr;
	SDL_Texture * button_texture = nullptr;

public:
	UI_1();
	~UI_1();
	bool OnCreate();
	void OnDestroy();
	//vector<Body*> Render();
	void Render(Matrix4 projectionMatrix, SDL_Window * window);
	void HandleEvents(const SDL_Event& event);
};

#endif