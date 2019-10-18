#include "BruteForce.h"


BruteForce::BruteForce(Puzzle* puzzleVal)
{
	permutationCounter = 0;
	continuousRows = 0;
	reverseContinuousRows = 0;
	continuousColumns = 0;
	reverseContinuousColumns = 0;

	puzzle = puzzleVal;
}

void BruteForce::swap(int pos1, int pos2)
{
	int temp = puzzle->getCopy()[pos1];
	puzzle->getCopy()[pos1] = puzzle->getCopy()[pos2];
	puzzle->getCopy()[pos2] = temp;
}

void BruteForce::printInfo()
{
	std::cout << "\n\n BRUTE FORCE IMPLEMENTATION" << std::endl;
	std::cout << "Continuous rows: " << continuousRows << std::endl;
	std::cout << "Reverse continuous rows: " << reverseContinuousRows << std::endl;
	std::cout << "Continuous columns: " << continuousColumns << std::endl;
	std::cout << "Reverse continuous columns: " << reverseContinuousColumns << std::endl;

	// Test
	/*std::cout << "continuous top row: " << topRowCount << std::endl;
	std::cout << "continuous middle row: " << middleRowCount << std::endl;
	std::cout << "continuous bottom row: " << bottomRowCount << std::endl;*/
}

void BruteForce::printArray()
{
	permutationCounter++;
	std::cout << permutationCounter << std::endl;
	std::cout << "\n\n" << std::endl;

	for (int i = 0; i < puzzle->getSize(); i++)
	{
		std::cout << puzzle->getCopy()[i] << std::endl;
	}

	std::cout << "\n\n\n\n" << std::endl;
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
	for (int j = 0; j < (puzzle->getDimensions() * 2) + 1; j += dimensions)
	{
		


		int* row = new int[puzzle->getDimensions()];

		for (int i = 0; i < 3; i++)
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

		if (checkForContinuous(row))
		{ 

			continuousRows++;
		}
			

		if (checkForReverse(row))
			reverseContinuousRows++;
	}
}

void BruteForce::calculateContinuousColumns()
{

	int dimensions = puzzle->getDimensions();
	for (int i = 0; i < puzzle->getDimensions(); i ++)
	{
		int* column = new int[dimensions];

		for (int i = 0; i < 3; i++)
		{
			column[i] = -1;
		}

		int columnIterator = 0;

		for (int j = i; j < (i + (puzzle->getDimensions() * 2) + 1); j += dimensions)
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

//void BruteForce::permutations(int k)
//{
//
//	int* indexes = new int[k];
//
//	for (int i = 0; i < k; i++)
//	{
//		indexes[i] = 0;
//	}
//
//			printArray();
//			if (isLegalPermutation())
//			{
//				calculateContinuousRows();
//				calculateContinuousColumns();
//			}
//
//	for (int i = 1; i < k;) 
//	{
//		if (indexes[i] < i)
//		{
//			if ((i & 1) == 1)
//			{
//				swap(i, indexes[i]);
//			}
//			else
//			{
//				swap(i, 0);
//			}
//
//			printArray();
//			if (isLegalPermutation())
//			{
//				calculateContinuousRows();
//				calculateContinuousColumns();
//			}
//
//			indexes[i]++;
//			i = 1;
//		}
//		else
//		{
//			indexes[i++] = 0;
//		}
//	}
//}

//void BruteForce::permutations(int k)
//{
//	std::sort(puzzle->getCopy(), puzzle->getCopy() + puzzle->getSize());
//
//	do {
//		printArray();
//		if (isLegalPermutation())
//		{
//			calculateContinuousRows();
//			calculateContinuousColumns();
//		}
//	} while (std::next_permutation(puzzle->getCopy(), puzzle->getCopy() + puzzle->getSize()));
//}

void BruteForce::permutations(int k)
{
	if (k == 1)
	{
		//printArray();
		if (isLegalPermutation())
		{
			calculateContinuousRows();
			calculateContinuousColumns();
		}

		//Finished
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

