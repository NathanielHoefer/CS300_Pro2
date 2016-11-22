/*****************************************************************************/
/* Project 2 - Sorting Algorithms											 */
/*****************************************************************************
	Author:  Atish Retna Rajah
    Student ID:

    Author: Nathaniel Hoefer
    Student ID: X529U639
    Program: Project 2



Description of the Problem:
	Create an application that will generate lists of 100, 5000, and 10000
	random values. Then sort them using the selection, insertion, bubble, and
	quick sort, while also generating a binary search tree to additionally sort
	the values. The resulting sorts will be output into individual files that
	include the required passes to sort.

Functions:
    + main() - Instructs the sorts to be processed.
    	> Initialize the lists
    	> Generate the random values for each size of list.
    	> Call all of the sorts on lists
    	> Print the values to a file
    	> Add lists to BSTs and print values to file

      
******************************************************************************/
/* Answer to Questions
*
*     1. Does the actual time agree with your calculations?
*        No. For the bubble sort, the bigO from the project is about
*        half of the calculated bigO. For the quick sort, the bigO from the
*        project is about 75% of the calculated bigO. For the selection sort, 
*        the bigO from the project is about half of the calculated bigO. For the
*        insertion sort, the bigO from the project is about 30%.
* 
*     2. Which sort is faster?
*        The fastest sort was the insertion sort. Since it only took about 30%
*        of the calculated bigO. 
* 
*     3. Does the data size make a difference?
*        
*        No. All the calculated bigO values, regardless of the data size, were 
*        approaching the percentages mentioned in question 1, except for 
*        the insertion sort. For this sort, as the size of the array gets 
*        larger, the percentage decreases. 
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>

#include "additionalFuncs.cpp"
#include "data.cpp"
#include "bubble.cpp"
#include "insertion.cpp"
#include "selection.cpp"
#include "quick.cpp"
#include "bst.hpp"


using namespace std;


int main()
{
	
   data num100[100], num5000[5000], num10000[10000];
   data temp100[100], temp5000[5000], temp10000[10000];

   // Generates the three lists based on the size
   generateList(num100, 100);
   generateList(num5000, 5000);
   generateList(num10000, 10000);
  
   // Call bubble sort function
	bubbleSort(num100,   100);
	bubbleSort(num5000, 5000);
	bubbleSort(num10000, 10000);

   // Call insertion sort function
	insertionSort(num100,   100);
	insertionSort(num5000, 5000);
	insertionSort(num10000, 10000);

   // Call selection sort function
	selectionSort(num100,   100);
	selectionSort(num5000, 5000);
	selectionSort(num10000, 10000);

/*****************************************************************************/

	int count;

   count = 0;
   
   // make copy of array
   for(int i = 0; i < 100; i++) 
      temp100[i] = num100[i];
    
   // call quickSort function
	quickSort(temp100, 0, 99, count);
  
   // print quickSort data to file
   ofstream quick100;
   quick100.open("quick100.dat");
   quick100 << "Calculated Big-O (nlog(n)): 200"                     << endl;
   quick100 << "From project Big-O: "             << count << endl;
   quick100 << "List of sorted keys and numbers:" << endl  << endl;
   quick100 << setw(10) << "Key" << setw(20) << "Data"     << endl;
   quick100 << "----------  ------------------"            << endl;
  
  for(int i = 0; i < 100; i++)
  {
    quick100 << setw(10) << temp100[i].key;
    quick100 << setw(20) << temp100[i].num << endl;
  }
  
   quick100.close();
   

