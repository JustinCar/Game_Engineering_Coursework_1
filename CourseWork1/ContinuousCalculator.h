#pragma once
#include "Puzzle.h"
#include <algorithm> 
#include <vector>
#include "ContinuousCount.h"

class ContinuousCalculator
{
protected:
	ContinuousCount* container;

	Puzzle* puzzle;

public:
	ContinuousCalculator(Puzzle* puzzleVal);

	int continuousNumberCountEqualToDimension();
	int continuousNumberCountEqualToDimensionMinusOne();

	int numberOfOccursions();
	int numberOfOccursionsBottomRow();

	int factorial(int n);

	ContinuousCount& getContainer() const;
};

