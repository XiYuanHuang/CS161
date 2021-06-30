
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::sort;

double findMedian(int arr[], int size)
{
	sort(arr, arr + size);
	int evenSize = size / 2;
	int oddSize = (size + 1) / 2;
	if(size % 2 == 0){
		return (arr[evenSize] + arr[evenSize + 1]) / 2;
	}else{
		return arr[oddSize] / 2;
	}		
}
int main()
{
	int array[] = {23, 5, -10, 0, 0, 321, 1, 2, 99, 30, 11};
	int size = 11; 

	cout << "The median is " << findMedian(array, size) << endl;
}
