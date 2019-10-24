#pragma once
#include "UserInterface.h"
#include "BruteForce.h"
#include <vector>

/**
Author: Justin Carter
Student number: 160383867
Date: 24/10/2019
User interface for read a 15-File and outputting a Solution_File
*/
class ReadFileInterface : public UserInterface
{
public:
	void run();
	
private:
	void read15File();
	void buildSolutionFile(std::vector<Solution*> solutions);
	bool includeEmptyTileRowAndColumn();
	bool useBruteForce();
	bool useBruteForceForAll();
	bool useFormulaForAll();
	void startBruteForceThread(BruteForce* job);
	void startFormulaThread(ContinuousCalculator* job);
};

