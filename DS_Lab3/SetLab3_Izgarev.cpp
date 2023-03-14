#include "SetLab3_Izgarev.h"
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
	first_node = nullptr;
}

/*
	F2. ������ ���������?
	������� ���������: ��������� �� ������ ������� ������.
	�������� ���������: ���������� ��������.
*/
bool SetList::EmptySetList() {
	return first_node == nullptr;
}

/*
	F3. �������� �������������� �������� ���������.
	������� ���������: ��������� �� ������ ������� ������, �������� ��������.
	�������� ���������: ���������� ��������. ������������ F2.
*/
bool SetList::ItemInSetList(int val) {
	if (!EmptySetList()) {
		for (Node* item = first_node; item != nullptr; item = item->next) {
			if (item->value == val) {
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
		Node* node = new Node();
		node->value = val;
		node->next = first_node;
		first_node = node;
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
	first_node = nullptr;
	if (len > 0 && max > min && len < max - min) {
		Node* pred_node = this->first_node;
		while (len > 0) {
			AddItem(GenerateValueAorB(min, max, sym));
			if (this->first_node != pred_node) {
				len--;
			}
			pred_node = this->first_node;
		}
	}
};

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
	if (EmptySetList()) {
		return 0;
	}
	else {
		int len = 0;
		for (Node* item = this->first_node; item != nullptr; item = item->next) {
			len++;
		}
		return len;
	}
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
		for (Node* item = this->first_node; item != nullptr; item = item->next) {
			result += to_string(item->value);
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
	while (first_node != nullptr) {
		Node* support_node = first_node->next;
		delete this->first_node;
		this->first_node = support_node;
	}
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

	for (Node* sub_elem = sub_set->first_node; sub_elem != nullptr; sub_elem = sub_elem->next) {

		if (!ItemInSetList(sub_elem->value)) {
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
	for (Node* first_elem = first_node; first_elem != nullptr; first_elem = first_elem->next) {
		result_set->AddItem(first_elem->value);
	}
	for (Node* first_elem = second_set->first_node; first_elem != nullptr; first_elem = first_elem->next) {
		result_set->AddItem(first_elem->value);
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
	for (Node* first_elem = second_set->first_node; first_elem != nullptr; first_elem = first_elem->next) {

		if (ItemInSetList(first_elem->value)) {
			result_set->AddItem(first_elem->value);
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
	for (Node* first_elem = first_node; first_elem != nullptr; first_elem = first_elem->next) {
		if (!second_set->ItemInSetList(first_elem->value)) {
			result_set->AddItem(first_elem->value);
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