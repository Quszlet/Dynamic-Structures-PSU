#pragma once
#include <string>
#include <list>

class ContListSet {
private:

	std::list<int> ContainerListSet;

	// ������� ��� F5
	int GenerateValueAorB(int min, int max, int number);

public:
	/*
	F1. �������� ������� ���������.
	������� ���������: ���.
	�������� ���������: ��������� �� ������ ������� ������, ������ NULL.
	*/
	ContListSet();

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
	ContListSet(int len, int min, int max);


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
	~ContListSet();

	/*
		F9. ������������ �-�. ������� ���������: ��� ��������� �� ������ �������� ������� � �������� �������� � � �.
		�������� ���������: ���������� �������� True, ���� � �������� ������������� �.
		������������ F2, F6.
	*/
	bool CheckSubSet(ContListSet* sub_set);

	/*
		F10. ��������� ���� �������� �-�.
		������� ���������: ��� ��������� �� ������ �������� ������� � �������� �������� � � �.
		�������� ���������: ���������� �������� True, ���� � ����� �. ������������ F9.
	*/
	bool EqualsSets(ContListSet* second_set);

	/*
		F11. ����������� ���� ��������.
		������� ���������: ��� ��������� �� ������ �������� ������� � �������� ��������.
		�������� ���������: ��������� �� ������ ������� ������-����������. ������������ F2, F4.
	*/
	ContListSet* MergeSets(ContListSet* second_set);

	/*
		F12. ����������� ���� ��������.
		������� ���������: ��� ��������� �� ������ �������� ������� � �������� ��������.
		�������� ���������: ��������� �� ������ ������� ������-����������. ������������ F2, F4.
	*/
	ContListSet* IntersectionSets(ContListSet* second_set);

	/*
		F13. �������� ��������.
		������� ���������: ��� ��������� �� ������ �������� ������� � �������� ��������.
		�������� ���������: ��������� �� ������ ������� ������-����������. ������������ F2, F4.
	*/
	ContListSet* DifferenceSets(ContListSet* second_set);

	/*
		F14. ������������ ��������.
		������� ���������: ��� ��������� �� ������ �������� ������� � �������� ��������.
		�������� ���������: ��������� �� ������ ������� ������-����������. ������������ F11, F12 � F13.
	*/
	ContListSet* SymmetricDifferenceSets(ContListSet* second_set);
};



