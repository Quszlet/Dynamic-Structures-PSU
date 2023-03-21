#include "SetLab5_Izgarev.h"
#include <iostream>
#include <random>
#include <string>

std::random_device rd;
std::mt19937 gen(rd());

using namespace std;


/*
	F1. �������� ������� ���������.
	������� ���������: ���.
	�������� ���������: ��������� �� ������ ������� ������, ������ NULL.
*/
SetList::SetList() {
	this->ContainerSet = set<int>();
}


/*
	F5. �������� ���������.
	������� ���������: ���������� ���������, �������� ���������� �������� (�� min �� max).
	�������� ���������: ��������� �� ������ ������� ������-����������.
	��������� �������� � �������� ��������� �����.
	������������ F4.
	����������: ��������� ����������� �������� ��������� � ��������� �����������.
*/
SetList::SetList(int len, int min, int max, int number) {
	this->ContainerSet = set<int>();
	if (len > 0 && max > min && len < max - min) {
		while (len > 0) {
			this->ContainerSet.insert(GenerateValueAorB(min, max, number));
			len--;
		}

	}
}

/*
	9.	��������� � � ��������� �����, ������� 3. ��������� � � ��������� �����, ������� 9.
*/
int SetList::GenerateValueAorB(int min, int max, int number) {
	int value = random(min, max);
	while (value % number != 0) {
		value = random(min, max);
	}
	return value;
}

// �������������� ������� ��� ��������� ��������� �����
int SetList::random(int low, int high)
{
	std::uniform_int_distribution<> dist(low, high);
	return dist(gen);
}


/*
	F6. �������� ���������.
	������� ���������: ��������� �� ������ ������� ������.
	�������� ���������: ������������� ��������.
	������������ F2.
*/
int SetList::PowerSet() {
	return this->ContainerSet.size();
}

/*
	F7. ����� ��������� ���������.
	������� ���������: ��������� �� ������ ������� ������, ������ �����������.
	�������� ���������: ������, ���������� �������� ���������, ����������� �������� �����������.
	������������ F2.
	����������: � ����� ������-���������� ����������� ������ �� ������
*/
string SetList::ToString(char sym) {
	if (!this->ContainerSet.empty()) {
		string result = "";
		for (int elem : this->ContainerSet) {
			result += to_string(elem);
			result += sym;
		}
		int len = result.length();
		return result.erase(len - 1, len);
	}
	return "";
}

/*
	F8. �������� ��������� (������� ������, ���������� �������).
	������� ���������: ��������� �� ������ ������� ������.
	�������� ���������: ��������� �� ������ ������� ������, ������ NULL.
*/
SetList::~SetList() {
	this->ContainerSet.clear();
}

/*
	F9. ������������ �-�. ������� ���������: ��� ��������� �� ������ �������� ������� � �������� �������� � � �.
	�������� ���������: ���������� �������� True, ���� � �������� ������������� �.
	������������ F2, F6.
*/
bool SetList::CheckSubSet(SetList* sub_set) {
	if (this->ContainerSet.empty()) {
		return true;
	}

	for (int elem : sub_set->ContainerSet) {

		if (!this->ContainerSet.contains(elem)) {
			return false;
		}
	}

	return true;
}

/*
	F10. ��������� ���� �������� �-�.
	������� ���������: ��� ��������� �� ������ �������� ������� � �������� �������� � � �.
	�������� ���������: ���������� �������� True, ���� � ����� �. ������������ F9.
*/
bool SetList::EqualsSets(SetList* second_set) {
	return CheckSubSet(second_set) && second_set->CheckSubSet(this);
}

/*
	F11. ����������� ���� ��������.
	������� ���������: ��� ��������� �� ������ �������� ������� � �������� ��������.
	�������� ���������: ��������� �� ������ ������� ������-����������. ������������ F2, F4.
*/
SetList* SetList::MergeSets(SetList* second_set) {

	SetList* result_set = new SetList();
	result_set->ContainerSet.insert(this->ContainerSet.begin(), this->ContainerSet.end());
	result_set->ContainerSet.insert(second_set->ContainerSet.begin(), second_set->ContainerSet.end());
	return result_set;
}

/*
	F12. ����������� ���� ��������.
	������� ���������: ��� ��������� �� ������ �������� ������� � �������� ��������.
	�������� ���������: ��������� �� ������ ������� ������-����������. ������������ F2, F4.
*/
SetList* SetList::IntersectionSets(SetList* second_set) {
	
	SetList* result_set = new SetList();
	for (int elem : second_set->ContainerSet) {

		if (this->ContainerSet.contains(elem)) {
			result_set->ContainerSet.insert(elem);
		}

	}
	return result_set;
}

/*
	F13. �������� ��������.
	������� ���������: ��� ��������� �� ������ �������� ������� � �������� ��������.
	�������� ���������: ��������� �� ������ ������� ������-����������. ������������ F2, F4.
*/
SetList* SetList::DifferenceSets(SetList* second_set) {

	SetList* result_set = new SetList();
	for (int elem : this->ContainerSet) {
		if (!second_set->ContainerSet.contains(elem)) {
			result_set->ContainerSet.insert(elem);
		}
	}
	return result_set;
}

/*
	F14. ������������ ��������.
	������� ���������: ��� ��������� �� ������ �������� ������� � �������� ��������.
	�������� ���������: ��������� �� ������ ������� ������-����������. ������������ F11, F12 � F13.
*/
SetList* SetList::SymmetricDifferenceSets(SetList* second_set) {
	SetList* merge_set = MergeSets(second_set);
	SetList* intersection_set = IntersectionSets(second_set);
	return merge_set->DifferenceSets(intersection_set);
}