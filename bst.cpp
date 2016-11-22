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
#include "bst.hpp"
#include <iomanip>
using namespace std;

/******************************************************************************/
// Constructor 
Node::Node(int k, double n)
{
   // set t.key equal to k
   t.key   = k; 
   // set t.num equal to n
   t.num   = n;
   // set left pointer = null
   left  = NULL;
   // set right pointer = null
   right = NULL;
}

// set_left
void Node::set_left(Node *tleft)
{
   //set left pointer equal to tleft
   left = tleft;
}

// set_right
void Node::set_right(Node *tright)
{
   //set right pointer equal to tright
   right = tright;
}

// setKey
void Node::setKey(int k)
{
   // set t.key = k
   t.key = k;
}

// getKey
int Node::getKey()
{
   return t.key;
}

// getNum
double Node::getNum()
{
   return t.num;
}

// getLeft
Node *Node::getLeft()
{
   return left;
}

// getRight
Node *Node::getRight()
{
   return right;
}

/*****************************************************************************/

// Default Constructor
BST::BST()
{
   root = NULL;
}

// Private Insert Function
void BST::insertNode(int k, double n, Node *leaf)
{
   // if k is less than the key of the leaf
   if (k < leaf->getKey()) 
   {
      // if the leaf's left pointer does not equal null, insert node
      if (leaf->getLeft() != NULL )
         insertNode(k, n, leaf->getLeft());

      // create new node, set the left pointer of leaf to treenode
      else 
      {
         Node *treenode = new Node(k, n);
         leaf->set_left(treenode);
      }
   }

   else 
   {
      // if the leaf's right pointer does not equal null, insert node
      if (leaf->getRight() != NULL )
         insertNode(k, n, leaf->getRight());

      // create new node, set the right pointer of leaf to treenode
      else 
      {
         Node *treenode = new Node(k, n);
         leaf->set_right(treenode);
      }
   }
}

// insertNode
void BST::insertNode(int k, double n)
{
   // if tree is empty
   if (isEmpty())
   {
      // create new node, set root equal to treenode
      Node *treenode = new Node(k, n);
      root = treenode;
   }
  
   // else, insert node
   else 
      insertNode(k, n, root);
}

//print_inorder
void BST::print_inorder(ofstream &output)
{   
   inorder(root, output);
}

//inorder
void BST::inorder(Node *p, ofstream &output)
{
   // if tree is not empty 
   if (p != NULL)
   {
      // call inorder function recursively
      inorder(p->getLeft(), output);
      
      // print to file
      output << setw(10) << p->getKey()
             << setw(20) << p->getNum() << endl;

      // call inorder function recursively
      inorder(p->getRight(), output);
   }
}

//isEmpty
bool BST::isEmpty()
{
   // returns 0 if root does not equal null
   // returns 1 if root equal null
   return (root == NULL);
}

