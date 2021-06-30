
#include <iostream>
#include <iomanip>
#include <fstream>

using std::endl;
using std::cout;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::string;

int main()
{
	 int sum = 0;
   	 int x;
	 string filename;

	 cout << "Please enter a filename" << endl;
	 cin >> filename;
    
	 ifstream myfile;
   	 myfile.open(filename);

   	 if (myfile.is_open()) {

	  	 while (myfile >> x) {
       		 sum += x;
   		 }

         }else{
		cout << "Could not access the file" << endl;
	 }

   	 myfile.close();

         ofstream outputfile;

	 outputfile.open("sum.txt");
	
	 if (outputfile.is_open()) {
	
		outputfile << sum;
	 }
	 
         outputfile.close();
 
  	 return 0;
}
