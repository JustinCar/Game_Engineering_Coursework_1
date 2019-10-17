#pragma once
#include <iostream>
#include "Puzzle.h"
#include <algorithm> 
#include "BruteForce.h"
#include <vector>
#include "PuzzleFile.h"

class UserInterface
{
protected:
	std::vector<BruteForce*> jobs;
	std::vector<Puzzle*> puzzles;

public:
	~UserInterface();
	void programStart();
	int inputPuzzleCount();
	char inputGenerationMethod();
	int inputPuzzleDimension();
	void generatePuzzles(int puzzleCount, char generationMethod);


	void generatePuzzleManually(int puzzleDimension);
	void generatePuzzleRandomly(int puzzleDimension);
	void build15File();

	bool uniqueNumberInPuzzle(int* puzzleArray, int arraySize, int number);
	bool validPuzzle(); // Check for parity, overlapping numbers, numbers within range
	bool validNumber(int x);


	void doJobs(); // Do each job on a different thread?
};
