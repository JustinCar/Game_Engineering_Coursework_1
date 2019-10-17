#include "UserInterface.h"

UserInterface::~UserInterface()
{
	for (int i = 0; i < puzzles.size(); i++)
		delete puzzles[i];

	for (int i = 0; i < jobs.size(); i++)
		delete jobs[i];
}

void UserInterface::programStart() 
{
	int puzzleCount = inputPuzzleCount();
	char method = inputGenerationMethod();

	generatePuzzles(puzzleCount, method);

	build15File();
}

void UserInterface::generatePuzzles(int puzzleCount, char generationMethod) 
{
	for (int i = 0; i < puzzleCount; i++)
	{
		int dimensions = inputPuzzleDimension();

		if (generationMethod == 'r')
			generatePuzzleRandomly(dimensions);
		else
			generatePuzzleManually(dimensions);
	}
}

int UserInterface::inputPuzzleDimension()
{
	std::cout << "What are the dimensions of the puzzle?" << std::endl;
	std::cout << "input 3 for 3x3, 4 for 4x4, 5 for 5x5 etc" << std::endl;

	int dimensions = 0;

	std::cin >> dimensions;
	while (!validNumber(dimensions))
	{
		std::cout << "Please enter a valid number" << std::endl;
		std::cin >> dimensions;
	}

	std::cout << "Creation of a " << dimensions << "x" << dimensions << " puzzle confirmed" << std::endl;

	return dimensions;
}

int UserInterface::inputPuzzleCount()
{
	std::cout << "How many puzzles would you like to create? " << std::endl;

	int puzzleCount = 0;

	std::cin >> puzzleCount;
	while (!validNumber(puzzleCount))
	{
		std::cout << "Please enter a valid number" << std::endl;
		std::cin >> puzzleCount;
	}

	std::cout << "Creation of " << puzzleCount << " puzzles confirmed" << std::endl;

	return puzzleCount;
}

char UserInterface::inputGenerationMethod()
{
	std::cout << "How would you like to generate these puzzles? \n" << std::endl;
	std::cout << "Enter r for randomly or m for manually" << std::endl;

	char generationMethod;
	std::cin >> generationMethod;
	while (generationMethod != 'r' && generationMethod != 'm')
	{
		std::cout << "Please enter a valid letter" << std::endl;
		std::cin >> generationMethod;
	}

	if (generationMethod == 'r')
		std::cout << "Creation of puzzles randomly confirmed" << std::endl;
	else
		std::cout << "Creation of puzzles manually confirmed" << std::endl;

	return generationMethod;

}

bool UserInterface::uniqueNumberInPuzzle(int* puzzleArray, int arraySize, int number)
{
	for (int i = 0; i < arraySize; i++)
	{
		if (puzzleArray[i] == number)
		{
			return false;
		}
	}
	return true;
}

void UserInterface::generatePuzzleRandomly(int puzzleDimension)
{
	int arraySize = (puzzleDimension * puzzleDimension) - 1; // -1 as we can ignore the empty space
	int* puzzleArray = new int[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		puzzleArray[i] = 0;
	}

	for (int i = 0; i < arraySize; i++) 
	{
		int number = rand() % 20 + 1; // Random number between one an twenty

		while (!uniqueNumberInPuzzle(puzzleArray, arraySize, number))
		{
			int number = rand() % 20 + 1;
		}

		puzzleArray[i] = number;
	}

	std::cout << "Puzzle created" << std::endl;

	Puzzle* p = new Puzzle(puzzleArray, puzzleDimension);
	puzzles.push_back(p);
}

void UserInterface::generatePuzzleManually(int puzzleDimension)
{
	int arraySize = (puzzleDimension * puzzleDimension) - 1; // -1 as we can ignore the empty space
	int* puzzleArray = new int[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		puzzleArray[i] = 0;
	}

	std::cout << "Enter each number starting from the top left tile, progressing from left to right" << std::endl;

	for (int i = 0; i < arraySize; i++)
	{
		std::cout << "Enter number " << i << std::endl;

		int number = 0;

		std::cin >> number;
		while (!uniqueNumberInPuzzle(puzzleArray, arraySize, number))
		{
			std::cout << "Number already present in puzzle" << std::endl;
			std::cout << "Please enter a unique number" << std::endl;
			std::cin >> number;
		}

		puzzleArray[i] = number;
	}

	std::cout << "Puzzle created" << std::endl;

	Puzzle* p = new Puzzle(puzzleArray, puzzleDimension);
	puzzles.push_back(p);
}

void UserInterface::build15File()
{
	PuzzleFile file(puzzles);
}

bool UserInterface::validPuzzle()
{
	return true;
}

bool UserInterface::validNumber(int x)
{
	if (x <= 0)
		return false;
}

void UserInterface::doJobs()
{

}