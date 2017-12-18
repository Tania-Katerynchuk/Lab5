#pragma once
#include <iostream>

using namespace std;
struct List
{
	int element;
	List *back, *next;
};

void SupstituteElement(List *&list, int element);

void AddElement(int element, List *&list)
{
	if (list == NULL)
	{
		list = new List;
		list->element = element;
		list->back = list->next = NULL;
	}

	else if (list != NULL)
	{
		if (list->next == NULL) {
			list->next = new List;
			list->next->next = NULL;
			list->next->back = list;
			//list->back = list->next;
			list->next->element = element;
			//tree->back->left = tree->left->right = NULL;
			//tree->left->top = top;
		}
		else if (list->next != NULL)
			AddElement(element, list->next);

	}
}
void OutputList(List *&list) {

	if (list != NULL) {
		cout << list->element << " ";
		OutputList(list->next);
	}


}
void AddOddElement(List *&list, int element, int position, int n) {
	if (list != NULL) {
		if (n != position) {
			AddOddElement(list->next, element, position, n + 1);

		}
		else if (n == position) {
			SupstituteElement(list, element);

		}
	}
}
void SupstituteElement(List *&list, int element) {
	if (list != NULL) {

		int temp = list->element;
		list->element = element;
		SupstituteElement(list->next, temp);
	}
	else {
		AddElement(element, list);
	}

}