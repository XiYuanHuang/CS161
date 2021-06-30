
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int numVowels(string input)
{
	int count = 0;

	for(int i = 0; i < input.length(); i++){
	
		if(input[i] == 'a' || input[i] == 'A'){

			count++;	
		}else if(input[i] == 'e' || input[i] == 'E'){
		
			count++;
		}else if(input[i] == 'i' || input[i] == 'I'){
			
			count++;
		}else if(input[i] == 'o' || input[i] == 'O'){
			
			count++;
		}else if(input[i] == 'u' || input[i] == 'U'){
			
			count++;
		}
	}			
	return count;
}

int main()
{
	string sentence = "";
	
	cout << "Please enter a sentence or a word" << endl;
	getline(cin, sentence);


	int numberOfVowels = numVowels(sentence);
	
	cout << "The number of vowels is " << numberOfVowels << endl;


	return 0;
}
