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
		cout << "\n1 - ����������� ������\n2 - ����������� ������\n0 - ���i�\n";
		cin >> menu;
		if (menu == 1) {
			cout << "����i�� �i���i��� �������i� ������: ";
			cin >> nList;
			List *list = NULL;
			for (int i = 0; i < nList; i++) {
				cout << "������� " << i + 1 << " = ";
				cin >> temp;
				AddElement(temp, list);
			}
			cout << "�������� ������: \n";
			OutputList(list);
			cout << endl;
			int addElement, nAddElement;
			cout << "����i�� �� ��� ������� (�������) �� ������ �������� �������: "; cin >> nAddElement;
			cout << "����i�� �������: "; cin >> addElement;
			AddOddElement(list, addElement, nAddElement, 1);
			OutputList(list);
			cout << endl;
		}
		if (menu == 2) {
			cout << "����i�� �i���i��� ����i�: ";
			cin >> nNodeTree;
			Node *tree = NULL;
			for (int i = 0; i < nNodeTree; i++) {
				cout << "����� " << i + 1 << " = ";
				cin >> temp;
				AddNode(temp, tree);
			}
			int choice = true;
			while (choice != 0) {
				OutputTree(tree);
				cout << "1 - ������ ����� �����\n2 - �������� �����\n0 - ���i� � ����\n";
				cin >> choice;
				if (!choice)
					return 0;
				switch (choice) {
				case 1:
					cout << "����i�� ����� �����: ";
					cin >> temp;
					cout << endl;
					AddNode(temp, tree);
					break;
				case 2:
					cout << "����i�� �����, ���� �� ������ ��������: ";
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