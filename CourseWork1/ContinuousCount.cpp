#include "ContinuousCount.h"

ContinuousCount::ContinuousCount(InfInt continuousRowsVal,
	InfInt  reverseContinuousRowsVal,
	InfInt continuousColumnsVal,
	InfInt reverseContinuousColumnsVal,
	InfInt total2PartialForStartingConfigVal,
	InfInt total3PartialForStartingConfigVal,
	InfInt total4PartialForStartingConfigVal,
	InfInt total2PartialForAllVal,
	InfInt total3PartialForAllVal,
	InfInt total4PartialForAllVal) : continuousRows(continuousRowsVal),
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

InfInt ContinuousCount::getContinuousRows() const
{
	return continuousRows;
}

InfInt ContinuousCount::getReverseContinuousRows() const
{
	return reverseContinuousRows;
}

InfInt ContinuousCount::getContinuousColumns() const
{
	return continuousColumns;
}

InfInt ContinuousCount::getReverseContinuousColumns() const
{
	return reverseContinuousColumns;
}

InfInt ContinuousCount::getTotal2PartialForStartingConfig() const
{
	return total2PartialForStartingConfig;
}


InfInt ContinuousCount::getTotal3PartialForStartingConfig() const
{
	return total3PartialForStartingConfig;
}

InfInt ContinuousCount::getTotal4PartialForStartingConfig() const
{
	return total4PartialForStartingConfig;
}

InfInt ContinuousCount::getTotal2PartialForAll() const
{
	return total2PartialForAll;
}

InfInt ContinuousCount::getTotal3PartialForAll() const
{
	return total3PartialForAll;
}

InfInt ContinuousCount::getTotal4PartialForAll() const
{
	return total4PartialForAll;
}
