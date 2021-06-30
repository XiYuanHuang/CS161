#include <iostream>
#include <iomanip>
#include <fstream>

using std::endl;
using std::cout;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::ios;

int main()
{
	 int sum = 0;
   	 int x;
   	 ifstream myfile;
    
   	 myfile.open("test.txt");

   	 if (myfile.is_open()) {

	  	 while (myfile >> x) {
       		 sum += x;
   		 }

         }else{
		cout << "Could not access the file" << endl;
	 }

   	 myfile.close();

         ofstream outputfile;

	 outputfile.open("sum.txt", ios::app);
	
	 if (outputfile.is_open()) {
	
		outputfile << sum;
	 }else{
		cout << "Could not access the file" << endl;
	 }
	 
         outputfile.close();
 
  	 return 0;
}
