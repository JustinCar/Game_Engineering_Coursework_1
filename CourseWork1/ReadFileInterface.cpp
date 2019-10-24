#include "ReadFileInterface.h"

void ReadFileInterface::run()
{
	read15File();

	std::vector<Solution*> solutions;

	bool includeEmpty = includeEmptyTileRowAndColumn();

	for (int i = 0; i < puzzles.size(); i++)
	{
		int a = 0;
		ContinuousCalculator c(puzzles[i], includeEmpty);

		Solution* s = new Solution(puzzles[i], c.getContainer());
		solutions.push_back(s);
		printInfo(c.getContainer());
	}

	int i = 0;

	buildSolutionFile(solutions);
}

bool ReadFileInterface::includeEmptyTileRowAndColumn()
{
	std::cout << "\nWould you like to include the empty tile's row & column? Enter y for yes or n for no" << std::endl;

	char input;
	std::cin >> input;
	while (input != 'y' && input != 'n')
	{
		std::cout << "Please enter a valid letter" << std::endl;
		std::cin >> input;
	}

	if (input == 'n')
		return false;
	else 
	{
		return true;
	}
}

void ReadFileInterface::printInfo(ContinuousCount& result)
{
	std::cout << "\n\n FORMULA IMPLEMENTATION" << std::endl;
	std::cout << "Continuous rows: " << result.getContinuousRows() << std::endl;
	std::cout << "Reverse continuous rows: " << result.getReverseContinuousRows() << std::endl;
	std::cout << "Continuous columns: " << result.getContinuousColumns() << std::endl;
	std::cout << "Reverse continuous columns: " << result.getReverseContinuousColumns() << std::endl;

}

void ReadFileInterface::read15File()
{
	ReadPuzzleFile file(puzzles);
}

void ReadFileInterface::buildSolutionFile(std::vector<Solution*> solutions)
{
	SolutionFile file(solutions);

	for (int i = 0; i < solutions.size(); i++)
		delete solutions[i];
}

// Whether or not the starting configuration is solvable
bool ReadFileInterface::validPuzzle()
{
	return true;
}