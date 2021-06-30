
/********************************************************************* 
 * ** Author: XiYuan Huang
 * ** Date:6/6/2018
 * ** Description: This is the head file of the Ship class. The detail of
 *    the Ship class is included in the Ship cpp file.
 * *********************************************************************/ 

#ifndef SHIP_HPP
#define SHIP_HPP

#include <iostream>

using std::string;

/*********************************************************************
 * * Description: The Ship class has:
 *
 *   a name (e.g. "my destroyer", "my submarine", "Boaty McBoatface")
 *   a length (the number of squares it occupies)
 *   a damage (how many of its squares have been hit)
 *   a constructor that takes as parameters (in this order): 
 *    the Ship's name and the Ship's length, which will be used to 
 *    initialize the corresponding data members.  The damage should be initialized to zero.
 *   getMethods for each data member (getName, getLength, getDamage)
 *   a method called takeHit that increments a Ship's damage by one
 *   a method called isSunk to distinguish whether the ship is sunk or not
 *********************************************************************/
class Ship
{
	private:
		string name;
		int length;
		int damage;
		//char shipLocation;
	public:
		Ship();
		Ship(string newName, int newlength);
		string getName();
		//char getShipLocation();
		int getLength();
		int getDamage();
		int takeHit();
		bool isSunk();
};

#endif
		
