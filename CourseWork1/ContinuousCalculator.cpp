#include "ContinuousCalculator.h"

ContinuousCalculator::ContinuousCalculator(Puzzle* puzzleVal)
{
	

	puzzle = puzzleVal;

	//int occursions = numberOfOccursions();
	//int occursionsBottomRow = numberOfOccursionsBottomRow();

	//int continous = continuousNumberCountEqualToDimension();
	//int continousBottomRow = continuousNumberCountEqualToDimensionMinusOne();

	//int i = 0;

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
	return (factorial((puzzle->getSize() - puzzle->getDimensions())) / 2) * (puzzle->getDimensions() - 1);
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


	int continuousCount = 0;

	for (int i = 1; i < arr.size(); i++)
	{
		int counter = 0;
		for (int j = i; j < (i + (puzzle->getDimensions() - 1)); j++)
		{
			if (j >= arr.size())
				break;

			if ((arr[j] - 1) == (arr[j - 1]))
				counter++;
		
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

	for (int i = 1; i < arr.size(); i++)
	{
		int counter = 0;
		for (int j = i; j < (i + (puzzle->getDimensions() - 2)); j++)
		{
			if (j >= arr.size())
				break;

			if ((arr[j] - 1) == arr[j - 1])
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
	std::cout << "\n\n FORMULA IMPLEMENTATION" << std::endl;
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