#include "Puzzle.h"
#include "BruteForce.h"

int main() 
{
	int testArray[8]{ 1, 2, 3, 4, 5, 6, 7, 8}; // three by three
	int* pointer = testArray;
	Puzzle p(pointer, 3);
	
	BruteForce b(&p);

	b.permutations(8);
	b.printInfo();

	std::cin.get();
	return 0;
}