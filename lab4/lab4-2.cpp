
#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	double num, sum;
	int count = 0;
	int  num2;

	cout << "How many values do you want to enter? " << endl;
	cin >> num2;

	do{
		cout << "Please enter the value you want" << endl;
		cin >> num;
		sum += num;
		count++;
	}while(num2 > count);

	cout << "The average is " << sum / count;
	cout << "." << endl;

	return 0;
}
