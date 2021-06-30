/*******************************************************************************
 * * Author:XiYuan Huang
 * * Date:5/22/2018
 * * Description:Write a program that allows two players to play a game on a board 
 *     (1)Each player has three pieces which begin the game off of the board.
 *     (2)If not all of a player's pieces are on the board, they place one of them on any empty square of the board.  
 *     	  The first player cannot take the center as the first move of the game.
 *     (3)If all a player's pieces are on the board, they move one of them to any empty square that is (orthogonally or diagonally) adjacent.
 *     (4)If after a move (as in #2 or in #3) a player has all three of their pieces in a row (orthogonally or diagonally), that player wins.
 *********************************************************************************/
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::abs;

/************************************************************
 * * Description: This function initializes all the empty spaces 
 *     to be dot in the beginning and it only will be used once.
 ************************************************************/
void init_table(string board[][3])
{
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++)
			board[i][j] = ".";
	}
}

/*************************************************************
 * * Description: This function prints out the result of the 
 *     board after each turn.
 *************************************************************/
void print_table(string board[][3])
{
	cout << " 0 1 2 " << endl;
	for(int i = 0; i < 3; i++){
		cout << i;
		for(int j = 0; j < 3; j++){
			cout << board[i][j] << " ";
		
		}
		cout << endl;
	}
}

/***********************************************************
 * * Description: This function is to check whether space is empty.
 ***********************************************************/
int validPosition(string board[][3], int x, int y)
{
	if(board[x][y] == ".")
	{
		return 1;
	}else{
		return 0;
	}
}

/***********************************************************
 * * Description: This function is to check whether a player has all three of their 
 *   pieces in a row (orthogonally or diagonally) in order to decide who is the winner.
 ********************************************************/
int getWinner(string board[][3], bool turn)
{
	if(turn == false)
	{
		for(int i = 0; i < 3; i++){
			if(board[i][0] == "x" && board[i][1] == "x" && board[i][2] == "x"){
				return 1;
			}
		}
		for(int i = 0; i < 3; i++){
			if(board[0][i] == "x" && board[1][i] == "x" && board[2][i] == "x"){
				return 1;
			}
		}
		if(board[0][0] == "x" && board[1][1] == "x" && board[2][2] == "x"){
			return 1;
		}else if(board[0][2] == "x" && board[1][1] == "x" && board[2][0] == "x"){
			return 1;
		}else{
			return 0;
		}
	}else{
		for(int i = 0; i < 3; i++){
			if(board[i][0] == "o" && board[i][1] == "o" && board[i][2] == "o"){
				return 1;
			}
		}
		for(int i = 0; i < 3; i++){
			if(board[0][i] == "o" && board[1][i] == "o" && board[2][i] == "o"){
				return 1;
			}
		}
		if(board[0][0] == "o" && board[1][1] == "o" && board[2][2] == "o"){
			return 1;
		}else if(board[0][2] == "o" && board[1][1] == "o" && board[2][0] == "o"){
			return 1;
		}else{
			return 0;
		}
	}
}

/***************************************************************
 * * Description: This function is to determine whether the 
 *    position(the player wants to move) is existed and is not empty.
 ***************************************************************/
int checkPosition(string board[][3],bool turn, int x, int y)
{
	if(turn == false){
		if(board[x][y] == "x")
		{
			return 1;
		}else{
			return 0;
		}
	}else{
		if(board[x][y] == "o")
		{
			return 1;
		}else{
			return 0;
		}
	}
}

/***************************************************************
 * * Description: This function is to check whether the position 
 * 	(to where the player wants to move) is valid.
 ***************************************************************/
int checkDistance(int a, int b, int x, int y)
{
	int xDistance = abs(x - a);
	int yDistance = abs(y - b);
	if(xDistance > 1 || yDistance > 1){
		return 1;
	}else{
		return 0;
	}
}

