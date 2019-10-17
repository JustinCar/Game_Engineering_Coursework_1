#include "ContinuousCalculator.h"

ContinuousCalculator::ContinuousCalculator(Puzzle* puzzleVal)
{
	int i = 0;

	puzzle = puzzleVal;

	int result = (numberOfOccursions() * continuousNumberCountEqualToDimension()) +
		(numberOfOccursionsBottomRow() * continuousNumberCountEqualToDimensionMinusOne());

	continuousRows = result;
	reverseContinuousRows = result;
	continuousColumns = result;
	reverseContinuousColumns = result;
}

int ContinuousCalculator::factorial(int n)
{
	if (n > 1)
		return n * factorial(n - 1);
	else
		return 1;
}

int ContinuousCalculator::numberOfOccursions()
{
	return (factorial((puzzle->getSize() - puzzle->getDimensions())) / 2) * puzzle->getDimensions() - 1;
}

int ContinuousCalculator::numberOfOccursionsBottomRow()
{
	return (factorial((puzzle->getSize() - (puzzle->getDimensions() - 1))) / 2);
}

int ContinuousCalculator::continuousNumberCountEqualToDimension()
{
	std::vector<int> arr;
	for (int i = 0; i < puzzle->getSize(); i++) 
	{
		arr.push_back(puzzle->getOriginal()[i]);
	}

	std::sort(arr.begin(), arr.begin() + arr.size());

	//for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)
	//{
	//	for (std::vector<int>::iterator it2 = it + 1; it2 != it2 + 3; ++it2)
	//	{
	//		/* std::cout << *it; ... */
	//	}
	//}
	int continuousCount = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		int counter = 0;
		for (int j = i + 1; j < i + (puzzle->getDimensions() - 1); j++)
		{
			if (j >= arr.size())
				break;

			if (arr[j] == (arr[j - 1] - 1))
				counter++;
			else
				break;
		}

		if (counter == puzzle->getDimensions() - 1)
			continuousCount++;
	}

	return continuousCount;
}

//The number of continous rows that could appear in the bottom row or right most column
int ContinuousCalculator::continuousNumberCountEqualToDimensionMinusOne()
{
	std::vector<int> arr;
	for (int i = 0; i < puzzle->getSize(); i++)
	{
		arr.push_back(puzzle->getOriginal()[i]);
	}

	std::sort(arr.begin(), arr.begin() + arr.size());

	int continuousCount = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		int counter = 0;
		for (int j = i + 1; j < i + (puzzle->getDimensions() - 2); j++)
		{

			if (j >= arr.size())
				break;

			if (arr[j] == (arr[j - 1] - 1))
				counter++;
			else
				break;
		}

		if (counter == puzzle->getDimensions() - 2)
			continuousCount++;
	}

	return continuousCount;
}

void ContinuousCalculator::printInfo()
{
	std::cout << "\n\n" << std::endl;
	std::cout << "Continuous rows: " << continuousRows << std::endl;
	std::cout << "Reverse continuous rows: " << reverseContinuousRows << std::endl;
	std::cout << "Continuous columns: " << continuousColumns << std::endl;
	std::cout << "Reverse continuous columns: " << reverseContinuousColumns << std::endl;

}

void ContinuousCalculator::printArray()
{

	for (int i = 0; i < puzzle->getSize(); i++)
	{
		std::cout << puzzle->getCopy()[i] << std::endl;
	}

	std::cout << "\n\n\n\n" << std::endl;
}