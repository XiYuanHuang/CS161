/********************************************************************* 
 *file:   checkers.cpp
 *author: Henry Peterson, with help from Tony
 *date:   March 2018 
 **********************************************************************/ 
#include <iostream>
#include <math.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

//*******************************************************************
//Function Prototypes

//These are functions that provide information about piece state
int    dir(char);
int    dir(int, int);
bool   is_king(char);
bool   is_digit(char);
bool   is_int(char*);
bool   clear(char);
bool   enemy(char, char);

//These are functions the provide information about board state
bool   in_bounds(int , int, int);
bool   is_valid_move(int, int, int, int, char**, int, int);
bool   has_valid_move(char**, int, int, int);
bool   no_pieces(char**, int, char);
bool   no_moves(char**, int, char);

//These are functions that modify board state
char** initialize_board(int, int);
void   apply_move(int, int, int, int, char**, int, char);
void   delete_board(char**, int);
void   copy_board(char**, char**, int);

//These are functions that handle user input
int    get_num(char*&, char []);
bool   get_pair(char*&, int&, int&);
int    check_args(int, char**, int&, int&);
void   reprompt(int &,int &);

//These are functions that handle output
void   print_board(char**, int);
void   clear_screen();

//These are functions that direct game flow
bool   game_over(char**, int, char&);
void   turn(char**, int, char);
bool   eval_input(char*, char**, int, char, int, int);
//*******************************************************************

/********************************************************************* 
 *Function:    dir
 *Description: This function takes in a pieces and returns the direction those
               regular pieces should move.
 *Parameters:  A character representing which team.
 *Pre:         sym must be a valid playing symbol.
 *Post:        None.
 **********************************************************************/ 
int dir(char sym){
    if(sym == 'x' || sym == 'X')
        return 1;
    if(sym == 'o' || sym == 'O')
        return -1;
    return 0;
}

/********************************************************************* 
 *Function:    dir
 *Description: This function takes a start value and and end value and  
               returns what direction that is.
 *Parameters:  Two ints, the start position and the end position.
 *Pre:         These should be valid board positions.
 *Post:        None.
 **********************************************************************/ 
int dir(int x1, int x2){
    if( x2 > x1)
        return 1;
    else
        return -1;
}

/********************************************************************* 
 *Function:    is_king
 *Description: returns true or false if a piece is a king or not.
 *Parameters:  a char, the piece whose royalty is being determined.
 *Pre:         The character should be a valid piece character.
 *Post:        None.
 **********************************************************************/ 
bool is_king(char sym){
    if(sym < 65 || sym > 90)
        return false;
    return true;
}

/********************************************************************* 
 *Function:    is_digit
 *Description: returns true or false if a given charatcer is a number
 *Parameters:  a char, the piece whose numerical qualities are 
               being determined
 *Pre:         None.
 *Post:        None.
 **********************************************************************/ 
bool is_digit(char c){
    if(c < '0' || c > '9')
        return false;
    return true;

}

/********************************************************************* 
 *Function:    is_int
 *Description: returns true or false if a given string is a number
 *Parameters:  a c string, the string whose numerical qualities are 
               being determined
 *Pre:         None.
 *Post:        None.
 **********************************************************************/ 
bool is_int(char* str){
    for(int i = 0; i < strlen(str); i++)
        if(!is_digit(str[i]))
            return false;
    return true;
}

/********************************************************************* 
 *Function:    clear
 *Description: Checks if a given spot is an empty spot
 *Parameters:  The spot to be checked
 *Pre:         None.
 *Post:        None.
 **********************************************************************/ 
bool clear(char sym){
    return sym == ' ';
}

/********************************************************************* 
 *Function:    enemy
 *Description: compares two pieces and determines if they are on 
               opposing sides.
 *Parameters:  The two pieces to be checked.
 *Pre:         The two pieces should be valid playing characters.
 *Post:        None.
 **********************************************************************/ 
bool enemy(char sym, char self){
    if(abs(sym - self) == abs('o' - 'x') ||
            abs(sym - self) == abs('x' - 'O') ||
            abs(sym - self) == abs('o' - 'X') || 
            abs(sym - self) == abs('O' - 'X'))
        return true;
    return false;
}

