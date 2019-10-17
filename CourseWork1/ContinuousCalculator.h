#pragma once
#include "Puzzle.h"
#include <algorithm> 
#include <vector>

class ContinuousCalculator
{
protected:
	int continuousRows;
	int reverseContinuousRows;
	int continuousColumns;
	int reverseContinuousColumns;

	int topRowCount;// Test
	int middleRowCount;// Test
	int bottomRowCount;// Test

	Puzzle* puzzle;

public:
	ContinuousCalculator(Puzzle* puzzleVal);

	int continuousNumberCountEqualToDimension();
	int continuousNumberCountEqualToDimensionMinusOne();

	int numberOfOccursions();
	int numberOfOccursionsBottomRow();

	int factorial(int n);

	void printInfo();



	void printArray(); // Testing
};

