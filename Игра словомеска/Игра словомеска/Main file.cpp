// Мой шаблон.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

#include "Functions.h"

using namespace std;

enum GameActions
{
	CHECK_RULES = 1,
};

int main()
{
	srand(time(0));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "\t\t\t\t\t\t Игра Словомеска" << endl;

	int gameAction = atoi(enterAction().c_str());

	if (gameAction == CHECK_RULES)
	{
		showGameRules();
		system("pause");
	}

	startLevel();


	system("pause");
	return 0;
}
