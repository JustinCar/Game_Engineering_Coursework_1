#pragma once
#include "InfInt.h"
class ContinuousCount
{
protected:
	InfInt continuousRows;
	InfInt reverseContinuousRows;
	InfInt continuousColumns;
	InfInt reverseContinuousColumns;

	InfInt total2PartialForStartingConfig;
	InfInt total3PartialForStartingConfig;
	InfInt total4PartialForStartingConfig;

	InfInt total2PartialForAll;
	InfInt total3PartialForAll;
	InfInt total4PartialForAll;
public:
	ContinuousCount(InfInt continuousRowsVal,
		InfInt  reverseContinuousRowsVal,
		InfInt continuousColumnsVal,
		InfInt reverseContinuousColumnsVal,
		InfInt total2PartialForStartingConfigVal,
		InfInt total3PartialForStartingConfigVal,
		InfInt total4PartialForStartingConfigVal,
		InfInt total2PartialForAllVal,
		InfInt total3PartialForAllVal,
		InfInt total4PartialForAllVal);

	InfInt getContinuousRows() const;
	InfInt getReverseContinuousRows() const;
	InfInt getContinuousColumns() const;
	InfInt getReverseContinuousColumns() const;

	InfInt getTotal2PartialForStartingConfig() const;
	InfInt getTotal3PartialForStartingConfig() const;
	InfInt getTotal4PartialForStartingConfig() const;

	InfInt getTotal2PartialForAll() const;
	InfInt getTotal3PartialForAll() const;
	InfInt getTotal4PartialForAll() const;
};

