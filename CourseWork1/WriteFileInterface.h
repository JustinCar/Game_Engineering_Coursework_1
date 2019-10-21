#pragma once
#include "UserInterface.h"

class WriteFileInterface : public UserInterface
{

public:

	virtual void run();

	int inputPuzzleCount();
	char inputGenerationMethod();
	int inputPuzzleDimension();
	void generatePuzzles(int puzzleCount, char generationMethod);
	void generatePuzzleManually(int puzzleDimension);
	void generatePuzzleRandomly(int puzzleDimension);

	void write15File();

	bool uniqueNumberInPuzzle(int* puzzleArray, int arraySize, int number);
	bool validPuzzle(); // Check for parity, overlapping numbers, numbers within range
	bool validNumber(int x);
	bool uniquePuzzle(Puzzle* p);
};

