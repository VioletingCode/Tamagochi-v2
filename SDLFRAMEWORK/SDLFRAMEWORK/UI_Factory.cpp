#include "UI_1.h"
#include "UI_2.h"
#include "UI_Factory.h"

using namespace std;

//UI_Factory to build up UI's as well as UI Manager does
void UI_Factory::createUI(int cUI) {
	switch (cUI)
	{
		//Switch case statement1
	case 1:
		//Hey currentUI is generating new UI_1 which is RPG hud
		currentUI = shared_ptr<UI_1>(new UI_1());
		//if current UI passes to nullptr set UI_1 to destroy
		if (currentUI == nullptr) {
			currentUI->OnDestroy();
		}
		//If you exit or any situation set currentUI OnCreate to false
		if (currentUI->OnCreate() == false) {
			currentUI->OnDestroy();
		}
		break;
	case 2:
		currentUI = shared_ptr<UI_2>(new UI_2());
		if (currentUI == nullptr) {
			currentUI->OnDestroy();
		}
		if (currentUI->OnCreate() == false) {
			currentUI->OnDestroy();
		}
		break;
	}
}

//OnCreate for factory to make sure UI_1(RPG) generates
bool UI_Factory::OnCreate() {

	currentUI = std::shared_ptr<UI_1>(new UI_1());

	if (currentUI == nullptr) {
		currentUI->OnDestroy();
		return false;
	}
	if (currentUI->OnCreate() == false) {
		currentUI->OnDestroy();
		return false;
	}
	return true;
}

shared_ptr<UI> UI_Factory::TempUI() {
	return currentUI;
}
