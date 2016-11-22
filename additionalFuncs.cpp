/******************************************************************************
Author:     
Student ID: 

Author:     
Studend ID: 

Project:    #2
******************************************************************************/


#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
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


void generateList(data arr[], int size) {
   int x, i;
   double y;

	// generate list of random numbers for the array of size 100
	for(i = 0; i < size; i++)
	{
		arr[i].key = rand () % 100000;
		x = rand () % 10000;
		y = rand () % 10000;
		arr[i].num = x / y;
	}
}



#endif
