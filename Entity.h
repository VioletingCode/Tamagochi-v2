#pragma once
#include "HFiles.h"
#include "Vector.h"
using namespace MATH;
class Entity
{
protected:
	Vec2 Position;

	SDL_Rect * rect = nullptr;
	SDL_Texture * texture = nullptr;
	SDL_Surface * image = nullptr;
	SDL_Renderer * renderer = nullptr;
	const char* imagename;
public:
	Vec2 getDimensions();
	Vec2 getPosition();
	void Render();
	virtual void Update() {};
	Entity() {};
	Entity(SDL_Renderer * renderer_, Vec2 Position_, string imagename_);
	~Entity();
};

