#include "LoadLevel.h"

LoadLevel::LoadLevel() {
	try {
		Level_file.open("test5.json", ifstream::in);
		cout << "file opened" << endl;
	}
	catch (exception e) {
		cout << e.what() << endl;
		cout << "File didnt open" << endl;
	}
}

void LoadLevel::GetWindow(Window * window_) {
	window = window_;
	renderer = window->GetRenderer();
}

string LoadLevel::getRoomName() {
	return roomName;
}

vector<Entity>& LoadLevel::getEntity() {
	return EntityList;
}

int LoadLevel::getWindowX() {
	return WindowX;
}

int LoadLevel::getWindowY() {
	return WindowY;
}

void LoadLevel::ReadIn() {
	try {
		Level_file >> objects;
		cout << "File deserialized" << endl;
		for (int i = 0; i < objects.size(); i++) {
			if ((objects[i][0]) == "bg.png") {
				roomName = "bg.png";
				WindowX = objects[0][1][0];
				WindowY = objects[0][1][1];
			}
			else if ((objects[i][0]) == "FoodBowlEmpty.png") {
				EntityList.push_back(Entity(renderer, Vec2((float)objects[i][1][2], (float)objects[i][1][3]), "FoodBowlEmpty.png"));
			}
			else if ((objects[i][0]) == "LitterEmpty.png") {
				EntityList.push_back(Entity(renderer, Vec2((float)objects[i][1][2], (float)objects[i][1][3]), "LitterEmpty.png"));
			}
			else {
				EntityList.push_back(Tamagotchi(renderer, Vec2((float)objects[i][1][2], (float)objects[i][1][3]), objects[i][0]));
			}
		}
	}
	catch (exception e) {
		cout << "ReadIn failed" << endl;	
		if (Level_file.is_open())
			Level_file.close();
		cout << "Closing File" << endl;
	}
}

LoadLevel::~LoadLevel() {
	/*if(Level_file.is_open())
		Level_file.close();
	cout << "Filestream closed" << endl;*/
}