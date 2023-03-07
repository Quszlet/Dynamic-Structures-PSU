#include<iostream>
#include "SetLab1_2_Izgarev.h"

using namespace std;

int main() {
	
	setlocale(LC_ALL, "ru");
	
	Node* set_a = CreateSetList(random(6,9), 10, 99, 'A');
	Node* set_b = CreateSetList(random(6, 9), 10, 99, 'B');
	cout << "Множество А: " << ToString(set_a, ' ') << endl;
	cout << "Множество В: " << ToString(set_b, ' ') << endl;
	cout << "Мощность А: " << PowerSetList(set_a) << endl;
	cout << "Мощность В: " << PowerSetList(set_b) << endl;
	cout << "F9. Подмножество А-В: " << boolalpha << CheckSubSet(set_a, set_b) << endl;
	cout << "F9. Подмножество А-A: " << boolalpha << CheckSubSet(set_a, set_a) << endl;
	cout << "F10. Равенство двух множеств А-В: " << boolalpha << EqualsSets(set_a, set_b) << endl;
	cout << "F10. Равенство двух множеств А-A: " << boolalpha << EqualsSets(set_a, set_a) << endl;
	cout << "F11. Объединение двух множеств А-B: " << ToString(MergeSets(set_a, set_b), ' ') << endl;
	cout << "F12. Пересечение двух множеств А-B: " << ToString(IntersectionSets(set_a, set_b), ' ') << endl;
	cout << "F13. Разность множеств А-B: " << ToString(DifferenceSets(set_a, set_b), ' ') << endl;
	cout << "F13. Разность множеств B-A: " << ToString(DifferenceSets(set_b, set_a), ' ') << endl;
	cout << "F14. Симметричная разность А-B: " << ToString(SymmetricDifferenceSets(set_a, set_b), ' ') << endl;
	cout << "Удаление множества А: " << ToString(DeleteSetList(set_a), ' ') << endl;
	cout << "Удаление множества B: " << ToString(DeleteSetList(set_b), ' ') << endl;
}