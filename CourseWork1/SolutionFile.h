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


