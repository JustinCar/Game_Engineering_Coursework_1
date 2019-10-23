#pragma once
class ContinuousCount
{
protected:
	unsigned long long continuousRows;
	unsigned long long reverseContinuousRows;
	unsigned long long continuousColumns;
	unsigned long long reverseContinuousColumns;

	int total2PartialForStartingConfig;
	int total3PartialForStartingConfig;
	int total4PartialForStartingConfig;

	unsigned long long total2PartialForAll;
	unsigned long long total3PartialForAll;
	unsigned long long total4PartialForAll;
public:
	ContinuousCount(unsigned long long continuousRowsVal, 
		unsigned long long  reverseContinuousRowsVal, 
		unsigned long long continuousColumnsVal, 
		unsigned long long reverseContinuousColumnsVal, 
		unsigned long long total2PartialForStartingConfigVal,
	unsigned long long total3PartialForStartingConfigVal,
	unsigned long long total4PartialForStartingConfigVal,
	unsigned long long total2PartialForAllVal,
	unsigned long long total3PartialForAllVal,
	unsigned long long total4PartialForAllVal);

	unsigned long long getContinuousRows() const;
	unsigned long long getReverseContinuousRows() const;
	unsigned long long getContinuousColumns() const;
	unsigned long long getReverseContinuousColumns() const;

	int getTotal2PartialForStartingConfig() const;
	int getTotal3PartialForStartingConfig() const;
	int getTotal4PartialForStartingConfig() const;

	unsigned long long getTotal2PartialForAll() const;
	unsigned long long getTotal3PartialForAll() const;
	unsigned long long getTotal4PartialForAll() const;
};

