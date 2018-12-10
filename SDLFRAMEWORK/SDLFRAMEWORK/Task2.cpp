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
	//Window 1280, 720

	int x = event.button.x;
	int y = event.button.y;

	if (event.type == SDL_MOUSEBUTTONDOWN) {
		if (x >= 1020 && y <= 60) {
			printf("MOUSE_button_1\n");
		} else if (x >= 1020 && y >= 65 && y <= 140) {
			printf("MOUSE_button_2\n");
		} else if (x >= 1020 && y >= 145 && y <= 215) {
			printf("MOUSE_button_3\n");
		} else if (x >= 1020 && y >= 220 && y <= 270) {
			printf("MOUSE_button_4\n");
		}
		else {
			printf("Not Detected\n");
		}
	}
}

void Task2::Render() {
	//UI will be rendered by here with separate window
	UI->Render(projectionMatrix, window, renderer);
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	
	SDL_RenderPresent(renderer);
	//SDL_UpdateWindowSurface(window);
}
