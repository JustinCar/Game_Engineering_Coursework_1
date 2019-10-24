#pragma once
#include "Puzzle.h"
#include <vector>
#include <iostream>
#include <fstream>

/**
Author: Justin Carter
Student number: 160383867
Date: 24/10/2019
Takes the puzzles which are stored in a vector, and outputs
them in valid format to the 15-File
*/
class WritePuzzleFile
{
protected:
	std::string fileName;
public:
	WritePuzzleFile(std::vector<Puzzle*>& puzzles);

	void writeToFile(std::vector<Puzzle*>& puzzles);
	void writePuzzle(Puzzle& puzzle, std::ofstream& myfile);
	bool validFileName(std::string name);
	bool puzzleFileCreated();
};
