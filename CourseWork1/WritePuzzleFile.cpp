#include "WritePuzzleFile.h"

WritePuzzleFile::WritePuzzleFile(std::vector<Puzzle*>& puzzles) : fileName("15-File.txt")
{
	do
		writeToFile(puzzles);
	while (!puzzleFileCreated());
}

bool WritePuzzleFile::puzzleFileCreated()
{
	std::ofstream myfile;
	myfile.open(fileName, std::ifstream::in);

	if (!myfile)
	{
		std::cout << "15-File creation failed, tring again" << std::endl;
		myfile.close();
		return false;
	}
	else 
	{
		std::cout << "15-File created successfully" << std::endl;
		myfile.close();
		return true;
	}
}

void WritePuzzleFile::writeToFile(std::vector<Puzzle*>& puzzles)
{
	if (!validFileName(fileName))
	{
		std::cout << "File name contains invalid characters" << std::endl;
		return;
	}

	std::ofstream myfile;
	myfile.open(fileName, std::ofstream::out | std::ofstream::trunc);
	
	if (!myfile)
	{
		std::cout << "Unable to find/open 15-file" << std::endl;
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