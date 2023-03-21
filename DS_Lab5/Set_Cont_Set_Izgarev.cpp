#include<iostream>
#include "SetLab5_Izgarev.h"

using namespace std;

int main() {

	setlocale(LC_ALL, "ru");

	SetList* set_a = new SetList(SetList::random(6, 9), 10, 99, 3);
	SetList* set_b = new SetList(SetList::random(6, 9), 10, 99, 9);
	cout << "F5. Множество А: " << set_a->ToString(' ') << endl;
	cout << "F5. Множество В: " << set_b->ToString(' ') << endl;
	cout << "F6. Мощность А: " << set_a->PowerSet() << endl;
	cout << "F6. Мощность В: " << set_b->PowerSet() << endl;
	cout << "F7. Вывод множества А: " << set_a->ToString('|') << endl;
	cout << "F7. Вывод множества В: " << set_b->ToString('|') << endl;
	cout << "F9. Подмножество А-В: " << boolalpha << set_a->CheckSubSet(set_b) << endl;
	cout << "F9. Подмножество А-A: " << boolalpha << set_a->CheckSubSet(set_a) << endl;
	cout << "F10. Равенство двух множеств А-В: " << boolalpha << set_a->EqualsSets(set_b) << endl;
	cout << "F10. Равенство двух множеств А-A: " << boolalpha << set_a->EqualsSets(set_a) << endl;
	cout << "F11. Объединение двух множеств А-B: " << set_a->MergeSets(set_b)->ToString(' ') << endl;
	cout << "F12. Пересечение двух множеств А-B: " << set_a->IntersectionSets(set_b)->ToString(' ') << endl;
	cout << "F13. Разность множеств А-B: " << set_a->DifferenceSets(set_b)->ToString(' ') << endl;
	cout << "F13. Разность множеств B-A: " << set_b->DifferenceSets(set_a)->ToString(' ') << endl;
	cout << "F14. Симметричная разность А-B: " << set_a->SymmetricDifferenceSets(set_b)->ToString(' ') << endl;
	cout << "Удаление множества А:" << endl;
	delete set_a;
	set_a = nullptr;
	cout << "Удаление множества B:" << endl;
	delete set_b;
	set_b = nullptr;
}