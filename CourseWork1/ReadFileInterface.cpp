#include "ReadFileInterface.h"

void ReadFileInterface::run()
{
	read15File();

	std::vector<Solution*> solutions;

	bool includeEmpty = includeEmptyTileRowAndColumn();

	bool bruteForceAll = useBruteForceForAll();

	for (int i = 0; i < puzzles.size(); i++)
	{
		if (bruteForceAll && puzzles[i]->getDimensions() <= 3 ||
			(puzzles[i]->getDimensions() <= 3 && useBruteForce())
			)
		{
			BruteForce b(puzzles[i]);
			Solution* s = new Solution(puzzles[i], b.getContainer());
			solutions.push_back(s);
			printInfo(b.getContainer());
		}
		else 
		{
			ContinuousCalculator c(puzzles[i], includeEmpty);

			Solution* s = new Solution(puzzles[i], c.getContainer());
			solutions.push_back(s);
			printInfo(c.getContainer());
		}
	}

	buildSolutionFile(solutions);
}

bool ReadFileInterface::useBruteForceForAll()
{
	std::cout << "\nWould you like to use the bruteforce algorithm for all puzzles (Where possible)?" << std::endl;
	std::cout << "Enter y for yes or n for no" << std::endl;

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

bool ReadFileInterface::useBruteForce()
{
	std::cout << "\nWould you like to use the bruteforce algorithm or the formula for this puzzle?" << std::endl;
	std::cout << "Enter b for bruteforce or f for formula (bruteforce takes much longer)" << std::endl;

	char input;
	std::cin >> input;
	while (input != 'b' && input != 'f')
	{
		std::cout << "Please enter a valid letter" << std::endl;
		std::cin >> input;
	}

	if (input == 'f')
		return false;
	else
	{
		return true;
	}
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