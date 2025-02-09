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