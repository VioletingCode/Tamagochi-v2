#include "GameManager.h"


int main(int argc, char* args[]) {

	//std::unique_ptr<GameManager> gm = std::unique_ptr<GameManager>(new GameManager());
	auto gm = std::unique_ptr<GameManager>(new GameManager());

	bool status = gm->OnCreate();

	if (status == true) {
		//gm instantiated correctly
		gm->Run();
	}

	else if (!status) {
		std::cerr << "Cannot start the program.";
	}

	return 0;
}