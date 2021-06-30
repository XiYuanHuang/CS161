
#include <iostream>

using namespace std;

int main()
{
	double fence, seeds, soil, total;

	cout << "How much do you spend on the fence?" << endl;
	cin >> fence;

	cout << "What is the cost of the flower seeds?" << endl;
	cin >> seeds;

	cout << "How much do you pay for the soil?" << endl;
	cin >> soil;

	total = fence + seeds + soil;
	
	cout << "You have spent $" << total << endl;
	return 0;
}

