
#include <iostream>
#include <cmath>

using std::endl;
using std::cin;
using std::cout;

int main()
{
	int num;
	bool result = true;

	cout << "Please type a positive integer" << endl;
	cin >> num;

	for(int i = 2; i < num; i++){

		if((num % i) == 0){

			result = false;
			cout << i << endl;
		}
	}
	if(result){
		cout << "true" <<endl;
	}else{
		cout << "false" << endl;
	}

	return 0;
}
