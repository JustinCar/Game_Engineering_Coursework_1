#include "WritePuzzleFile.h"

WritePuzzleFile::WritePuzzleFile(std::vector<Puzzle*>& puzzles)
{
	writeToFile(puzzles);
}

void WritePuzzleFile::writeToFile(std::vector<Puzzle*>& puzzles)
{
	std::ofstream myfile;
	myfile.open("15-File.txt", std::ofstream::out | std::ofstream::trunc);
	myfile << puzzles.size();

	for (int i = 0; i < puzzles.size(); i++)
	{
		writePuzzle(*puzzles[i], myfile);
		myfile << "\n";
	}

	myfile.close();
}

void WritePuzzleFile::writePuzzle(Puzzle& puzzle, std::ofstream& myfile)
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