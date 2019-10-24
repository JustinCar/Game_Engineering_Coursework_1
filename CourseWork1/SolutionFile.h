#pragma once
#include "Puzzle.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string> 
#include <sstream> 
#include <cmath>
#include "Solution.h"
#include "Windows.h"

/**
Author: Justin Carter
Student number: 160383867
Date: 24/10/2019
Takes in a vector of solutions and outputs the
data in valid format to Solution-File
*/
class SolutionFile
{
protected:
	std::vector<Solution*>& solutions;
	std::string fileName;

public:
	SolutionFile(std::vector<Solution*>& solutionsVal);

	void writeToFile();
	void writePuzzle(Puzzle& puzzle, std::ofstream& myfile);
	void writeSolution(ContinuousCount& solution, std::ofstream& myfile);
	bool validFileName(std::string name);
	bool puzzleFileCreated();
	bool solutionFileCreated();

};


