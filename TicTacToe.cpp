//Author: Nathan Zou
//Date: 10/24/21
//Console Tic-Tac-Toe game between two users
#include <iostream>

using namespace std;

void printBoard(char board[3][3]);
int readInputRow(char in[2]);
int readInputCol(char in[2]);
char checkWin(char board[3][3]);
char checkTie(char board[3][3]);

int main() {
  char board[3][3];
  char input[2];
  bool xTurn = true;
  bool end = false;
  char winner;
  char playing = 'y';
  int xWins = 0;
  int oWins = 0;
  int ties = 0;
  char oPlay = 'O';
  char xPlay = 'X';

  while (playing == 'y') {//Clears the board by resetting spaces to blanks
    for (int col = 0; col < 3 ; col++) {
      for (int row = 0; row < 3; row++) {
        board[row][col] = ' ';
      }
    }
    winner = ' ';
    printBoard(board);
    while (end == false) {
      if (xTurn == true) {//X's turn
        cout << "X turn: " << endl; //Asking for user input
        cin >> input;
        bool move = true;
        while (move == true) {//Read in input with help from Stephan Ene
          if (board[readInputRow(input)][readInputCol(input)] == ' ') {//Takes the users input and marks where the user wants to go
            board[readInputRow(input)][readInputCol(input)] = xPlay;
            printBoard(board);
            move = false;
          }
          else {//Wrong format or spot not available
            cout << "Illegal move, try again: " << endl;
            cin >> input;
            move = true;
          }
        }
        //Checks for wins or ties and switches to O's turn
        xTurn = false;
        winner = checkWin(board);
        char Tie = checkTie(board);
        if (winner == xPlay || winner == oPlay) {
          end = true;
        }
        if (Tie == 'y') {
          end = true;
        }
      }
      //O's turn, same as X but with O instead
      else {
        cout << "O turn: " << endl;
        cin >> input;
        bool move = true;
        while (move == true) {
          if (board[readInputRow(input)][readInputCol(input)] == ' ') {
            board[readInputRow(input)][readInputCol(input)] = oPlay;
            printBoard(board);
            move = false;
          }
          else {
            cout << "Illegal move, try again: " << endl;
            cin >> input;
            move = true;
          }
        }
        xTurn = true;
        winner = checkWin(board);
        char Tie = checkTie(board);
        if (winner == xPlay || winner == oPlay) {
          end = true;
        }
        if (Tie == 'y') {
          end = true;
        }
      }
    }
    if (end == true) {//Winners
      if (winner == xPlay) {//How many times X has won
        xWins++;
        cout << "X has won: " << xWins << " time(s)." << endl;
      }
      else if (winner == oPlay) {//How many times O has won
        oWins++;
        cout << "X has won: " << oWins << " time(s)." << endl;
      }
      else {//How many ties there have been
        ties++;
        cout << "There have been " << ties << " ties." << endl;
      } 
    }
    //Checks if you want to play again
    bool playAgain = true;
    cout << "Would you like to continue playing? 'y' for yes and 'n' for no" << endl;
    while (playAgain == true) {
      char response;
      cin >> response;
      if (response == 'y') {//If yes, will reset the game
        playing = 'y';
        playAgain = false;
	end = false;
	xTurn = true;
      }
      else if (response == 'n') {//If no, will end the game
        playing = 'n';
        playAgain = false;
      }
      else {//Wrong input
        cout << "Response invalid, please input 'y' or 'n'." << endl;
	playAgain = true;
      }
    }
  }
}

//Board with help from Chris Zou
void printBoard(char board[3][3]) {//Prints the board
  cout << "  a b c" << endl;
  cout << "1 ";
  for (int i = 0; i < 3; i++) {//Creates the 1 row
    cout << board[i][0] << " ";
  }
  cout << endl;
  cout << "2 ";
  for (int i = 0; i < 3; i++) {//Creates the 2 row
    cout << board[i][1] << " ";
  }
  cout << endl;
  cout << "3 ";
  for (int i = 0; i < 3; i++) {//Creates the 3 row
    cout << board[i][2] << " ";
  }
  cout << endl; 
} 

