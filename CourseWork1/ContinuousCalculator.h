#pragma once
#include "Puzzle.h"
#include <algorithm> 
#include <vector>
#include "ContinuousCount.h"
#include "Solution.h"
#include "InfInt.h"

class ContinuousCalculator
{
protected:
	ContinuousCount* container;
	Puzzle* puzzle;
	bool includeEmpty;

public:
	ContinuousCalculator(Puzzle* puzzleVal, bool includeEmptyVal);

	void run();

	InfInt calculateContinuous();
	InfInt calculatePartiallyContinuous(int constantValue);

	InfInt continuousNumberCountEqualToDimension();
	InfInt continuousNumberCountEqualToDimensionMinusOne();
	InfInt numberOfOccursions();
	InfInt numberOfOccursionsBottomRow();

	InfInt numberOfOccursionsPartial(int constantValue);
	InfInt numberOfOccursionsPartialBottomRow(int constantValue);
	InfInt partialContinuousCount(int constantValue);

	// Functions for starting config
	InfInt calculatePartialContinuousRowsStartingConfig(int constantValue);
	InfInt calculatePartialContinuousColumnsStartingConfig(int constantValue);
	InfInt checkForContinuousStartingConfig(int* arr, int constantValue);
	int* flipArray(int* arr, int size);

	InfInt factorial(InfInt n);

	ContinuousCount& getContainer() const;
};

