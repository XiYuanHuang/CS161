
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;
using std::abs;

class Taxicab
{
	private:
		int x;
		int y;
		int total;
	public:
		Taxicab()
		{
			x = 0;
			y = 0;
			total = 0;
		}
		Taxicab(int xd, int yd)
		{
			x = xd;
			y = yd;
		}
		int getX()
		{
			return x;	
		}
		int getY()
		{
			return y;
		}
		void moveX(int xMove)
		{
			x += xMove;
			total += abs(xMove);
		
		}
		void moveY(int yMove)
		{
			y += yMove;
			total += abs(yMove);
		}
		int getDistanceTraveled()
		{
			return total;	
		}
};	

int main()
{
	Taxicab cab1;
	Taxicab cab2(5, -8);
	cab1.moveX(3);
	cab1.moveY(-4);
	cab1.moveX(-1);
	cout << cab1.getDistanceTraveled() << endl;
	cab2.moveY(7);
	cout << cab2.getY() << endl;
}
