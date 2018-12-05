#include "GameManager.h"



GameManager::GameManager()
{
	//clears all pointers (set them to null)
	//and all variables set to default
	window = nullptr;
	isRunning = true;
}


GameManager::~GameManager()
{
}

void GameManager::OnDestroy() {
	delete window;
}


bool GameManager::OnCreate() {

	window = new Window("Game Window", 800, 600);

	if (window == nullptr) {
		OnDestroy();
		return false;
	}

	if (window->OnCreate() == false) {
		OnDestroy();
		return false;
	}

	sceneHandler = new SceneHandler(window);	

	if (sceneHandler == nullptr) {
		OnDestroy();
		return false;
	}

	if (sceneHandler->OnCreate() == false) {
		OnDestroy();
		return false;
	}

	return true;
}

void GameManager::Run() {
	SDL_Event event;

	while (isRunning) {


		//if there was an event
		if (SDL_PollEvent(&event) != 0) {

			//order UI handler to deal with it
			sceneHandler->HandleEvents(event);

			//check the event type
			if (event.type == SDL_QUIT) {
				isRunning = false;
			}

			if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_ESCAPE) isRunning = false;
			}
		}

		//update UIhandler, timer, game, etc
		sceneHandler->Update();

	}

	SDL_Quit();

}
