#pragma once
#include "UserInterface.h"

class ReadFileInterface : public UserInterface
{
public:
	void run();
	void read15File();
	bool validPuzzle(); // Check for parity, overlapping numbers, numbers within range
	void printInfo(ContinuousCount& result);
	void buildSolutionFile(std::vector<Solution*> solutions);
};

