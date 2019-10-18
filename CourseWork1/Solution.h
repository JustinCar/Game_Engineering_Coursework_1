#pragma once
#include "Puzzle.h"
#include <vector>
#include "ContinuousCount.h"

class Solution
{
protected:
	Puzzle* puzzle;
	ContinuousCount& solution;

public:
	Solution(Puzzle* puzzleVal, ContinuousCount& solutionVal);

	Puzzle* getPuzzle() const;
	ContinuousCount& getSolution() const;
};

