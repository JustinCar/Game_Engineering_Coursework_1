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

	int counter2 = 1;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			original[counter2] = grid[i][j];
			counter2++;
		}

	permutationCounter = 0;


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

int* Puzzle::getOriginal()
{
	int* arr = original;
	return arr;
}

void Puzzle::swap(int pos1, int pos2, int* arr)
{
	int temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

void Puzzle::printArray(int* arr)
{
	permutationCounter++;
	std::cout << permutationCounter << std::endl;
	std::cout << "\n\n" << std::endl;


	for (int i = 0; i < 7; i++) 
	{
		std::cout << arr[i] << std::endl;
	}
	
	std::cout << "\n\n\n\n" << std::endl;
}


void Puzzle::permutations(int k, int* arr)
{
	if (k == 1)
	{
		printArray(arr);
		//Finished
	}
	else
	{
		// Generate permutations with kth unaltered
		// Initially k == length(A)
		permutations(k - 1, arr);

		// Generate permutations for kth swapped with each k-1 initial
		for (int i = 0; i < k - 1; i++)
		{
			// Swap choice dependent on parity of k (even or odd)
			if ((k % 2) == 0)
			{
				swap(i, k - 1, arr); // zero-indexed, the kth is at k-1
			}
			else
			{
				swap(0, k - 1, arr);
			}

			permutations(k - 1, arr);
		}
	}
}

