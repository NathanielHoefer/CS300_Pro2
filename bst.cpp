/*****************************************************************************/
/* Project 2 - Sorting Algorithms											 */
/*****************************************************************************
	Author:  Atish Retna Rajah
    Student ID:

    Author: Nathaniel Hoefer
    Student ID: X529U639
    Program: Project 2
******************************************************************************/

#include <iostream> 
#include <string>
#include <fstream>
#include <iomanip>
#include "bst.hpp"

using namespace std;


/*****************************************************************************/
// Class Source Functions
/*****************************************************************************/


// CONSTRUCTORS ***************************************************************


Node::Node(int key, double num)
{
   mData.key = key;

   mData.num = num;

   mLeft = NULL;

   mRight = NULL;
}


/*****************************************************************************/


BST::BST()
{
   mRoot = NULL;
}


// METHODS ********************************************************************


//	Inserts a node with the data into the correct location within the BST
//		recursively
//		Preconditions: None
//		Postconditions: Node with contact info is correctly located in tree
void BST::insertNode(int key, double num, Node *node)
{
   // Key is less than mRoot
   if (key < node->getKey()) 
   {
      // root has a left child
      if (node->getLeft() != NULL )
         insertNode(key, num, node->getLeft());

      // root doesn'mData have a mLeft child
      else 
      {
         Node *temp = new Node(key, num);
         node->setLeft(temp);
      }
   }

   else 
   {
      // root has mRight child
      if (node->getRight() != NULL )
         insertNode(key, num, node->getRight());

      // root doesn't have mRight child
      else 
      {
         Node *temp = new Node(key, num);
         node->setRight(temp);
      }
   }
}


/*****************************************************************************/


//	Inserts a node with the data into the
//		correct location within the BST
//		Preconditions: None
//		Postconditions: Node with contact info is correctly located in tree
void BST::insertNode(int key, double num)
{
   // if tree is empty
   if (isEmpty())
   {
      // set root equal to newly created node
      Node *temp = new Node(key, num);
      mRoot = temp;
   }
  
   // otherwise insert node in tree
   else 
      insertNode(key, num, mRoot);
}


/*****************************************************************************/


//	Calls the inOrder print function
//		Precoditions: None
//		Postconditions: Data is printed to an output file
void BST::print(ofstream &output)
{   
   inOrder(mRoot, output);
}


/*****************************************************************************/


//	Prints the data in BST in order using recursion.
//		Preconditions: None
//		Posconditions: Data is printed to an output file
void BST::inOrder(Node *node, ofstream &output)
{
   // if tree is not empty 
   if (node != NULL)
   {
      // Recursively call function on left children
      inOrder(node->getLeft(), output);
      
      // Print to file the root
      output << setw(10) << node->getKey()
             << setw(20) << node->getNum() << endl;

      // Recursively call function on right children
      inOrder(node->getRight(), output);
   }
}


/*****************************************************************************/


//	Checks to see if bst is empty
//		Preconditions: None
//		Postconditions: None
bool BST::isEmpty()
{
   return (mRoot == NULL);
}

