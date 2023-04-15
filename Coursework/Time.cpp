#include "Time.h"
#include<chrono>

using namespace std;

TimeSets::TimeSets(int size) {
    Size = size;
    SetStructA = CreateSetList(size, 0, 10 * size);
    SetStructB = CreateSetList(size, 0, 10 * size);
    SetClassA = new SetList(size, 0, 10 * size);
    ContListSetA = new ContListSet(size, 0, 10 * size);
    ContSetA = new Set(size, 0, 10 * size);
}

template <typename Func, typename... Args>
long TimeSets::CountingTime(Func func, Args... args) {
    auto start = chrono::steady_clock::now();
    func(args...);
    auto result = chrono::steady_clock::now() - start;
    return chrono::duration_cast<std::chrono::microseconds>(result).count();
}



long* TimeSets::CalculateToCreateSets() {
    long* arr = new long[4];
    arr[0] = CountingTime(static_cast<Node* (*)(int, int, int)>(&CreateSetList), Size, 0, Size*10);
    arr[1] = CountingTime([](int arg1, int arg2, int arg3, TimeSets* Time) -> void {
        Time->SetClassB = new SetList(arg1, arg2, arg3);
    }, Size, 0, Size * 10, this);
    arr[2] = CountingTime([](int arg1, int arg2, int arg3, TimeSets* Time) -> void {
        Time->ContListSetB = new ContListSet(arg1, arg2, arg3);
        }, Size, 0, Size * 10, this);
    arr[3] = CountingTime([](int arg1, int arg2, int arg3, TimeSets* Time) -> void {
        Time->ContSetB = new Set(arg1, arg2, arg3);
        }, Size, 0, Size * 10, this);
    return arr;
}

long* TimeSets::CalculateToPowerSets() {
    long* arr = new long[4];
    arr[0] = CountingTime(&PowerSetList, SetStructA);
    arr[1] = CountingTime([](SetList* SetClassA) -> void {
        SetClassA->PowerSetList();
        }, SetClassA);
    arr[2] = CountingTime([](ContListSet* contListSetA) -> void {
        contListSetA->PowerSetList();
        }, ContListSetA);
    arr[3] = CountingTime([](Set* contSetA) -> void {
        contSetA->PowerSet();
        }, ContSetA);
    return arr;
}

long* TimeSets::CalculateToSubSetsAA() {
    long* arr = new long[4];
    arr[0] = CountingTime(&CheckSubSet, SetStructA, SetStructA);
    arr[1] = CountingTime([](SetList* setClassA) -> void {
        setClassA->CheckSubSet(setClassA);
        }, SetClassA);
    arr[2] = CountingTime([](ContListSet* contListSetA) -> void {
        contListSetA->CheckSubSet(contListSetA);
        }, ContListSetA);
    arr[3] = CountingTime([](Set* contSetA) -> void {
        contSetA->CheckSubSet(contSetA);
        }, ContSetA);
    return arr;
}

long* TimeSets::CalculateToSubSetsAB() {
    long* arr = new long[4];
    arr[0] = CountingTime(&CheckSubSet, SetStructA, SetStructB);
    arr[1] = CountingTime([](SetList* setClassA, SetList* setClassB) -> void {
        setClassB->CheckSubSet(setClassA);
        }, SetClassA, SetClassB);
    arr[2] = CountingTime([](ContListSet* contListSetA, ContListSet* contListSetB) -> void {
        contListSetB->CheckSubSet(contListSetA);
        }, ContListSetA, ContListSetB);
    arr[3] = CountingTime([](Set* contSetA, Set* contSetB) -> void {
        contSetB->CheckSubSet(contSetA);
        }, ContSetA, ContSetB);
    return arr;
}

long* TimeSets::CalculateToEqualsSetsAA() {
    long* arr = new long[4];
    arr[0] = CountingTime(&EqualsSets, SetStructA, SetStructA);
    arr[1] = CountingTime([](SetList* setClassA) -> void {
        setClassA->EqualsSets(setClassA);
        }, SetClassA);
    arr[2] = CountingTime([](ContListSet* contListSetA) -> void {
        contListSetA->EqualsSets(contListSetA);
        }, ContListSetA);
    arr[3] = CountingTime([](Set* contSetA) -> void {
        contSetA->EqualsSets(contSetA);
        }, ContSetA);
    return arr;
}

