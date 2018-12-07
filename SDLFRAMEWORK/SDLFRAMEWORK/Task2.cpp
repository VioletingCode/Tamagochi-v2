#include "Task2.h"


Task2::Task2(SDL_Window * window_, SDL_Renderer* renderer_)
{
	window = window_;
	renderer = renderer_;
}


Task2::~Task2()
{
}

void Task2::OnDestroy() {
	
}

bool Task2::OnCreate() {
	SDL_GetWindowSize(window, &w, &h);

	projectionMatrix = MMath::viewportNDC(w, h) * MMath::orthographic(0.0f, 30.0f, 0.0f, 15.0f, 0.0f, 1.0f);

	//shared_ptr to create new UI Factory
	factory = shared_ptr<UI_Factory>(new UI_Factory());
	//Hey Factory generate UI 1 for me!
	factory->createUI(1);
	//Temporary abstract UI function stores up factory creation 
	UI = factory->TempUI();



	cout << "Task 2" << endl;
	return true;
}

void Task2::Update() {
	
}

void Task2::HandleEvents(const SDL_Event event) {
	
}

void Task2::Render() {
	//UI will be rendered by here with separate window
	UI->Render(projectionMatrix, window);


	//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	//SDL_RenderClear(renderer);

	//SDL_RenderPresent(renderer);
}
