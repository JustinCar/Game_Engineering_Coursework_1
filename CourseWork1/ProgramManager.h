#pragma once
#include <iostream>
#include "WriteFileInterface.h"
#include "ReadFileInterface.h"
#include "UserInterface.h"

/**
Author: Justin Carter
Student number: 160383867
Date: 24/10/2019
Called directly from the main function, runs the program
*/
class ProgramManager
{
public:
	int readInOrCreateFile();
	virtual void run();
};

