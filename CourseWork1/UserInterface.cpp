#include "UserInterface.h"

UserInterface::~UserInterface()
{
	for (int i = 0; i < puzzles.size(); i++)
		delete puzzles[i];
}

void UserInterface::programStart() 
{
	int option = readInOrCreateFile();

	if (option == 2) 
	{
		int puzzleCount = inputPuzzleCount();
		char method = inputGenerationMethod();
		generatePuzzles(puzzleCount, method);
		build15File(option);
	}
	else 
	{
		build15File(option);

		std::vector<Solution*> solutions;

		for (int i = 0; i < puzzles.size(); i++) 
		{
			ContinuousCalculator c(puzzles[i]);

			Solution* s = new Solution(puzzles[i], c.getContainer());
			solutions.push_back(s);
			printInfo(c.getContainer());
		}

		buildSolutionFile(solutions);
	}
}

void UserInterface::printInfo(ContinuousCount& result)
{
	std::cout << "\n\n FORMULA IMPLEMENTATION" << std::endl;
	std::cout << "Continuous rows: " << result.getContinuousRows() << std::endl;
	std::cout << "Reverse continuous rows: " << result.getReverseContinuousRows() << std::endl;
	std::cout << "Continuous columns: " << result.getContinuousColumns() << std::endl;
	std::cout << "Reverse continuous columns: " << result.getReverseContinuousColumns() << std::endl;

}

void UserInterface::build15File(int option)
{
	PuzzleFile file(puzzles, option);
}

void UserInterface::buildSolutionFile(std::vector<Solution*> solutions)
{
	SolutionFile file(solutions);

	for (int i = 0; i < solutions.size(); i++)
		delete solutions[i];
}

int UserInterface::readInOrCreateFile()
{
	std::cout << "Would you like to read in a 15-File, or create a new one?" << std::endl;
	std::cout << "Press 1 to read in or 2 to create new" << std::endl;

	int input = 0;

	std::cin >> input;
	while (input != 1 && input != 2)
	{
		std::cout << "Please enter a valid number" << std::endl;
		std::cin >> input;
	}

	return input;
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
	int arraySize = (puzzleDimension * puzzleDimension - 1); // -1 as we can ignore the empty space
	int* puzzleArray = new int[arraySize];
	//std::vector<int> numberPool;

	int amount = 20;
	if (puzzleDimension > 4)
		amount = (puzzleDimension * puzzleDimension) + 5;


	std::vector<bool> inserted;
	for (int i = 0; i <= amount; i++)
		inserted.push_back(false);

	Dist distribution(1, amount);

	for (int i = 0; i < arraySize; i++)
	{
		puzzleArray[i] = 0;
	}

	for (int i = 0; i < arraySize; i++) 
	{
		int randomNumber;
		do {
			randomNumber = distribution(generator);
		} while (inserted[randomNumber]);
		inserted[randomNumber] = true;
		puzzleArray[i] = randomNumber;
	}

	Puzzle* p = new Puzzle(puzzleArray, puzzleDimension);

	if (!uniquePuzzle(p)) {
		delete p;
		generatePuzzleRandomly(puzzleDimension);
	} else {
		std::cout << "Puzzle created" << std::endl;
		puzzles.push_back(p);
	}
}

bool UserInterface::uniquePuzzle(Puzzle* p)
{
	if (puzzles.size() == 0)
		return true;

	for (int i = 0; i < puzzles.size(); i++) 
	{
		for (int j = 0; j < puzzles[i]->getSize(); j++) 
		{
			if (puzzles[i]->getCopy()[j] == p->getCopy()[j])
				return false;
		}
	}

	int i = 0;

	return true;
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


// Whether or not the starting configuration is solvable
bool UserInterface::validPuzzle()
{
	return true;
}

bool UserInterface::validNumber(int x)
{
	if (x <= 0)
		return false;
}