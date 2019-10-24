#pragma once
#include "Puzzle.h"
#include <algorithm> 
#include "ContinuousCount.h"

/**
Author: Justin Carter
Student number: 160383867
Date: 24/10/2019
Iterate through all possible permutations of a set, 
check each permutation for 15 puzzle validity and then count 
the number of continuous/reverse rows and columns as well as 
partially continuous/reverse rows and columns.
*/
class BruteForce
{
protected:
	int continuousRows;
	int reverseContinuousRows;
	int continuousColumns;
	int reverseContinuousColumns;

	int numberOfTwoPartialStartingConfig;
	int numberOfThreePartialStartingConfig;
	int numberOfFourPartialStartingConfig;
	int totalNumberOfTwoPartial;
	int totalNumberOfThreePartial;
	int totalNumberOfFourPartial;

	ContinuousCount* container;
	Puzzle* puzzle;

public:
	BruteForce(Puzzle* puzzleVal);
	void run();
	ContinuousCount& getContainer() const;

private:
	bool isLegalPermutation();
	void permutations(int k);
	void swap(int pos1, int pos2);
	void calculateContinuousRows();
	void calculateContinuousColumns();
	bool checkForContinuous(int* arr);
	bool checkForReverse(int* arr);

	int calculatePartialContinuousRows(int constantValue);
	int calculatePartialContinuousColumns(int constantValue);
	int checkForContinuous(int* arr, int constantValue);
	int* flipArray(int* arr, int size);
};