/********************************************************************* 
 *Function:    in_bounds
 *Description: given a coordinate and size, determines if it is in 
               bounds of the board.
 *Parameters:  The coordinate as two ints, the boundry size.
 *Pre:         Size should be a valid board size.
 *Post:        None.
 **********************************************************************/ 
bool in_bounds(int i, int j, int size){
    if( i >= 0 &&
            i < size &&
            j >= 0 &&
            j < size)
        return true;
    return false;
}

/********************************************************************* 
 *Function:    is_valid_move
 *Description: given a two coordinates on a board, determines if the 
               second is a valid move from the first one for a given board
 *Parameters:  The inital coordinate, the resulting coordinate, the board
               being moved on, the size of that board, the piece being moved.
 *Pre:         Board must be initialized, size must accurately represent that
               board, symbol must be a valid playing character
 *Post:        None.
 **********************************************************************/ 
bool is_valid_move(int x, int y, int x2, int y2, char**  board, int size, int symbol){
    int midx = (x2 + x) / 2;
    int midy = (y2 + y) / 2;
    // each of these conditions sperated by an || is something that would
    // cause the move to be invalid. just one big if statement
    if(!(in_bounds(x,y, size) && in_bounds(x2,y2, size))         ||
            (dir(y, y2) != dir(symbol) && !is_king(board[y][x])) ||
            abs(x - x2) != abs(y - y2)                           ||

            (abs(x - x2) != 2 && 
             abs(x - x2) != 1)                                   ||
            
            !clear(board[y2][x2])                                ||
            (abs(x - x2) == 2 && !enemy(board[midy][midx], symbol)))
        return false;
    return true;
}

/********************************************************************* 
 *Function:    has_valid_move
 *Description: given a piece on a board, determines if it has a valid move
 *Parameters:  The board, the size of the board, the coordinate to be checked
 *Pre:         Board must be initialized, size must accuratly represent that
               board, i and j must be a spot on that board.
 *Post:        None.
 **********************************************************************/ 
bool has_valid_move(char** board, int size, int i, int j){
    char symbol = board[i][j];
    //for loop looks at each possible move location around a coord
    for(int m = 1; m > -2; m-=2){
        for(int k = -1; k < 2; k+=2){
            if(is_valid_move(i, j, i + m, j + k, board, size, symbol))
                return true;
        }
    }
    return false;
}

/********************************************************************* 
 *Function:    no_pieces
 *Description: given a board, determines if there are any pieces of a certain
               side present.
 *Parameters:  The board, the size of the board, the player being checked.
 *Pre:         Board must be initialized, size must accuratly represent that
               board, symbol must be a valid palying character.
 *Post:        None.
 **********************************************************************/ 
bool no_pieces(char** board, int size, char symbol){
    int count = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(board[i][j] == symbol || board[i][j] == symbol + 32)
                count++;
        }
    }
    if(count == 0)
        return true;
    return false;
}

/********************************************************************* 
 *Function:    no_moves
 *Description: given a board, determines if a side has any possible moves
 *Parameters:  The board, the size of the board, the player being checked.
 *Pre:         Board must be initialized, size must accuratly represent that
               board, symbol must be a valid palying character.
 *Post:        None.
 **********************************************************************/ 
bool no_moves(char** board, int size, char symbol){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(board[i][j] == ' ')
                continue;
            // if there is a pieces with a move, not a loss
            else if(board[i][j] == symbol && has_valid_move(board, size, i, j))
                return false;
        }
    }
    // if none were found
    return true;
}

/********************************************************************* 
 *Function:    initialize_board
 *Description: given a size, allocate a board, and populate it based on 
               the specified option
 *Parameters:  The desired size of the board, how the board will be populated
 *Pre:         None.
 *Post:        None.
 **********************************************************************/ 
