#include "UserInterface.h"

//int main() 
//{
//	int testArray[8]{ 1, 18, 6, 7, 8, 9, 16, 13}; // three by three
//	int* pointer = testArray;
//	Puzzle p(pointer, 3);
//	
//	BruteForce b(&p);
//
//	b.permutations(8);
//	b.printInfo();
//
//	std::cin.get();
//	return 0;
//}

int main()
{
	bool runAgain = true;

	while (runAgain)
	{
		UserInterface interface;
		interface.programStart();

		std::cout << "Would you like to run the program again? Enter y for yes or n for no" << std::endl;

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

	std::cin.get();
	return 0;
}