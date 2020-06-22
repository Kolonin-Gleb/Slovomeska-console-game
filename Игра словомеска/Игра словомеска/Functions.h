#pragma once

#include <iostream>
#include <algorithm>

#include "Array functions.h"


using namespace std;

string enterAction();

void showGameRules();

void startLevel();

string generateQuestion(string * const word);

string generateHint(string* const word);

void useHint(short playerHints, string playerQuestion, string hint);