int readInputRow(char in[2]) {//Reads in the second char from the input and determines if it is either a, b, or c
  if (in[0] == 'a') {
    return 0;
  }
  else if (in[0] == 'b') {
    return 1;
  }
  else if (in[0] == 'c') {
    return 2;
  }
  else {
    return ' ';
  }
}

int readInputCol(char in[2]) {//Reads in the first char from the input and determines if it is either 1, 2, or 3
  if (in[1] == '1') {
    return 0;
  }
  if (in[1] == '2') {
    return 1;
  }
  if (in[1] == '3') {
    return 2;
  }
  else {
    return ' ';
  }
}

char checkWin(char board[3][3]) {
  char xPlay = 'X';
  char oPlay = 'O';
  //Checking for X wins
  if (board[0][0] == xPlay && board[0][1] == xPlay && board[0][2] == xPlay) {//Top horizontal 
    return xPlay;
  }
  else if (board[1][0] == xPlay && board[1][1] == xPlay && board[1][2] == xPlay) {//Mid horizontal
    return xPlay;
  }
  else if (board[2][0] == xPlay && board[2][1] == xPlay && board[2][2] == xPlay) {//Bot horizontal
    return xPlay;
  }
  else if (board[0][0] == xPlay && board[1][0] == xPlay && board[2][0] == xPlay) {//Left vertical
    return xPlay;
  }
  else if (board[0][1] == xPlay && board[1][1] == xPlay && board[2][1] == xPlay) {//Mid vertical
    return xPlay;
  }
  else if (board[0][2] == xPlay && board[1][2] == xPlay && board[2][2] == xPlay) {//Right vertical
    return xPlay;
  }
  else if (board[0][0] == xPlay && board[1][1] == xPlay && board[2][2] == xPlay) {//Diagonal from left upper to right bottom corner
    return xPlay;
  }
  else if (board[0][2] == xPlay && board[1][1] == xPlay && board[2][0] == xPlay) {//Diagonal from right upper to left bottom corner
    return xPlay;
  }
    //Checking for Owins
  else if (board[0][0] == oPlay && board[0][1] == oPlay && board[0][2] == oPlay) {//Top horizontal
    return oPlay;
  }
  else if (board[1][0] == oPlay && board[1][1] == oPlay && board[1][2] == oPlay) {//Mid horizontal
    return oPlay;
  }
  else if (board[2][0] == oPlay && board[2][1] == oPlay && board[2][2] == oPlay) {//Bot horizontal 
    return oPlay;
  }
  else if (board[0][0] == oPlay && board[1][0] == oPlay && board[2][0] == oPlay) {//Left vertical
    return oPlay;
  }
  else if (board[0][1] == oPlay && board[1][1] == oPlay && board[2][1] == oPlay) {//Mid vertical
    return oPlay;
  }
  else if (board[0][2] == oPlay && board[1][2] == oPlay && board[2][2] == oPlay) {//Right vertical
    return oPlay;
  }
  else if (board[0][0] == oPlay && board[1][1] == oPlay && board[2][2] == oPlay) {//Diagonal from left upper to right bottom corner
    return oPlay;
  }
  else if (board[0][2] == oPlay && board[1][1] == oPlay && board[2][0] == oPlay) {//Diagonal from right upper to left bottom corner
    return oPlay;
  }
  else {
    return ' ';
  }
}

char checkTie(char board[3][3]) {
  //checks to see if whole board is full
  if (board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] != ' '
   && board[1][0] != ' ' && board[1][1] != ' ' && board[1][2] != ' '
   && board[2][0] != ' ' && board[2][1] != ' ' && board[2][2] != ' ') {
    return 'y';
  }
  else {
    return ' ';
  }
}