char** initialize_board(int size, int option){
    // I wouldn't turn this in like this since it breaks the 20 line
    // limit rule, but having multiple population options is nice for 
    // testing
    char** board = new char*[size];
    for(int i = 0; i < size; i++){
        board[i] = new char[size];
        memset(board[i], ' ', size);
    }
    switch(option){
        // nice testing case, works best on 8x8 board
        case 1:
            board[1][0] = 'x';
            board[2][1] = 'o';
            board[4][1] = 'o';
            board[6][1] = 'o';
            board[6][3] = 'o';
            board[2][3] = 'o';
            break;
        // option if you want to actually play
        default: 
            for(int i = 0; i < size; i++){
                for(int j = 0; j < size; j++){
                    if(i % 2 == 1 && j % 2 == 0 && j < (size/2) - 1)
                        board[j][i] = 'x';
                    else if(i % 2 == 0 && j % 2 == 1 && j < (size/2) - 1)
                        board[j][i] = 'x';
                    else if(i % 2 == 1 && j % 2 == 0 && j > (size/2))
                        board[j][i] = 'o';
                    else if(i % 2 == 0 && j % 2 == 1 && j > (size/2))
                        board[j][i] = 'o';
                    else
                        board[j][i] = ' ';
                }
            }
    }
    return board;
}

/********************************************************************* 
 *Function:    delete_board
 *Description: this deallocates memory allocated for a dynamic 2d array
 *Parameters:  The board to be deleted, the size of that board.
 *Pre:         board shouldn't be NULL, size must accurate represent board
 *Post:        board will no long point at allocated memory.
 **********************************************************************/ 
void delete_board(char** board, int size){
    for(int i = 0; i < size; i++){
        delete [] board[i];
    }
    delete [] board;
}

/********************************************************************* 
 *Function:    copy_board
 *Description: copies all values in one board to another board.
 *Parameters:  The destination board, the source board, the size of the source
 *Pre:         copy and board must be initialized, size must accurately
               represent board, copy must be the same size or larger than board
 *Post:        copy will hold all of the same values in the same position as 
               board.
 **********************************************************************/ 
void copy_board(char** copy, char** board, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            copy[i][j] = board[i][j];
        }
    }
}

/********************************************************************* 
 *Function:    apply_move
 *Description: given two coordinates, proccess the move from the first to
               the second. it will also proccess any side effect resulting 
               from a move such as a capture.
 *Parameters:  the start coordinate, the end coordinate, the board being moved
               upon, the size of that board, the side of the piece being moved.
 *Pre:         board must be initialized, size must accurately represent that 
               board, the move must already be validated.
 *Post:        board will contain the resulting changes.
 **********************************************************************/ 
void apply_move(int x, int y, int x2, int y2, char** board, int size, char symbol){
    int midx = (x2 + x) / 2;
    int midy = (y2 + y) / 2;
    // updates destination
    board[y2][x2] = board[y][x];
    // updates source
    board[y][x] = ' ';
    // make capture if applicable
    if(abs(x2 - x) == 2)
        board[midy][midx] = ' ';
    // find any new kings
    for(int i = 0; i < size; i++){
        if(board[0][i] == 'o')
            board[0][i] -= 32;
        if(board[size - 1][i] == 'x')
            board[size - 1][i] -= 32;
    }
}

/********************************************************************* 
 *Function:    get_num
 *Description: given a string, copy up to 3 numerical elements on the front
               to another string. The largest coordinate value in this game
               is two characters. It then returns the number of characters
               copied.
 *Parameters:  the source c string, the destination c string
 *Pre:         num must be at least 3 long
 *Post:        num will contain up to 3 numerical characters
 **********************************************************************/ 
int get_num(char*& input, char num[]){
    int i = 0;
    memset(num, '\0', 4);
    while(is_digit(input[i]) && i < min(3, (int)strlen(input))){
        num[i] = input[i];
        i++;
    }
    return i;
}

/********************************************************************* 
 *Function:    get_pair
 *Description: given a string, get the first two integers seperated by a 
               comma, either ending in a space, indicating another pair after
               , or the null terminator indicating the end of the input. it
               then returns whether or not there was valid formatting.
 *Parameters:  the source c string, the x and y coordinate to be determined
 *Pre:         none
 *Post:        input will point at rest of the string excluding the pair
               just read, x and y will hold the first number and the 
               second number respectively. These conditions are dependent
               on valid formatting.
 **********************************************************************/ 
