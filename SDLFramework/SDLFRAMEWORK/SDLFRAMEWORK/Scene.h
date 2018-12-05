#pragma once
#include "HFiles.h"

class Scene {
public:
	virtual bool OnCreate() = 0;
	virtual void OnDestroy() = 0;
	virtual void Update() = 0;
	virtual void HandleEvents(SDL_Event) = 0;
	virtual void Render() = 0;
};