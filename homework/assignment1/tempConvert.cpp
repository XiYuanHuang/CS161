/******************************************************************
 * * Author: XiYuan Huang
 * * Date: 4/9/2018
 * * Description: This program converts the Celsius temperature to 
 * 		  the Fahrenheit temperature.
 ******************************************************************/
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	double Fah, Cel;
	
	cout << "Please enter a Celsius temperature" << endl;
	cin >> Cel;

	Fah = (( 9.0 / 5.0) * Cel ) + 32;
	cout << "The equivalent Fahrenheit temperature is: " << endl;
	cout << Fah << endl;

	return 0;
}
