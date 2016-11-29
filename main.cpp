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


const int COUNT1 = 100;
const int COUNT2 = 5000;
const int COUNT3 = 10000;


int main()
{
	
	Data list1[COUNT1], list2[COUNT2], list3[COUNT3];
	Data temp1[COUNT1], temp2[COUNT2], temp3[COUNT3];
	BST bst1, bst2, bst3;
	int quickCount;

	// Generates the three lists based on the size
	generateList(list1, COUNT1);
	generateList(list2, COUNT2);
	generateList(list3, COUNT3);
   

	// Copies the arrays
	for(int i = 0; i < COUNT1; i++)
		temp1[i] = list1[i];
	for(int i = 0; i < COUNT2; i++)
		temp2[i] = list2[i];
	for(int i = 0; i < COUNT3; i++)
		temp3[i] = list3[i];


	// Sorts the elements within 100 element lists
	cout << endl << COUNT1 << " Element Lists" << endl;
	cout << "------------------------------------" << endl;

	bubbleSort(list1, COUNT1);
	insertionSort(list1, COUNT1);
	selectionSort(list1, COUNT1);

	quickCount = 0;
	quickSort(temp1, 0, (COUNT1 - 1), quickCount);
	outputData(temp1, COUNT1, quickCount, 'q');

	for(int i = 0; i < COUNT1; i++)
		bst1.insertNode(list1[i].key, list1[i].num);

	printBST(bst1, COUNT1);


	// Sorts the elements within 5000 element lists
	cout << endl << COUNT2 << " Element Lists" << endl;
	cout << "------------------------------------" << endl;

	bubbleSort(list2, COUNT2);
	insertionSort(list2, COUNT2);
	selectionSort(list2, COUNT2);

	quickCount = 0;
	quickSort(temp2, 0, (COUNT2 - 1), quickCount);
	outputData(temp2, COUNT2, quickCount, 'q');

	for(int i = 0; i < COUNT2; i++)
	  bst2.insertNode(list2[i].key, list2[i].num);

	printBST(bst2, COUNT2);


	// Sorts the elements within 10000 element lists
	cout << endl << COUNT3 << " Element Lists" << endl;
	cout << "------------------------------------" << endl;

	bubbleSort(list3, COUNT3);
	insertionSort(list3, COUNT3);
	selectionSort(list3, COUNT3);

	quickCount = 0;
	quickSort(temp3, 0, (COUNT3 - 1), quickCount);
	outputData(temp3, COUNT3, quickCount, 'q');

	for(int i = 0; i < COUNT3; i++)
		bst3.insertNode(list3[i].key, list3[i].num);

	printBST(bst3, COUNT3);


	cout << endl << "Files generated" << endl << endl;
   
	return 0;
}



