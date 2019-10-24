#pragma once
#include "UserInterface.h"

/**
Author: Justin Carter
Student number: 160383867
Date: 24/10/2019
User interface for writing puzzles to the 15-File
*/
class WriteFileInterface : public UserInterface
{

public:
	virtual void run();

private:
	int inputPuzzleCount();
	char inputGenerationMethod();
	int inputPuzzleDimension();
	void generatePuzzles(int puzzleCount, char generationMethod);
	void generatePuzzleManually(int puzzleDimension);
	void generatePuzzleRandomly(int puzzleDimension);
	bool generateAllPuzzleAtOnce();

	void write15File();

	bool uniqueNumberInPuzzle(int* puzzleArray, int arraySize, int number);
	bool validNumber(int x);
	bool uniquePuzzle(Puzzle* p);
};

