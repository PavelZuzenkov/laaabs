#include "Human.h"
#include "Tourist.h"
#include "Businessman.h"
#include "Chelnok.h"
#include "Menu.h"
#include "interface.h"

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Interface <int> obj;

	obj.Menu();
}