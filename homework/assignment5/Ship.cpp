
/********************************************************************* 
 * ** Author: XiYuan Huang
 * ** Date:6/6/2018
 * ** Description: This is the Ship cpp file which includes the detail of public functions.
 * *********************************************************************/ 
#include "Ship.hpp"

#include <iostream>

using std::endl;
using std::cout;

/******************************************************
 * * Description:This is the default constructor which 
 *   initializes all private members.
 *****************************************************/
Ship::Ship()
{
	name = " ";
	length = 0;
	damage = 0;
	//shipLocation = 'x';
}

/******************************************************
 * * Description:This is the constructor that takes as 
 *    parameters (in this order): the Ship's name and 
 *    the Ship's length, which will be used to initialize 
 *    the corresponding data members. The damage should 
 *    be initialized to zero.
 ******************************************************/
Ship::Ship(string newName, int newlength)
{
	name = newName;
	length = newlength;
	damage = 0;
	//shipLocation = 'x';
}

/****************************************************
 * * Description:This function is to show the location 
 *   of the ship on the board by using the symbol of 'x'.
 ***************************************************/
/*char Ship::getShipLocation()
{
	return shipLocation;
}*/

/*****************************************************
 * * Description:This function is to get the name of a ship.
 *****************************************************/
string Ship::getName()
{
	return name;
}

/******************************************************
 * * Description:This function is to get the length of a ship.
 *****************************************************/
int Ship::getLength()
{
	return length;
}

/*****************************************************
 * * Description:This function is to show how many squares of a ship have been hit.
 ****************************************************/	
int Ship::getDamage()
{
	return damage;
}

/*****************************************************
 * * Description:This function increments a Ship's damage by one.
 *****************************************************/
int Ship::takeHit()
{
	damage += 1;

}

/****************************************************
 * * Description:This function is to distinguish whether the ship is sunk or not.
 ****************************************************/
bool Ship::isSunk()
{
	return this->damage == this->length;
}

