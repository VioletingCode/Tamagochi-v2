#include "Character.h"

using namespace MATH;

Character::Character(SDL_Renderer * renderer_)
{
	renderer = renderer_;

	//load image and convert it to texture
	image = IMG_Load("smiley.png");
	texture = SDL_CreateTextureFromSurface(renderer, image);

	//check if the image loaded properly (used in render function)
	if (image == nullptr || texture == nullptr) hasImg = false;
	else hasImg = true;

	//set character default stats
	position = new Vec2(0.0f, 0.0f);
	randPos = new Vec2(rand() % 800, rand() % 600);
	health = 50;
	speed = 0.1;

	//create rectangle to display as character
	rect = new SDL_Rect;
	rect->w = 100;
	rect->h = 100;
	rect->x = position->x - 50;
	rect->y = position->y - 50;
}


Character::~Character()
{
	delete position;
	delete rect;

	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(image);
}

void Character::Update() {

	//update character's rectangle so that it always equals position
	//the -50 essentially puts the rect's origin in the middle of itself
	rect->x = position->x - 50;
	rect->y = position->y - 50;

	lastPos = position;

	Idle();
}

void Character::Render() {

	//if there is an image, render it
	if (hasImg) SDL_RenderCopy(renderer, texture, NULL, rect);

	//if not, render a coloured rect
	else {
		SDL_SetRenderDrawColor(renderer, 78, 42, 163, 255);
		SDL_RenderFillRect(renderer, rect);
	}
}

bool Character::DetectCollision(Entity * entity) {

	if (position->x - 50 < entity->getPosition().x + entity->getDimensions().x &&
		position->x + 50 > entity->getPosition().x &&
		position->y - 50 < entity->getPosition().y + entity->getDimensions().y &&
		position->y + 50 > entity->getPosition().y) 
	{
		cout << "Collision detected!" << endl;
		return true;
	}

	return false;
}

void Character::CollisionResponse() {
	position = lastPos;
}

void Character::addHealth(int amount) {
	health += amount;
}

void Character::removeHealth(int amount) {
	health -= amount;
}

void Character::moveTo(Vec2 * pos) {
	float distance = sqrt(powf((position->x - pos->x), 2) + powf((position->y - pos->y), 2));

	float angle = atan2((position->y - pos->y), (position->x - pos->x));

	if (distance >= 1) {
		Move(new Vec2(-cos(angle) * speed, -sin(angle) * speed));
	}
}

void Character::Move(Vec2 * direction) {
	position = new Vec2(position->x + direction->x, position->y + direction->y);
}

void Character::Idle() {

	moveTo(randPos);

	if (lastPos == position) {
		randPos = new Vec2(rand() % 800, rand() % 600);
	}

}
