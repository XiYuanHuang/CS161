
/********************************************************************* 
 * ** Author: XiYuan Huang
 * ** Date: 6/6/2018
 * ** Description: This program replaces an array with one that is twice as long, 
 *    with the values from the original array followed by each of those values plus one. 
 * *********************************************************************/

#include <iostream>

using std::cout;
using std::endl;

/***************************************************************
 * * Description: This function takes two parameters-
 *   a reference to a pointer to a dynamically allocated array of ints, 
 *   and the size of that array. This function replaces the array with 
 *   one that is twice as long, with the values from the 
 *   original array followed by each of those values plus one. 
 ****************************************************************/
void transformArray(int*& myArray, int size)
{
	int* newArray = new int[size * 2];
	for(int i = 0; i < size; i++){
		newArray[i] = myArray[i];
	}
	for(int k = 0; k < size; k++){
		int i = 1;
		newArray[size + k] = myArray[k] + i;
	}
	
	delete [] myArray;
	myArray = newArray;
}

/*int main()
{

	int* myArray = new int[3];
	myArray[0] = 4;
	myArray[1] = 2;
	myArray[2] = 5;

   	transformArray(myArray, 3);
   	for (int i=0; i<6; i++)
      	cout << myArray[i] << endl;

   	delete []myArray;
}*/
