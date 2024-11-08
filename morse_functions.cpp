/*
 * Morse Code Binary Search Tree (BST) Implementation
 *
 * This program implements a Binary Search Tree (BST) to store and search for Morse code characters.
 *
 * Gabriel Bisco Reinato
 * Date: 2/9/2019
 */

#include "morse.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

// Insert function for Binary Search Tree (BST)
void BSTnode::insert(Node*& nodePtr, Node*& newNode)
{
	if (nodePtr == nullptr)                // If nodePtr is null, place newNode here
		nodePtr = newNode;                  // Insert the node.
	else if (newNode->txtchar < nodePtr->txtchar)
		insert(nodePtr->left, newNode);     // Insert in left subtree if newNode's character is less
	else
		insert(nodePtr->right, newNode);    // Otherwise, insert in right subtree
}

// Search function to find Morse code for a given character
void BSTnode::search(Node* nodePtr, char& Ptxtchar, string& Pstring)
{
	if (nodePtr->txtchar == Ptxtchar)       // If current node matches target character
		Pstring = nodePtr->morse;           // Store the Morse code in Pstring
	else if (nodePtr->txtchar > Ptxtchar)   // If target character is smaller, go left
		search(nodePtr->left, Ptxtchar, Pstring);
	else                                    // If target character is larger, go right
		search(nodePtr->right, Ptxtchar, Pstring);
}

// Public function to initiate search from the root of the BST
void BSTnode::searchNode(char& letter, string& Pstring)
{
	search(root, letter, Pstring);          // Start search from root node
}

// Recursive function to delete all nodes in the BST
void BSTnode::destroySubTree(Node* nodePtr)
{
	if (nodePtr)                            // If node exists
	{
		if (nodePtr->left)                  // Recursively delete left subtree
			destroySubTree(nodePtr->left);
		if (nodePtr->right)                 // Recursively delete right subtree
			destroySubTree(nodePtr->right);
		delete nodePtr;                     // Delete current node
	}
}

// Display function to print the BST in order
void BSTnode::displayInOrder(Node* nodePtr) const
{
	if (nodePtr)                            // If node exists
	{
		displayInOrder(nodePtr->left);      // Visit left subtree
		cout << nodePtr->txtchar << ": " << nodePtr->morse << endl; // Display character and Morse code
		displayInOrder(nodePtr->right);     // Visit right subtree
	}
}

// Constructor for BSTnode: initializes tree by reading Morse table from file
BSTnode::BSTnode()
{
	string str;
	char val;
	ifstream ifile("MorseTable.txt");       // Open Morse code table file

	while (ifile >> val)                    // Read character from file
	{
		ifile >> str;                       // Read Morse code associated with character
		insertNode(str, val);               // Insert character and Morse code into BST
	}
}

// Destructor to free memory by deleting entire BST
BSTnode::~BSTnode()
{
	destroySubTree(root);                   // Delete all nodes in the BST
}

// Function to create a new node and insert it into the BST
void BSTnode::insertNode(string str, char val)
{
	Node* newNode = new Node;               // Allocate a new node

	// Initialize node with character and Morse code
	newNode->txtchar = val;
	newNode->morse = str;
	newNode->left = newNode->right = nullptr;

	// Insert the node into the tree
	insert(root, newNode);
}

// Public function to print the entire tree in order
void BSTnode::print()
{
	displayInOrder(root);                   // Display all nodes starting from root
}
