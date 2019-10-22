#pragma once
#include <iostream>

class Puzzle
{
protected:
	int* original;
	int* copy;
	int dimensions;
	int size;
public:
	Puzzle(int* originalVal, int dimensionsVal);
	~Puzzle();

	bool operator==(Puzzle& other);

	int* getCopy();
	int* getOriginal() const;
	int getSize() const;
	int getDimensions() const;

};

