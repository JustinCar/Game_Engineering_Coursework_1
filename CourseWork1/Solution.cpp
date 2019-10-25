#include "Solution.h"

Solution::Solution(Puzzle* puzzleVal, ContinuousCount& solutionVal) : puzzle(puzzleVal), solution(solutionVal)
{
}

Solution::~Solution()
{
	delete &solution;
}

Puzzle* Solution::getPuzzle() const 
{
	return puzzle;
}

ContinuousCount& Solution::getSolution() const 
{
	return solution;
}
