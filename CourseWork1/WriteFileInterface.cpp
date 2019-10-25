#include "WriteFileInterface.h"

void WriteFileInterface::run()
{
	int puzzleCount = inputPuzzleCount();
	char method = inputGenerationMethod();
	generatePuzzles(puzzleCount, method);
	write15File();
}

void WriteFileInterface::write15File()
{
	WritePuzzleFile file(puzzles);
}

void WriteFileInterface::generatePuzzles(int puzzleCount, char generationMethod)
{
	if (generationMethod == 'r' && ((puzzleCount > 1) && generateAllPuzzleAtOnce()))
	{
		std::cout << "Creation of puzzles all at once confirmed" << std::endl;
		int dimensions = inputPuzzleDimension();

		for (int i = 0; i < puzzleCount; i++)
		{
			generatePuzzleRandomly(dimensions);
		}
	}
	else 
	{
		if (puzzleCount > 1)
		{
			std::cout << "Creation of puzzles individually confirmed" << std::endl;
		}
		
		for (int i = 0; i < puzzleCount; i++)
		{
			int dimensions = inputPuzzleDimension();

			if (generationMethod == 'r')
				generatePuzzleRandomly(dimensions);
			else
				generatePuzzleManually(dimensions);
		}
	}
}

bool WriteFileInterface::generateAllPuzzleAtOnce() 
{
	std::cout << "\nWould you like to generate each puzzle individually or all at once?" << std::endl;
	std::cout << "input 1 for individually or 2 for all at once" << std::endl;

	int num = 0;

	std::cin >> num;
	while (num !=1 && num != 2)
	{
		std::cout << "Please enter a valid number" << std::endl;
		std::cin >> num;
	}

	if (num == 1)
		return false;
	else
		return true;
}

int WriteFileInterface::inputPuzzleDimension()
{
	std::cout << "\nWhat are the dimensions of the puzzle?" << std::endl;
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

int WriteFileInterface::inputPuzzleCount()
{
	std::cout << "\nHow many puzzles would you like to create? " << std::endl;

	int puzzleCount = 0;

	std::cin >> puzzleCount;
	while (!validNumber(puzzleCount))
	{
		std::cout << "Please enter a valid number" << std::endl;
		std::cin.clear();
		std::cin >> puzzleCount;
	}

	std::cout << "Creation of " << puzzleCount << " puzzles confirmed" << std::endl;

	return puzzleCount;
}

char WriteFileInterface::inputGenerationMethod()
{
	std::cout << "\nHow would you like to generate these puzzles?" << std::endl;
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

bool WriteFileInterface::uniqueNumberInPuzzle(int* puzzleArray, int arraySize, int number)
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

void WriteFileInterface::generatePuzzleRandomly(int puzzleDimension)
{
	int arraySize = (puzzleDimension * puzzleDimension - 1); // -1 as we can ignore the empty space
	int* puzzleArray = new int[arraySize];

	int amount = 20;
	if (puzzleDimension > 4)
		amount = (puzzleDimension * puzzleDimension) + 5;

	std::vector<int> numberPool;

	for (int i = 1; i < amount; i++)
	{
		numberPool.push_back(i);
	}

	for (int i = 0; i < arraySize; i++)
	{
		puzzleArray[i] = 0;
	}

	for (int i = 0; i < arraySize; i++)
	{

		Dist distribution(0, numberPool.size() - 1);

		int randomIndex = distribution(generator);
		int number = numberPool[randomIndex]; // Random number between one an twenty
		numberPool.erase(numberPool.begin() + randomIndex);
		puzzleArray[i] = number;
	}

	Puzzle* p = new Puzzle(puzzleArray, puzzleDimension);

	if (!uniquePuzzle(p)) 
	{
		delete p;
		generatePuzzleRandomly(puzzleDimension);
	}
	else {
		std::cout << "Puzzle created" << std::endl;
		puzzles.push_back(p);
	}
}

bool WriteFileInterface::uniquePuzzle(Puzzle* p)
{
	if (puzzles.size() == 0)
		return true;

	for (int i = 0; i < puzzles.size(); i++)
	{
		if (puzzles[i] == p)
			return false;
	}

	return true;
}

void WriteFileInterface::generatePuzzleManually(int puzzleDimension)
{
	int arraySize = (puzzleDimension * puzzleDimension) - 1; // -1 as we can ignore the empty space
	int* puzzleArray = new int[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		puzzleArray[i] = 0;
	}

	std::cout << "\nEnter each number starting from the top left tile, progressing from left to right" << std::endl;

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

bool WriteFileInterface::validNumber(int x)
{
	if (x <= 2 || x == INT_MAX)
		return false;
}