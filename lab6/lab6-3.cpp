
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int hailstone(int input)
{
	int count = 0;
	if(input != 1){

		do{
			if(input % 2 == 0){
				
			input = input / 2;
			}else{
			
			input = input * 3 + 1;
			}
			count++;
		}while(input != 1);

	}
	
	return count;

}

int main()
{
	int num, numOfStep;

	cout << "Please enter a number " << endl;
	cin >> num;
	
	numOfStep = hailstone(num);
	
	cout << "The total steps are " << numOfStep << endl;
	
return 0;
}
