#include "Scene0.h"


Scene0::Scene0(SDL_Window * window_, SDL_Renderer* renderer_)
{
	window = window_;
	renderer = renderer_;
}


Scene0::~Scene0()
{
}

void Scene0::OnDestroy() {

}

bool Scene0::OnCreate() {
	SDL_GetWindowSize(window, &w, &h);

	cout << "Scene 0 created" << endl;

	tam = new Character(renderer);

	if (tam == nullptr) {
		OnDestroy();
		return false;
	}

	entity = new Entity(renderer, Vec2(w/2, h/2), "smiley.png");

	//tam->setPosition(new Vec2(800, 600));

	return true;
}

void Scene0::Update() {

	if (tam->DetectCollision(entity)) tam->CollisionResponse();

	tam->Update();
}

void Scene0::HandleEvents(SDL_Event event) {
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == SDLK_SPACE) {
			tam->coutPosition();
			cout << "Entity pos: " << entity->getPosition().x << endl;
		}
	}

}

void Scene0::Render() {

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	tam->Render();
	entity->Render();

	SDL_RenderPresent(renderer);
}
