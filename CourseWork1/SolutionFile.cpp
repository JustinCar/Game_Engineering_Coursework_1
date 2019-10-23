#include "SolutionFile.h"

SolutionFile::SolutionFile(std::vector<Solution*>& solutionsVal) : solutions(solutionsVal)
{
	writeToFile();
}

void SolutionFile::writeToFile()
{
	std::ofstream myfile;
	myfile.open("Solution-File.txt", std::ofstream::out | std::ofstream::trunc);
	myfile << solutions.size();

	for (int i = 0; i < solutions.size(); i++)
	{
		writePuzzle(*solutions[i]->getPuzzle(), myfile);
		writeSolution(solutions[i]->getSolution(), myfile);
		myfile << "\n";
	}

	myfile.close();
}

void SolutionFile::writeSolution(ContinuousCount& solution, std::ofstream& myfile)
{
	myfile << "\n";
	myfile << "row = " << solution.getContinuousRows() << "\n";
	myfile << "column = " << solution.getContinuousColumns() << "\n";
	myfile << "reverse row = " << solution.getReverseContinuousRows() << "\n";
	myfile << "reverse column = " << solution.getReverseContinuousColumns() << "\n";
	myfile << "(total for row & column, including reverse, in this configuration)" << "\n";
	myfile << "2 = " << solution.getTotal2PartialForStartingConfig() << "\n";
	myfile << "3 = " << solution.getTotal3PartialForStartingConfig() << "\n";
	myfile << "4 = " << solution.getTotal4PartialForStartingConfig() << "\n";

	myfile << "(total for row & column, including reverse, for all valid turns)" << "\n";
	myfile << "2 = " << solution.getTotal2PartialForAll() << "\n";
	myfile << "3 = " << solution.getTotal3PartialForAll() << "\n";
	myfile << "4 = " << solution.getTotal4PartialForAll() << "\n";
}

void SolutionFile::writePuzzle(Puzzle& puzzle, std::ofstream& myfile)
{
	int size = puzzle.getSize();
	int rowCounter = 0;
	myfile << "\n";

	for (int j = 0; j < size; j++)
	{
		if (rowCounter == puzzle.getDimensions())
		{
			rowCounter = 0;
			myfile << "\n";
		}

		myfile << puzzle.getOriginal()[j] << " ";

		rowCounter++;
	}
}