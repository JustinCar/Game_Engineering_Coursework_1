#pragma once
#include "Puzzle.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string> 
#include <sstream> 
#include <cmath>

class PuzzleFile
{
protected:

public:
	PuzzleFile(std::vector<Puzzle*>& puzzles, int option);

	void writeToFile(std::vector<Puzzle*>& puzzles);
	void writePuzzle(Puzzle& puzzle, std::ofstream& myfile);
	void processLine(std::vector<int>& puzzleNumbers, std::string line);

	void readFile(std::vector<Puzzle*>& puzzles);
	bool readPuzzle(std::vector<Puzzle*>& puzzles, std::ifstream& myfile);
};

