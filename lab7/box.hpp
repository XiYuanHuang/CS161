
#ifndef BOX_HPP
#define BOX_HPP

#include <iostream>

class Box
{
	private:
		double length;
		double height;
		double width;
	public:
		Box();
		Box(double len, double wid, double hei);
		void setHeight(double hei);
		void setWidth(double wid);
		void setLength(double len);
		double calcVolume();
		double calcSurfaceArea();
};

#endif
