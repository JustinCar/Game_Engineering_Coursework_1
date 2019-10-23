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
	unsigned long long calculateContinuous();
	unsigned long long calculatePartiallyContinuous(int constantValue);

	int continuousNumberCountEqualToDimension();
	int continuousNumberCountEqualToDimensionMinusOne();
	unsigned long long numberOfOccursions();
	unsigned long long numberOfOccursionsBottomRow();

	unsigned long long numberOfOccursionsPartial(int constantValue);
	unsigned long long numberOfOccursionsPartialBottomRow(int constantValue);
	int partialContinuousCount(int constantValue);

	// Functions for starting config
	int calculatePartialContinuousRowsStartingConfig(int constantValue);
	int calculatePartialContinuousColumnsStartingConfig(int constantValue);
	int checkForContinuousStartingConfig(int* arr, int constantValue);
	int checkForReverseStartingConfig(int* arr, int constantValue);
	int* flipArray(int* arr, int size);

	

	unsigned long long factorial(int n);

	ContinuousCount& getContainer() const;
};

