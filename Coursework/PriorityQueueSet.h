#pragma once
#include <string>
#include <queue>

class PriorityQueueSet {
private:

	std::priority_queue<int> ContainerPriorityQueueSet;

	// ������� ��� F5
	int GenerateValueAorB(int min, int max, int number);

public:
	/*
	F1. �������� ������� ���������.
	������� ���������: ���.
	�������� ���������: ��������� �� ������ ������� ������, ������ NULL.
	*/
	PriorityQueueSet();

	/*
		F2. ������ ���������?
		������� ���������: ��������� �� ������ ������� ������.
		�������� ���������: ���������� ��������.
	*/
	bool EmptySet();

	/*
		F3. �������� �������������� �������� ���������.
		������� ���������: ��������� �� ������ ������� ������, �������� ��������.
		�������� ���������: ���������� ��������. ������������ F2.
	*/
	bool ItemInSet(int val);

	/*
		F4. ���������� ������ �������� � ���������.
		������� ���������: ��������� �� ������ ������� ������, ����������� � ������ ��������.
		�������� ���������: ��������� �� ������ ������� ������-����������.
		������������ F3. �����������: ���������� ������������ � ������ ������.
	*/
	bool AddItem(int val);


	/*
		F5. �������� ���������.
		������� ���������: ���������� ���������, �������� ���������� �������� (�� min �� max).
		�������� ���������: ��������� �� ������ ������� ������-����������.
		��������� �������� � �������� ��������� �����.
		������������ F4.
		����������: ��������� ����������� �������� ��������� � ��������� �����������.
	*/
	PriorityQueueSet(int len, int min, int max);


	/// �������������� ������� ��� ��������� ��������� �����
	int random(int low, int high);

	/*
		F6. �������� ���������.
		������� ���������: ��������� �� ������ ������� ������.
		�������� ���������: ������������� ��������.
		������������ F2.
	*/
	int PowerSet();

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
	~PriorityQueueSet();

	/*
		F9. ������������ �-�. ������� ���������: ��� ��������� �� ������ �������� ������� � �������� �������� � � �.
		�������� ���������: ���������� �������� True, ���� � �������� ������������� �.
		������������ F2, F6.
	*/
	bool CheckSubSet(PriorityQueueSet* sub_set);

	/*
		F10. ��������� ���� �������� �-�.
		������� ���������: ��� ��������� �� ������ �������� ������� � �������� �������� � � �.
		�������� ���������: ���������� �������� True, ���� � ����� �. ������������ F9.
	*/
	bool EqualsSets(PriorityQueueSet* second_set);

	/*
		F11. ����������� ���� ��������.
		������� ���������: ��� ��������� �� ������ �������� ������� � �������� ��������.
		�������� ���������: ��������� �� ������ ������� ������-����������. ������������ F2, F4.
	*/
	PriorityQueueSet* MergeSets(PriorityQueueSet* second_set);

	/*
		F12. ����������� ���� ��������.
		������� ���������: ��� ��������� �� ������ �������� ������� � �������� ��������.
		�������� ���������: ��������� �� ������ ������� ������-����������. ������������ F2, F4.
	*/
	PriorityQueueSet* IntersectionSets(PriorityQueueSet* second_set);

	/*
		F13. �������� ��������.
		������� ���������: ��� ��������� �� ������ �������� ������� � �������� ��������.
		�������� ���������: ��������� �� ������ ������� ������-����������. ������������ F2, F4.
	*/
	PriorityQueueSet* DifferenceSets(PriorityQueueSet* second_set);

	/*
		F14. ������������ ��������.
		������� ���������: ��� ��������� �� ������ �������� ������� � �������� ��������.
		�������� ���������: ��������� �� ������ ������� ������-����������. ������������ F11, F12 � F13.
	*/
	PriorityQueueSet* SymmetricDifferenceSets(PriorityQueueSet* second_set);
};



