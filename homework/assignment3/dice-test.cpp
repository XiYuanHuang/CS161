
#include<iostream>

#include<cstdlib>

#include<string>

#include<time.h>

using namespace std;

int playerRoll(int strat, string name);

int getStrat(string name);

void printResults(string p1, int t1, string p2, int t2);

int getRandomNum(int lowRange, int highRange);

int main()

{

int total_player1 = 0;

int total_player2 = 0;

int player1_strat = 0;

int player2_strat = 0;

srand(static_cast<int> (time(NULL)));

player1_strat = getStrat("Player1");

player2_strat = getStrat("Player2");

cout << endl;

  

int whosTurn = 1;

do{

if (whosTurn == 1)

{

total_player1 = total_player1 + playerRoll(player1_strat, "Player 1");

cout << total_player1 << endl << endl;

whosTurn++;

}

else

{

total_player2 = total_player2 + playerRoll(player1_strat, "Player 2");

cout << total_player2 << endl << endl;

whosTurn--;

}

} while (total_player1 <= 100 && total_player2 <= 100);

if (total_player1 > total_player2)

{

printResults("Player 1", total_player1, "Player 2", total_player2);

}

else if (total_player2 > total_player1)

{

printResults("Player 2", total_player2, "Player 1", total_player1);

}

else

{

cout << "Draw! ";

cout << "(Note: if this happens there is something wrong with the code)";

cout << endl;

}

system("pause");

return 0;

}

int getStrat(string name)

{

int num = 0;

cout << "Enter "<<name<<"'s play until strategy: ";

do{

cin >> num;

if (!cin)

{

cin.clear();

cin.ignore(2000, '\n');

cout << "A number Please : ";

num = -1;

}

} while (num<0);

return num;

}

int playerRoll(int strat, string name)

{

int randomNum = 0;

int total = 0;

cout << name << "'s rolls for this turn are: ";

while (randomNum != 1 && total<strat)

{

randomNum = getRandomNum(1, 6);

total = total + randomNum;

if (randomNum!=1)

cout << randomNum << " ";

}

if (randomNum == 1)

{

cout << endl << name <<" rolled a " << randomNum << " ,its turn is over.";

total = 0;

}

cout << endl << name << " has completed its turn." << endl << name << " received " << total << " points for the turn." << endl << "current score for " << name << " is: ";

return total;

}

void printResults(string p1, int t1, string p2, int t2)

{

cout << p1 << " " << t1 << " ---V--- " << t2 << " " << p2 << endl << p1 << " has won with a score of " << t1 << "!!" << endl;

}

int getRandomNum(int lowRange, int highRange)

{

int randNum;

randNum = (rand() % (highRange - lowRange + 1)) + lowRange;

return randNum;

}
