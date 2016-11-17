/******************************************************************************
Author:    
Student ID: 

Author:     
Studend ID: 

Project:    #2


/******************************************************************************


Description of the problem: 
   This program will generate three unsorted lists of data of different sizes:
   100, 1000, and 5000 items.  The unsorted lists will consist of a data
   structure that contains the key (an integer), and a random double number.  
   Both the key and the random double number will be randomly generated. The 
   structure will be put into an array and each array will be sorted using four
   different sorts. The program determines the Big-O value for each data size.
   
   Sorts:
      Quick     Sort: Chris
      Bubble    Sort: Chris
      Insertion Sort: Arelis
      Selection Sort: Arelis
   
Pseudocode
   
   Structure Name: data
   Data: key - holds an integer
         num - holds a double
   
   Functions: 
         void swapData(data & x, data & y)
         void quickSort(data arr[], int left, int right, int & count)
         void bubbleSort(data arr[], int size)
         void insertionSort(data arr[], int size)
         void selectionSort(data arr[], int size)
         
         
 *****************************************************************************
            
            
      swapData - swaps the order of two structures using a temp of the same type
         inputs:  x, y
         outputs: none
         returns: none
         
         
         temp = x
         x    = y
         y    = temp
         
         
******************************************************************************
     
         
      quickSort - sorts the data from smallest to largest, counts the passes it 
                  takes to sort the data
                  
         inputs:  array of structures (arr[]), integers: left, right, count
         outputs: none
         
         1. if (right - left) > 0, then
            1. sortleft  = left + 1
            2. sortright = right
            3. middle    = (left + right)/2
            4. if (arr[left] > arr[middle])
               1. call function swapData(arr[left], arr[middle])
            5. if (arr[left] > arr[right])
               1. call function swapData(arr[left], arr[right])     
            6. if (arr[middle] > arr[right])
               1. call function swapData(arr[middle], arr[right])
            7. call function swapData(arr[middle], arr[left])
            8. pivot = left
            9. loop (sortleft <= sortright)
               1. loop (arr[sortleft] < arr[pivot])
                  1. increment sortleft
               2. end loop
               3. loop (arr[sortright] >= arr[pivot])
                  1. decrement sortright
               4. end loop
               5. increment count
               6. if (sortleft < sortright)
                  1. call functin swapData(arr[sortleft], arr[sortright])
                  2. increment sortleft;
                  3. decrement sortright;
            10. end loop
            11. call function swapData(arr[sortleft - 1], arr[pivot])
            12. if (left < sortright)
               1. call quickSort recursively
            13. if (sortleft < right)
               1. call quickSort recursively
         2. end quickSort
         3. write data to files 
     
               
******************************************************************************


      bubbleSort - sorts array using bubble sort
      
      inputs: array, size
      outputs: prints information to bub100.dat, bub1000.dat, bub5000.dat
      
      Pre:   array cannot be empty
             size is the size of the array
             size - 1 is an index to the last element in the array

      Post:  array has been sorted
      
      1. sorted = false
      2. loop (curr = 0; curr < size && sorted == false; increment curr)
         1. sorted = true
         2. loop (walker = size - 1; walker > curr; decrement walker)
            1. increment count
            2. if (arr[walker] < arr[walker - 1])
               1. call function swapData
               2. sorted = false
         3. end loop
      3. end loop
      4. end bubbleSort
      5. write data to files

      
******************************************************************************


      insertionSort - sorts array using insertion. The array will be divided 
                      into two parts: unsorted and sorted. The first element of
                      the unsorted list will be inserted into the sorted list.
                      
      inputs: array, size
      outputs: prints information to sins100.dat, sins1000.dat, sins5000.dat 
                     
      Pre:   array cannot be empty
             size is the size of the array
             size - 1 is an index to the last element in the array

      Post:  array has been sorted
      
      1. loop (i = 0; i < size; increment i)
         1. set walker = i
         2. loop (walker > 0 AND arr[walker - 1] > arr[walker])
            1. increment count
            2. call function swapData
            3. decrement walker
         3. end loop
      2. end loop
      3. end insertionSort
      4. write data to files

      
*******************************************************************************


      selectionSort - sorts array using selection. Selects smallest element in 
                      the unsorted portion of the array and exchanges with the 
                      first element of the unsorted array
                      
      inputs: array, size
      outputs: prints information to sels100.dat, sels1000.dat, sels5000.dat 
      
      Pre:  array cannot be empty
            size is the size of the array
            size - 1 is an index to the last element in the array
            
      Post: array has been sorted
      
      1. loop (i = 0; i < size; increment i)
         1. set min = i
         2. loop (j = i + 1; j < size; increment j)
            1. increment count
            2. if (arr[j] < arr[min])
               1. min = j
         3. end loop
         4. if (min != i)
            1. call function swapData
      2. end loop
      3. end selectionSort
      4. write data to files
      

********************************************************************************
      
      
      Class Name: Node
       
      Data:    t         - data structure
               left      - Node pointer
               right     - Node pointer
               
      Constructor
         inputs: k (key), n (num)
         output: none
               sets t.key = k
               sets t.num = n
               sets left  = NULL
               sets right = NULL
               
      Mutator Functions
               set_left  - sets left  pointer
               set_right - sets right pointer
               setKey    - sets key
               
      Accesor Functions
               getKey    - returns key
               getNum    - returns num
               getLeft   - returns left  pointer
               getRight  - returns right pointer
               
               
*******************************************************************************
               
               
      Class Name: BST
      Data:   root       - Node pointer
              insertNode - recursive function
               
      Mutator Functions
               no mutator functions were used
               
      Accesor Functions
               no accesor functions were used
               
      Functions: 
            void insertNode(int, double, Node)
            void inorder(Node *p, ofstream &output)
            void print_inorder(ofstream &output)
            bool isEmpty()
            
            
******************************************************************************
               
      insertNode - inserts Node into binary search tree (private function)
      
      inputs:  integer, double
      outputs: none
      
      Pre:  binary search tree must be created
      Post: node must be inserted 
      
      1. if (k < leaf->getKey())
         1. if (leaf->getLeft() != NULL)
            1. call function insertNode
         2. else
            1. create new node
            2. set left leaf's pointer to treenode
      2. else
         1. if leaf's right pointer does not equal NULL
            1. call function insertNode
         2. else
            1. create new node
            2. set right leaf's pointer to treenode
      3. end insertNode
      
      
*******************************************************************************
               
      insertNode - inserts Node into binary search tree (public function)
      
      inputs: integer, double
      outputs: none
      
      Pre:  binary search tree must be created
      Post: node must be inserted 
      
      1. if (call function isEmpty)
         1. create new node
         2. set root = new node
      2. else 
         1. call function insertNode
      3. end insertNode
      
*******************************************************************************

      inorder - prints to file in order
      
      inputs: Node pointer, ofstream &output
      outputs: prints to file
      
      Pre: tree must have at least one node
      Post: tree node must be printed to file
      
      1. if node is not NULL
         1. call function inorder(p->getLeft(), output)
         2. print to node's key and num to file 
         3. call function inorder(p->getRight(), output)
      2. end inorder
      
*******************************************************************************

      print_inorder - recursive function
      
      inputs: ofstream &output
      outputs: prints to file
      
      Pre: tree must have at least one node
      Post: entire tree must be printed to the file
      
      1. call function inorder
      2. end print_inorder
      
********************************************************************************
      
      isEmpty - determines whether tree is empty
      
      inputs: none
      outputs: 1 if root equals NULL
               0 if root does not equal NULL
               
      Pre: none
      Post: returns tree empty or not empty
      
      1. return root == NULL
      2. end isEmpty
      
******************************************************************************/
/* Answer to Questions
*
*     1. Does the actual time agree with your calculations?
*        No. For the bubble sort, the bigO from the project is about
*        half of the calculated bigO. For the quick sort, the bigO from the
*        project is about 75% of the calculated bigO. For the selection sort, 
*        the bigO from the project is about half of the calculated bigO. For the
*        insertion sort, the bigO from the project is about 30%.
* 
*     2. Which sort is faster?
*        The fastest sort was the insertion sort. Since it only took about 30%
*        of the calculated bigO. 
* 
*     3. Does the data size make a difference?
*        
*        No. All the calculated bigO values, regardless of the data size, were 
*        approaching the percentages mentioned in question 1, except for 
*        the insertion sort. For this sort, as the size of the array gets 
*        larger, the percentage decreases. 
*/

