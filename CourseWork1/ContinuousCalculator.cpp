#include "ContinuousCalculator.h"

ContinuousCalculator::ContinuousCalculator(Puzzle* puzzleVal)
{
	

	puzzle = puzzleVal;

	unsigned long long occursions = numberOfOccursions();
	unsigned long long occursionsBottomRow = numberOfOccursionsBottomRow();

	unsigned long long continous = continuousNumberCountEqualToDimension();
	unsigned long long continousBottomRow = continuousNumberCountEqualToDimensionMinusOne();

	unsigned long long numberOfContinuous = occursions * continous;
	unsigned long long  numberOfContinuousBottomRow = occursionsBottomRow * continousBottomRow;

	unsigned long long  totalNumberOfContinuous = numberOfContinuous + numberOfContinuousBottomRow;

	container = new ContinuousCount(totalNumberOfContinuous, totalNumberOfContinuous, totalNumberOfContinuous, totalNumberOfContinuous);
}

ContinuousCount& ContinuousCalculator::getContainer() const
{
	return *container;
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