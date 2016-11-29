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


#ifndef __INSERTION__
#define __INSERTION__

// Insertion Sort
void insertionSort(Data arr[], int size)
{

	int walker;
	int count = 0;

	ofstream sins;

	Data copy[size];

   // make copy of array
	for(int i = 0; i < size; i ++)
		copy[i] = arr[i];

	for(int i = 1; i < size; i++)
	{
		walker = i;
		while((walker > 0) && (copy[walker - 1].key > copy[walker].key))
		{
         // increment count, used for bigO
         count++;

         // swap data
			swapData(copy[walker], copy[walker - 1]);
         
         // decrement walker
			walker--;
		}
	}

	outputData(copy, size, count, 'i');
   
   return;

}


#endif
