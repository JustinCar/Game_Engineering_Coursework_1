#pragma once
#include "Puzzle.h"
#include <algorithm> 
#include <vector>
#include "ContinuousCount.h"
#include "Solution.h"

class ContinuousCalculator
{
protected:
	ContinuousCount* container;

	Puzzle* puzzle;

public:
	ContinuousCalculator(Puzzle* puzzleVal);

	int continuousNumberCountEqualToDimension();
	int continuousNumberCountEqualToDimensionMinusOne();

	int numberOfOccursionsPartial(int constantValue);
	int numberOfOccursionsPartialBottomRow(int constantValue);
	int partialContinuousCount(int constantValue, bool startingConfig);

	int numberOfOccursions();
	int numberOfOccursionsBottomRow();

	int factorial(int n);

	ContinuousCount& getContainer() const;
};

