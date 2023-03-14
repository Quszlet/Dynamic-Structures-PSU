#include "SetLab4_Izgarev.h"
#include <iostream>
#include <random>
#include <string>

std::random_device rd;
std::mt19937 gen(rd());

using namespace std;


/*
	F1. Создание пустого множества.
	Входные параметры: нет.
	Выходные параметры: указатель на первый элемент списка, равный NULL.
*/
SetList::SetList() {
	this->ContainerListSet = list<int>();
}

/*
	F2. Пустое множество?
	Входные параметры: указатель на первый элемент списка.
	Выходные параметры: логическое значение.
*/
bool SetList::EmptySetList() {
	return this->ContainerListSet.empty();
}

/*
	F3. Проверка принадлежности элемента множеству.
	Входные параметры: указатель на первый элемент списка, значение элемента.
	Выходные параметры: логическое значение. Использовать F2.
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
	F4. Добавление нового элемента в множество.
	Входные параметры: указатель на первый элемент списка, добавляемое в список значение.
	Выходные параметры: указатель на первый элемент списка-результата.
	Использовать F3. Ограничение: добавление осуществлять в начало списка.
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
	F5. Создание множества.
	Входные параметры: количество элементов, интервал допустимых значений (от min до max).
	Выходные параметры: указатель на первый элемент списка-результата.
	Генерация значений – датчиком случайных чисел.
	Использовать F4.
	Требования: проверить возможность создания множества с заданными параметрами.
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
	9.	Множество А – множество чисел, кратных 3. Множество В – множество чисел, кратных 9.
*/
int SetList::GenerateValueAorB(int min, int max, int number) {
	int value = random(min, max);
	while (value % number != 0) {
		value = random(min, max);
	}
	return value;
}

// дополнительная функция для генерации случайных чисел
int SetList::random(int low, int high)
{
	std::uniform_int_distribution<> dist(low, high);
	return dist(gen);
}


/*
	F6. Мощность множества.
	Входные параметры: указатель на первый элемент списка.
	Выходные параметры: целочисленное значение.
	Использовать F2.
*/
int SetList::PowerSetList() {
	return this->ContainerListSet.size();
}

/*
	F7. Вывод элементов множества.
	Входные параметры: указатель на первый элемент списка, символ разделителя.
	Выходные параметры: строка, содержащая элементы множества, разделенные символом разделителя.
	Использовать F2.
	Требования: в конце строки-результата разделитель стоять не должен
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
	F8. Удаление множества (очистка памяти, занимаемой списком).
	Входные параметры: указатель на первый элемент списка.
	Выходные параметры: указатель на первый элемент списка, равный NULL.
*/
SetList::~SetList() {
	this->ContainerListSet.clear();
}

/*
	F9. Подмножество А-В. Входные параметры: два указателя на первые элементы списков – исходных множеств А и В.
	Выходные параметры: логическое значение True, если А является подмножеством В.
	Использовать F2, F6.
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
	F10. Равенство двух множеств А-В.
	Входные параметры: два указателя на первые элементы списков – исходных множеств А и В.
	Выходные параметры: логическое значение True, если А равно В. Использовать F9.
*/
bool SetList::EqualsSets(SetList* second_set) {
	return CheckSubSet(second_set) && second_set->CheckSubSet(this);
}

/*
	F11. Объединение двух множеств.
	Входные параметры: два указателя на первые элементы списков – исходных множеств.
	Выходные параметры: указатель на первый элемент списка-результата. Использовать F2, F4.
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
	F12. Пересечение двух множеств.
	Входные параметры: два указателя на первые элементы списков – исходных множеств.
	Выходные параметры: указатель на первый элемент списка-результата. Использовать F2, F4.
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
	F13. Разность множеств.
	Входные параметры: два указателя на первые элементы списков – исходных множеств.
	Выходные параметры: указатель на первый элемент списка-результата. Использовать F2, F4.
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
	F14. Симметричная разность.
	Входные параметры: два указателя на первые элементы списков – исходных множеств.
	Выходные параметры: указатель на первый элемент списка-результата. Использовать F11, F12 и F13.
*/
SetList* SetList::SymmetricDifferenceSets(SetList* second_set) {
	SetList* merge_set = MergeSets(second_set);
	SetList* intersection_set = IntersectionSets(second_set);
	return merge_set->DifferenceSets(intersection_set);
}