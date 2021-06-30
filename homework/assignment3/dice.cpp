/*********************************************************************
 * * Author: XiYuan Huang
 * * Date: 5/8/2018
 * * Description:
 *******************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using std::endl;
using std::cout;
using std::cin;


int player_scoreboard(int Dice1, int Dice2, int player_turn)
{
	int player1 = 0;
	int player2 = 0;
	
	if(player_turn == 1){

		player1 = player1 + Dice1 + Dice2;
		return player1;

	}else if(player_turn == 2){

		player2 = player2 + Dice1 + Dice2;
		return player2;
	}
}	
	
void rollDice(int& x, int& y)
{
	int first, second;

	srand(time(NULL));

	first = rand()% 6 + 1;
	second = rand()% 6 + 1;
	


}

int player()
{
 	int count = 0;
	int player;
	if(count == 0){
		player = 1;
		count++;
	}else if(count == 1){
		player = 2;
		--count;
	}

	return player;
}

int checkDice(int first, int second)
{
	if(first == 1 || second == 1){
		
		return 0;

	}else if(first == 1 && second == 1){
		
		return 1;

	}else{
	
		return 2;
	}				
}

int main()
{
	int Dice1;
	int Dice2;
	char input = ' ';
	bool repeat = false;
	int player_turn = player();
	//while(number < 100){
		do{
			//repeat = true;

			cout << "This is the player" << player_turn << "'s turn" << endl;
			rollDice(Dice1, Dice2);
			cout << "Dice1 is " << Dice1 << "Dice2 is " << Dice2 << endl;
			int num = checkDice(Dice1, Dice2);
			int playerScore = player_scoreboard(Dice1, Dice2, player_turn);
			cout << "The current score is " << playerScore << endl;
			cout << "Do you want to keep going (Y/N) " << endl;
			cin >> input;
			if(input == 'Y'){
				repeat = true;
			}else if(input == 'N'){
				repeat = false;
			}else{
				repeat = false;
			}
		}while(repeat == true );

	//}

	return 0;
}
