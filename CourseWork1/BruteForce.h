#pragma once
#include "Puzzle.h"
#include <algorithm> 
#include "ContinuousCount.h"

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

	bool isLegalPermutation();
	void printInfo();
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

	ContinuousCount& getContainer() const;
};

