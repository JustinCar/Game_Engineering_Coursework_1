#pragma once
#include "UserInterface.h"
#include "BruteForce.h"
#include <vector>

class ReadFileInterface : public UserInterface
{
public:
	void run();
	void read15File();
	void buildSolutionFile(std::vector<Solution*> solutions);
	bool includeEmptyTileRowAndColumn();
	bool useBruteForce();
	bool useBruteForceForAll();
	bool useFormulaForAll();
	void startBruteForceThread(BruteForce* job);
	void startFormulaThread(ContinuousCalculator* job);
};

