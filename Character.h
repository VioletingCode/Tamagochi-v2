#pragma once
#include "Vector.h"
#include "Entity.h"
#include "HFiles.h"


using namespace MATH;

class Character
{
private:
	//Member variables that can be changed
	int health;
	bool hasImg;
	float speed;
	
	Vec2 * randPos = nullptr;
	Vec2 * lastPos = nullptr;
	Vec2 * position = nullptr;

	//objects used to render
	SDL_Rect * rect = nullptr;
	SDL_Texture * texture = nullptr;
	SDL_Surface * image = nullptr;
	SDL_Renderer * renderer = nullptr;

public:
	//Lets us render our character
	Character(SDL_Renderer * renderer_);
	~Character();

	void Update();
	void Render();

	void addHealth(int amount);
	void removeHealth(int amount);

	void moveTo(Vec2 * pos);
	void Move(Vec2 * direction);
	void Idle();

	bool DetectCollision(Entity * entity);
	void CollisionResponse();

	inline int getHealth() { return health; }
	inline void setPosition(Vec2 * pos) { position = pos; }
	inline void coutPosition() { cout << "Tam position: " << position->x << ", " << position->y << endl; }
};

