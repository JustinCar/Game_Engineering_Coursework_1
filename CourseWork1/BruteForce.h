#pragma once
#include <iostream>
#include "Puzzle.h"
class BruteForce
{
protected:
	int permutationCounter; // Test
	int continuousRows;
	int reverseContinuousRows;
	int continuousColumns;
	int reverseContinuousColumns;

	Puzzle* puzzle;

public:
	BruteForce(Puzzle* puzzleVal);

	bool isLegalPermutation();
	void printInfo();
	void permutations(int k);
	void swap(int pos1, int pos2);
	void calculateContinuousRows();
	void calculateContinuousColumns();
	bool checkForContinuous(int* arr);
	bool checkForReverse(int* arr);



	void printArray(); // Testing
};

