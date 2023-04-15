#pragma once
#include<string>

class UserInterface
{
private:
	int ColWidth;
	char Delimiter = '-';
	char Row_delimiter = '|';
	long* ResultTimeCreateSets;
	long* ResultTimePowerSets;
	long* ResultTimeSubSetsAA;
	long* ResultTimeSubSetsAB;
	long* ResultTimeEqualsSetsAA;
	long* ResultTimeEqualsSetsBA;
	long* ResultTimeMergeSetsAB;
	long* ResultTimeIntersectionSetsAB;
	long* ResultTimeDifferenceSetsAB;
	long* ResultTimeDifferenceSetsBA;
	long* ResultTimeSymmDifferenceSetsAB;

	void PrintRow(std::string nameRow, long* arrResult);

public:
	UserInterface(int, long*, long*, long*, long*, long*, long*, long*, long*, long*, long*, long*);

	void static StartApp();

	std::string static InputStr();

	void PrintTable();
};