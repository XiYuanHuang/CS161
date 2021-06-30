 
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int num = 0;

	cout << "How many integers do you want? " << endl;
	cin >> num;
	
	int input[num];

	for(int i=0; i < num; i++) {

		cout << "Please enter " << i+1 << " integer. " << '\t';
		cin >> input[i];
	
	}
	
	int max = input[0];
	for(int i=1; i < num; i++) {
		if(input[i] > max){
			max = input[i];
		}
	}

	int min = input[0];
	for(int i=1; i < num; i++) {
		if(input[i] < min){
			min = input[i];
		}
	}
	
	cout << "The Max number is " << max << endl;
	cout << "The Min number is " << min << endl;
	return 0;
}
