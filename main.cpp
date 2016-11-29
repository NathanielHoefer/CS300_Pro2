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


static const int COUNT1 = 100;
static const int COUNT2 = 5000;
static const int COUNT3 = 10000;


int main()
{
	
	Data num100[100], num5000[5000], num10000[10000];
	Data temp100[100], temp5000[5000], temp10000[10000];
	BST bst1, bst2, bst3;
	int quickCount;

	// Generates the three lists based on the size
	generateList(num100, 100);
	generateList(num5000, 5000);
	generateList(num10000, 10000);
   

	// Copies the arrays
	for(int i = 0; i < 100; i++)
		temp100[i] = num100[i];
	for(int i = 0; i < 5000; i++)
		temp5000[i] = num5000[i];
	for(int i = 0; i < 10000; i++)
		temp10000[i] = num10000[i];

	// Sorts the elements within 100 element lists
	cout << endl << 100 << " Element Lists" << endl;
	cout << "------------------------------------" << endl;

	bubbleSort(num100, 100);
	insertionSort(num100, 100);
	selectionSort(num100, 100);

	quickCount = 0;
	quickSort(temp100, 0, 99, quickCount);
	outputData(temp100, 100, quickCount, 'q');

	for(int i = 0; i < 100; i++)
	  bst1.insertNode(num100[i].key, num100[i].num);

	printBST(bst1, 100);


	// Sorts the elements within 5000 element lists
	cout << endl << 5000 << " Element Lists" << endl;
	cout << "------------------------------------" << endl;

	bubbleSort(num5000, 5000);
	insertionSort(num5000, 5000);
	selectionSort(num5000, 5000);

	quickCount = 0;
	quickSort(temp5000, 0, 4999, quickCount);
	outputData(temp5000, 5000, quickCount, 'q');

	for(int i = 0; i < 5000; i++)
	  bst2.insertNode(num5000[i].key, num5000[i].num);

	printBST(bst2, 5000);


	// Sorts the elements within 10000 element lists
	cout << endl << 10000 << " Element Lists" << endl;
	cout << "------------------------------------" << endl;

	bubbleSort(num10000, 10000);
	insertionSort(num10000, 10000);
	selectionSort(num10000, 10000);

	quickCount = 0;
	quickSort(temp10000, 0, 9999, quickCount);
	outputData(temp10000, 10000, quickCount, 'q');

	for(int i = 0; i < 10000; i++)
		bst3.insertNode(num10000[i].key, num10000[i].num);

	printBST(bst3, 10000);

	cout << endl << "Files generated" << endl << endl;
   
	return 0;
}



