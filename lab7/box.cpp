
#include "box.hpp"

#include <iostream>

Box::Box()
{
	length = 1;
	height = 1;
	width = 1;
}
Box::Box(double len, double wid, double hei)
{
	length = len;
	width = wid;
	height = hei;
}
void Box::setHeight(double hei)
{
	height = hei;
}
void Box::setWidth(double wid)
{
	width = wid;
}
void Box::setLength(double len)
{
	length = len;
}
double Box::calcVolume()
{
	return height * width * length;
}
double Box::calcSurfaceArea()
{
	return 2 * ((length *width) + (width * height) + (height * length));
}
