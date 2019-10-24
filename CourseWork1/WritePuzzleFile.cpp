#include "WritePuzzleFile.h"

WritePuzzleFile::WritePuzzleFile(std::vector<Puzzle*>& puzzles) : fileName("15-File.txt")
{
	writeToFile(puzzles);
}

void WritePuzzleFile::writeToFile(std::vector<Puzzle*>& puzzles)
{
	if (!validFileName(fileName))
	{
		std::cout << "File name contains invalid characters";
		return;
	}

	std::ofstream myfile;
	myfile.open(fileName, std::ofstream::out | std::ofstream::trunc);
	
	if (!myfile)
	{
		std::cout << "Unable to find/open 15-file";
		return;
	}

	myfile << puzzles.size();

	for (int i = 0; i < puzzles.size(); i++)
	{
		writePuzzle(*puzzles[i], myfile);
		myfile << "\n";
	}

	myfile.close();
}

bool WritePuzzleFile::validFileName(std::string name)
{
	if (name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890-. ") != std::string::npos)
		return false;

	return true;
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