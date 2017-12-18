#pragma once
#include <iostream>

using namespace std;



struct Node
{
	int top;
	Node *left, *right;
};
void DeleteOneNode(Node *&fatherNode, Node *tree);
int DeleteTwoNode(Node *&fatherNode, Node *tree);
void OutputTree(Node *&tree)
{
	if (tree != NULL && (tree->left != NULL || tree->right != NULL))
	{
		cout << "\t    " << tree->top << endl;
		if (tree->left != NULL) {
			cout << "\t" << tree->left->top;
			if (tree->right != NULL)
				cout << "\t" << tree->right->top;
		}
		else {
			cout << "\t\t" << tree->right->top;
		}
		cout << endl << endl << endl;
		OutputTree(tree->left);
		OutputTree(tree->right);
	}
}

void AddNode(int top, Node *&tree)
{
	if (NULL == tree)
	{
		tree = new Node;
		tree->top = top;
		tree->left = tree->right = NULL;
	}

	if (top<tree->top)
	{
		if (tree->left != NULL) AddNode(top, tree->left);
		else
		{
			tree->left = new Node;
			tree->left->left = tree->left->right = NULL;
			tree->left->top = top;
		}
	}

	if (top>tree->top)
	{
		if (tree->right != NULL) AddNode(top, tree->right);
		else
		{
			tree->right = new Node;
			tree->right->left = tree->right->right = NULL;
			tree->right->top = top;
		}
	}

}

int DeleteNode(Node *tree, Node *&fatherNode, int deleteNode) {
	if (tree != NULL) {
		if (tree->top == deleteNode) {
			if (tree->left == NULL&&tree->right == NULL) {
				if (fatherNode->left != NULL) {
					fatherNode->left = NULL;
				}
				else if (fatherNode->right != NULL) {
					fatherNode->right = NULL;
				}
			}
			else if (tree->left != NULL&&tree->right == NULL) {
				if (fatherNode->left != NULL) {
					if (fatherNode->left->top == tree->top) {
						DeleteOneNode(fatherNode->left, tree->left);
					}
				}
				else if (fatherNode->right != NULL) {
					if (fatherNode->right->top == tree->top) {
						DeleteOneNode(fatherNode->right, tree->left);
					}
				}
			}
			else if (tree->left == NULL&&tree->right != NULL) {
				if (fatherNode->left != NULL) {

					if (fatherNode->left->top == tree->top)
						DeleteOneNode(fatherNode->left, tree->right);
				}
				if (fatherNode->right != NULL) {
					if (fatherNode->right->top == tree->top) {
						DeleteOneNode(fatherNode->right, tree->right);
					}
				}
			}
			else {
				if (fatherNode->left != NULL) {
					if (fatherNode->left->top == tree->top) {
						Node* tempTree = tree->left;
						DeleteOneNode(fatherNode->left, tree->right);
						DeleteTwoNode(fatherNode->left, tempTree);
						free(tempTree);
					}
				}
				if (fatherNode->right != 0) {
					if (fatherNode->right->top == tree->top) {
						Node* tempTree = tree->left;
						DeleteOneNode(fatherNode->right, tree->right);
						DeleteTwoNode(fatherNode->right, tempTree);
						free(tempTree);
					}
				}

			}
			return 0;


		}
		else if (deleteNode<tree->top) {
			DeleteNode(tree->left, tree, deleteNode);
		}
		else if (deleteNode > tree->top) {
			DeleteNode(tree->right, tree, deleteNode);
		}
		else {
			cout << "Даного вузла немає у дереві!\n";
			return 0;
		}

	}
	else {
		return 0;
	}

}
int DeleteTwoNode(Node *&fatherNode, Node *tree) {
	if (fatherNode == NULL) {
		DeleteOneNode(fatherNode, tree);
		return 0;
	}
	DeleteTwoNode(fatherNode->left, tree);
	return 0;
}
void DeleteOneNode(Node *&fatherNode, Node *tree) {

	if (tree != NULL) {
		if (fatherNode == NULL) {
			fatherNode = new Node;
			fatherNode->left = new Node;
			fatherNode->right = new Node;
			fatherNode->left = NULL;
			fatherNode->right = NULL;
		}

		fatherNode->top = tree->top;
		fatherNode->left = tree->left;
		fatherNode->right = tree->right;
		DeleteOneNode(fatherNode->right, tree->right);
		DeleteOneNode(fatherNode->left, tree->left);

	}

}