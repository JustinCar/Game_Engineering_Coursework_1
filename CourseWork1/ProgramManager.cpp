#include "ProgramManager.h"

void ProgramManager::run()
{
	bool runAgain = true;

	while (runAgain)
	{
		int option = readInOrCreateFile();

		if (option == 2)
		{
			WriteFileInterface interface;
			interface.run();
		}
		else
		{
			ReadFileInterface interface;
			interface.run();
		}

		std::cout << "\nWould you like to run the program again? Enter y for yes or n for no" << std::endl;

		char input;
		std::cin >> input;
		while (input != 'y' && input != 'n')
		{
			std::cout << "Please enter a valid letter" << std::endl;
			std::cin >> input;
		}

		if (input == 'n')
			runAgain = false;
	}
}

int ProgramManager::readInOrCreateFile()
{
	std::cout << "\nWould you like to read in a 15-File, or create a new one?" << std::endl;
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