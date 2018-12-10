#include "UI_1.h"

UI_1::UI_1() {

}


UI_1::~UI_1() {}

//RPG HUD OnCreate from vector bodies and return it
bool UI_1::OnCreate() {

	vBodies.push_back(new Body("button_give-food.png", 0, 0, Vec3(24.0f, 15.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), 0, false));
	vBodies.push_back(new Body("button_clean.png", 0, 0, Vec3(24.0f, 13.5f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), 0, false));
	vBodies.push_back(new Body("button_play.png", 0, 0, Vec3(24.0f, 12.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), 0, false));
	vBodies.push_back(new Body("buttons_medicine.png", 0, 0, Vec3(24.0f, 10.5f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), 0, false));


	////Iterator goes through Vector
	//for (int i = 0; i < vBodies.size(); i++) {
	//	vBodies[i]->getImage();
	//	
	//}


	for (auto it : vBodies) {
		if (it == nullptr) {
			return false;
		}
	}
	return true;
}

//RPG HUD OnDestory function to delete pointer of Vector and set it nullptr
void UI_1::OnDestroy() {
	for (auto it : vBodies) {
		delete it;
		it = nullptr;
	}
}

//RPG HUD Render to generate 3 bodies with UI Window, ScreenCoordinates, and BlitSurface.
void UI_1::Render(Matrix4 projectionMatrix, SDL_Window * window, SDL_Renderer * renderer) {
	SDL_Surface *uiScreenSurface = SDL_GetWindowSurface(window);
	SDL_Rect imageRectangle;
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, uiScreenSurface);
	SDL_FreeSurface(uiScreenSurface);


	for (int i = 0; i < 4; ++i) {
		Vec3 screenCoords = projectionMatrix * vBodies[i]->pos;

		imageRectangle.h = vBodies[i]->getImage()->h;
		imageRectangle.w = vBodies[i]->getImage()->w;
		imageRectangle.x = screenCoords.x; /// implicit type conversions BAD - probably causes a compiler warning
		imageRectangle.y = screenCoords.y; /// implicit type conversions BAD - probably causes a compiler warning

		SDL_RenderCopy(renderer, texture, NULL, &imageRectangle);

		//SDL_BlitSurface(vBodies[i]->getImage(), nullptr, uiScreenSurface, &imageRectangle);
	}
}

//Leave as void
void UI_1::HandleEvents(const SDL_Event& event) {
}