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


#ifndef __INSERTION__
#define __INSERTION__

// Insertion Sort
void insertionSort(data arr[], int size)
{

	int walker;
	int count = 0;

	ofstream sins;

	data copy[size];

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

   // copy to file, if size = 100
	if(size == 100)
	{
		sins.open("sins100.dat");
		sins << "Calculated Big-O: 10000"                   << endl;
		sins << "From project Big-O: "             << count << endl;
		sins << "List of sorted keys and numbers:" <<  endl << endl;
		sins << setw(10) << "Key" << setw(20) << "Data"     << endl;
		sins << "----------  ------------------"            << endl;
		
		for(int i = 0; i < size; i++)
		{
			sins << setw(10) << copy[i].key;
			sins << setw(20) << copy[i].num << endl;
		}
	}

   // copy to file, if size = 1000
	if(size == 1000)
	{
		sins.open("sins1000.dat");
		sins << "Calculated Big-O: 1000000"                 << endl;
		sins << "From project Big-O: "             << count << endl;
		sins << "List of sorted keys and numbers:" << endl  << endl;
		sins << setw(10) << "Key" << setw(20) << "Data"     << endl;
		sins << "----------  ------------------"            << endl;
		
		for(int i = 0; i < size; i++)
		{
			sins << setw(10) << copy[i].key;
			sins << setw(20) << copy[i].num << endl;
		}
		
	}

   // copy to file, if size = 5000
	if(size == 5000)
	{
		sins.open("sins5000.dat");
		sins << "Calculated Big-O: 25000000"                 << endl;
		sins << "From project Big-O: "              << count << endl;
		sins << "List of sorted keys and numbers:"  <<  endl << endl;
		sins << setw(10) << "Key" << setw(20) << "Data"      << endl;
		sins << "----------  ------------------"             << endl;
		
		for(int i = 0; i < size; i++)
		{
			sins << setw(10) << copy[i].key;
			sins << setw(20) << copy[i].num << endl;
		}
	}
   
   return;

}


#endif
