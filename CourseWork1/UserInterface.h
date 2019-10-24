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
#include <thread>

/**
Author: Justin Carter
Student number: 160383867
Date: 24/10/2019
Base class for both write and read subclasses.
Six threads are created when the object is created.
*/
class UserInterface
{
protected:
	std::vector<Puzzle*> puzzles;
	std::default_random_engine generator;
	using Dist = std::uniform_int_distribution<int>;
	std::thread threads[6];

public:
	UserInterface();
	~UserInterface();
	virtual void run();
};