bool get_pair(char*& input, int& x, int& y){
    int i = 0;
    char num[4];
    //gets first integer
    i = get_num(input, num);
    // must be followed by comma
    if(input[i] != ',')
        return false;
    x = atoi(num);
    // updates string to be at next integer
    input += ++i;
    i = get_num(input, num);
    // must be followed by space or end of string
    if(input[i] != ' ' && input[i] != '\0')
        return false;
    y = atoi(num);
    // updates string to be at next integer
    if(strlen(input) != '\0')
        input += ++i;
    return true;
}

/********************************************************************* 
 *Function:    check_args
 *Description: Takes in the command lines arguments and evaulates them. If they
               a correct it  assigns the proper values, otherwise it exits.
 *Parameters:  The command line arguments, an int where the size will be stored,
               an int where the starting board option will be stored
 *Pre:         None.
 *Post:        None.
 **********************************************************************/ 
int check_args(int count, char** args, int& size, int& opt){
    string usage = "invalid arguments\nusage: checkers {8, 10, 12} {option}";
    char* arg_temp;

    if(count != 3){
        cout << usage << endl;
        return 0;
    }

    arg_temp = args[1];
    if(!is_int(arg_temp)){
        cout << usage << endl;
        return 0;
    }
    size = atoi(arg_temp);

    // breaks 20 line rule for the sake of nice testing, would
    // would not be in final submission.
    arg_temp = args[2];
    if(!is_int(arg_temp)){
        cout << usage << endl;
        return 0;
    }
    opt = atoi(arg_temp);

    if(!(size >= 8 && size <= 12 && size % 2 == 0)){
        cout << usage << endl;
        return 0;
    }
    return 1;
}

/********************************************************************* 
 *Function:    print_board
 *Description: given a board and its size, print out it visual representation
               to the screen. provided by shannon.
 *Parameters:  The board to be printed, its size
 *Pre:         board must be initialized, size must accurately represent board
 *Post:        None.
 **********************************************************************/ 
void print_board(char** board, int size){
    cout << "   ";
    for(int i = 0; i < size; i++)
        cout << i << "  ";
    cout << endl;
    for(int i = 0; i < size; i++){
        cout << i << " ";
        if( i > 9)
            cout << "\b";
        for(int j = 0; j < size; j++){
            if (i % 2 == 0 && j % 2 == 0)
                cout << "|\033[30;47m" << board[i][j] << " ";
            else if (i % 2 == 1 && j % 2 == 1)
                cout << "|\033[30;47m" << board[i][j] << " ";
            else
                cout << "|\033[0m"     << board[i][j] << " ";
            cout << "\033[0m";
        }
        cout << endl;
    }
}

/********************************************************************* 
 *Function:    clear_screen
 *Description: prints enough new lines to clear the terminal.
 *Parameters:  none.
 *Pre:         none.
 *Post:        none.
 **********************************************************************/ 
void clear_screen(){
    for(int i = 0; i < 200; i++)
        cout << endl;
}

/********************************************************************* 
 *Function:    game_over
 *Description: determines if both x and o have pieces left and if 
               at least one of those pieces has a valid move.
 *Parameters:  the board to be checked, the size of that board
               the winner if there is one
 *Pre:         board must be initialized, size must accurately represent
               board.
 *Post:        winner will contain the pieces that hasn't lost, dependent
               on a true return.
 **********************************************************************/ 
bool game_over(char** board, int size, char& winner){
    // if x has no moves or pieces, o wins
    if((no_pieces(board, size, 'x') || no_moves(board, size, 'x')) &&
      (no_pieces(board, size, 'X') || no_moves(board, size, 'X'))){
        winner = 'o';
    // if o has no moves or pieces, x wins
    }else if((no_pieces(board, size, 'o') || no_moves(board, size, 'o')) &&
      (no_pieces(board, size, 'O') || no_moves(board, size, 'O'))){
        winner = 'x';
    }else{
        return false;
    }
    return true;
}

