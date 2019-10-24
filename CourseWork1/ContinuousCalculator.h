#pragma once
#include "Puzzle.h"
#include <algorithm> 
#include <vector>
#include "ContinuousCount.h"
#include "Solution.h"
#include "InfInt.h"

/**
Author: Justin Carter
Student number: 160383867
Date: 24/10/2019
Given a puzzle, calculate the total continuous/reverse rows and columns
as well as the partially continuous/reverse rows and columns for both the starting configurations
and all valid permutations
*/
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

	InfInt continuousNumberCountEqualToDimension(); // Calculates the number of continuous sequences equal to row/column length in the puzzle when sorted
	InfInt continuousNumberCountEqualToDimensionMinusOne();
	InfInt numberOfOccursions(); // Calculates the number of times a single sequence could occur in all rows/columns except the row/column with the empty tile
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
private:

};

