/*****************************************************************************/
/* Project 2 - Sorting Algorithms											 */
/*****************************************************************************
	Author:  Atish Retna Rajah
    Student ID:

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


#ifndef __BUBBLE__
#define __BUBBLE__

// Bubble Sort
void bubbleSort(data arr[], int size)
{
	ofstream bub;

   // sets precision
   bub.setf(ios::fixed);
   bub.setf(ios::showpoint);
   bub.precision(2);

	data copy[size];
   
   // make a copy of the array
	for(int i = 0; i < size; i ++)
		copy[i] = arr[i];	

	int curr, walker;
	int count = 0;
	bool sorted = false;
	
	for(curr = 0; curr < size && sorted == false; curr++)
	{
		sorted = true;
		for(walker = size - 1; walker > curr; walker--)
		{
         // increment count, used for bigO
         count++;
      
			if(copy[walker].key < copy[walker - 1].key)
			{
				swapData(copy[walker], copy[walker - 1]);
				sorted = false;
			}
		}
	}	


   // copy to file, if size = 100
	if(size == 100)
	{
		bub.open("bub100.dat");
		bub << "Calculated Big-O (n^2): 10,000"             << endl;
		bub << "From project Big-O: "              << count << endl;
		bub << "List of sorted keys and numbers:"  <<  endl << endl;
		bub << setw(10) << "Key" << setw(20) << "Data"      << endl;
		bub << "----------  ------------------"             << endl;
		
		for(int i = 0; i < size; i++)
		{
			bub << setw(10) << copy[i].key;
			bub << setw(20) << copy[i].num << endl;
		}
	}


   // copy to file, if size = 5000
	if(size == 5000)
	{
		bub.open("bub5000.dat");
		bub << "Calculated Big-O (n^2): 25,000,000"         << endl;
		bub << "From project Big-O: "              << count << endl;
		bub << "List of sorted keys and numbers:"  <<  endl << endl;
		bub << setw(10) << "Key" << setw(20) << "Data"      << endl;
		bub << "----------  ------------------"             << endl;
		
		for(int i = 0; i < size; i++)
		{
			bub << setw(10) << copy[i].key;
			bub << setw(20) << copy[i].num << endl;
		}
	}

   // copy to file, if size = 10000
	if(size == 10000)
	{
		bub.open("bub10000.dat");
		bub << "Calculated Big-O (n^2): 100,000,000"       << endl;
		bub << "From project Big-O: "             << count << endl;
		bub << "List of sorted keys and numbers:" << endl  << endl;
		bub << setw(10) << "Key" << setw(20) << "Data"     << endl;
		bub << "----------  ------------------"            << endl;
		
		for(int i = 0; i < size; i++)
		{
			bub << setw(10) << copy[i].key;
			bub << setw(20) << copy[i].num << endl;
		}
	}

   return;

}

#endif
