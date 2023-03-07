#include "SetLab1_2_Izgarev.h"
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
Node* CreateSetList() {
	return nullptr;
}

/*
	F2. ������ ���������?
	������� ���������: ��������� �� ������ ������� ������.
	�������� ���������: ���������� ��������.
*/
bool EmptySetList(Node* first_element) {
	return first_element == nullptr;
}

/*
	F3. �������� �������������� �������� ���������.
	������� ���������: ��������� �� ������ ������� ������, �������� ��������.
	�������� ���������: ���������� ��������. ������������ F2.
*/
bool ItemInSetList(Node* first_element, int val) {
	if (!EmptySetList(first_element)) {
		for (Node* item = first_element; item != nullptr; item = item->next) {
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
Node* AddItem(Node* first_element, int val) {
	if (ItemInSetList(first_element, val)) {
		return first_element;
	} 
	else {
		Node* node = new Node();
		node->next = first_element;
		node->value = val;
		return node;
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
Node* CreateSetList(int len, int min, int max, char sym) {
	Node* set = CreateSetList();
	if (len > 0 && max > min && len < max - min) {
		Node* pred_node = set;
		while (len > 0) {
			set = AddItem(set, GenerateValueAorB(min, max, sym));
			if (set != pred_node) {
				len--;
			}
			pred_node = set;
		}
	}
	return set;
};

/*
	9.	��������� � � ��������� �����, ������� 3. ��������� � � ��������� �����, ������� 9.
*/
int GenerateValueAorB(int min, int max, char sym) {
	int value = random(min, max);
	switch (sym)
	{
	case 'A':
		while (value % 3 != 0) {
			value = random(min, max);
		}
		return value;
	case 'B':
		while (value % 9 != 0) {
			value = random(min, max);
		}
		return value;
	default:
		return -1;
	}
}

// �������������� ������� ��� ��������� ��������� �����
int random(int low, int high)
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
int PowerSetList(Node* first_element) {
	if (EmptySetList(first_element)) {
		return 0;
	} 
	else {
		int len = 0;
		for (Node* item = first_element; item != nullptr; item = item->next) {
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
string ToString(Node* first_element, char sym) {
	if (!EmptySetList(first_element)) {
		string result = "";
		for (Node* item = first_element; item != nullptr; item = item->next) {
			result += to_string(item->value);
			result += sym;
		}
		int len = result.length();
		return result.erase(len-1, len);
	}
	return "";
}

/*
	F8. �������� ��������� (������� ������, ���������� �������).
	������� ���������: ��������� �� ������ ������� ������.
	�������� ���������: ��������� �� ������ ������� ������, ������ NULL.
*/
Node* DeleteSetList(Node* first_element) {
	if (!EmptySetList(first_element)) {
		Node* result_ptr = DeleteSetList(first_element->next);
		delete first_element;
		first_element = result_ptr;
	}
	else {
		return nullptr;
	}	
}

/*
	F9. ������������ �-�. ������� ���������: ��� ��������� �� ������ �������� ������� � �������� �������� � � �.
	�������� ���������: ���������� �������� True, ���� � �������� ������������� �.
	������������ F2, F6.
*/
bool CheckSubSet(Node* sub_set, Node* set) {
	if (EmptySetList(sub_set)) {
		return true;
	}

	for (Node* sub_elem = sub_set; sub_elem != nullptr; sub_elem = sub_elem->next) {
		
			if (!ItemInSetList(set, sub_elem->value)) {
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
bool EqualsSets(Node* first_set, Node* second_set) {
	return CheckSubSet(second_set, first_set) && CheckSubSet(first_set, second_set);
}

/*
	F11. ����������� ���� ��������.
	������� ���������: ��� ��������� �� ������ �������� ������� � �������� ��������.
	�������� ���������: ��������� �� ������ ������� ������-����������. ������������ F2, F4.
*/
Node* MergeSets(Node* first_set, Node* second_set) {

	Node* result_set = CreateSetList();
	while (true) {

		if (first_set != nullptr) {
			result_set = AddItem(result_set, first_set->value);
			first_set = first_set->next;
		} else if (second_set != nullptr) {
			result_set = AddItem(result_set, second_set->value);
			second_set = second_set->next;
		}
		else {
			return result_set;
		}

	}
}

/*
	F12. ����������� ���� ��������.
	������� ���������: ��� ��������� �� ������ �������� ������� � �������� ��������.
	�������� ���������: ��������� �� ������ ������� ������-����������. ������������ F2, F4.
*/
Node* IntersectionSets(Node* first_set, Node* second_set) {
	
	Node* result_set = CreateSetList();
	for (Node* first_elem = first_set; first_elem != nullptr; first_elem = first_elem->next) {
		
		if (ItemInSetList(second_set, first_elem->value)) {
			result_set = AddItem(result_set, first_elem->value);
		}
		
	}
	return result_set;
}

/*
	F13. �������� ��������.
	������� ���������: ��� ��������� �� ������ �������� ������� � �������� ��������.
	�������� ���������: ��������� �� ������ ������� ������-����������. ������������ F2, F4.
*/
Node* DifferenceSets(Node* first_set, Node* second_set) {

	Node* result_set = CreateSetList();
	for (Node* first_elem = first_set; first_elem != nullptr; first_elem = first_elem->next) {
		if (!ItemInSetList(second_set, first_elem->value)) {
			result_set = AddItem(result_set, first_elem->value);
		}
	}
	return result_set;
}

/*
	F14. ������������ ��������.
	������� ���������: ��� ��������� �� ������ �������� ������� � �������� ��������.
	�������� ���������: ��������� �� ������ ������� ������-����������. ������������ F11, F12 � F13.
*/
Node* SymmetricDifferenceSets(Node* first_set, Node* second_set) {
	Node* merge_set = MergeSets(first_set, second_set);
	Node* intersection_set = IntersectionSets(first_set, second_set);
	return DifferenceSets(merge_set, intersection_set);
}