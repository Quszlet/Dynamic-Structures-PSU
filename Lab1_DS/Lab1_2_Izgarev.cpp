#include<iostream>
#include "SetLab1_2_Izgarev.h"

using namespace std;

int main() {
	
	setlocale(LC_ALL, "ru");
	
	Node* set_a = CreateSetList(random(6,9), 10, 99, 'A');
	Node* set_b = CreateSetList(random(6, 9), 10, 99, 'B');
	cout << "��������� �: " << ToString(set_a, ' ') << endl;
	cout << "��������� �: " << ToString(set_b, ' ') << endl;
	cout << "�������� �: " << PowerSetList(set_a) << endl;
	cout << "�������� �: " << PowerSetList(set_b) << endl;
	cout << "F9. ������������ �-�: " << boolalpha << CheckSubSet(set_a, set_b) << endl;
	cout << "F9. ������������ �-A: " << boolalpha << CheckSubSet(set_a, set_a) << endl;
	cout << "F10. ��������� ���� �������� �-�: " << boolalpha << EqualsSets(set_a, set_b) << endl;
	cout << "F10. ��������� ���� �������� �-A: " << boolalpha << EqualsSets(set_a, set_a) << endl;
	cout << "F11. ����������� ���� �������� �-B: " << ToString(MergeSets(set_a, set_b), ' ') << endl;
	cout << "F12. ����������� ���� �������� �-B: " << ToString(IntersectionSets(set_a, set_b), ' ') << endl;
	cout << "F13. �������� �������� �-B: " << ToString(DifferenceSets(set_a, set_b), ' ') << endl;
	cout << "F13. �������� �������� B-A: " << ToString(DifferenceSets(set_b, set_a), ' ') << endl;
	cout << "F14. ������������ �������� �-B: " << ToString(SymmetricDifferenceSets(set_a, set_b), ' ') << endl;
	cout << "�������� ��������� �: " << ToString(DeleteSetList(set_a), ' ') << endl;
	cout << "�������� ��������� B: " << ToString(DeleteSetList(set_b), ' ') << endl;
}