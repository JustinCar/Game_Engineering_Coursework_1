#include "PuzzleFile.h"

PuzzleFile::PuzzleFile(std::vector<Puzzle*> puzzles)
{
	std::ofstream myfile;
	myfile.open("15-File.txt", std::ofstream::out | std::ofstream::trunc);
	myfile << puzzles.size();

	for(int i = 0; i < puzzles.size(); i++)
	{
		/*writePuzzle(puzzles[i], &myfile);*/

		int dimensions = puzzles[i]->getDimensions();
		for (int j = 0; j < (puzzles[i]->getDimensions() * 2) + 1; j += dimensions)
		{
			myfile << "\n";

			for (int i = j; i < j + puzzles[i]->getDimensions(); i++)
			{
				if (i == puzzles[i]->getSize())
					myfile << " " << "\n";
				break;

				myfile << puzzles[i]->getOriginal()[i] << " ";

			}
		}
	}

	myfile.close();
}

void PuzzleFile::writePuzzle(Puzzle* puzzle, std::ofstream* myfile)
{

	int dimensions = puzzle->getDimensions();
	for (int j = 0; j < (puzzle->getDimensions() * 2) + 1; j += dimensions)
	{
		*myfile << "\n";

		for (int i = j; i < j + puzzle->getDimensions(); i++)
		{
			if (i == puzzle->getSize())
				*myfile << " " << "\n";
				break;

			*myfile << puzzle->getOriginal()[i] << " ";

		}
	}

}
