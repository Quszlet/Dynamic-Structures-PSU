//#include "PriorityQueueSet.h"
//
//using namespace std;
//
//PriorityQueueSet::PriorityQueueSet() {
//	this->ContainerPriorityQueueSet = priority_queue<int>();
//}
//
///*
//	F2. ������ ���������?
//	������� ���������: ��������� �� ������ ������� ������.
//	�������� ���������: ���������� ��������.
//*/
//bool PriorityQueueSet::EmptySet() {
//	return this->ContainerPriorityQueueSet.empty();
//}
//
///*
//	F3. �������� �������������� �������� ���������.
//	������� ���������: ��������� �� ������ ������� ������, �������� ��������.
//	�������� ���������: ���������� ��������. ������������ F2.
//*/
//bool PriorityQueueSet::ItemInSet(int val) {
//	auto it = find(this->ContainerPriorityQueueSet, );
//	if (it != this->ContainerListSet.end()) {
//		return true;
//	}
//	return false;
//}
//
///*
//	F4. ���������� ������ �������� � ���������.
//	������� ���������: ��������� �� ������ ������� ������, ����������� � ������ ��������.
//	�������� ���������: ��������� �� ������ ������� ������-����������.
//	������������ F3. �����������: ���������� ������������ � ������ ������.
//*/
//void ContListSet::AddItem(int val) {
//	if (ItemInSetList(val)) {
//		return;
//	}
//	else {
//		this->ContainerListSet.push_front(val);
//	}
//}
//
///*
//	F5. �������� ���������.
//	������� ���������: ���������� ���������, �������� ���������� �������� (�� min �� max).
//	�������� ���������: ��������� �� ������ ������� ������-����������.
//	��������� �������� � �������� ��������� �����.
//	������������ F4.
//	����������: ��������� ����������� �������� ��������� � ��������� �����������.
//*/
//ContListSet::ContListSet(int len, int min, int max) {
//	this->ContainerListSet = list<int>();
//	if (len > 0 && max > min && len < max - min) {
//		list<int>::const_iterator pred_node = this->ContainerListSet.begin();
//		while (len > 0) {
//			AddItem(random(min, max));
//			if (this->ContainerListSet.begin() != pred_node) {
//				len--;
//			}
//			pred_node = this->ContainerListSet.begin();
//
//		}
//
//	}
//}
//
///*
//	9.	��������� � � ��������� �����, ������� 3. ��������� � � ��������� �����, ������� 9.
//*/
//int ContListSet::GenerateValueAorB(int min, int max, int number) {
//	int value = random(min, max);
//	while (value % number != 0) {
//		value = random(min, max);
//	}
//	return value;
//}
//
//// �������������� ������� ��� ��������� ��������� �����
//int ContListSet::random(int low, int high)
//{
//	random_device rd;
//	mt19937 gen(rd());
//	uniform_int_distribution<> dis(low, high);
//	return dis(gen);
//}
//
//
///*
//	F6. �������� ���������.
//	������� ���������: ��������� �� ������ ������� ������.
//	�������� ���������: ������������� ��������.
//	������������ F2.
//*/
//int ContListSet::PowerSetList() {
//	return this->ContainerListSet.size();
//}
//
///*
//	F7. ����� ��������� ���������.
//	������� ���������: ��������� �� ������ ������� ������, ������ �����������.
//	�������� ���������: ������, ���������� �������� ���������, ����������� �������� �����������.
//	������������ F2.
//	����������: � ����� ������-���������� ����������� ������ �� ������
//*/
//string ContListSet::ToString(char sym) {
//	if (!EmptySetList()) {
//		string result = "";
//		for (int elem : this->ContainerListSet) {
//			result += to_string(elem);
//			result += sym;
//		}
//		int len = result.length();
//		return result.erase(len - 1, len);
//	}
//	return "";
//}
//
///*
//	F8. �������� ��������� (������� ������, ���������� �������).
//	������� ���������: ��������� �� ������ ������� ������.
//	�������� ���������: ��������� �� ������ ������� ������, ������ NULL.
//*/
//ContListSet::~ContListSet() {
//	this->ContainerListSet.clear();
//}
//
///*
//	F9. ������������ �-�. ������� ���������: ��� ��������� �� ������ �������� ������� � �������� �������� � � �.
//	�������� ���������: ���������� �������� True, ���� � �������� ������������� �.
//	������������ F2, F6.
//*/
//bool ContListSet::CheckSubSet(ContListSet* sub_set) {
//	if (EmptySetList()) {
//		return true;
//	}
//
//	for (int elem : sub_set->ContainerListSet) {
//
//		if (!ItemInSetList(elem)) {
//			return false;
//		}
//	}
//
//	return true;
//}
//
///*
//	F10. ��������� ���� �������� �-�.
//	������� ���������: ��� ��������� �� ������ �������� ������� � �������� �������� � � �.
//	�������� ���������: ���������� �������� True, ���� � ����� �. ������������ F9.
//*/
//bool ContListSet::EqualsSets(ContListSet* second_set) {
//	return CheckSubSet(second_set) && second_set->CheckSubSet(this);
//}
//
///*
//	F11. ����������� ���� ��������.
//	������� ���������: ��� ��������� �� ������ �������� ������� � �������� ��������.
//	�������� ���������: ��������� �� ������ ������� ������-����������. ������������ F2, F4.
//*/
//ContListSet* ContListSet::MergeSets(ContListSet* second_set) {
//
//	ContListSet* result_set = new ContListSet();
//	for (int elem : this->ContainerListSet) {
//		result_set->AddItem(elem);
//	}
//	for (int elem : second_set->ContainerListSet) {
//		result_set->AddItem(elem);
//	}
//	return result_set;
//}
//
///*
//	F12. ����������� ���� ��������.
//	������� ���������: ��� ��������� �� ������ �������� ������� � �������� ��������.
//	�������� ���������: ��������� �� ������ ������� ������-����������. ������������ F2, F4.
//*/
//ContListSet* ContListSet::IntersectionSets(ContListSet* second_set) {
//
//	ContListSet* result_set = new ContListSet();
//	for (int elem : second_set->ContainerListSet) {
//
//		if (ItemInSetList(elem)) {
//			result_set->AddItem(elem);
//		}
//
//	}
//	return result_set;
//}
//
///*
//	F13. �������� ��������.
//	������� ���������: ��� ��������� �� ������ �������� ������� � �������� ��������.
//	�������� ���������: ��������� �� ������ ������� ������-����������. ������������ F2, F4.
//*/
//ContListSet* ContListSet::DifferenceSets(ContListSet* second_set) {
//
//	ContListSet* result_set = new ContListSet();
//	for (int elem : this->ContainerListSet) {
//		if (!second_set->ItemInSetList(elem)) {
//			result_set->AddItem(elem);
//		}
//	}
//	return result_set;
//}
//
///*
//	F14. ������������ ��������.
//	������� ���������: ��� ��������� �� ������ �������� ������� � �������� ��������.
//	�������� ���������: ��������� �� ������ ������� ������-����������. ������������ F11, F12 � F13.
//*/
//ContListSet* ContListSet::SymmetricDifferenceSets(ContListSet* second_set) {
//	ContListSet* merge_set = MergeSets(second_set);
//	ContListSet* intersection_set = IntersectionSets(second_set);
//	return merge_set->DifferenceSets(intersection_set);
//}