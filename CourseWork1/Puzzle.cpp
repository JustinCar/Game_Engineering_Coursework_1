#include "Puzzle.h"

Puzzle::Puzzle()
{
	grid = new int* [4];

	for (int i = 0; i < 4; i++)
		grid[i] = new int[4];


	int counter = 1;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			grid[i][j] = counter;
			counter++;
		}
			

}

Puzzle::~Puzzle()
{
	for (int i = 0; i < 4; i++)
		delete[] grid[i];

	delete[] grid;
}

int** Puzzle::getGrid()
{
	return grid;
}