long* TimeSets::CalculateToEqualsSetsBA() {
    long* arr = new long[4];
    arr[0] = CountingTime(&EqualsSets, SetStructB, SetStructA);
    arr[1] = CountingTime([](SetList* setClassA, SetList* setClassB) -> void {
        setClassB->EqualsSets(setClassA);
        }, SetClassA, SetClassB);
    arr[2] = CountingTime([](ContListSet* contListSetA, ContListSet* contListSetB) -> void {
        contListSetB->EqualsSets(contListSetA);
        }, ContListSetA, ContListSetB);
    arr[3] = CountingTime([](Set* contSetA, Set* contSetB) -> void {
        contSetB->EqualsSets(contSetA);
        }, ContSetA, ContSetB);
    return arr;
}

long* TimeSets::CalculateToMergeSetsAB() {
    long* arr = new long[4];
    arr[0] = CountingTime(&MergeSets, SetStructA, SetStructB);
    arr[1] = CountingTime([](SetList* setClassA, SetList* setClassB) -> void {
        setClassB->MergeSets(setClassA);
        }, SetClassA, SetClassB);
    arr[2] = CountingTime([](ContListSet* contListSetA, ContListSet* contListSetB) -> void {
        contListSetB->MergeSets(contListSetA);
        }, ContListSetA, ContListSetB);
    arr[3] = CountingTime([](Set* contSetA, Set* contSetB) -> void {
        contSetB->MergeSets(contSetA);
        }, ContSetA, ContSetB);
    return arr;
}

long* TimeSets::CalculateToIntersectionSetsAB() {
    long* arr = new long[4];
    arr[0] = CountingTime(&IntersectionSets, SetStructA, SetStructB);
    arr[1] = CountingTime([](SetList* setClassA, SetList* setClassB) -> void {
        setClassA->IntersectionSets(setClassB);
        }, SetClassA, SetClassB);
    arr[2] = CountingTime([](ContListSet* contListSetA, ContListSet* contListSetB) -> void {
        contListSetA->IntersectionSets(contListSetB);
        }, ContListSetA, ContListSetB);
    arr[3] = CountingTime([](Set* contSetA, Set* contSetB) -> void {
        contSetA->IntersectionSets(contSetB);
        }, ContSetA, ContSetB);
    return arr;
}

long* TimeSets::CalculateToDifferenceSetsAB() {
    long* arr = new long[4];
    arr[0] = CountingTime(&DifferenceSets, SetStructA, SetStructB);
    arr[1] = CountingTime([](SetList* setClassA, SetList* setClassB) -> void {
        setClassA->DifferenceSets(setClassB);
        }, SetClassA, SetClassB);
    arr[2] = CountingTime([](ContListSet* contListSetA, ContListSet* contListSetB) -> void {
        contListSetA->DifferenceSets(contListSetB);
        }, ContListSetA, ContListSetB);
    arr[3] = CountingTime([](Set* contSetA, Set* contSetB) -> void {
        contSetA->DifferenceSets(contSetB);
        }, ContSetA, ContSetB);
    return arr;
}

long* TimeSets::CalculateToDifferenceSetsBA() {
    long* arr = new long[4];
    arr[0] = CountingTime(&DifferenceSets, SetStructB, SetStructA);
    arr[1] = CountingTime([](SetList* setClassA, SetList* setClassB) -> void {
        setClassB->DifferenceSets(setClassA);
        }, SetClassA, SetClassB);
    arr[2] = CountingTime([](ContListSet* contListSetA, ContListSet* contListSetB) -> void {
        contListSetB->DifferenceSets(contListSetA);
        }, ContListSetA, ContListSetB);
    arr[3] = CountingTime([](Set* contSetA, Set* contSetB) -> void {
        contSetB->DifferenceSets(contSetA);
        }, ContSetA, ContSetB);
    return arr;
}

long* TimeSets::CalculateToSymmDifferenceSetsAB() {
    long* arr = new long[4];
    arr[0] = CountingTime(&SymmetricDifferenceSets, SetStructA, SetStructB);
    arr[1] = CountingTime([](SetList* setClassA, SetList* setClassB) -> void {
        setClassA->SymmetricDifferenceSets(setClassB);
        }, SetClassA, SetClassB);
    arr[2] = CountingTime([](ContListSet* contListSetA, ContListSet* contListSetB) -> void {
        contListSetA->SymmetricDifferenceSets(contListSetB);
        }, ContListSetA, ContListSetB);
    arr[3] = CountingTime([](Set* contSetA, Set* contSetB) -> void {
        contSetA->SymmetricDifferenceSets(contSetB);
        }, ContSetA, ContSetB);
    return arr;
}

TimeSets::~TimeSets() {
    delete SetStructA;
    delete SetStructB;
    delete SetClassA;
    delete SetClassB;
    delete ContListSetA;
    delete ContListSetB;
    delete ContSetA;
    delete ContSetB;
}
