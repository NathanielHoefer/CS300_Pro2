/*****************************************************************************/
/* Project 2 - Sorting Algorithms											 */
/*****************************************************************************
	Author:  Atish Retna Rajah
    Student ID: R643D785

    Author: Nathaniel Hoefer
    Student ID: X529U639
    Program: Project 2


Class Name: Node
	Contains the data for a binary search tree, which in this case is a struct
	with a key and double

Data:
	- Data mData: Key and double
	- Node* mLeft: Pointer to left tree
	- Node* mRight: Pointer to the right tree

Constructors:
	+ Node(int key, double num) - Creates a node with default Data

Accessor and Mutator Functions:
	+ getKey()
	+ getNum()
	+ getLeft()
	+ getRight()
	+ setKey(int key)
	+ setLeft(Node *left)
	+ setRight(Node *right)


*******************************************************************************


Class Name: BST
	A binary search tree that operates with nodes containing Data which includes
	a key and a double number.

Data:
	- Node* mRoot: The very first entry of the binary search tree

Constructors:
	+ BST(): Initializes an empty binary search tree.

Functions:
	- insertNode(int key, double num, Node *node): Inserts a node with the data
		into the correct location within the BST recursively
		Preconditions: None
		Postconditions: Node with contact info is correctly located in tree
		> If the phone number is less than the root, recursively check the left
			node.
		> Otherwise, recursively check the right node.

	+ insertNode(int key, double num): Inserts a node with the data into the
		correct location within the BST
		Preconditions: None
		Postconditions: Node with contact info is correctly located in tree
		> If the tree is empty, update root to new node
		> Otherwise recursively call the overloaded insertNode function

	+ print(ofstream &output): Calls the inOrder print function
		Precoditions: None
		Postconditions: Data is printed to an output file
		> Call inOrder function.

	- inOrder(Node *node, ofstream &output): Prints the data in BST in order
		using recursion.
		Preconditions: None
		Posconditions: Data is printed to an output file
		> Base case: Node is NULL
		> General case: 1. inOrder(left) 2. output node 3. inOrder(right)

	+ isEmpty(): Checks to see if bst is empty
		Preconditions: None
		Postconditions: None
		Returns: True if bst is empty

*/

#include "data.cpp"


/*****************************************************************************/
// Node Class Protocol Functions and Variables
/*****************************************************************************/


#ifndef NODE_CPP_
#define NODE_CPP_

class Node
{

private:

// MEMBER VARIABLES ***********************************************************

	// Key and double
	Data mData;

	// Pointers to left and right tree
	Node *mLeft;
	Node *mRight;

public:

// CONSTRUCTORS ***************************************************************

	Node(int key, double num);


// Accessors and Mutators
	int getKey() { return mData.key; };

	double getNum() { return mData.num; };

	Node *getLeft() { return mLeft; };

	Node *getRight() { return mRight; };

	void setKey(int key) { mData.key = key; };

	void setLeft(Node  *left) { mLeft = left; };

	void setRight(Node *right) { mRight = right; };

};
#endif /*NODE_CPP_*/


/*****************************************************************************/
// Node Class Protocol Functions and Variables
/*****************************************************************************/


#ifndef BST_CPP_
#define BST_CPP_

class BST
{

private:

// MEMBER VARIABLES ***********************************************************

	// The very first entry of the binary search tree
	Node *mRoot;


public:

// CONSTRUCTORS ***************************************************************

	BST();


// FUNCTIONS ******************************************************************

//	Inserts a node with the data into the
//		correct location within the BST
//		Preconditions: None
//		Postconditions: Node with contact info is correctly located in tree
	void insertNode(int key, double num);


/*****************************************************************************/


//	Calls the inOrder print function
//		Precoditions: None
//		Postconditions: Data is printed to an output file
	void print(ofstream &output);


/*****************************************************************************/


//	Checks to see if bst is empty
//		Preconditions: None
//		Postconditions: None
	bool isEmpty();


/*****************************************************************************/


private:


//	Inserts a node with the data into the correct location within the BST
//		recursively
//		Preconditions: None
//		Postconditions: Node with contact info is correctly located in tree
	void insertNode(int key, double num, Node *node);


/*****************************************************************************/


//	Prints the data in BST in order using recursion.
//		Preconditions: None
//		Posconditions: Data is printed to an output file
	void inOrder(Node *node, ofstream &output);
};

#endif /*BST_CPP_*/
