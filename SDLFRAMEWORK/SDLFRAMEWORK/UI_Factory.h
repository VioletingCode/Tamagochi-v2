#include "UI.h"
#include <SDL.h>
#include <iostream>
#include <memory>
#ifndef UI_FACTORY_H
#define UI_FACTORY_H

// C++ program factory method design pattern. UI_Factory builds up UI's and handle them
class UI_Factory
{
public:
private:
	//Giving shared_ptr of Abstract UI
	std::shared_ptr<UI> currentUI;
public:
	void createUI(int cUI);
	bool OnCreate();
	//Setting temp Abstract UI to return it
	std::shared_ptr<UI> TempUI();
	//static inline std::shared_ptr<UI> createUI(int cUI) {}
};

#endif

