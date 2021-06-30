
#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	double origin, percent, profit;

	cout << "What is the origin piece?" << endl;
	cin >> origin;

	cout << "What is the percent of profit?(the number should be float)" << endl;
	cin >> percent;

	profit = origin + origin * percent;
	cout << "The selling piece is " << profit;
	cout << "." << endl;
	
	return 0;
}		

