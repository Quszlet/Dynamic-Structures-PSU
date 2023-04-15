#pragma once
#include "Node.h"
#include "StructSet.h"
#include "ClassSet.h"
#include "ContainerList.h"
#include "ContainerSet.h"




class TimeSets
{
private:
	int Size;
	Node* SetStructA;
	Node* SetStructB;
	SetList* SetClassA;
	SetList* SetClassB;
	ContListSet* ContListSetA;
	ContListSet* ContListSetB;
	Set* ContSetA;
	Set* ContSetB;

public:
	TimeSets(int size);

	template <typename Func, typename... Args>
	static long CountingTime(Func func, Args... args);


	long* CalculateToCreateSets();
	long* CalculateToPowerSets();
	long* CalculateToSubSetsAA();
	long* CalculateToSubSetsAB();
	long* CalculateToEqualsSetsAA();
	long* CalculateToEqualsSetsBA();
	long* CalculateToMergeSetsAB();
	long* CalculateToIntersectionSetsAB();
	long* CalculateToDifferenceSetsAB();
	long* CalculateToDifferenceSetsBA();
	long* CalculateToSymmDifferenceSetsAB();

	~TimeSets();
};
