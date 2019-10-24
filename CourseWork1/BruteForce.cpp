#include "BruteForce.h"


BruteForce::BruteForce(Puzzle* puzzleVal) : continuousRows(0),
											reverseContinuousRows(0),
											continuousColumns(0),
											reverseContinuousColumns(0), 
											puzzle(puzzleVal),
											numberOfTwoPartialStartingConfig(0),
											numberOfThreePartialStartingConfig(0),
											numberOfFourPartialStartingConfig(0),
											totalNumberOfTwoPartial(0),
											totalNumberOfThreePartial(0),
											totalNumberOfFourPartial(0)
{
}

void BruteForce::run()
{
	int numberOfTwoPartialStartingConfig = calculatePartialContinuousRows(2) + calculatePartialContinuousColumns(2);
	int numberOfThreePartialStartingConfig = calculatePartialContinuousRows(3) + calculatePartialContinuousColumns(3);
	int numberOfFourPartialStartingConfig = calculatePartialContinuousRows(4) + calculatePartialContinuousColumns(4);

	permutations(puzzle->getSize());

	container = new ContinuousCount(continuousRows, reverseContinuousRows, continuousColumns, reverseContinuousColumns,
		numberOfTwoPartialStartingConfig, numberOfThreePartialStartingConfig, numberOfFourPartialStartingConfig,
		totalNumberOfTwoPartial, totalNumberOfThreePartial, totalNumberOfFourPartial);
}

ContinuousCount& BruteForce::getContainer() const
{
	return *container;
}

void BruteForce::swap(int pos1, int pos2)
{
	int temp = puzzle->getCopy()[pos1];
	puzzle->getCopy()[pos1] = puzzle->getCopy()[pos2];
	puzzle->getCopy()[pos2] = temp;
}

// Make sure the permutation is reachable
// By only sliding the tiles
// Number of inversions must always be even
// An inversion is every time that a larger number is located
// Before a smaller number
bool BruteForce::isLegalPermutation()
{
	int counter = 0;
	int* arr = puzzle->getCopy();

	for (int i = 0; i < puzzle->getSize(); i++)
	{
		for (int j = i + 1; j < puzzle->getSize(); j++)
		{
			if (arr[i] > arr[j])
				counter++;
		}
	}

	if (counter % 2 == 0)
		return true;

	return false;
}

int  BruteForce::calculatePartialContinuousRows(int constantValue)
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

		counter += checkForContinuous(row, constantValue);

		int* flippedRow = flipArray(row, dimensions);
		counter += checkForContinuous(flippedRow, constantValue);

		delete[] flippedRow;
		delete[] row;
	}

	return counter;
}

int BruteForce::calculatePartialContinuousColumns(int constantValue)
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

		counter += checkForContinuous(column, constantValue);

		int* flippedColumn = flipArray(column, dimensions);
		counter += checkForContinuous(flippedColumn, constantValue);

		delete[] flippedColumn;
		delete[] column;
	}

	return counter;
}

int BruteForce::checkForContinuous(int* arr, int constantValue)
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

int* BruteForce::flipArray(int* arr, int size)
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

bool BruteForce::checkForContinuous(int* arr)
{
	for (int i = 1; i < puzzle->getDimensions(); i++)
	{
		if (arr[i] - 1 != arr[i - 1] &&
			arr[i] != -1)
		{
			return false;
		}
	}

	return true;
}

bool BruteForce::checkForReverse(int* arr)
{
	for (int i = puzzle->getDimensions() - 2; i > - 1; i--)
	{
		if (arr[i] - 1 != arr[i + 1] && 
			arr[i + 1] != -1)
		{
			return false;
		}
	}

	return true;
}

void BruteForce::calculateContinuousRows()
{

	int dimensions = puzzle->getDimensions();
	for (int j = 0; j < (dimensions * 2) + 1; j += dimensions)
	{
		
		int* row = new int[dimensions];

		for (int i = 0; i < 3; i++)
		{
			row[i] = -1;
		}

		int rowIterator = 0;

		for (int i = j; i < j + dimensions; i++)
		{
			if (i == puzzle->getSize())
				break;

			row[rowIterator] = puzzle->getCopy()[i];
			rowIterator++;
		}

		if (checkForContinuous(row))
			continuousRows++;
			

		if (checkForReverse(row))
			reverseContinuousRows++;
	}
}

void BruteForce::calculateContinuousColumns()
{

	int dimensions = puzzle->getDimensions();
	for (int i = 0; i < dimensions; i ++)
	{
		int* column = new int[dimensions];

		for (int i = 0; i < 3; i++)
		{
			column[i] = -1;
		}

		int columnIterator = 0;

		for (int j = i; j < (i + (dimensions * 2) + 1); j += dimensions)
		{
			if (j == puzzle->getSize())
				break;

			int copy = puzzle->getCopy()[j];
			column[columnIterator] = copy;
			columnIterator++;
		}

		if (checkForContinuous(column))
			continuousColumns++;

		if (checkForReverse(column))
			reverseContinuousColumns++;
	}
}

void BruteForce::permutations(int k)
{
	if (k == 1)
	{
		if (isLegalPermutation())
		{
			calculateContinuousRows();
			calculateContinuousColumns();

			totalNumberOfTwoPartial += calculatePartialContinuousRows(2);
			totalNumberOfThreePartial += calculatePartialContinuousRows(3);
			totalNumberOfFourPartial += calculatePartialContinuousRows(4);

			totalNumberOfTwoPartial += calculatePartialContinuousColumns(2);
			totalNumberOfThreePartial += calculatePartialContinuousColumns(3);
			totalNumberOfFourPartial += calculatePartialContinuousColumns(4);

		}
	}
	else
	{
		permutations(k - 1);

		for (int i = 0; i < k - 1; i++)
		{
			if ((k % 2) == 0)
			{
				swap(i, k - 1);
			}
			else
			{
				swap(0, k - 1);
			}

			permutations(k - 1);
		}
	}
}

