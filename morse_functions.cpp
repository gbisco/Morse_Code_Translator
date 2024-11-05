#include "morse.h"
#include<iostream>
#include<fstream>
#include <string>

using namespace std;

void BSTnode::insert(Node*& nodePtr, Node*& newNode)
{
	if (nodePtr == nullptr)
		nodePtr = newNode;                  // Insert the node.
	else if (newNode->txtchar < nodePtr->txtchar)
		insert(nodePtr->left, newNode);     // Search the left branch
	else
		insert(nodePtr->right, newNode);    // Search the right branch
}

void BSTnode::search(Node* nodePtr, char& Ptxtchar, string& Pstring)
{
	if (nodePtr->txtchar == Ptxtchar)
		Pstring = nodePtr->morse;
	else if (nodePtr->txtchar > Ptxtchar)
		search(nodePtr->left, Ptxtchar, Pstring);
	else
		search(nodePtr->right, Ptxtchar, Pstring);
}

void BSTnode::searchNode(char& letter, string& Pstring)
{
	search(root, letter, Pstring);
}

void BSTnode::destroySubTree(Node* nodePtr)
{
	if (nodePtr)
	{
		if (nodePtr->left)
			destroySubTree(nodePtr->left);
		if (nodePtr->right)
			destroySubTree(nodePtr->right);
		delete nodePtr;
	}
}

void BSTnode::displayInOrder(Node* nodePtr) const
{
	if (nodePtr)
	{
		displayInOrder(nodePtr->left);
		cout << nodePtr->txtchar << ": " << nodePtr->morse << endl;
		displayInOrder(nodePtr->right);
	}
}

BSTnode::BSTnode()
{
	string str;
	char val;
	ifstream ifile("MorseTable.txt");

	while (ifile >> val)
	{
		ifile >> str;
		insertNode(str, val);
	}
}

BSTnode::~BSTnode()
{
	destroySubTree(root);
}

void BSTnode::insertNode(string str, char val)
{
	Node* newNode = new Node;	// Pointer to a new node.

	// Create a new node and store num in it.
	newNode->txtchar = val;
	newNode->morse = str;
	newNode->left = newNode->right = nullptr;

	// Insert the node.
	insert(root, newNode);
}

void BSTnode::print()
{
	displayInOrder(root);
}