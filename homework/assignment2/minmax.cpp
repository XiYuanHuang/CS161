 
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int num = 0;
	int input, max, min;

	cout << "How many integers do you want? " << endl;
	cin >> num;
	
	cout << "What is the first integer? " << '\t';
	cin >> input;
	max = input;
	min = input;

	for(int i= 1; i < num; i++) {

		cout << "Please enter the " << i+1 << " integer. " << '\t';
		cin >> input;

		if(input > max){
			max = input;
		}else if(input < min){
			min = input;
		}
	
	}
	
	cout << "The Max number is " << max << endl;
	cout << "The Min number is " << min << endl;
	return 0;
}
