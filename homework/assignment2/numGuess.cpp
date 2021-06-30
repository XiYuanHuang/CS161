
#include <iostream>

using std::endl;
using std::cin;
using std::cout;

int main()
{
	int input = 0;
	int count = 0;
	int guess = 0;

	cout << "Please enter a integer for the player to guess." <<endl;
	cin >> input;

	do{
		cout << "Enter your guess" << endl;
		cin >> guess;

		if(guess > input){
			cout << "Too high - try again" << endl;
		}else if(guess < input){
			cout << "Too lower - try again" << endl;
		}
		count++;
	}while(guess != input);		

	cout << "You guessed it in " << count << " tries. " << endl;

	return 0;
}
