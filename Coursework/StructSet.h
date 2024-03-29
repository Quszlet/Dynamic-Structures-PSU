#pragma once
#include <string>
#include "Node.h"

/*
	F1. �������� ������� ���������.
	������� ���������: ���.
	�������� ���������: ��������� �� ������ ������� ������, ������ NULL.
*/
Node* CreateSetList();

/*
	F2. ������ ���������?
	������� ���������: ��������� �� ������ ������� ������.
	�������� ���������: ���������� ��������.
*/
bool EmptySetList(Node* first_element);

/*
	F3. �������� �������������� �������� ���������.
	������� ���������: ��������� �� ������ ������� ������, �������� ��������.
	�������� ���������: ���������� ��������. ������������ F2.
*/
bool ItemInSetList(Node* first_element, int val);

/*
	F4. ���������� ������ �������� � ���������.
	������� ���������: ��������� �� ������ ������� ������, ����������� � ������ ��������.
	�������� ���������: ��������� �� ������ ������� ������-����������.
	������������ F3. �����������: ���������� ������������ � ������ ������.
*/
Node* AddItem(Node* first_element, int val);

/*
	F5. �������� ���������.
	������� ���������: ���������� ���������, �������� ���������� �������� (�� min �� max).
	�������� ���������: ��������� �� ������ ������� ������-����������.
	��������� �������� � �������� ��������� �����.
	������������ F4.
	����������: ��������� ����������� �������� ��������� � ��������� �����������.
*/
Node* CreateSetList(int len, int min, int max);

// ������� ���������� ������� F5
int GenerateValueAorB(int min, int max, int number);
/// �������������� ������� ��� ��������� ��������� �����
int random(int low, int high);

/*
	F6. �������� ���������.
	������� ���������: ��������� �� ������ ������� ������.
	�������� ���������: ������������� ��������.
	������������ F2.
*/
int PowerSetList(Node* first_element);

/*
	F7. ����� ��������� ���������.
	������� ���������: ��������� �� ������ ������� ������, ������ �����������.
	�������� ���������: ������, ���������� �������� ���������, ����������� �������� �����������.
	������������ F2.
	����������: � ����� ������-���������� ����������� ������ �� ������
*/
std::string ToString(Node* first_element, char sym);

/*
	F8. �������� ��������� (������� ������, ���������� �������).
	������� ���������: ��������� �� ������ ������� ������.
	�������� ���������: ��������� �� ������ ������� ������, ������ NULL.
*/
Node* DeleteSetList(Node* first_element);

/*
	F9. ������������ �-�. ������� ���������: ��� ��������� �� ������ �������� ������� � �������� �������� � � �.
	�������� ���������: ���������� �������� True, ���� � �������� ������������� �.
	������������ F2, F6.
*/
bool CheckSubSet(Node* sub_set, Node* set);

/*
	F10. ��������� ���� �������� �-�.
	������� ���������: ��� ��������� �� ������ �������� ������� � �������� �������� � � �.
	�������� ���������: ���������� �������� True, ���� � ����� �. ������������ F9.
*/
bool EqualsSets(Node* first_set, Node* second_set);

/*
	F11. ����������� ���� ��������.
	������� ���������: ��� ��������� �� ������ �������� ������� � �������� ��������.
	�������� ���������: ��������� �� ������ ������� ������-����������. ������������ F2, F4.
*/
Node* MergeSets(Node* first_set, Node* second_set);

/*
	F12. ����������� ���� ��������.
	������� ���������: ��� ��������� �� ������ �������� ������� � �������� ��������.
	�������� ���������: ��������� �� ������ ������� ������-����������. ������������ F2, F4.
*/
Node* IntersectionSets(Node* first_set, Node* second_set);

/*
	F13. �������� ��������.
	������� ���������: ��� ��������� �� ������ �������� ������� � �������� ��������.
	�������� ���������: ��������� �� ������ ������� ������-����������. ������������ F2, F4.
*/
Node* DifferenceSets(Node* first_set, Node* second_set);

/*
	F14. ������������ ��������.
	������� ���������: ��� ��������� �� ������ �������� ������� � �������� ��������.
	�������� ���������: ��������� �� ������ ������� ������-����������. ������������ F11, F12 � F13.
*/
Node* SymmetricDifferenceSets(Node* first_set, Node* second_set);

