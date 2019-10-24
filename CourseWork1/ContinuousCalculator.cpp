#include "ContinuousCalculator.h"

ContinuousCalculator::ContinuousCalculator(Puzzle* puzzleVal, bool includeEmptyVal) : puzzle (puzzleVal), includeEmpty(includeEmptyVal)
{
	unsigned long long totalNumberOfContinuous = calculateContinuous();

	int numberOfTwoPartialStartingConfig = calculatePartialContinuousRowsStartingConfig(2) + calculatePartialContinuousColumnsStartingConfig(2);
	int numberOfThreePartialStartingConfig = calculatePartialContinuousRowsStartingConfig(3) + calculatePartialContinuousColumnsStartingConfig(3);
	int numberOfFourPartialStartingConfig = calculatePartialContinuousRowsStartingConfig(4) + calculatePartialContinuousColumnsStartingConfig(4);

	unsigned long long totalNumberOfTwoPartial = calculatePartiallyContinuous(2);
	unsigned long long totalNumberOfThreePartial = calculatePartiallyContinuous(3);
	unsigned long long totalNumberOfFourPartial = calculatePartiallyContinuous(4);

	container = new ContinuousCount(totalNumberOfContinuous, totalNumberOfContinuous, totalNumberOfContinuous, totalNumberOfContinuous, 
		numberOfTwoPartialStartingConfig, numberOfThreePartialStartingConfig, numberOfFourPartialStartingConfig,
		totalNumberOfTwoPartial, totalNumberOfThreePartial, totalNumberOfFourPartial);
}

unsigned long long ContinuousCalculator::calculateContinuous()
{
	if (includeEmpty) 
	{
		unsigned long long occursions = numberOfOccursions();
		unsigned long long occursionsBottomRow = numberOfOccursionsBottomRow();

		unsigned long long continous = continuousNumberCountEqualToDimension();
		unsigned long long continousBottomRow = continuousNumberCountEqualToDimensionMinusOne();

		unsigned long long numberOfContinuous = occursions * continous;
		unsigned long long numberOfContinuousBottomRow = occursionsBottomRow * continousBottomRow;

		return numberOfContinuous + numberOfContinuousBottomRow;
	}
	else 
	{
		unsigned long long occursions = numberOfOccursions();

		unsigned long long continous = continuousNumberCountEqualToDimension();

		unsigned long long numberOfContinuous = occursions * continous;

		return numberOfContinuous;
	}
}

unsigned long long ContinuousCalculator::calculatePartiallyContinuous(int constantValue)
{
	unsigned long long partialOccursions = numberOfOccursionsPartial(constantValue);
	unsigned long long partialOccursionsBottomRow = numberOfOccursionsPartialBottomRow(constantValue);
	unsigned long long partialContinous = partialContinuousCount(constantValue);
	return (partialContinous * (partialOccursions + partialOccursionsBottomRow)) * 4;
}

ContinuousCount& ContinuousCalculator::getContainer() const
{
	return *container;
}

unsigned long long ContinuousCalculator::factorial(int n)
{
	if (n > 1)
		return n * factorial(n - 1);
	else
		return 1;
}

unsigned long long ContinuousCalculator::numberOfOccursions()
{
	return (factorial((puzzle->getSize() - puzzle->getDimensions())) / 2) * (puzzle->getDimensions() - 1);
}

unsigned long long ContinuousCalculator::numberOfOccursionsBottomRow()
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

unsigned long long ContinuousCalculator::numberOfOccursionsPartial(int constantValue)
{
	if (puzzle->getDimensions() < constantValue)
		return 0;

	return ((factorial((puzzle->getSize() - constantValue)) / 2) * (puzzle->getDimensions() - (constantValue - 1))) * (puzzle->getDimensions() - 1);
}

unsigned long long ContinuousCalculator::numberOfOccursionsPartialBottomRow(int constantValue)
{
	if ((puzzle->getDimensions() - 1) < constantValue)
		return 0;

	return ((factorial((puzzle->getSize() - constantValue)) / 2) * ((puzzle->getDimensions() - 1) - (constantValue - 1)));
}

int ContinuousCalculator::partialContinuousCount(int constantValue)
{
	if (puzzle->getDimensions() < constantValue)
		return 0;

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
		for (int j = i; j < (i + (constantValue - 1)); j++)
		{
			if (j >= arr.size())
				break;

			if ((arr[j] - 1) == (arr[j - 1]))
				counter++;
		}

		if (counter == (constantValue - 1))
			continuousCount++;
	}

	return continuousCount;
}

int  ContinuousCalculator::calculatePartialContinuousRowsStartingConfig(int constantValue)
{
	int counter = 0;

	int dimensions = puzzle->getDimensions();
	for (int j = 0; j < (dimensions * dimensions); j += dimensions)
	{

		int* row = new int[puzzle->getDimensions()];

		for (int i = 0; i < dimensions; i++)
		{
			row[i] = -1;
		}

		int rowIterator = 0;

		for (int i = j; i < j + puzzle->getDimensions(); i++)
		{
			if (i == puzzle->getSize())
				break;

			row[rowIterator] = puzzle->getCopy()[i];
			rowIterator++;
		}

		counter += checkForContinuousStartingConfig(row, constantValue);

		int* flippedRow = flipArray(row, dimensions);
		counter += checkForContinuousStartingConfig(flippedRow, constantValue);

		delete[] flippedRow;
		delete[] row;
	}

	return counter;
}

int ContinuousCalculator::calculatePartialContinuousColumnsStartingConfig(int constantValue)
{
	int counter = 0;
	int dimensions = puzzle->getDimensions();
	for (int i = 0; i < dimensions; i++)
	{
		int* column = new int[dimensions];

		for (int i = 0; i < dimensions; i++)
		{
			column[i] = -1;
		}

		int columnIterator = 0;

		for (int j = i; j < (i + (dimensions * (dimensions))); j += dimensions)
		{
			if (j == puzzle->getSize())
				break;

			int copy = puzzle->getCopy()[j];
			column[columnIterator] = copy;
			columnIterator++;
		}

		counter += checkForContinuousStartingConfig(column, constantValue);

		int* flippedColumn = flipArray(column, dimensions);
		counter += checkForContinuousStartingConfig(flippedColumn, constantValue);

		delete[] flippedColumn;
		delete[] column;
	}

	return counter;
}

int ContinuousCalculator::checkForContinuousStartingConfig(int* arr, int constantValue)
{
	int continuousCount = 0;

	for (int i = 0; i < puzzle->getDimensions(); i++)
	{
		int counter = 0;

		for (int j = i + 1; j < (i + (constantValue)); j++)
		{
			if (j >= puzzle->getDimensions())
				break;

			if (arr[j] - 1 == arr[j - 1] &&
				arr[j] != -1)
			{
				int i = 0;
				counter++;
			}
		}
		if (counter == (constantValue - 1))
			continuousCount++;
	}

	return continuousCount;
}

int* ContinuousCalculator::flipArray(int* arr, int size)
{
	int* flipped = new int[size];

	int iter = 0;
	for (int i = (size - 1); i > -1; i--)
	{
		flipped[iter] = arr[i];
		iter++;
	}

	return flipped;
}