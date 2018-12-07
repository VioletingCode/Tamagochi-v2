#include <SDL.h>
#include "MMath.h"

#ifndef UI_H
#define UI_H

//UI abstract class which does nothing for now 
using namespace MATH;

class UI {
public:
	virtual bool OnCreate() = 0;
	virtual void OnDestroy() = 0;
	virtual void Render(Matrix4 projectionMatrix, SDL_Window * window) = 0;
	virtual void HandleEvents(const SDL_Event& event) = 0; //Read address but not touch
};

#endif