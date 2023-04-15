#include "UserInterface.h"
#include "Time.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <chrono>
#include <regex>


using namespace std;

UserInterface::UserInterface(int col_width, long* arrTimeCreateSets, long* arrTimePowerSets, long* arrTimeSubSetsAA, long* arrTimeSubSetsAB,
    long* arrTimeEqualsSetsAA, long* arrTimeEqualsSetsBA, long* arrTimeMergeSetsAB, long* arrTimeIntersectionSetsAB, long* arrTimeDifferenceAB,
    long* arrTimeDifferenceSetsBA, long* arrTimeSymmDfSetsAB) {
	this->ColWidth = col_width;
    this->ResultTimeCreateSets = arrTimeCreateSets;
    this->ResultTimePowerSets = arrTimePowerSets;
    this->ResultTimeSubSetsAA = arrTimeSubSetsAA;
    this->ResultTimeSubSetsAB = arrTimeSubSetsAB;
    this->ResultTimeEqualsSetsAA = arrTimeEqualsSetsAA;
    this->ResultTimeEqualsSetsBA = arrTimeEqualsSetsBA;
    this->ResultTimeMergeSetsAB = arrTimeMergeSetsAB;
    this->ResultTimeIntersectionSetsAB = arrTimeIntersectionSetsAB;
    this->ResultTimeDifferenceSetsAB = arrTimeDifferenceAB;
    this->ResultTimeDifferenceSetsBA = arrTimeDifferenceSetsBA;
    this->ResultTimeSymmDifferenceSetsAB = arrTimeSymmDfSetsAB;
}

void UserInterface::StartApp() {

    string inputString = InputStr();
   
    while (inputString != "exit") {


        int inputInt = std::stoi(inputString);

        TimeSets* times = new TimeSets(inputInt);
        long* arrCreate = times->CalculateToCreateSets();
        long* arrPower = times->CalculateToPowerSets();
        long* arrSubSetsAA = times->CalculateToSubSetsAA();
        long* arrSubSetsAB = times->CalculateToSubSetsAB();
        long* arrEqualsAA = times->CalculateToEqualsSetsAA();
        long* arrEqualsBA = times->CalculateToEqualsSetsBA();
        long* arrMergeAB = times->CalculateToMergeSetsAB();
        long* arrIntersectionAB = times->CalculateToIntersectionSetsAB();
        long* arrDifferenceSetsAB = times->CalculateToDifferenceSetsAB();
        long* arrDifferenceSetsBA = times->CalculateToDifferenceSetsBA();
        long* arrSymmDFSetsAB = times->CalculateToSymmDifferenceSetsAB();
        UserInterface* table = new UserInterface(24, arrCreate, arrPower, arrSubSetsAA, arrSubSetsAB, arrEqualsAA, arrEqualsBA,
            arrMergeAB, arrIntersectionAB, arrDifferenceSetsAB, arrDifferenceSetsBA, arrSymmDFSetsAB);
        table->PrintTable();
        delete times;
        delete table;
        inputString = InputStr();
    }
}

string UserInterface::InputStr() {
    string inputString;
    cout << "Введите мощность множества(для выхода напишите exit): ";
    getline(std::cin, inputString);
    cout << endl;

    regex positive_int_or_exit_regex("^exit|[1-9]\\d{3,}$");

    while (!regex_match(inputString, positive_int_or_exit_regex)) {
        cout << "Введите корректное значения мощности(положительное целое число, которое больше или равно 1000): ";
        getline(std::cin, inputString);
        cout << endl;
    }

    return inputString;
}

void UserInterface::PrintTable() {
    // Set table headers
    string headers[] = { " ", "Односвязный список", "Класс 'Список'", "List", "Set", "priority_queue", "queue"};

    // Set table rows
    string rows[] = { "Создание множества", "Мощность", "Подмножество A-A", "Подмножество B-A", "Равенство A-A", "Равенство B-A", "Объединение А-В", "Пересечение А-В", "Разность A-B", "Разность B-А", "Симметричная разность А-В" };
    cout << setfill(Delimiter) << setw((ColWidth + 3) * 7) << "" << endl;
    // Print headers
    for (int i = 0; i < 7; i++) {
        cout << left << setw(ColWidth) << setfill(' ') << headers[i] << " | ";
    }
    cout << endl;

    // Print delimiter between headers and rows
    cout << setfill(Delimiter) << setw((ColWidth + 3) * 7) << "" << endl;
   
    PrintRow(rows[0], ResultTimeCreateSets);
    PrintRow(rows[1], ResultTimePowerSets);
    PrintRow(rows[2], ResultTimeSubSetsAA);
    PrintRow(rows[3], ResultTimeSubSetsAB);
    PrintRow(rows[4], ResultTimeEqualsSetsAA);
    PrintRow(rows[5], ResultTimeEqualsSetsBA);
    PrintRow(rows[6], ResultTimeMergeSetsAB);
    PrintRow(rows[7], ResultTimeIntersectionSetsAB);
    PrintRow(rows[8], ResultTimeDifferenceSetsAB);
    PrintRow(rows[9], ResultTimeDifferenceSetsBA);
    PrintRow(rows[10], ResultTimeSymmDifferenceSetsAB);
}

void UserInterface::PrintRow(string nameRows, long* arrResult) {
    cout << left << setw(ColWidth) << setfill(' ') << nameRows << " | ";
    cout << left << setw(ColWidth) << setfill(' ') << arrResult[0] << " | ";
    cout << left << setw(ColWidth) << setfill(' ') << arrResult[1] << " | ";
    cout << left << setw(ColWidth) << setfill(' ') << arrResult[2] << " | ";
    cout << left << setw(ColWidth) << setfill(' ') << arrResult[3] << " | ";
    cout << left << setw(ColWidth) << setfill(' ') << " " << " | ";
    cout << left << setw(ColWidth) << setfill(' ') << " " << " | ";
    cout << endl;
    // Print delimiter after each row
    cout << setfill(Delimiter) << setw((ColWidth + 3) * 7) << "" << endl;
}

