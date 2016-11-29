/*****************************************************************************/
/* Project 2 - Sorting Algorithms											 */
/*****************************************************************************
	Author:  Atish Retna Rajah
    Student ID: R643D785

    Author: Nathaniel Hoefer
    Student ID: X529U639
    Program: Project 2

Functions:
	+ quickSort(Data list[], int left, int right, int &count): Sorts the list
		using the quick sort method through recursion
		Preconditions: left key is the first index and right key is the last
			index of the list.
		Postconditions: The submitted list will be in order
		> Check to see if left and right are the same
		> If not, find median
			> Loop while sortLeft is <= sortRight
				> Increment sortLeft while key < pivot key
				> Decrement sortRight while key >= pivot key
				> Exchange sortLeft and sortRight if sortLeft is <= sortRight
					then increment sortLeft and decrement sortRight
			> Update pivots and left element
			> Quicksort(left , sortRight -1) if left < sortRight
			> Quicksort(sortLeft, right) if sortLeft < right)


******************************************************************************/


#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include "additionalFuncs.cpp"
#include "data.cpp"

using namespace std;

#ifndef QUICK_CPP_
#define QUICK_CPP_

//	Sorts the list using the quick sort method through recursion
//		Preconditions: left key is the first index and right key is the last
//			index of the list.
//		Postconditions: The submitted list will be in order
void quickSort(Data list[], int left, int right, int &count)
{
	// Determines that left and right are not the same
	if((right - left) > 0)
	{

		int sortLeft = left + 1;
		int sortRight = right;
		int middle = (left + right) / 2;

		// When the key of list[left] is greater than middle, swap
		if(list[left].key > list[middle].key)
		swapData(list[left],  list[middle]);

		// When the key of list[left] is greater than right, swap
		if(list[left].key > list[right].key)
		swapData(list[left], list[right]);

		// When the key of list[middle] is greater than right, swap
		if(list[middle].key > list[right].key)
		swapData(list[middle], list[right]);

		// Swap the data of middle and left
		swapData(list[middle], list[left]);


		int pivot = left;

		// While sortLeft is less than or equal to the sortRight
		while (sortLeft <= sortRight)
		{
			while(list[sortLeft].key < list[pivot].key)
				sortLeft++;

			while(list[sortRight].key >= list[pivot].key)
				sortRight--;
		
		 // Increment the count
		 count++;

         // While sortLeft is less than sortRight
			if(sortLeft < sortRight)
			{
				swapData(list[sortLeft], list[sortRight]);
				sortLeft++;
				sortRight--;
			}
		}

		swapData(list[sortLeft - 1], list[pivot]);

		// Recursively call quickSort for left < sortRight
		if(left < sortRight)
			quickSort(list, left, sortRight - 1, count);

		// Recursively call quickSort for sortleft < right
		if(sortLeft < right)
			quickSort(list, sortLeft, right, count);
	}
}
#endif /* QUICK_CPP_ */
