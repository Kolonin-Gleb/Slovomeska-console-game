#include "Functions.h"

string enterAction()
{
	string action = "";

	while (true)
	{
		cout << "Введите 1, чтобы ознакомится с правилами." << endl;
		cout << "Введите 2, чтобы начать играть!" << endl;
		cin >> action;
		if (action == "1" || action == "2")
		{
			return action;
		}
		else
		{
			cout << "Выбранное действие отсутствует!" << endl;
		}
	}
}

void showGameRules()
{
	cout << "\t\t Правила игры:" << endl;
	cout << "Компьютер говорит вам слово, буквы которого перемешались." << endl;
	cout << "Ваша задача угадать, что это за слово и ввести его." << endl;
	cout << "У вас есть 3 жизни." << endl;
	cout << "Одна жизнь отнимается, если вы неправильно вводите загаданное слово."<< endl;
	cout << "Если жизни закончатся, то вы проиграли." << endl;
	cout << "Если вы отгадали все слова, то вы победили." << endl;
	cout << "У вас также есть 3 подсказки." << endl;
	cout << "Для каждого слова можно использовать только 1 подсказку." << endl;
	cout << "Подсказкой является первая половина загаданного слова." << endl;
	cout << "Чтобы использовать подсказку введите \"подсказка\" в поле вашего ответа" << endl;
	cout << "Удачи и приятной игры!" << endl;
	cout << endl << endl;
}

void startLevel()
{
	system("cls");

	short playerLives = 3;
	short playerHints = 3;
	const short COUNT_OF_EASY_WORDS = 10;

	string words[COUNT_OF_EASY_WORDS] =
	{
		"акула"  , "белка" , "камень" , "горка"  , "дракон",
		"ежевика", "желудь", "заклад", "крапива", "лимонад"
	};
	randomizeArray(words, COUNT_OF_EASY_WORDS);

	cout << "\t\tИгра началась!" << endl;

	for (int i = 0; i < COUNT_OF_EASY_WORDS; i++)
	{
		string playerAnswer;
		string playerQuestion = generateQuestion(&words[i]);

		cout << "\nВы отгадываете " << i + 1 << " слово из " << COUNT_OF_EASY_WORDS << endl;
		cout << "Загаданное слово: " << playerQuestion << endl;
		cout << "Это слово: ";
		cin >> playerAnswer;
		if (playerAnswer == "подсказка")
		{
			if (playerHints != 0)
			{
				string hint = generateHint(&words[i]);
				useHint(playerHints, playerQuestion, hint);
				cin >> playerAnswer;
			}
			else
			{
				cout << "Количество ваших подсказок = 0!" << endl;
				cout << "Загаданное слово: " << playerQuestion << endl;
				cout << "Это слово: ";
				cin >> playerAnswer;
			}
		}
		if (playerAnswer == words[i])
		{
			cout << "Верно!" << endl;
		}
		else
		{
			cout << endl;
			cout << "Вы ошиблись!" << endl;
			cout << "Правильный ответ: " << words[i] << endl;
			cout << "Количество ваших жизней = " << --playerLives << endl;

			if (playerLives == 0)
			{
				cout << "К сожалению вы проиграли! У вас обязательно получится в следующий раз." << endl;
				break;
			}
		}
	}

	if (playerLives > 0)
	{
		cout << "\nВы победили! Поздравляем!" << endl;
	}
}

string generateQuestion(string* const word)
{
	string playerQuestion = *word;
	while (playerQuestion == *word)
	{
		random_shuffle(playerQuestion.begin(), playerQuestion.end());
	}
	return playerQuestion;
}

string generateHint(string* const word)
{
	string hint = *word;
	hint.erase(hint.length() / 2);
	return hint;
}

void useHint(short playerHints, string playerQuestion, string hint)
{
	cout << "Теперь количество ваших подсказок = " << --playerHints << endl << endl;
	cout << "Загаданное слово: " << playerQuestion << endl;
	cout << "Подсказка: " << hint << endl;
	cout << "Это слово: ";
}

