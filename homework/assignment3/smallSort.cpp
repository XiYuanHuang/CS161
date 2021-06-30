/***********************************************************************
 * * Author: XiYuan Huang
 * * Date:5/8/2018
 * * Description:The program takes three int parameters by reference and sorts their values into ascending order, 
 *   so that the first parameter now has the lowest value, 
 *   the second parameter the middle value, and the third parameter has the highest value.  
 ***********************************************************************/

#include <iostream>

using std::endl;
using std::cout;
using std::cin;

/**********************************************************
 * * Description: This function takes three int parameters by reference and sorts their 
 *   value from lowest to highest.
 **********************************************************/
void smallsort(int& first, int& second,int& third)
{
	int max, mid,min; 
	if(first > second && first > third){
		max = first;
		if(second > third){
			mid = second;
			min = third;
		}else if(second < third){
			mid = third;
			min = second;
		}
	}else if(first < second && first < third){
		min = first;
		if(second > third){
			max = second;
			mid = third;
		}else if(second < third){
			max = third;
			mid = second;
		}
	}else if(first > second && first < third){
		mid = first;
		max = third;
		min = second;
	}else if(first < second && first > third){
		mid = first;
		max = second;
		min = third;
	}else if(first == second && first == third && second == third){
		min = first;
		mid = second;
		max = third;
	}

	if(first == second){
		if(second > third){
			max = second;
			mid = first;
			min = third;
		}else if(second < third){
			mid = second;
			max = third;
			min = first;
		}
	}else if(second == third){
		if(first > second){
			max = first;
			mid = second;
			min = third;
		}else if(first < second){
			max = second;
			mid = third;
			min = first;
		}
	}else if(first == third){
		if(second > third){
			max = second;
			min = first;
			mid = third;
		}else if(second < third){
			max = third;
			mid = first;
			min = second;
		}
	}

	first= min;
	second = mid;
	third = max;
}
    
int main()
{
	int first, second, third;
	cout << "enter the first integer" << endl;
	cin >> first;
	cout << endl;
	cout << "enter the second integer" << endl;
	cin >> second;
	cout << endl;
	cout << "enter the third integer" << endl;
	cin >> third;
	cout << endl;

	smallsort(first, second, third);
	cout << first << "," << second << "," << third << endl;

	return 0;
}

