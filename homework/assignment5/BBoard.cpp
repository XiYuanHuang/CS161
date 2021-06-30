
/********************************************************************* 
 * ** Author: XiYuan Huang
 * ** Date:6/6/2018
 * ** Description:This is the BBoard cpp file which includes the detail of public functions.
 * *********************************************************************/ 
#include "BBoard.hpp"


#include <iostream>

using std::cout;
using std::endl;

/************************************************
 * * Description:This is the constructor that initializes 
 *   each element of the bool array to false and each 
 *   element of the Ship-pointer array to NULL.
 ************************************************/
BBoard::BBoard()
{
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			attacked[i][j] = false;
			shipArray[i][j] = NULL;
		}
	}
	unSunk = 0;
}

/***********************************************
 * * Description:This function is to print out the board.
 **********************************************/
/*void BBoard::printBoard()
{
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(shipArray[i][j] == NULL){
				cout << ' ' << '|';
			}else{
				cout << shipArray[i][j]->getShipLocation()<< '|';
			}
		}
	cout << endl << "---------------------------"<< endl;
	}
}*/

/************************************************
 * * Description:This function is to take a row and column 
 *   (in that order) and returns the element at that position of the bool array.
 ************************************************/
bool BBoard::getAttacksArrayElement(int r, int c)
{
	return attacked[r][c]; 
}

/***********************************************
 * * Description: This function is to take a row and column 
 *   (in that order) and returns the element at that position of the ships array.
 ***********************************************/
Ship* BBoard::getShipsArrayElement(int r, int c)
{
	return shipArray[r][c];
}

/**********************************************
 * * Description: This function is to record how many ships remain un-sunk.
 *********************************************/
int BBoard::getNumShipsRemaining()
{
	return unSunk;
}

/***********************************************
 * * Description:This function is to place a ship on the board.
 ***********************************************/
bool BBoard::placeShip(Ship* ship, int r, int c, char orientation)
{
	if(shipArray[r][c] == NULL){
	if(orientation == 'R'){
		if((c + (*ship).getLength() < 10)){
			for(int i = c; i < c + (*ship).getLength(); i++){
				shipArray[r][i] = ship;
			}
			unSunk++;
			return true;
		}else{
			return false;
		}
	}else if(orientation == 'C'){
		if((r + (*ship).getLength() < 10)){
			for(int i = r; i < r + (*ship).getLength(); i++){
				shipArray[i][c] = ship;
			}
			unSunk++;
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
	}else{
		return false;
	}		
}

/***********************************************
 * * Description:This function is to take as parameters 
 *   the row and column of the attack (in that order).
 ***********************************************/
bool BBoard::attack(int r, int c)
{
	if(shipArray[r][c] == NULL){
		attacked[r][c] = true;
		
		return false;
	}else{
		if(attacked[r][c] == false){
			
			shipArray[r][c]->takeHit();
			
		
			if(shipArray[r][c]->isSunk()){
		
				cout << "They sank " << shipArray[r][c]->getName() << endl;
				unSunk--;
			}
		}	
		attacked[r][c] = true;
	}
	return true;
}

/************************************************
 * * Description: This function returns true if all ships 
 *   on the Board have been sunk, but returns false otherwise.
 ***********************************************/
bool BBoard::allShipsSunk()
{
	if(unSunk == 0){
		return true;
	}else{
		return false;
	}
}



