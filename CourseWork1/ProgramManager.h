#pragma once
#include <iostream>
#include "WriteFileInterface.h"
#include "ReadFileInterface.h"
#include "UserInterface.h"

class ProgramManager
{
public:
	int readInOrCreateFile();
	virtual void run();
};

