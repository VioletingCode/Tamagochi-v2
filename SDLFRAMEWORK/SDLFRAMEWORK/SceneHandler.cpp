#include "SceneHandler.h"
#include "Task2.h"



SceneHandler::SceneHandler(Window * window_)
{
	changeScenes = false;
	window = window_;
	renderer = window->GetRenderer();
}


SceneHandler::~SceneHandler()
{
}

void SceneHandler::OnDestroy() {
	for (int i = 0; i < tasks.size(); i++) {
		tasks[i]->OnDestroy();
		delete tasks[i];
	}

	//delete window;
	SDL_DestroyRenderer(renderer);
	//SDL_Quit();
	//TTF_Quit();
	//IMG_Quit();
}

bool SceneHandler::OnCreate() {

	tasks.push_back(new Task2(window->GetWindow(), window->GetRenderer()));

	if (tasks.back() == nullptr) {
		OnDestroy();
		return false;
	}

	if (tasks.back() == nullptr) {
		OnDestroy();
		return false;
	}

	if (tasks.front()->OnCreate() == false) {
		OnDestroy();
		return false;
	}

	return true;
}

void SceneHandler::Update() {


	tasks.front()->Update();

	//if (changeScenes) {
	//	tasks.push_back(tasks.front());
	//	tasks.front()->OnDestroy();
	//	tasks.pop_front(); // Removes the scene in the front of the queue, new front should be of next scene type 

	//	if (tasks.front()->OnCreate() == false) OnDestroy();

	//	changeScenes = false;
	//}

	tasks.front()->Render();


}

void SceneHandler::HandleEvents(SDL_Event event) {

	//if (event.type == SDL_KEYUP) {
	//	if (event.key.keysym.sym == SDLK_SPACE) {
	//		changeScenes = true;
	//	}
	//}

	//if (changeScenes == false)	
		tasks.front()->HandleEvents(event);

}