int main()
{
	int player1 = 3, player2 = 3;
	bool flag = false, checkPiece;
	string table[3][3];
	int x = 0, y = 0, a = 0, b = 0;
	
	init_table(table);	
	print_table(table);

	do{
		checkPiece = false;	
	
		if(flag == false){
			cout << "This is player1's turn" << endl;
			cout << "Please enter two number to decide your piece's position" << endl;
			cout << "and seperate it with space" << endl;
			cin >> x >> y;
			cout << endl;
			while(checkPiece == false){
				if(player1 == 3 && x == 1 && y == 1)
				{
					cout << "The first player cannot put the first piece in the center" << endl;
					cout << "Please enter the position again" << endl;
					cin >> x >> y;
					cout << endl;
				}else if((x > 2) || (x < 0) || (y > 2) || (y < 0)){
					cout << "The position is not exist " << endl;
					cout << "Please enter the position again" << endl;
					cin >> x >> y;
					cout << endl;
				}else{ 
					if(validPosition(table, x, y) == 1){
						checkPiece = true;
					}else{
						cout << "The position is occupied" << endl;
						cout << "Please enter the position again" << endl;
						cin >> x >> y;
						cout << endl;
					}
				}
			}
		
			table[x][y] = "x";
			print_table(table);
			player1--;
			if(getWinner(table, flag) == 1){
				cout << "The player1 is the winner" << endl;
				break;
			}
			flag = true;
			
		}else{
			cout << "This is player2's turn" << endl;
			cout << "Please enter two number to decide your piece's position" << endl;
			cout << "and seperate it with space" << endl;
			cin >> x >> y;
			cout << endl;
			while(checkPiece == false){
				if((x > 2) || (x < 0) || (y > 2) || (y < 0)){
					cout << "The position is not exist " << endl;
					cout << "Please enter the position again" << endl;
					cin >> x >> y;
					cout << endl;
				}else{ 
					if(validPosition(table, x, y) == 1){
						checkPiece = true;
					}else{
						cout << "The position is occupied" << endl;
						cout << "Please enter the position again" << endl;
						cin >> x >> y;
						cout << endl;
					}
				}
			}
		
			table[x][y] = "o";
			print_table(table);
			player2--;
			if(getWinner(table, flag) == 1){
				cout << "The player2 is the winner" << endl;
				break;
			}
			flag = false;
		}
	}while(player1 > 0 || player2 > 0);
	
	if(getWinner(table, flag) == 0){
	do{
		cout << "All player's pieces are on the board" << endl;
		cout << "Each player just move their piece in the rest of turn " << endl;
 		checkPiece = false;

		if(flag == false){
			while(checkPiece == false){
				cout << "This is player1's turn" << endl;
				cout << "Please enter the position which you want to move" << endl;
				cout << "and seperate it with space" << endl;
				cin >> a >> b;
				cout << endl;	
				if(checkPosition(table,flag, a, b) == 1){
				
					cout << "Please enter the position to where you want to move" << endl;
					cout << "and seperate it with space" << endl;
					cin >> x >> y;
					cout << endl;
					if(checkDistance(a, b, x, y) == 1){
						cout << "The position which you choose is not next to the position which you want to move" << endl;	
					
					}else{
						if(validPosition(table, x, y) == 1){
							table[a][b] = ".";
							checkPiece = true;
						}else{
							cout << "The position to where you want to move is occupied" << endl;
							
						}
					}
				}else{
					cout << "The position is empty or the position does not belong to player1" << endl;
				}
			
			}
			
			table[x][y] = "x";
			print_table(table);
			if(getWinner(table, flag) == 1){
				cout << "The player1 is the winner" << endl;
				break;
			}
			flag = true;
		}else{	
			while(checkPiece == false){
				cout << "This is player2's turn" << endl;
				cout << "Please enter the position which you want to move" << endl;
				cout << "and seperate it with space" << endl;
				cin >> a >> b;
				cout << endl;
				if(checkPosition(table, flag, a, b) == 1){
				
					cout << "Please enter the position to where you want to move" << endl;
					cout << "and seperate it with space" << endl;
					cin >> x >> y;
					cout << endl;
					if(checkDistance(a, b, x, y) == 1){
						cout << "The position which you choose is not next to the position which you want to move" << endl;	
				
					}else{

						if(validPosition(table, x, y) == 1){
							table[a][b] = ".";
							checkPiece = true;
						}else{
							cout << "The position to where you want to move is occupied" << endl;
						}
					}
				}else{
					cout << "the position is empty or the position does not belong to player" << endl;
				}
			
			}
			
			table[x][y] = "o";
			print_table(table);
			if(getWinner(table, flag) == 1){
				cout << "The player2 is the winner" << endl;
				break;	
			}

			flag = false;
		}
			

	}while(player1 == 0 && player2 == 0);
	}
}

