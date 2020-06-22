#include "Array functions.h"

void randomizeArray(string array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		swap(array[i], array[rand() % size]);
	}
}

