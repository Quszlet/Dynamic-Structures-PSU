#include "SetLab4_Izgarev.h"
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
	this->ContainerListSet = list<int>();
}

/*
	F2. ������ ���������?
	������� ���������: ��������� �� ������ ������� ������.
	�������� ���������: ���������� ��������.
*/
bool SetList::EmptySetList() {
	return this->ContainerListSet.empty();
}

/*
	F3. �������� �������������� �������� ���������.
	������� ���������: ��������� �� ������ ������� ������, �������� ��������.
	�������� ���������: ���������� ��������. ������������ F2.
*/
bool SetList::ItemInSetList(int val) {
	if (!EmptySetList()) {
		for (auto elem : this->ContainerListSet) {
			if (elem == val) {
				return true;
			}
		}
	}
	return false;
}

/*
	F4. ���������� ������ �������� � ���������.
	������� ���������: ��������� �� ������ ������� ������, ����������� � ������ ��������.
	�������� ���������: ��������� �� ������ ������� ������-����������.
	������������ F3. �����������: ���������� ������������ � ������ ������.
*/
void SetList::AddItem(int val) {
	if (ItemInSetList(val)) {
		return;
	}
	else {
		this->ContainerListSet.push_front(val);
	}
}

/*
	F5. �������� ���������.
	������� ���������: ���������� ���������, �������� ���������� �������� (�� min �� max).
	�������� ���������: ��������� �� ������ ������� ������-����������.
	��������� �������� � �������� ��������� �����.
	������������ F4.
	����������: ��������� ����������� �������� ��������� � ��������� �����������.
*/
SetList::SetList(int len, int min, int max, char sym) {
	this->ContainerListSet = list<int>();
	if (len > 0 && max > min && len < max - min) {
		list<int>::const_iterator pred_node = this->ContainerListSet.begin();
		while (len > 0) {
			AddItem(GenerateValueAorB(min, max, sym));
			if (this->ContainerListSet.begin() != pred_node) {
				len--;
			}
			pred_node = this->ContainerListSet.begin();

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
int SetList::PowerSetList() {
	return this->ContainerListSet.size();
}

/*
	F7. ����� ��������� ���������.
	������� ���������: ��������� �� ������ ������� ������, ������ �����������.
	�������� ���������: ������, ���������� �������� ���������, ����������� �������� �����������.
	������������ F2.
	����������: � ����� ������-���������� ����������� ������ �� ������
*/
string SetList::ToString(char sym) {
	if (!EmptySetList()) {
		string result = "";
		for (auto elem : this->ContainerListSet) {
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
	this->ContainerListSet.clear();
}

/*
	F9. ������������ �-�. ������� ���������: ��� ��������� �� ������ �������� ������� � �������� �������� � � �.
	�������� ���������: ���������� �������� True, ���� � �������� ������������� �.
	������������ F2, F6.
*/
bool SetList::CheckSubSet(SetList* sub_set) {
	if (EmptySetList()) {
		return true;
	}

	for (auto elem : sub_set->ContainerListSet) {

		if (!ItemInSetList(elem)) {
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
	for (auto elem : this->ContainerListSet) {
		result_set->AddItem(elem);
	}
	for (auto elem : second_set->ContainerListSet) {
		result_set->AddItem(elem);
	}
	return result_set;
}

/*
	F12. ����������� ���� ��������.
	������� ���������: ��� ��������� �� ������ �������� ������� � �������� ��������.
	�������� ���������: ��������� �� ������ ������� ������-����������. ������������ F2, F4.
*/
SetList* SetList::IntersectionSets(SetList* second_set) {

	SetList* result_set = new SetList();
	for (auto elem : second_set->ContainerListSet) {

		if (ItemInSetList(elem)) {
			result_set->AddItem(elem);
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
	for (auto elem : this->ContainerListSet) {
		if (!second_set->ItemInSetList(elem)) {
			result_set->AddItem(elem);
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