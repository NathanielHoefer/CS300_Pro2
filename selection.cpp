/*****************************************************************************/
/* Project 2 - Sorting Algorithms											 */
/*****************************************************************************
	Author:  Atish Retna Rajah
    Student ID: R643D785

    Author: Nathaniel Hoefer
    Student ID: X529U639
    Program: Project 2
******************************************************************************/

using namespace std;
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include "data.cpp"
#include "additionalFuncs.cpp"


#ifndef __SELECTION__
#define __SELECTION__

// Selection Sort
void selectionSort(Data arr[], int size)
{
	int j, min;
	int count = 0;

	ofstream sels;

	Data copy[size];

   // make copy of array
	for(int i = 0; i < size; i ++)
		copy[i] = arr[i];
      
	for(int i = 0; i < size - 1; i++)
	{
      // set minimum = i
		min = i;
	
		for(j = i + 1; j < size; j++)
      {
         // increment count
         count++;
      
         // if the key of the jth position is less than the key of the min 
         //position then set min = j
			if(copy[j].key < copy[min].key)
				min = j;
      }
      
      // if the minimum does not equal i, swap data
		if (min != i)
			swapData(copy[i], copy[min]);
	}

	outputData(copy, size, count, 's');
}


#endif
