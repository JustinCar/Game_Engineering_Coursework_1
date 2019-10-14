#pragma once
class Puzzle
{
public:
	Puzzle();
	~Puzzle();

	int** getGrid();
protected:
	int** grid;
};

