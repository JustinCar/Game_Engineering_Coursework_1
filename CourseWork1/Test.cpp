#include "Puzzle.h"



int main() 
{
	Puzzle p;

	int** arr = p.getGrid();

	int testArray[7]{ 1, 2, 3, 4, 5, 6, 7};

	int* pointer = testArray;
	p.permutations(7, pointer);

	//for (int i = 0; i < 4; i++)
	//	for (int j = 0; j < 4; j++)
	//	{
	//		std::cout << arr[i][j] << std::endl;
	//	}



	std::cin.get();
	return 0;
}