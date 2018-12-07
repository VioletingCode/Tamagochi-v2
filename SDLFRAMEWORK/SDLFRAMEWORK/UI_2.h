#ifndef UI_2_H
#define UI_2_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <vector>
#include "MMath.h"
#include "UI.h"
#include "UI_Factory.h"
#include "Body.h"

using namespace std;

//Inherit from abstract Base UI
class UI_2 : public UI
{
public:
	//Vector bodies to create memory space
	vector<Body*> vBodies;
private:

public:
	UI_2();
	~UI_2();
	bool OnCreate();
	void OnDestroy();
	void HandleEvents(const SDL_Event& event);
	void Render(Matrix4 projectionMatrix, SDL_Window * window);
};

#endif