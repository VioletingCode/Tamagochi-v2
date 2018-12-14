#include "TamagotchiScene.h"

bool TamagotchiScene::OnCreate() {
	SDL_GetWindowSize(window, &w, &h);

	cout << "Tamagotchi Scene Active" << endl;
	roomimage = IMG_Load(roomImageName);
	texture = SDL_CreateTextureFromSurface(renderer, roomimage);
	
	projectionMatrix = MMath::viewportNDC(w, h) * MMath::orthographic(0.0f, 30.0f, 0.0f, 15.0f, 0.0f, 1.0f);

	factory = shared_ptr<UI_Factory>(new UI_Factory());
	//Hey Factory generate UI 1 for me!
	factory->createUI(1);
	//Temporary abstract UI function stores up factory creation 
	UI = factory->TempUI();
	return true;
}

void TamagotchiScene::Update() {

}

void TamagotchiScene::Render() {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, rect);

	UI->Render(projectionMatrix, window);
	SDL_RenderPresent(renderer);
}

void TamagotchiScene::HandleEvents(SDL_Event event) {
	//Window 1280, 720

	int x = event.button.x;
	int y = event.button.y;

	if (event.type == SDL_MOUSEBUTTONDOWN) {
		if (x >= 1020 && y <= 60) {
			printf("MOUSE_button_1\n"); //Button 1 (FEED)

		}
		else if (x >= 1020 && y >= 65 && y <= 140) {
			printf("MOUSE_button_2\n"); //Button 2 (CLEAN)

		}
		else if (x >= 1020 && y >= 145 && y <= 215) {
			printf("MOUSE_button_3\n"); //Button 3 (PLAY)

		}
		else if (x >= 1020 && y >= 220 && y <= 270) {
			printf("MOUSE_button_4\n"); //Button 4 (MEDICINE)

		}
		else {
			printf("Not Detected\n"); //No buttons detected
		}
	}
}

TamagotchiScene::TamagotchiScene(SDL_Window* window_, SDL_Renderer* renderer_, vector<Entity>& EntityList_, string RoomImage_) {
	window = window_;
	renderer = renderer_;
	*EntityList = EntityList_;
	roomImageName = RoomImage_.c_str();
	rect = new SDL_Rect;
	OnCreate();
}

void TamagotchiScene::OnDestroy() {

}

TamagotchiScene::~TamagotchiScene(){
	delete roomImageName;
	delete rect;

	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(roomimage);
}
