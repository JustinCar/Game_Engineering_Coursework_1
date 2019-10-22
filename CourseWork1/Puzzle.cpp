#include "Puzzle.h"

Puzzle::Puzzle(int* originalVal, int dimensionsVal) : original(originalVal), dimensions(dimensionsVal)
{
	size = (dimensionsVal * dimensionsVal) - 1;
	copy = new int[size];

	for (int i = 0; i < size; i++)
	{
		copy[i] = original[i];
	}

		
}

Puzzle::~Puzzle()
{
	delete[] original;

	delete[] copy;
}

bool Puzzle::operator==(Puzzle& other)
{
	if (other.getSize() <= size)
	{
		for (int j = 0; j < other.getSize(); j++)
		{
			if (other.getCopy()[j] != copy[j])
				return false;
		}
	}
	else
	{
		for (int j = 0; j < size; j++)
		{
			if (other.getCopy()[j] != copy[j])
				return false;
		}
	}

	return true;
}

int* Puzzle::getCopy()
{
	return copy;
}

int* Puzzle::getOriginal() const
{
	return original;
}

int Puzzle::getSize() const
{
	return size;
}

int Puzzle::getDimensions() const
{
	return dimensions;
}