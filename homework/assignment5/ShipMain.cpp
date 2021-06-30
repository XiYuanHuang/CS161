#include "Ship.hpp"
#include "BBoard.hpp"

#include <iostream>

using std::cout;
using std::endl;

int main()
{
   BBoard board;  // creates BBoard object
   Ship ship1("Boaty McBoatface", 2);  // creates Ship object
   cout << "the place ship1 "<< std::boolalpha << board.placeShip(&ship1, 2, 2, 'R') << endl;  // adds the Ship object to the Board object
   Ship ship2("Alex", 2);
   cout << "the place ship2 " << std::boolalpha << board.placeShip(&ship2, 2, 2, 'C') << endl;
   cout << std::boolalpha << board.allShipsSunk() << endl;  // prints whether all Ships are sunk
   board.attack(2, 2);  // attacks one square the Ship is on
   cout << "damage = " << ship1.getDamage() << endl;  // asks the Ship for its damage
   board.attack(2, 3);  // attacks the other square the Ship is on to sink the Ship
   cout << "The length of ship is " << ship1.getLength() << endl;
   cout << std::boolalpha << board.allShipsSunk() << endl;  // prints whether all Ships are sunk
   board.attack(2, 3);  // attacks a square that was already attacked
   board.attack(2, 2);
   cout << "After the ship sunk, the damage is " << ship1.getDamage() << endl;
   Ship* shipPtr = board.getShipsArrayElement(2, 3);  // gets the address of the Ship on square (2,3)

   return 0;
}
