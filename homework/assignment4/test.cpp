
#include <iostream>

using std::endl;
using std::cout;
using std::cin;
using std::string;


	/*string Table [3][3];
	cout << " 0 1 2 " << endl;
	for(int i = 0; i < 3; i++)	
		for(int j = 0; j < 3; j++)
		able[i][j] = "." ;*/


int main()
{
	string Table [3][3];
	cout << " 0 1 2 " << endl;
	for(int i = 0; i < 3; i++)	
		for(int j = 0; j < 3; j++)
		Table[i][j] = "." ;
		

	for(int i = 0; i < 3; i++)
	{
		cout << i;	
		for(int j = 0; j < 3; j++)
			cout << Table[i][j] << " ";
		cout << endl;
	}
	
	return 0;
}


