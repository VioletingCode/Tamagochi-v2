#include "Entity.h"



Entity::Entity(SDL_Renderer * renderer_, Vec2 Position_, string imagename_){
	imagename = imagename_.c_str();
	renderer = renderer_;
	*Position = Position_;
	image = IMG_Load(imagename);
	texture = SDL_CreateTextureFromSurface(renderer, image);
	rect = new SDL_Rect;
	rect->h = image->h;
	rect->w = image->w;
	rect->x = Position->x / 2;
	rect->y = Position->y / 2;
}

Vec2 Entity::getPosition() {
	return *Position;
}

Vec2 Entity::getDimensions() {
	return Vec2(image->w, image->h);
}

void Entity::Render() {
	SDL_RenderCopy(renderer, texture, NULL, rect);
}

Entity::~Entity(){
	delete Position;
	delete rect;

	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(image);
}
