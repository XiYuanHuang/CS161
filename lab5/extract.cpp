
#include <iostream>
#include <cmath>

using std::endl;
using std::cin;
using std::cout;

int presentValue(double p, double f, int n);

int presentValue(double p, double f, int n, double i)
{


 		p = f / pow ( 1 + i, n);
	
	
	return p;
}
int main()
{
	double p,money;
	double f = 10000;
	int n = 10;
	
	for(double i = 0.01; i < 0.05; i += 0.005){
		
	int num = presentValue(p,f,n,i);
	
	cout << "the amount of money in the rate of " << i <<endl;	
	cout << num << endl;

	}
	

	return 0;
		
}
