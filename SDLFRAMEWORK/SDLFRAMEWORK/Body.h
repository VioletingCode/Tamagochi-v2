#ifndef BODY_H
#define BODY_H
#include "Vector.h"
#include "SDL.h"
#include <SDL_image.h>
using namespace MATH;

class Body {
public:
	Vec3 pos;
	Vec3 vel;
	float mass;
	float radius;
	bool movable;
private:
	Vec3 accel;
	Vec3 gravity;
	SDL_Surface *bodyImage;
	SDL_Renderer *bodyRender;
	SDL_Texture *bodyTexture;

public:
	Body(char* imageName, float mass_, float radius_, Vec3 pos_, Vec3 vel_, Vec3 accel_, Vec3 gravity_, bool movable_);
	~Body();
	void Update(const float deltaTime);
	void ApplyForce(Vec3 force);

	/// Just a little helper function
	SDL_Surface* getImage();

	SDL_Texture* getTexture();
};


#endif
