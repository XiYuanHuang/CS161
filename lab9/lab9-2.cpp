
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

double stdDev(Person *array, int size)
{
	double average = 0, sum = 0, stdDev = 0;
	for(int i = 0; i < size; i++)
	{
		sum += array[i].getAge();
	}
	average = sum / size;
	cout << "The average of age is: " << average << endl;
	for(int i = 0; i < size; i++)
	{
		stdDev += pow(array[i].getAge() - average, 2);
	}
	return sqrt(stdDev / size);
}

int main()
{
	double result;
	Person peopleArray[] = { 
		Person("Bob", 25),
		Person("Alex", 40),
		Person("Nick", 20),
		Person("Kit", 34)
	};


	result = stdDev(peopleArray, 4);
	cout << "The standard deviation of Age is :" <<result << endl;

	return 0;
}
