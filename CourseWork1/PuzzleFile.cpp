#include "PuzzleFile.h"

PuzzleFile::PuzzleFile(std::vector<Puzzle*>& puzzles, int option)
{
	if (option == 2) 
	{
		writeToFile(puzzles);
	}
	else 
	{
		readFile(puzzles);
	}
}

void PuzzleFile::readFile(std::vector<Puzzle*>& puzzles)
{
	std::ifstream myfile;
	myfile.open("15-File.txt", std::ifstream::in);

	if (!myfile)
	{
		std::cout << "Unable to open 15-file";
		return;
	}

	int puzzleCount = 0;
	myfile >> puzzleCount;
		
	if (puzzleCount == 0)
	{
		std::cout << "There are no puzzles";
		return;
	}

	for (int i = 0; i < puzzleCount;)
	{
		if (readPuzzle(puzzles, myfile))
			i++;
	}

	myfile.close();
}

bool PuzzleFile::readPuzzle(std::vector<Puzzle*>& puzzles, std::ifstream& myfile)
{
	std::vector<int> puzzleNumbers;
	std::string line;
	
	while (std::getline(myfile, line) && line != "") 
	{	
		processLine(puzzleNumbers, line);
	}

	// three is smallest size possible for a valid grid (2x2)
	if (puzzleNumbers.size() < 3)
		return false;

	int* puzzleArray = new int[puzzleNumbers.size()];

	for (int i = 0; i < puzzleNumbers.size(); i++)
	{
		puzzleArray[i] = puzzleNumbers[i];
	}

	int puzzleDimension = sqrt(puzzleNumbers.size() + 1);

	Puzzle* p = new Puzzle(puzzleArray, puzzleDimension);
	puzzles.push_back(p);
	
	return true;
}

void PuzzleFile::processLine(std::vector<int>& puzzleNumbers, std::string line)
{
	std::stringstream stream;
	stream << line;

	int number;
	std::string temp;
	while (stream >> temp)
	{

		if (std::stringstream(temp) >> number)
			puzzleNumbers.push_back(number);

	}
}

void PuzzleFile::writeToFile(std::vector<Puzzle*>& puzzles)
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

void PuzzleFile::writePuzzle(Puzzle& puzzle, std::ofstream& myfile)
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

		/*if (puzzle.getOriginal()[j] < 10)
			myfile << puzzle.getOriginal()[j] << "  ";
		else
			myfile << puzzle.getOriginal()[j] << " ";*/

		rowCounter++;
	}
}
