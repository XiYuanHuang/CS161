
#include <iostream>

using std::cout;
using std::endl;
using std::max;

int arrayMax(int arr[], int size)
{
	if(size == 1){
		return arr[0];
	}else{
		return max(arr[size - 1], arrayMax(arr, size - 1));		
	}
}
int main()
{
	int arr[] = {23, 5, -10, 0, 0, 321, 1, 2, 99, 30, 11};
        int size = 11;
	
	cout << arrayMax(arr, size) << endl;
}
