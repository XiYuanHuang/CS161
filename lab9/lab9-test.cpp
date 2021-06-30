
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::string;

class Person
{
	private:
		string name;
		double age;
	public:
		Person()
		{
			name = " ";
			age = 0;
		}
		Person(string personName, double personAge)
		{
			name = personName;
			age = personAge;
		}
		string getName()
		{
			return name;
		}
		double getAge()
		{
			return age;
		}
};

double stdDev(Person *people, int size)
{
	double sum = 0,average,standardDeviation=0;

	for (int count = 0; count < size; count++)
	{
		sum += people[count].getAge(); 
	}
	average = sum / size;
	cout << "The average of Age is :" << average <<endl;
	for(int i = 0; i < size; ++i){
		standardDeviation += pow(people[i].getAge() - average, 2); 
	}

	return sqrt(standardDeviation / size);

}                                                        

int main()
{
	double result;
	Person peopleArray[] = { 
		Person("Bob", 25),
		Person("Michele", 40),
		Person("nick", 20),
		Person("Rachel", 34)
	};


	result = stdDev(peopleArray, 4);
	cout << "The standard deviation of Age is :" <<result << endl;

	return 0;
}
