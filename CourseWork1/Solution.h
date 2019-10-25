#pragma once
#include "Puzzle.h"
#include <vector>
#include "ContinuousCount.h"

/**
Author: Justin Carter
Student number: 160383867
Date: 24/10/2019
Container for a puzzle and its solution.
A vector of solutions is sent to class SolutionFile 
to allow easy output to Solution-File
*/
class Solution
{
protected:
	Puzzle* puzzle;
	ContinuousCount& solution;

public:
	Solution(Puzzle* puzzleVal, ContinuousCount& solutionVal);
	~Solution();

	Puzzle* getPuzzle() const;
	ContinuousCount& getSolution() const;
};

