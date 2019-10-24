#pragma once
#include "UserInterface.h"
#include "BruteForce.h"

class ReadFileInterface : public UserInterface
{
public:
	void run();
	void read15File();
	bool validPuzzle(); // Check for parity, overlapping numbers, numbers within range
	void printInfo(ContinuousCount& result, bool usedFormula);
	void buildSolutionFile(std::vector<Solution*> solutions);
	bool includeEmptyTileRowAndColumn();
	bool useBruteForce();
	bool useBruteForceForAll();
	bool useFormulaForAll();
};

