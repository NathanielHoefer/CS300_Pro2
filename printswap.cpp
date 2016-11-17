/******************************************************************************
Author:     
Student ID: 

Author:     
Studend ID: 

Project:    #2
******************************************************************************/

using namespace std;
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>

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

#endif
