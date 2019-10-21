#pragma once
#include "Puzzle.h"
#include <vector>
#include <iostream>
#include <fstream>

class WritePuzzleFile
{
protected:

public:
	WritePuzzleFile(std::vector<Puzzle*>& puzzles);

	void writeToFile(std::vector<Puzzle*>& puzzles);
	void writePuzzle(Puzzle& puzzle, std::ofstream& myfile);
};
