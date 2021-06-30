
#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	int num1, num2, num3;

	srand (time(NULL));

	num1 = rand() % 41 + 10;
	num2 = rand() % 41 + 10;

	cout << "What is " << num1 << " + " << num2;
	cout << "?" << endl;
	cin >> num3;
	if (num3 == num1 + num2){
		cout << "Congratulation!" << endl;
	}else {
		cout << "The correct answer is " << num1 + num2 << endl;
	}
	return 0;
}
