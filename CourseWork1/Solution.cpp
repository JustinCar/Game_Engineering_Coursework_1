#include "Solution.h"

Solution::Solution(Puzzle* puzzleVal, ContinuousCount& solutionVal) : puzzle(puzzleVal), solution(solutionVal)
{
}

Puzzle* Solution::getPuzzle() const 
{
	return puzzle;
}

ContinuousCount& Solution::getSolution() const 
{
	return solution;
}
