
/********************************************************************* 
 * ** Author: XiYuan Huang
 * ** Date:6/6/2018
 * ** Description:This is the head file of the BBoard class. The detail of
 *  the BBoard class is included in the BBoard cpp file.
 * *********************************************************************/ 
#ifndef BBOARD_HPP
#define BBOARD_HPP

#include <iostream>
#include "Ship.hpp"

/********************************************************************
 * * Description:The BBoard class has:
 *
 *   a 10x10 array of bools (for keeping track of what squares have been attacked)
 *   a 10x10 array of Ship-pointers (for keeping track of which Ships occupy which squares)
 *   a variable that keeps track of the number of ships that remain un-sunk
 *   a constructor that initializes each element of the bool array to false and each 
 *     element of the Ship-pointer array to NULL (or nullptr if you prefer)
 *   a method called getAttacksArrayElement that takes a row and column (in that order) 
 *     and returns the element at that position of the bool array
 *   a method called getShipsArrayElement that takes a row and column (in that order) 
 *     and returns the element at that position of the ships array
 *   a method called getNumShipsRemaining that returns how many ships remain un-sunk
 *   a method called placeShip that takes as parameters (in this order): the address 
 *     of a Ship object, the row and column of the square of the Ship that is closest 
 *     to (0, 0), and the Ship's orientation (either 'R' if its squares occupy the 
 *     same row or 'C' if its squares occupy the same column). 
 *   a method called attack that takes as parameters the row and column of the attack 
 *     (in that order).
 *   a method called allShipsSunk that returns true if all ships on the Board have 
 *     been sunk, but returns false otherwise
 *******************************************************************/
class BBoard
{
	private:
		bool attacked[10][10];
		Ship* shipArray[10][10];
		int unSunk;
	public:
		BBoard();
		//void printBoard();
		bool getAttacksArrayElement(int r, int c);
		Ship* getShipsArrayElement(int r, int c);
		int  getNumShipsRemaining();
		bool placeShip(Ship* ship, int r, int c, char orientation);
		bool attack(int r, int c);
		bool allShipsSunk();
};

#endif 
				
		
