#include "Puzzle.h"
#include <iostream>



int main() 
{
	Puzzle p;

	int** arr = p.getGrid();

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			std::cout << arr[i][j] << std::endl;
		}



	std::cin.get();
	return 0;
}