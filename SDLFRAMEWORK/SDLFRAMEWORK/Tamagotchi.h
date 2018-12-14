#pragma once
#include "Entity.h"
class Tamagotchi :
	public Entity
{
private:
	//Member variable that track their respective meters
	int hunger;
	int	poop;
	int happiness;
	
	//Images for different animations
	SDL_Surface * imageIdle = nullptr;
	SDL_Surface * imageEat = nullptr;
	SDL_Surface * imagePoop = nullptr;
	const char *imagename;
public:
	//methods that tell the pet to go to a place and do something
	//void Eat();
	//void Poop();

	//Updates meters and moves the tamagotchi
	//void Update();

	//Constructors
	Tamagotchi(SDL_Renderer * renderer_, Vec2 Position_, string imagename_);
	~Tamagotchi();
};

