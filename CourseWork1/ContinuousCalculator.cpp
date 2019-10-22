#include "ContinuousCalculator.h"

ContinuousCalculator::ContinuousCalculator(Puzzle* puzzleVal) : puzzle (puzzleVal)
{

	unsigned long long occursions = numberOfOccursions();
	unsigned long long occursionsBottomRow = numberOfOccursionsBottomRow();

	unsigned long long continous = continuousNumberCountEqualToDimension();
	unsigned long long continousBottomRow = continuousNumberCountEqualToDimensionMinusOne();

	unsigned long long numberOfContinuous = occursions * continous;
	unsigned long long numberOfContinuousBottomRow = occursionsBottomRow * continousBottomRow;

	unsigned long long totalNumberOfContinuous = numberOfContinuous + numberOfContinuousBottomRow;

	unsigned long long numberOfTwoPartialStartingConfig = partialContinuousCount(2, true);
	unsigned long long numberOfThreePartialStartingConfig = partialContinuousCount(3, true);
	unsigned long long numberOfFourPartialStartingConfig = partialContinuousCount(4, true);

	unsigned long long twoPartialOccursions = numberOfOccursionsPartial(2);
	unsigned long long twoPartialOccursionsBottomRow = numberOfOccursionsPartialBottomRow(2);
	unsigned long long twoPartialContinous = partialContinuousCount(2, false);
	unsigned long long totalNumberOfTwoPartial = twoPartialContinous * (twoPartialOccursions + twoPartialOccursionsBottomRow);

	unsigned long long threePartialOccursions = numberOfOccursionsPartial(3);
	unsigned long long threePartialOccursionsBottomRow = numberOfOccursionsPartialBottomRow(3);
	unsigned long long threePartialContinous = partialContinuousCount(3, false);
	unsigned long long totalNumberOfThreePartial = threePartialContinous * (threePartialOccursions + threePartialOccursionsBottomRow);

	unsigned long long fourPartialOccursions = numberOfOccursionsPartial(4);
	unsigned long long fourPartialOccursionsBottomRow = numberOfOccursionsPartialBottomRow(4);
	unsigned long long fourPartialContinous = partialContinuousCount(4, false);
	unsigned long long totalNumberOfFourPartial = fourPartialContinous * (fourPartialOccursions + fourPartialOccursionsBottomRow);

	container = new ContinuousCount(totalNumberOfContinuous, totalNumberOfContinuous, totalNumberOfContinuous, totalNumberOfContinuous, 
		numberOfTwoPartialStartingConfig, numberOfThreePartialStartingConfig, numberOfFourPartialStartingConfig,
		totalNumberOfTwoPartial, totalNumberOfThreePartial, totalNumberOfFourPartial);
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

int ContinuousCalculator::numberOfOccursionsPartial(int constantValue)
{
	if (puzzle->getDimensions() < constantValue)
		return 0;

	return ((factorial((puzzle->getSize() - constantValue)) / 2) * puzzle->getDimensions() - (constantValue - 1)) * (puzzle->getDimensions() - 1);
}

int ContinuousCalculator::numberOfOccursionsPartialBottomRow(int constantValue)
{
	if ((puzzle->getDimensions() - 1) < constantValue)
		return 0;

	return ((factorial((puzzle->getSize() - constantValue)) / 2) * (puzzle->getDimensions() - 1) - (constantValue - 1));
}

int ContinuousCalculator::partialContinuousCount(int constantValue, bool startingConfig)
{
	if (puzzle->getDimensions() < constantValue)
		return 0;

	std::vector<int> arr;
	for (int i = 0; i < puzzle->getSize(); i++)
	{
		arr.push_back(puzzle->getOriginal()[i]);
	}

	if (!startingConfig)
		std::sort(arr.begin(), arr.begin() + arr.size());

	int continuousCount = 0;

	for (int i = 1; i < arr.size(); i++)
	{
		int counter = 0;
		for (int j = i; j < (i + (constantValue - 1)); j++)
		{
			if (j >= arr.size())
				break;

			if ((arr[j] - 1) == (arr[j - 1]))
				counter++;

		}

		if (counter == constantValue)
			continuousCount++;
	}

	return continuousCount;
}