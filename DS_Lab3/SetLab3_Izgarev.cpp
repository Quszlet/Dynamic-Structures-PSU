#include "SetLab3_Izgarev.h"
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
	first_node = nullptr;
}

/*
	F2. Пустое множество?
	Входные параметры: указатель на первый элемент списка.
	Выходные параметры: логическое значение.
*/
bool SetList::EmptySetList() {
	return first_node == nullptr;
}

/*
	F3. Проверка принадлежности элемента множеству.
	Входные параметры: указатель на первый элемент списка, значение элемента.
	Выходные параметры: логическое значение. Использовать F2.
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
		Node* node = new Node();
		node->value = val;
		node->next = first_node;
		first_node = node;
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
	F7. Вывод элементов множества.
	Входные параметры: указатель на первый элемент списка, символ разделителя.
	Выходные параметры: строка, содержащая элементы множества, разделенные символом разделителя.
	Использовать F2.
	Требования: в конце строки-результата разделитель стоять не должен
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
	F8. Удаление множества (очистка памяти, занимаемой списком).
	Входные параметры: указатель на первый элемент списка.
	Выходные параметры: указатель на первый элемент списка, равный NULL.
*/
SetList::~SetList() {
	while (first_node != nullptr) {
		Node* support_node = first_node->next;
		delete this->first_node;
		this->first_node = support_node;
	}
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

	for (Node* sub_elem = sub_set->first_node; sub_elem != nullptr; sub_elem = sub_elem->next) {

		if (!ItemInSetList(sub_elem->value)) {
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
	for (Node* first_elem = first_node; first_elem != nullptr; first_elem = first_elem->next) {
		result_set->AddItem(first_elem->value);
	}
	for (Node* first_elem = second_set->first_node; first_elem != nullptr; first_elem = first_elem->next) {
		result_set->AddItem(first_elem->value);
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
	for (Node* first_elem = second_set->first_node; first_elem != nullptr; first_elem = first_elem->next) {

		if (ItemInSetList(first_elem->value)) {
			result_set->AddItem(first_elem->value);
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
	for (Node* first_elem = first_node; first_elem != nullptr; first_elem = first_elem->next) {
		if (!second_set->ItemInSetList(first_elem->value)) {
			result_set->AddItem(first_elem->value);
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