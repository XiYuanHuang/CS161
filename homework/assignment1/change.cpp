/**************************************************************************************************************
 * * Author: XiYuan Huang
 * * Date: 4/9/2018
 * * Description:This program asks the user for a (integer) number of cents, from 0 to 99, 
 *   and outputs how many of each type of coin would represent that amount with the fewest total number of coins. 
 ***************************************************************************************************************/
 
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	int num1, num2, num3, num4, num5, num6, num7, num8;

	cout << "Please enter an amount in cents less than a dollar." << endl;
	cin >> num1;
	
	num2 = num1 / 25;
	num3 = num1 % 25;
	num4 = num3 / 10;
	num5 = num3 % 10;
	num6 = num5 / 5;
	num7 = num5 % 5;
	num8 = num7 / 1;
	
	cout << "Your change will be: " << endl;
	cout << "Quarter: " << num2 << endl;
	cout << "Dime: " << num4 << endl;
	cout << "Nickel: " << num6 << endl;
	cout << "Penny: " << num8 << endl;

	return 0;
}
