#include "UserInterface.h"

UserInterface::UserInterface()
{

}

UserInterface::~UserInterface()
{
	for (int i = 0; i < puzzles.size(); i++)
		delete puzzles[i];
}


void UserInterface::run() 
{

}
