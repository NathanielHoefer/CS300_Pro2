/******************************************************************************
Author:     
Studend ID: 

Project:    #2
******************************************************************************/

using namespace std;
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include "data.cpp"
#include "printswap.cpp"


#ifndef __SELECTION__
#define __SELECTION__

// Selection Sort
void selectionSort(data arr[], int size)
{
	int j, min;
	int count = 0;

	ofstream sels;

	data copy[size];

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


   // prints out data if size = 100
	if(size == 100)
	{
      sels.open("sels100.dat");
		sels << "Calculated Big-O: 10000"                   << endl;
		sels << "From project Big-O: "             << count << endl;
		sels << "List of sorted keys and numbers:" << endl  << endl;
		sels << setw(10) << "Key" << setw(20) << "Data"     << endl;
		sels << "----------  ------------------"            << endl;
		
		for(int i = 0; i < size; i++)
		{
			sels << setw(10) << copy[i].key;
			sels << setw(20) << copy[i].num << endl;
		}
	}
   
   // prints out data if size = 1000
	if(size == 1000)
	{
		sels.open("sels1000.dat");
		sels << "Calculated Big-O: 1000000"                 << endl;
		sels << "From project Big-O: "             << count << endl;
		sels << "List of sorted keys and numbers:" << endl  << endl;
		sels << setw(10) << "Key" << setw(20) << "Data"     << endl;
		sels << "----------  ------------------"            << endl;
		
		for(int i = 0; i < size; i++)
		{
			sels << setw(10) << copy[i].key;
			sels << setw(20) << copy[i].num << endl;
		}
	}

   // prints out data if size = 5000
	if(size == 5000)
	{
		sels.open("sels5000.dat");
		sels << "Calculated Big-O: 25000000"                << endl;
		sels << "From project Big-O: "             << count << endl;
		sels << "List of sorted keys and numbers:" << endl  << endl;
		sels << setw(10) << "Key" << setw(20) << "Data"     << endl;
		sels << "----------  ------------------"            << endl;
		
		for(int i = 0; i < size; i++)
		{
			sels << setw(10) << copy[i].key;
			sels << setw(20) << copy[i].num << endl;
		}
	}
}


#endif
