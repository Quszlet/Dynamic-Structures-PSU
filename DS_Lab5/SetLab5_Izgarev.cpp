#include "SetLab5_Izgarev.h"
#include <iostream>
#include <random>
#include <string>

std::random_device rd;
std::mt19937 gen(rd());

using namespace std;


/*
	F1. Создание пустого множества.
*/
Set::Set() {
	this->ContainerSet = set<int>();
}


/*
	F2. Пустое множество?
*/
bool Set::EmptySet() {
	return this->ContainerSet.empty();
}

/*
	F3. Проверка принадлежности элемента множеству.
*/
bool Set::ItemInSet(int val) {
	return this->ContainerSet.contains(val);
}

/*
	F4. Добавление нового элемента в множество.
*/
bool Set::AddItem(int val) {
	return this->ContainerSet.insert(val).second;
}

/*
	F5. Создание множества.
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
	9.	Множество А – множество чисел, кратных 3. Множество В – множество чисел, кратных 9.
*/
int Set::GenerateValueAorB(int min, int max, int number) {
	int value = random(min, max);
	while (value % number != 0) {
		value = random(min, max);
	}
	return value;
}

// дополнительная функция для генерации случайных чисел
int Set::random(int low, int high)
{
	std::uniform_int_distribution<> dist(low, high);
	return dist(gen);
}


/*
	F6. Мощность множества.
	Использовать F2.
*/
int Set::PowerSet() {
	return this->ContainerSet.size();
}

/*
	F7. Вывод элементов множества.
	Использовать F2.
	Требования: в конце строки-результата разделитель стоять не должен
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
	F8. Удаление множества (очистка памяти, занимаемой списком).
*/
Set::~Set() {
	this->ContainerSet.clear();
}

/*
	F9. Подмножество А-В. Входные параметры: два указателя на первые элементы списков – исходных множеств А и В.
	Использовать F2, F6.
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
	F10. Равенство двух множеств А-В.
*/
bool Set::EqualsSets(Set* second_set) {
	return CheckSubSet(second_set) && second_set->CheckSubSet(this);
}

/*
	F11. Объединение двух множеств.
*/
Set* Set::MergeSets(Set* second_set) {

	Set* result_set = new Set();
	result_set->ContainerSet.insert(this->ContainerSet.begin(), this->ContainerSet.end());
	result_set->ContainerSet.insert(second_set->ContainerSet.begin(), second_set->ContainerSet.end());
	return result_set;
}

/*
	F12. Пересечение двух множеств.
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
	F13. Разность множеств.
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
	F14. Симметричная разность.
*/
Set* Set::SymmetricDifferenceSets(Set* second_set) {
	Set* merge_set = MergeSets(second_set);
	Set* intersection_set = IntersectionSets(second_set);
	return merge_set->DifferenceSets(intersection_set);
}