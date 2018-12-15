#include "Entity.h"



Entity::Entity(SDL_Renderer * renderer_, Vec2 Position_, string imagename_) {
	imagename = imagename_.c_str();
	renderer = renderer_;
	Position = Position_;
	image = IMG_Load(imagename);
	texture = SDL_CreateTextureFromSurface(renderer, image);
	rect = new SDL_Rect;
	rect->h = 200;
	rect->w = 200;
	//rect->x = Position.x - ( rect->w / 2);
	//rect->y = Position.y - ( rect->w / 2);

	cout << "Entity pos: " << Position.x << ", " << Position.y << endl;
	rect->x = Position.x;
	rect->y = Position.y;
}

Vec2 Entity::getPosition() {
	//cout << "pos " << Position.x << ", " << Position.y << endl;
	return Vec2(Position.x, Position.y);
}

Vec2 Entity::getDimensions() {
	return Vec2(rect->w, rect->h);
}

void Entity::Render() {
	SDL_RenderCopy(renderer, texture, NULL, rect);
}

Entity::~Entity() {
	delete Position;
	delete rect;

	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(image);
}
