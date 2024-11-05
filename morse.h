#ifndef MORSE_H
#define MORSE_H
#include <string>

using namespace std;

class BSTnode {
private:
	struct Node {
		char txtchar;
		string morse;
		Node* right;
		Node* left;
	};

	Node* root;

	//private functions
	void destroySubTree(Node*);
	void insert(Node*&, Node*&);
	void displayInOrder(Node*) const;
	void search(Node*, char&, string&);

public:
	//constructor
	BSTnode();
	//destructor
	~BSTnode();
	//public functions
	void insertNode(string, char);
	void print();
	void searchNode(char&, string&);




};



#endif 
