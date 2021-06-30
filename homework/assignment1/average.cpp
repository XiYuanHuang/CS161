/****************************************************************
 * * Author: XiYuan Huang
 * * Date: 4/9/2018
 * * Description: This program asks the user for five numbers
 * 		  and then print out the average of those numbers.
 ****************************************************************/

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	double num1, num2, num3, num4, num5, average;
	
	cout << "Please enter five different numbers" << endl;
	cin >> num1;
	cin >> num2;
	cin >> num3;
	cin >> num4;
	cin >> num5;

	average = (num1 + num2 + num3 + num4 + num5) / 5;
	cout << "The average of those number is " << average;
	cout << "." << endl;

	return 0;
}	
