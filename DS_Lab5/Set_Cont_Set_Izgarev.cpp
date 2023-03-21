#include<iostream>
#include "SetLab5_Izgarev.h"

using namespace std;

int main() {

	setlocale(LC_ALL, "ru");

	SetList* set_a = new SetList(SetList::random(6, 9), 10, 99, 3);
	SetList* set_b = new SetList(SetList::random(6, 9), 10, 99, 9);
	cout << "F5. ��������� �: " << set_a->ToString(' ') << endl;
	cout << "F5. ��������� �: " << set_b->ToString(' ') << endl;
	cout << "F6. �������� �: " << set_a->PowerSet() << endl;
	cout << "F6. �������� �: " << set_b->PowerSet() << endl;
	cout << "F7. ����� ��������� �: " << set_a->ToString('|') << endl;
	cout << "F7. ����� ��������� �: " << set_b->ToString('|') << endl;
	cout << "F9. ������������ �-�: " << boolalpha << set_a->CheckSubSet(set_b) << endl;
	cout << "F9. ������������ �-A: " << boolalpha << set_a->CheckSubSet(set_a) << endl;
	cout << "F10. ��������� ���� �������� �-�: " << boolalpha << set_a->EqualsSets(set_b) << endl;
	cout << "F10. ��������� ���� �������� �-A: " << boolalpha << set_a->EqualsSets(set_a) << endl;
	cout << "F11. ����������� ���� �������� �-B: " << set_a->MergeSets(set_b)->ToString(' ') << endl;
	cout << "F12. ����������� ���� �������� �-B: " << set_a->IntersectionSets(set_b)->ToString(' ') << endl;
	cout << "F13. �������� �������� �-B: " << set_a->DifferenceSets(set_b)->ToString(' ') << endl;
	cout << "F13. �������� �������� B-A: " << set_b->DifferenceSets(set_a)->ToString(' ') << endl;
	cout << "F14. ������������ �������� �-B: " << set_a->SymmetricDifferenceSets(set_b)->ToString(' ') << endl;
	cout << "�������� ��������� �:" << endl;
	delete set_a;
	set_a = nullptr;
	cout << "�������� ��������� B:" << endl;
	delete set_b;
	set_b = nullptr;
}