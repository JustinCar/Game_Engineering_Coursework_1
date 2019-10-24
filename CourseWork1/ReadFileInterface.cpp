#include "ReadFileInterface.h"

void ReadFileInterface::startBruteForceThread(BruteForce* job)
{
	job->run();
}

void ReadFileInterface::startFormulaThread(ContinuousCalculator* job)
{
	job->run();
}

void ReadFileInterface::run()
{
	read15File();

	std::vector<Solution*> solutions;

	bool includeEmpty = includeEmptyTileRowAndColumn();

	bool bruteForceAll = useBruteForceForAll();

	bool formulaAll = false;

	if (!bruteForceAll)
		formulaAll = useFormulaForAll();

	for (int i = 0; i < puzzles.size(); i += 6)
	{
		std::vector<ContinuousCalculator*> formulaVector(6);
		std::vector<BruteForce*> bruteVector(6);
	
		for (int j = 0; j < 6; j++) 
		{
			int index = i + j;

			if (index >= puzzles.size())
				break;

			if (!formulaAll &&
				(bruteForceAll && puzzles[index]->getDimensions() <= 3 ||
				(puzzles[index]->getDimensions() <= 3 && useBruteForce()))
				)
			{
				BruteForce* b = new BruteForce(puzzles[index]);
				threads[j] = std::thread([b, this] {startBruteForceThread(b); });

				bruteVector[j] = b;
			}
			else 
			{
				ContinuousCalculator* c = new ContinuousCalculator(puzzles[index], includeEmpty);
				threads[j] = std::thread([c, this] {startFormulaThread(c); });

				formulaVector[j] = c;
			}
		}

		for (int k = 0; k < 6; k++) 
		{
			if (k + i >= puzzles.size())
				break;

			threads[k].join();
		}

		for (int k = 0; k < 6; k++)
		{
			if (k + i >= puzzles.size())
				break;

			Solution* s;
			if (bruteVector[k]) 
			{
				s = new Solution(puzzles[i + k], bruteVector[k]->getContainer());
			}
			else
			{
				s = new Solution(puzzles[i + k], formulaVector[k]->getContainer());
			}

			solutions.push_back(s);
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

bool ReadFileInterface::useFormulaForAll()
{
	std::cout << "\nWould you like to use the formula for all puzzles?" << std::endl;
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