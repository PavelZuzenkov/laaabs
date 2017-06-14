#pragma once
#include "Human.h"
#include "Businessman.h"
#include "Tourist.h"
#include "Chelnok.h"
#include <Windows.h>

class Menu
{
public:
	Menu();
	~Menu();
	void menu();
	void touristmenu();
	void busmenu();
	void chelnokmenu();
};

