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

#include "additionalFuncs.cpp"
#include "data.cpp"

using namespace std;

#ifndef __QUICK__
#define __QUICK__

// Quick sort
void quickSort(data arr[], int left, int right, int & count)
{
   // if right minus left is greater than zero
   if((right - left) > 0)
	{
      // set sortleft = left + 1
      int sortleft  = left + 1;
      // set sortright = right
		int sortright = right;
      // set middle equal to the average of left and right
		int middle    = (left + right) / 2;			

      // if the key of arr[left] is greater, swap
		if(arr[left].key   > arr[middle].key)
			swapData(arr[left],  arr[middle]);

      // if the key of arr[left] is greater, swap
		if(arr[left].key   > arr[right].key)
			swapData(arr[left],   arr[right]);

      // if the key of arr[middle] is greater, swap
		if(arr[middle].key > arr[right].key)
			swapData(arr[middle], arr[right]);

      // swap data
		swapData(arr[middle], arr[left]);

      // set pivot equal to the value of the left
		int pivot = left;

      // while sortleft is less than or equal to the sortright
		while (sortleft <= sortright)
		{
         // while arr[sortleft] < arr[pivot], increment left
			while(arr[sortleft].key  < arr[pivot].key)
            sortleft++;
		
         // while arr[sortright] >= arr[pivot], decrement right
			while(arr[sortright].key >= arr[pivot].key)
				sortright--;

         // increment count
         count++;

         // if sortleft is less than sortright
			if(sortleft < sortright)
			{
            //swap data
				swapData(arr[sortleft], arr[sortright]);
            //increment sort left
				sortleft++;
            //decrement sort right
				sortright--;
			}
		}

      // swapData
		swapData(arr[sortleft - 1], arr[pivot]);

      // call quicksort function recursively
      // if left is less than sortright
		if(left < sortright)
			quickSort(arr, left, sortright - 1, count);

      // if sortleft is less than sortright
		if(sortleft < right)
			quickSort(arr, sortleft, right, count);
  }
  
  return;
}
#endif