/********************************************************************* 
 *Function:    eval_input
 *Description: given input from the user, determine if there is a valid
               move from the current position the the one on the front
               of the string, and if so apply it to the board. It returns
               whether or not input is a valid move.
 *Parameters:  the input from the user, the board, the size of the board,
               the symbol of the player moving, the current x and y.
 *Pre:         board must be initialized, size must accurately represent
               board, symbol must be a valid plaing character. x and y should
               be given as -1 if this is the first call of the function,
               indicating the current position is not know by the program
               and must be retrieved off the front of the string.
 *Post:        in the event of a valid move, board will be updated with
               its resulting state.
 **********************************************************************/ 
bool eval_input(char* input, char** board, int size, char symbol, int x, int y){
    int x2, y2;
    bool first_move = false;
    // if this is the initial call of this function for a given input,
    // then we have to manually get the current position
    if(x == -1){ 
        first_move = true;
        if(!get_pair(input, x, y))
            return false;
    }
    // gets the destination
    if(!get_pair(input, x2, y2) ||
            !is_valid_move(x, y, x2, y2, board, size, symbol))
        return false;

    apply_move(x, y, x2, y2, board, size, symbol);
    // you cannot be on a second move in a turn and have it
    // not be a jump
    if(!first_move && abs(x - x2) == 1)
        return false;
    // mo more moves
    else if(strlen(input) == 0 )
        return true;
    // evaluate rest of input
    else
        return eval_input(input, board, size, symbol, x2, y2);
}

/********************************************************************* 
 *Function:    turn
 *Description: given a board, its size, a player, ask to make a move until
               they make a valid one.
 *Parameters:  the board with the game state, the size of that board, the 
               symbol of whose turn it is.
 *Pre:         board must be initialized, size must accurately represent
               that board, symbol must be a valid playing character.
 *Post:        board will hold the resulting state of the player's move
 **********************************************************************/ 
void turn(char** board, int size, char symbol){
    size_t num;
    char input[256];
    char** cpy;

    // cpy hold a tempory state so that the actual 
    // board is not updated in the event of invalid input
    cpy = initialize_board(size, 0);
    clear_screen();
    print_board(board, size);
    //gets user input until valid input is given
    do{
        cout << symbol << "'s turn > ";
        // people may not have seen memset, it just takes an array
        // a value, and and number of elements to put that character into
        memset(input, '\0', 256);
        cin.getline(input, 256, '\n');
        copy_board(cpy, board, size);
        if(!eval_input(input, cpy, size, symbol, -1, -1))
            cout << "invalid" << endl;
        else
            break;
    }while(true);

    // at this point it is assured a valid move was made, so the actual
    // state gets the temporary state
    copy_board(board, cpy, size);
    // it might be inefficient to allocate a new board at each turn then
    // delete it, but it works, and reduces clutter elsewhere
    delete_board(cpy,  size);
}
/********************************************************************* 
 *Function:    reprompt
 *Description: ask user input size until user give the right number(8 or 10 or 12)
 *Parameters:  size of board, choice of option
 *Pre:         None. 
 *Post:        None. 
 **********************************************************************/ 
void reprompt(int &size,int &option)
{
  do{
    cout<<"Please input size again"<<endl;
    cin>>size;
  }while(size!=8 && size!=10 &&size!=12);
  cout<<"Please input option again"<<endl;
  cin>>option;
}
/********************************************************************* 
 *Function:    main
 *Description: sets up a board, then alternates giving x and o turns until     
               the game is won. x goes first.
 *Parameters:  the command line arguments
 *Pre:         None. 
 *Post:        None. 
 **********************************************************************/ 
int main(int argc, char** argv){
    int size, option;
    char winner;
    char** board;

    //set up board
    if(check_args(argc, argv, size, option)==0){
        reprompt(size,option);
    }
    cin.clear();
    cin.ignore(256,'\n');//clean the input stream
    board = initialize_board(size, option);

    //game loop
    print_board(board, size);
    while(!game_over(board, size, winner)){
        turn(board, size, 'x');
        if(!game_over(board, size, winner))
            turn(board, size, 'o');
    }
    clear_screen();
    print_board(board, size);

    //clean up
    delete_board(board, size);
    cout << "wow, " << winner 
         << " has won. you've done it. won checkers." << endl;

    return 0;
}
