#pragma once
#include <iostream>

/**
Author: Justin Carter
Student number: 160383867
Date: 24/10/2019
Stores each individual puzzle
*/
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

