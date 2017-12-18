#include <iostream>
#include "MyTree.h"
#include "MyList.h"
using namespace std;



int main()
{
	setlocale(LC_CTYPE, "ukr");
	int menu = true;
	while (menu) {
		int nNodeTree, temp, nList;
		cout << "\n1 - опрацюванн€ списка\n2 - опрацюванн€ дерева\n0 - вихiд\n";
		cin >> menu;
		if (menu == 1) {
			cout << "¬ведiть кiлькiсть елементiв списка: ";
			cin >> nList;
			List *list = NULL;
			for (int i = 0; i < nList; i++) {
				cout << "≈лемент " << i + 1 << " = ";
				cin >> temp;
				AddElement(temp, list);
			}
			cout << "≈лементи списка: \n";
			OutputList(list);
			cout << endl;
			int addElement, nAddElement;
			cout << "¬ведiть на €ку позиц≥ю (непарну) ви хочете вставити елемент: "; cin >> nAddElement;
			cout << "¬ведiть елемент: "; cin >> addElement;
			AddOddElement(list, addElement, nAddElement, 1);
			OutputList(list);
			cout << endl;
		}
		if (menu == 2) {
			cout << "¬ведiть кiлькiсть вузлiв: ";
			cin >> nNodeTree;
			Node *tree = NULL;
			for (int i = 0; i < nNodeTree; i++) {
				cout << "¬узол " << i + 1 << " = ";
				cin >> temp;
				AddNode(temp, tree);
			}
			int choice = true;
			while (choice != 0) {
				OutputTree(tree);
				cout << "1 - ввести новий вузол\n2 - ¬идалити вузол\n0 - вихiд в меню\n";
				cin >> choice;
				if (!choice)
					return 0;
				switch (choice) {
				case 1:
					cout << "¬ведiть новий вузол: ";
					cin >> temp;
					cout << endl;
					AddNode(temp, tree);
					break;
				case 2:
					cout << "¬ведiть вузол, €кий ви хочете видалити: ";
					cin >> temp;
					cout << endl;
					DeleteNode(tree, tree, temp);
					break;
				case 0:
					break; break;
				default:
					break;
				}
			}
		}
	}
	return 0;
}