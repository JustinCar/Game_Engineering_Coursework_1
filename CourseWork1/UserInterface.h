#pragma once
#include <iostream>
#include "Puzzle.h"
#include <algorithm> 
#include "BruteForce.h"
#include <vector>
#include "ContinuousCalculator.h"
#include "ContinuousCount.h"
#include "Solution.h"
#include "SolutionFile.h"
#include <ctime>
#include <random>
#include "WritePuzzleFile.h"
#include "ReadPuzzleFile.h"

class UserInterface
{
protected:
	std::vector<Puzzle*> puzzles;
	std::default_random_engine generator;
	using Dist = std::uniform_int_distribution<int>;

public:
	UserInterface();
	~UserInterface();
	virtual void run();
};

