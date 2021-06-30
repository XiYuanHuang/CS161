
#include <iostream>

using std::cout;
using std::endl;

void swap(int *first, int *second);
void smallSort2(int *a, int *b, int *c);

void smallSort2(int *a, int *b, int *c)
{
	if((*a <= *b) && (*b <= *c)){

	}
	if((*a <= *c) && (*c <= *b)){
		swap(c, b);
	
	}
	if((*c <= *a) && (*a <= *b)){
		swap(a, c);
		swap(b, c);
		
	}
	if((*c <= *b) && (*b <= *a)){
		swap(a, c);
	

	}
	if((*b <= *a) && (*a <= *c)){
		swap(a, b);
	
	
	}
	if((*b <= *c) && (*c <= *a)){
		swap(a, b);
		swap(b, c);
		
	}
}

void swap(int *first, int *second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}

int main()
{
	int a = 14;
	int b = -90;
	int c = 2;
	smallSort2(&a, &b, &c);
	cout << a << ", " << b << ", " << c << endl;
}
