#pragma once
#include <string>

struct Node {
	int value;
	Node* next;
};

class SetList {
private:
	Node* first_node;

	// ������� ���������� ������� F5
	int GenerateValueAorB(int min, int max, char sym);
public:
	/*
	F1. �������� ������� ���������.
	������� ���������: ���.
	�������� ���������: ��������� �� ������ ������� ������, ������ NULL.
	*/
	SetList();


	/*
		F2. ������ ���������?
		������� ���������: ��������� �� ������ ������� ������.
		�������� ���������: ���������� ��������.
	*/
	bool EmptySetList();

	/*
		F3. �������� �������������� �������� ���������.
		������� ���������: ��������� �� ������ ������� ������, �������� ��������.
		�������� ���������: ���������� ��������. ������������ F2.
	*/
	bool ItemInSetList(int val);

	/*
		F4. ���������� ������ �������� � ���������.
		������� ���������: ��������� �� ������ ������� ������, ����������� � ������ ��������.
		�������� ���������: ��������� �� ������ ������� ������-����������.
		������������ F3. �����������: ���������� ������������ � ������ ������.
	*/
	void AddItem(int val);

	/*
		F5. �������� ���������.
		������� ���������: ���������� ���������, �������� ���������� �������� (�� min �� max).
		�������� ���������: ��������� �� ������ ������� ������-����������.
		��������� �������� � �������� ��������� �����.
		������������ F4.
		����������: ��������� ����������� �������� ��������� � ��������� �����������.
	*/
	SetList(int len, int min, int max, char sym);


	/// �������������� ������� ��� ��������� ��������� �����
	int static random(int low, int high);

	/*
		F6. �������� ���������.
		������� ���������: ��������� �� ������ ������� ������.
		�������� ���������: ������������� ��������.
		������������ F2.
	*/
	int PowerSetList();

	/*
		F7. ����� ��������� ���������.
		������� ���������: ��������� �� ������ ������� ������, ������ �����������.
		�������� ���������: ������, ���������� �������� ���������, ����������� �������� �����������.
		������������ F2.
		����������: � ����� ������-���������� ����������� ������ �� ������
	*/
	std::string ToString(char sym);

	/*
		F8. �������� ��������� (������� ������, ���������� �������).
		������� ���������: ��������� �� ������ ������� ������.
		�������� ���������: ��������� �� ������ ������� ������, ������ NULL.
	*/
	~SetList();

	/*
		F9. ������������ �-�. ������� ���������: ��� ��������� �� ������ �������� ������� � �������� �������� � � �.
		�������� ���������: ���������� �������� True, ���� � �������� ������������� �.
		������������ F2, F6.
	*/
	bool CheckSubSet(SetList* sub_set);

	/*
		F10. ��������� ���� �������� �-�.
		������� ���������: ��� ��������� �� ������ �������� ������� � �������� �������� � � �.
		�������� ���������: ���������� �������� True, ���� � ����� �. ������������ F9.
	*/
	bool EqualsSets(SetList* second_set);

	/*
		F11. ����������� ���� ��������.
		������� ���������: ��� ��������� �� ������ �������� ������� � �������� ��������.
		�������� ���������: ��������� �� ������ ������� ������-����������. ������������ F2, F4.
	*/
	SetList* MergeSets(SetList* second_set);

	/*
		F12. ����������� ���� ��������.
		������� ���������: ��� ��������� �� ������ �������� ������� � �������� ��������.
		�������� ���������: ��������� �� ������ ������� ������-����������. ������������ F2, F4.
	*/
	SetList* IntersectionSets(SetList* second_set);

	/*
		F13. �������� ��������.
		������� ���������: ��� ��������� �� ������ �������� ������� � �������� ��������.
		�������� ���������: ��������� �� ������ ������� ������-����������. ������������ F2, F4.
	*/
	SetList* DifferenceSets(SetList* second_set);

	/*
		F14. ������������ ��������.
		������� ���������: ��� ��������� �� ������ �������� ������� � �������� ��������.
		�������� ���������: ��������� �� ������ ������� ������-����������. ������������ F11, F12 � F13.
	*/
	SetList* SymmetricDifferenceSets(SetList* second_set);
};

