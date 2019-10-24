#pragma once
#include "Puzzle.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string> 
#include <sstream> 

class ReadPuzzleFile
{
protected:
	std::string fileName;
public:
	ReadPuzzleFile(std::vector<Puzzle*>& puzzles);

	void processLine(std::vector<int>& puzzleNumbers, std::string line);
	void readFile(std::vector<Puzzle*>& puzzles);
	bool readPuzzle(std::vector<Puzzle*>& puzzles, std::ifstream& myfile);
	bool validFileName(std::string name);
};

