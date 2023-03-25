#include "SetLab5_Izgarev.h"
#include <iostream>
#include <random>
#include <string>

std::random_device rd;
std::mt19937 gen(rd());

using namespace std;


/*
	F1. �������� ������� ���������.
*/
Set::Set() {
	this->ContainerSet = set<int>();
}


/*
	F2. ������ ���������?
*/
bool Set::EmptySet() {
	return this->ContainerSet.empty();
}

/*
	F3. �������� �������������� �������� ���������.
*/
bool Set::ItemInSet(int val) {
	return this->ContainerSet.contains(val);
}

/*
	F4. ���������� ������ �������� � ���������.
*/
bool Set::AddItem(int val) {
	return this->ContainerSet.insert(val).second;
}

/*
	F5. �������� ���������.
*/
Set::Set(int len, int min, int max, int number) {
	this->ContainerSet = set<int>();
	if (len > 0 && max > min && len < max - min) {
		while (len > 0) {
			bool check = AddItem(GenerateValueAorB(min, max, number));
			if (check) {
				len--;
			}
		}

	}
}

/*
	9.	��������� � � ��������� �����, ������� 3. ��������� � � ��������� �����, ������� 9.
*/
int Set::GenerateValueAorB(int min, int max, int number) {
	int value = random(min, max);
	while (value % number != 0) {
		value = random(min, max);
	}
	return value;
}

// �������������� ������� ��� ��������� ��������� �����
int Set::random(int low, int high)
{
	std::uniform_int_distribution<> dist(low, high);
	return dist(gen);
}


/*
	F6. �������� ���������.
	������������ F2.
*/
int Set::PowerSet() {
	return this->ContainerSet.size();
}

/*
	F7. ����� ��������� ���������.
	������������ F2.
	����������: � ����� ������-���������� ����������� ������ �� ������
*/
string Set::ToString(char sym) {
	if (!EmptySet()) {
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
*/
Set::~Set() {
	this->ContainerSet.clear();
}

/*
	F9. ������������ �-�. ������� ���������: ��� ��������� �� ������ �������� ������� � �������� �������� � � �.
	������������ F2, F6.
*/
bool Set::CheckSubSet(Set* sub_set) {
	if (EmptySet()) {
		return true;
	}

	for (int elem : sub_set->ContainerSet) {

		if (!ItemInSet(elem)) {
			return false;
		}
	}

	return true;
}

/*
	F10. ��������� ���� �������� �-�.
*/
bool Set::EqualsSets(Set* second_set) {
	return CheckSubSet(second_set) && second_set->CheckSubSet(this);
}

/*
	F11. ����������� ���� ��������.
*/
Set* Set::MergeSets(Set* second_set) {

	Set* result_set = new Set();
	result_set->ContainerSet.insert(this->ContainerSet.begin(), this->ContainerSet.end());
	result_set->ContainerSet.insert(second_set->ContainerSet.begin(), second_set->ContainerSet.end());
	return result_set;
}

/*
	F12. ����������� ���� ��������.
*/
Set* Set::IntersectionSets(Set* second_set) {
	
	Set* result_set = new Set();
	for (int elem : second_set->ContainerSet) {

		if (ItemInSet(elem)) {
			result_set->ContainerSet.insert(elem);
		}

	}
	return result_set;
}

/*
	F13. �������� ��������.
*/
Set* Set::DifferenceSets(Set* second_set) {

	Set* result_set = new Set();
	for (int elem : this->ContainerSet) {
		if (!second_set->ItemInSet(elem)) {
			result_set->AddItem(elem);
		}
	}
	return result_set;
}

/*
	F14. ������������ ��������.
*/
Set* Set::SymmetricDifferenceSets(Set* second_set) {
	Set* merge_set = MergeSets(second_set);
	Set* intersection_set = IntersectionSets(second_set);
	return merge_set->DifferenceSets(intersection_set);
}