/*****************************************************************************/
// Print Quicksort of 5000
/*****************************************************************************/

   count = 0;
   
   // make copy of array
   for(int i = 0; i < 5000; i++)
      temp5000[i] = num5000[i];

   // call quickSort function
	quickSort(temp5000, 0, 4999, count);

   // print quickSort data to file
   ofstream quick5000;
   quick5000.open("quick5000.dat");
   quick5000 << "Calculated Big-O (nlog(n)): 18,495"        << endl;
   quick5000 << "From project Big-O: "             << count << endl;
   quick5000 << "List of sorted keys and numbers:" << endl  << endl;
   quick5000 << setw(10) << "Key" << setw(20) << "Data"     << endl;
   quick5000 << "----------  ------------------"            << endl;

   for(int i = 0; i < 5000; i++)
   {
      quick5000 << setw(10) << temp5000[i].key;
      quick5000 << setw(20) << temp5000[i].num << endl;
   }

   quick5000.close();

/*****************************************************************************/
// Print Quicksort of 10000
/*****************************************************************************/

   count = 0;
   
   // make copy of array
   for(int i = 0; i < 10000; i++)
      temp10000[i] = num10000[i];

   // call quickSort function
   quickSort(temp10000, 0, 9999, count);

   //print quickSort data to file
   ofstream quick10000;
   quick10000.open("quick10000.dat");
   quick10000 << "Calculated Big-O (nlog(n)): 40,000"        << endl;
   quick10000 << "From project Big-O: "             << count << endl;
   quick10000 << "List of sorted keys and numbers:" << endl  << endl;
   quick10000 << setw(10) << "Key" << setw(20) << "Data"     << endl;
   quick10000 << "----------  ------------------"            << endl;
  
  for(int i = 0; i < 10000; i++)
  {
    quick10000 << setw(10) << temp10000[i].key;
    quick10000 << setw(20) << temp10000[i].num << endl;
  }
  
   quick10000.close();
  
  
   cout << endl << "Files generated" << endl << endl;
        
/*****************************************************************************/
// Print BST of 100
/*****************************************************************************/

   // create three different binary trees
   // for different the different sizes
   BST  binaryTree1 = BST();
   BST  binaryTree2 = BST();
   BST  binaryTree3 = BST();
   
   // insert each node
   for(int i = 0; i < 100; i++)
      binaryTree1.insertNode(num100[i].key, num100[i].num);
   
   // print data to file
   ofstream bst1("bst100.dat");
   
   
   bst1 << "List of sorted keys and numbers:"  <<  endl << endl;
   bst1 << setw(10) << "Key" << setw(20) << "Data"      << endl;
   bst1 << "----------  ------------------"             << endl;
   
   bst1.setf(ios::fixed);
   bst1.setf(ios::showpoint);

   // print inoder
   binaryTree1.print_inorder(bst1);
   bst1.close();

/*****************************************************************************/
// Print BST of 5000
/*****************************************************************************/
   
   // insert each node
   for(int i = 0; i < 5000; i++)
      binaryTree2.insertNode(num5000[i].key, num5000[i].num);
   
   // print data to file
   ofstream bst2("bst5000.dat");
   
   bst2 << "List of sorted keys and numbers:"  <<  endl << endl;
   bst2 << setw(10) << "Key" << setw(20) << "Data"      << endl;
   bst2 << "----------  ------------------"             << endl;
   
   
   bst2.setf(ios::fixed);
   bst2.setf(ios::showpoint);

   // print inorder
   binaryTree2.print_inorder(bst2);
   bst2.close();
   
/*****************************************************************************/
// Print BST of 10000
/*****************************************************************************/
   
   // insert each node
   for(int i = 0; i < 10000; i++)
      binaryTree3.insertNode(num10000[i].key, num10000[i].num);
   
   ofstream bst3("bst10000.dat");
   
   // print data to file
   bst3 << "List of sorted keys and numbers:"  <<  endl << endl;
   bst3 << setw(10) << "Key" << setw(20) << "Data"      << endl;
   bst3 << "----------  ------------------"             << endl;
   
   
   bst3.setf(ios::fixed);
   bst3.setf(ios::showpoint);

   // print inorder
   binaryTree3.print_inorder(bst3);
   bst3.close();
   
   return 0;
}



