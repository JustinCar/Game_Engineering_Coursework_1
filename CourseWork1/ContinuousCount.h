#pragma once
class ContinuousCount
{
protected:
	unsigned long long continuousRows;
	unsigned long long  reverseContinuousRows;
	unsigned long long continuousColumns;
	unsigned long long reverseContinuousColumns;
public:
	ContinuousCount(unsigned long long continuousRowsVal, 
		unsigned long long  reverseContinuousRowsVal, 
		unsigned long long continuousColumnsVal, 
		unsigned long long reverseContinuousColumnsVal);

	unsigned long long getContinuousRows() const;
	unsigned long long getReverseContinuousRows() const;
	unsigned long long getContinuousColumns() const;
	unsigned long long getReverseContinuousColumns() const;
};

