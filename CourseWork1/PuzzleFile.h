#pragma once
#include "Puzzle.h"
#include <vector>
#include <iostream>
#include <fstream>

class PuzzleFile
{
protected:

public:
	PuzzleFile(std::vector<Puzzle*> puzzles);

	void writePuzzle(Puzzle* puzzle, std::ofstream* myfile);
};