using namespace std;
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include "data.cpp"
#include "bubble.cpp"
#include "insertion.cpp"
#include "selection.cpp"
#include "printswap.cpp"
#include "quick.cpp"
#include "bst.hpp"

// function used to swap data
void swapData(data & x, data & y);
// function used to print during testing
void printKey(data arr[], int size);

int main()
{
   int x, i;
	double y;

   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

	
	data  num100[100],  num1000[1000],  num5000[5000];
   data temp100[100], temp1000[1000], temp5000[5000];
  
   // generate list of random numbers for the array of size 100
   for(i = 0; i < 100; i++)
	{
		num100[i].key = rand () % 100000;
		x = rand () % 10000;
		y = rand () % 10000;
		num100[i].num = x / y;
	}

   // generate list of random numbers for the array of size 1000
	for(i = 0; i < 1000; i++)
	{
		num1000[i].key = rand () % 100000;
		x = rand () % 10000;
		y = rand () % 10000;
		num100[i].num = x / y;
	}

   // generate list of random numbers for the array of size 5000
	for(i = 0; i < 5000; i++)
	{
		num5000[i].key = rand () % 100000;
		x = rand () % 10000;
		y = rand () % 10000;
		num5000[i].num = x / y;
	}
  
   // Call bubble sort function
	bubbleSort(num100,   100);
	bubbleSort(num1000, 1000);
	bubbleSort(num5000, 5000);

   // Call insertion sort function
	insertionSort(num100,   100);
	insertionSort(num1000, 1000);
	insertionSort(num5000, 5000);

   // Call selection sort function
	selectionSort(num100,   100);
	selectionSort(num1000, 1000);
	selectionSort(num5000, 5000);

/*****************************************************************************/

	int count;

   count = 0;
   
   // make copy of array
   for(int i = 0; i < 100; i++) 
      temp100[i] = num100[i];
    
   // call quickSort function
	quickSort(temp100, 0, 99, count);
  
   // print quickSort data to file
   ofstream quick100;
   quick100.open("quick100.dat");
   quick100 << "Calculated Big-O: 200"                     << endl;
   quick100 << "From project Big-O: "             << count << endl;
   quick100 << "List of sorted keys and numbers:" << endl  << endl;
   quick100 << setw(10) << "Key" << setw(20) << "Data"     << endl;
   quick100 << "----------  ------------------"            << endl;
  
  for(int i = 0; i < 100; i++)
  {
    quick100 << setw(10) << temp100[i].key;
    quick100 << setw(20) << temp100[i].num << endl;
  }
  
   quick100.close();
   

/*****************************************************************************/

   count = 0;
   
   // make copy of array
   for(int i = 0; i < 1000; i++)
      temp1000[i] = num1000[i];

   // call quickSort function
	quickSort(temp1000, 0, 999, count);

   // print quickSort data to file
   ofstream quick1000;
   quick1000.open("quick1000.dat");
   quick1000 << "Calculated Big-O: 3000"                    << endl;
   quick1000 << "From project Big-O: "             << count << endl;
   quick1000 << "List of sorted keys and numbers:" << endl  << endl;
   quick1000 << setw(10) << "Key" << setw(20) << "Data"     << endl;
   quick1000 << "----------  ------------------"            << endl;

   for(int i = 0; i < 1000; i++)
   {
      quick1000 << setw(10) << temp1000[i].key;
      quick1000 << setw(20) << temp1000[i].num << endl;
   }

   quick1000.close();

/*****************************************************************************/

   count = 0;
   
   // make copy of array
   for(int i = 0; i < 5000; i++)
      temp5000[i] = num5000[i];

   // call quickSort function
   quickSort(temp5000, 0, 4999, count);

   //print quickSort data to file
   ofstream quick5000;
   quick5000.open("quick5000.dat");
   quick5000 << "Calculated Big-O: 18495"                   << endl;
   quick5000 << "From project Big-O: "             << count << endl;
   quick5000 << "List of sorted keys and numbers:" << endl  << endl;
   quick5000 << setw(10) << "Key" << setw(20) << "Data"     << endl;
   quick5000 << "----------  ------------------"            << endl;
  
  for(int i = 0; i < 5000; i++)
  {
    quick5000 << setw(10) << temp5000[i].key;
    quick5000 << setw(20) << temp5000[i].num << endl;
  }
  
   quick5000.close();
  
  
   cout << endl << "All of the data was sent to their respective files!" 
        << endl << endl;
        
/*****************************************************************************/

   // create three different binary trees
   // for different the different sizes
   BST  binaryTree1 = BST();
   BST  binaryTree2 = BST();
   BST  binaryTree3 = BST();
   
   // insert each node
   for(int i = 0; i < 100; i++)
      binaryTree1.insertNode(num100[i].key, num100[i].num);
   
   // print data to file
   ofstream bst1("bst100.dat");
   
   
   bst1 << "List of sorted keys and numbers:"  <<  endl << endl;
   bst1 << setw(10) << "Key" << setw(20) << "Data"      << endl;
   bst1 << "----------  ------------------"             << endl;
   
   bst1.setf(ios::fixed);
   bst1.setf(ios::showpoint);
   bst1.precision(2);

   // print inoder
   binaryTree1.print_inorder(bst1);
   bst1.close();

/*****************************************************************************/
   
   // insert each node
   for(int i = 0; i < 1000; i++)
      binaryTree2.insertNode(num1000[i].key, num1000[i].num);
   
   // print data to file
   ofstream bst2("bst1000.dat");
   
   bst2 << "List of sorted keys and numbers:"  <<  endl << endl;
   bst2 << setw(10) << "Key" << setw(20) << "Data"      << endl;
   bst2 << "----------  ------------------"             << endl;
   
   
   bst2.setf(ios::fixed);
   bst2.setf(ios::showpoint);
   bst2.precision(2);

   // print inorder
   binaryTree2.print_inorder(bst2);
   bst2.close();
   
/******************************************************************************/
   
   // insert each node
   for(int i = 0; i < 5000; i++)
      binaryTree3.insertNode(num5000[i].key, num5000[i].num);
   
   ofstream bst3("bst5000.dat");
   
   // print data to file
   bst3 << "List of sorted keys and numbers:"  <<  endl << endl;
   bst3 << setw(10) << "Key" << setw(20) << "Data"      << endl;
   bst3 << "----------  ------------------"             << endl;
   
   
   bst3.setf(ios::fixed);
   bst3.setf(ios::showpoint);
   bst3.precision(2);

   // print inorder
   binaryTree3.print_inorder(bst3);
   bst3.close();
   
   return 0;
}



