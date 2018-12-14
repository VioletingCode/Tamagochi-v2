#include "Tamagotchi.h"

Tamagotchi::Tamagotchi(SDL_Renderer * renderer_, Vec2 Position_, string imagename_){
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
//
//void Tamagotchi::Eat() {
//
//}
//
//void Tamagotchi::Poop() {
//
//}
//
//void Tamagotchi::Update() {
//
//}
//
//void Tamagotchi::Update() {
//
//}

Tamagotchi::~Tamagotchi(){
}
