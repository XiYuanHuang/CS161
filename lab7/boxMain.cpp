
#include <iostream>
#include "box.hpp"

using std::endl;
using std::cout;
using std::cin;



int main()
{
	Box box2;
        Box box1(2.4, 7.1, 5.0);
	
	double volume1 = box1.calcVolume();
	double surfaceArea1 = box1.calcSurfaceArea();

	double volume2 = box2.calcVolume();
	double surfaceArea2 = box2.calcSurfaceArea();
	
	cout << "The box1's volume is " << volume1 << endl;
	cout << "The box1's surfaceArea1 is " << surfaceArea1 << endl;
	cout << "The box'2 volume is " << volume2 << endl;
	cout << "The box's surfaceArea1 is " << surfaceArea2 << endl;

	return 0;
}

