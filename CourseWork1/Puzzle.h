#pragma once
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <iostream>

class Puzzle
{
protected:
	int** grid;
	int original[16];




	int permutationCounter; // Test
	//enum Direction { up, down, left, right };
	//std::vector<std::vector<Direction>> previousTurns;
public:
	Puzzle();
	~Puzzle();

	int** getGrid();
	int* getOriginal();
	void permutations(int k, int* arr);
	void swap(int pos1, int pos2, int* arr);



	void printArray(int* arr); // Testing

};

