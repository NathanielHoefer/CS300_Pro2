/*****************************************************************************/
/* Project 2 - Sorting Algorithms											 */
/*****************************************************************************
	Author:  Atish Retna Rajah
    Student ID: R643D785

    Author: Nathaniel Hoefer
    Student ID: X529U639
    Program: Project 2


Functions:
+ swapData(Data &x, Data &y): Swaps data utilizing a temporary object
	Preconditions: None
	Postconditions: None
	> set temp = x
	> swap x and y
	> set y = temp

+ generateList(Data arr[], int size): Generates an array of random integers
	between 0-100000 for a key and a random double as data
	Preconditions: Size is not larger than the length of the array
	Postconditions: Array is filled with randomly generated numbers
	> Set seed for random generator
	> Generate a number of keys equal to the submitted size
	> Generate a number of doubles equal to the submitted size

+ outputData(Data arr[], int size, int passes, char sort): 	Outputs the
	sorting data into both a file and to the console
	Preconditions: Size is the length of the array passed in.
		Sort Char: s = selection sort, i = insertion sort, b = bubble sort,
				q = quick sort
	Postconditions: Data printed to a file with header and sorting info
		printed to console
	> Create a file name to be used for saving the output
	> Use a switch statement for each sort
	> Output the formatted information to the file
	> Output the Big-O info to console.

+ printBST(BST tree, int size): Print the binary search tree in order
	Preconditions: tree is not empty
	Postconditions: File is created with bst data listed in order
	> Create the file name to be used for saving the output
	> Output the formatted information to the file


******************************************************************************/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <math.h>
#include <sstream>
#include <ctime>
#include "data.cpp"
#include "bst.hpp"

using namespace std;

#ifndef FUNCS_CPP_
#define FUNCS_CPP_


// FUNCTIONS ******************************************************************


//	Swaps data utilizing a temporary object
//		Preconditions: None
//		Postconditions: None
void swapData(Data &x, Data &y)
{
	Data temp;
	
	temp = x;

	x = y;

	y = temp;
}


/*****************************************************************************/


//	Generates an array of random integers between 0-100000 for a key and a
//		random double as data
//		Preconditions: Size is not larger than the length of the array
//		Postconditions: Array is filled with randomly generated numbers
void generateList(Data list[], int size)
{
   int x, i;
   double y;
   srand(time(NULL));

	// generate list of random numbers for the array of size 100
	for(i = 0; i < size; i++)
	{
		list[i].key = rand () % 100000;
		x = rand () % 10000;
		y = rand () % 10000;
		list[i].num = x / y;
	}
}


/*****************************************************************************/


//	Outputs the sorting data into both a file and to the console
//		Preconditions: Size is the length of the array passed in.
//			Sort Char: s = selection sort, i = insertion sort, b = bubble sort,
//					q = quick sort
//		Postconditions: Data printed to a file with header and sorting info
//			printed to console
void outputData(Data arr[], int size, int passes, char sort)
{
	string file = "";
	string bigO = "Calculated Big-O ";
	string title = "";
	int bigOCalc;
	stringstream fileNum;
	stringstream bigONum;

	// Updates the file name and info based on sort being used
	switch (sort)
	{
	case 's' :
		file += "sels";
		title = "Selection Sort - ";
		bigO += "(n^2): ";
		bigOCalc = size * size;
		break;
	case 'i' :
		file += "sins";
		title = "Insertion Sort - ";
		bigO += "(n^2): ";
		bigOCalc = size * size;
		break;
	case 'b' :
		file += "bub";
		title = "Bubble Sort - ";
		bigO += "(n^2): ";
		bigOCalc = size * size;
		break;
	case 'q' :
		file += "quick";
		title = "Quick Sort - ";
		bigO += "(nlog(n)): ";
		bigOCalc = size * log10(size);
		break;
	}

	// Convert int to string and concatenate for full file name
	fileNum << size;
	file += fileNum.str();
	file += ".dat";
	bigONum << bigOCalc;
	bigO += bigONum.str();


	// Outputs the sorted data to a .dat file
	ofstream output;
	output.open(file.c_str());
	output << "-------------------------------" 		<< endl;
	output << title << fileNum.str() << " Elements" 	<< endl;
	output << "-------------------------------" 		<< endl;
	output << bigO << endl;
	output << "Actual Big-O: "   << passes << endl << endl;
	output << setw(10) << "Key" << setw(20) << "Data" 	<< endl;
	output << "----------  ------------------"          << endl;

	// Displays each element
	for(int i = 0; i < size; i++)
	{
		output << setw(10) << arr[i].key << " ";
		output << setw(20) << arr[i].num << endl;
	}

	output.close();

	// Outputs results to the console
	cout << title << "Actual Big-O: " << passes << endl;
}


/*****************************************************************************/


//	Print the binary search tree in order
//		Preconditions: tree is not empty
//		Postconditions: File is created with bst data listed in order
void printBST(BST tree, int size)
{
	// Generate file name
	string file = "bst";
	stringstream fileNum;
	fileNum << size;
	file += fileNum.str();
	file += ".dat";

	// Begin file stream
	ofstream bst;

	// Create header for file
	bst.open(file.c_str());
	bst << "-------------------------------" 		  << endl;
	bst << "Binary Search Tree " << fileNum.str();
	bst << " Elements" << endl;
	bst << "-------------------------------" <<  endl << endl;
	bst << setw(10) << "Key" << setw(20) << "Data"    << endl;
	bst << "----------  ------------------"           << endl;

	// Print tree in order
	tree.print(bst);

	bst.close();
}


#endif /* FUNCS_CPP_ */
