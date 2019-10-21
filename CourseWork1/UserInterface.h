#pragma once
#include <iostream>
#include "Puzzle.h"
#include <algorithm> 
#include "BruteForce.h"
#include <vector>
#include "PuzzleFile.h"
#include "ContinuousCalculator.h"
#include "ContinuousCount.h"
#include "Solution.h"
#include "SolutionFile.h"
#include <ctime>
#include <random>

class UserInterface
{
protected:
	std::vector<Puzzle*> puzzles;
	std::default_random_engine generator;
	using Dist = std::uniform_int_distribution<int>;

public:
	~UserInterface();
	void programStart();
	int readInOrCreateFile();
	void printInfo(ContinuousCount& result);
	void buildSolutionFile(std::vector<Solution*> solutions);

	int inputPuzzleCount();
	char inputGenerationMethod();
	int inputPuzzleDimension();
	void generatePuzzles(int puzzleCount, char generationMethod);
	void generatePuzzleManually(int puzzleDimension);
	void generatePuzzleRandomly(int puzzleDimension);
	void build15File(int option);

	bool uniqueNumberInPuzzle(int* puzzleArray, int arraySize, int number);
	bool validPuzzle(); // Check for parity, overlapping numbers, numbers within range
	bool validNumber(int x);
	bool uniquePuzzle(Puzzle* p);
};

