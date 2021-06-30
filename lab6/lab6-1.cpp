
#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

double fallDistance(int time)
{
	double distance = (0.5 * 9.8) * pow(time, 2);

	return distance;
}

int main()
{
	double falling_time;
	double distance;
	cout << "Please enter the falling time " << endl;
	cin >> falling_time;

	distance = fallDistance(falling_time);

	cout << "The distance is " << distance << endl;
	return 0;
}
