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
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <math.h>
#include <sstream>
#include <ctime>
#include "data.cpp"

using namespace std;

#ifndef __PRINT__
#define __PRINT__

// prints Key, only used for testing purposes
void printKey(data arr[], int size)
{
   // print each element of array
	for (int i = 0; i < size; i++)
		cout << setw(5) << arr[i].key << " ";

	cout << endl << endl;
}



// swapData
void swapData(data & x, data & y)
{
   // create temporary 
	data temp;
	
   // set temp equal to x
	temp = x;
   // set x equal to y
	x = y;
   // set y equal to temp
	y = temp;
}




void generateList(data arr[], int size)
{
   int x, i;
   double y;
   srand(time(NULL));

	// generate list of random numbers for the array of size 100
	for(i = 0; i < size; i++)
	{
		arr[i].key = rand () % 100000;
		x = rand () % 10000;
		y = rand () % 10000;
		arr[i].num = x / y;
	}
}




void outputData(data arr[], int size, int count, char sort)
{

	// selection, quick, insertion, b

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

	// Convert int to string and concatenate
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
	output << "Actual Big-O: "   << count << endl << endl;
	output << setw(10) << "Key" << setw(20) << "Data" 	<< endl;
	output << "----------  ------------------"          << endl;

	for(int i = 0; i < size; i++)
	{
		output << setw(10) << arr[i].key << " ";
		output << setw(20) << arr[i].num << endl;
	}

	output.close();

	cout << title << count << " passes" << endl;
}



#endif
