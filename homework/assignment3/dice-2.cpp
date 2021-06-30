/*************************************************************************************
 * * Author: XiYuan Huang
 * * Date: 5/9/2018
 * * Description:This programs allows 2 people to play a simple dice game.
 *   This game will alternate between players until one of them has won.The rules are as follows:
 *
 *   Each turn, a player repeatedly rolls two dice:
 *
 *   If no 1s are rolled, the sum of the dice is added to their turn total and the player's turn continues.
 *   If a player chooses to "hold", their turn total is added to their score, and it becomes the next player's turn.
 *   If a single 1 is rolled, the player scores nothing for that round and it becomes the next player's turn.
 *   If two 1s are rolled, the player’s entire score is lost, and it becomes the next player's turn.
 *************************************************************************************/

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using std::endl;
using std::cin;
using std::cout;

int rollDice();
int player_scoreboard(int total, int playerturnscore);

/*******************************************************************
 * * Description: This function is to roll two Dice, and returns 1, 
 *   0, and the sum of the two Dices. If the function returns 1, it means
 *   the point of two Dices is one. When the function returns 0, it means 
 *   either the point of Dice1 or Dice2 is one.
 ******************************************************************/
int rollDice()
{
	int x, y, turn;
	

	x = rand() % 6 + 1;
	y = rand() % 6 + 1;
	cout << "Dice1 = " << x << ", Dice2 = " << y << endl;

	if(x == 1 && y == 1){
		turn = 1;
	}else if(x == 1 || y == 1){
		turn = 0;
	}else{
		turn = x + y;
	}
	return turn;

}

/*****************************************************************
 * * Description: This function is to calculate the score of current turn.
 ****************************************************************/
int player_scoreboard(int total, int playerturnscore)
{

	if(total == 0){
		playerturnscore = 0;
	}else{
		playerturnscore = playerturnscore+ total;
	}
		return playerturnscore;

}


int main()
{
	int player1_score = 0, player2_score = 0;
	int total_player1 = 0, total_player2 = 0;
	bool player_turn = true;
	char decide = ' ';
	int startDice = 0;
	int player1turntotal = 0, player2turntotal = 0;
	srand(time(0));
	
	cout << "Welcome to the Dice game " << endl;
	cout << "This game will have two player and start at player1" << endl;
	cout << "Please enter 1 to start the game" << endl;
	cin >> startDice;
	cout << endl;
	
	if(startDice == 1){

	do{
		if(player_turn == true){
			
			int player1Dice = rollDice();
	
			cout << "total score of player1: " << total_player1 << endl;
			player1turntotal = player1turntotal + player_scoreboard(player1Dice, player1_score);
		
			cout << "player1_turntotal: " << player1turntotal << endl;				
			
			if(player1Dice == 1){
				cout << "player1's total score will become zero" << endl;
				total_player1 = 0;
				cout << "the current total score of player1 is " << total_player1 << endl;
				cout << " switch to next player" << endl << endl;
				player1turntotal = 0;
				player_turn = false;
			}else if(player1Dice == 0){
			
				cout << "The current turn score is zero, switch to next player " << endl;
				player1turntotal = 0;
				cout << "the current total score of player1 is " << total_player1 << endl << endl;
				player_turn = false;	
			}else{
			
				cout << "Do you want to keep going or not? (y/n)" << '\t';
				cin >> decide;
				if(decide == 'n'){
					total_player1 = total_player1 + player1turntotal;	
					cout << "the current total score of player1 is " << total_player1 << endl << endl;
					player1turntotal = 0;
					player_turn = false;				
				}else{
					player_turn = true;
				}
				if(total_player1 >= 100){
					cout << "player1 is winner" << endl;
					cout << "total score is " << total_player1 << endl;
				}else if (total_player2 >= 100){
					cout << "player2 is winner" << endl;
					cout << "total score is " << total_player2 << endl;
				}
	
			}
			
			/*total_player1 = total_player1 + player1turntotal;	
			cout << "the current total score of player1 is " << total_player1 << endl << endl;*/
	
		}else if(player_turn == false){
		
			int player2Dice = rollDice();
			
			cout << "total score of player2: " << total_player2 << endl;
			player2turntotal = player2turntotal + player_scoreboard(player2Dice, player2_score);
			cout << "player2_turntotal: " << player2turntotal << endl;		

			if(player2Dice == 1){
				cout << "player2's total score will become zero" << endl;
				total_player2 = 0;
				cout << "the current total score of player2 is " << total_player2 << endl;
				cout << " switch to next player " << endl << endl;
				player2turntotal = 0;
				player_turn = true;
			}else if(player2Dice == 0){

				cout << "The current turn score is zero, switch to next player " << endl;
				player2turntotal = 0;
				cout << "the current total score of player2 is " << total_player2 << endl << endl;
				player_turn = true;
			}else{
				
				cout << "Do you want to keep going or not? (y/n)" << '\t';
				cin >> decide;
				if(decide == 'n'){
					total_player2 = total_player2 + player2turntotal;
					cout << "the current total score of player2 is " << total_player2 << endl << endl;
					player2turntotal = 0;
					player_turn = true;
					
				}else{
					player_turn = false;
				}
 				if(total_player1 >= 100){
					cout << "player1 is winner" << endl;
					cout << "total score is " << total_player1 << endl;
				}else if (total_player2 >= 100){
				cout << "player2 is winner" << endl;
				cout << "total score is " << total_player2 << endl;
				}

			}
			
		}


	}while(total_player1 < 100 && total_player2 < 100);	
	}


	return 0;
}
