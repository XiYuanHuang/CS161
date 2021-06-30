
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;


int main()
{
	int num1, num2, num3, num4;

	cout << "Please enter a year" << endl;
	cin >> num1;
	
	num2 = num1 % 100;
	num3 = num1 % 400;
	num4 = num1 % 4;

	if(num2 == 0 && num3 == 0){
		cout << "The month of February in this year is 29 days" << endl;
	}else if(num2 != 0 && num4 == 0){
		cout << "The month of February in this year is 29 days" << endl;
	}else{
		cout << "The moneth of February in this year is 28 days" << endl;
	}
	return 0;
}

