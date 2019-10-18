#include "ContinuousCount.h"

ContinuousCount::ContinuousCount(unsigned long long continuousRowsVal,
	unsigned long long  reverseContinuousRowsVal,
	unsigned long long continuousColumnsVal,
	unsigned long long reverseContinuousColumnsVal)
{
	continuousRows = continuousRowsVal;
	reverseContinuousRows = reverseContinuousRowsVal;
	continuousColumns = continuousColumnsVal;
	reverseContinuousColumns = reverseContinuousColumnsVal;
}

unsigned long long ContinuousCount::getContinuousRows() const
{
	return continuousRows;
}

unsigned long long ContinuousCount::getReverseContinuousRows() const
{
	return reverseContinuousRows;
}

unsigned long long ContinuousCount::getContinuousColumns() const
{
	return continuousColumns;
}

unsigned long long ContinuousCount::getReverseContinuousColumns() const
{
	return reverseContinuousColumns;
}
