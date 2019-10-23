#include "ContinuousCount.h"

ContinuousCount::ContinuousCount(unsigned long long continuousRowsVal,
	unsigned long long  reverseContinuousRowsVal,
	unsigned long long continuousColumnsVal,
	unsigned long long reverseContinuousColumnsVal,
	unsigned long long total2PartialForStartingConfigVal,
	unsigned long long total3PartialForStartingConfigVal,
	unsigned long long total4PartialForStartingConfigVal,
	unsigned long long total2PartialForAllVal,
	unsigned long long total3PartialForAllVal,
	unsigned long long total4PartialForAllVal) : continuousRows(continuousRowsVal),
														reverseContinuousRows(reverseContinuousRowsVal),
														continuousColumns(continuousColumnsVal),
														reverseContinuousColumns(reverseContinuousColumnsVal),
														total2PartialForStartingConfig(total2PartialForStartingConfigVal),
														total3PartialForStartingConfig(total3PartialForStartingConfigVal),
														total4PartialForStartingConfig(total4PartialForStartingConfigVal),
														total2PartialForAll(total2PartialForAllVal),
														total3PartialForAll(total3PartialForAllVal),
														total4PartialForAll(total4PartialForAllVal)
{

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

int ContinuousCount::getTotal2PartialForStartingConfig() const
{
	return total2PartialForStartingConfig;
}


int ContinuousCount::getTotal3PartialForStartingConfig() const
{
	return total3PartialForStartingConfig;
}

int ContinuousCount::getTotal4PartialForStartingConfig() const
{
	return total4PartialForStartingConfig;
}

unsigned long long ContinuousCount::getTotal2PartialForAll() const
{
	return total2PartialForAll;
}

unsigned long long ContinuousCount::getTotal3PartialForAll() const
{
	return total3PartialForAll;
}

unsigned long long ContinuousCount::getTotal4PartialForAll() const
{
	return total4PartialForAll;
}
