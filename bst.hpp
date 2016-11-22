/*****************************************************************************/
/* Project 2 - Sorting Algorithms											 */
/*****************************************************************************
	Author:  Atish Retna Rajah
    Student ID:

    Author: Nathaniel Hoefer
    Student ID: X529U639
    Program: Project 2
******************************************************************************/

#include "data.cpp"

#ifndef __NODE__
#define __NODE__

// Node Class
class Node
{
   // contains key and num 
   data t;
   
   // left and right pointers
   Node *left;
   Node *right;
   
   public:
      // constructors
      Node(int, double);
      
      // Mutator functions
      void   set_left(Node  *tleft);
      void   set_right(Node *tright);
      void   setKey(int k);
      
      // Accesor Fucntions
      int    getKey();
      double getNum();
      Node  *getLeft();
      Node  *getRight();
};
#endif


#ifndef __BST__
#define __BST__

// Binary Search Tree Class
class BST
{
   Node *root;
   void insertNode(int k, double n, Node *leaf);
   
   public:
      // Constructor
      BST();
      
      // inserts node into tree
      void insertNode(int, double);
      
      // prints in order, uses recursion
      void inorder(Node *p, ofstream &output);
      void print_inorder(ofstream &output);
      
      // checks to see if tree is empty
      bool isEmpty();
};

#endif
