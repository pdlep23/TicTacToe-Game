#include "TicTacToe.h"
#include <string>
#include <iostream>
using namespace std;

//default constructor
ticTacToe::ticTacToe(){
  
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      board[i][j] = ' ';
    }
  }
  noOfMoves = 0;
}

//board use to show user current status
void ticTacToe::displayBoard() const {
  cout << "   1   2   3\n" << endl;
  cout << "1 " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
  cout << "____|___|____" << endl;
  cout << "    |   |    " << endl;
  cout << "2 " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
  cout << "____|___|____" << endl;
  cout << "    |   |    " << endl;
  cout << "3 " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

//checks with the game board if the move is valid
bool ticTacToe::isValidMove(int x, int y) const{
  if(board[x-1][y-1] == ' ')
  {
    return true;
  }
  return false;
}

//restart game to empty game board
void ticTacToe::reStart(){
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      board[i][j] = ' ';
    }
  }
  noOfMoves = 0;
  
}

//test what is the current status of the game
status ticTacToe::gameStatus(){
  
  //performs the diagonal checks of the board
  if(board[1][1] != ' ')
  {
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
      displayBoard();
      cout <<"Player Won!" << endl;
      return WIN;
    }
    else if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
      displayBoard();
      cout <<"Player Won!" << endl;
      return WIN;
    }
  }

  int CountO = 0;
  int CountX = 0;
  //performs a horizontal sweep of the game board
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      if(board[i][j] == 'X')
      {
        CountX++;
      }
      if(board[i][j] == 'O')
      {
        CountO++;
      }
    }
    if(CountO == 3 || CountX == 3)
    {
      displayBoard();
      cout <<"Player Won!" << endl;
      return WIN;
    }
    CountX = CountO = 0;
  }

  //performs a vertical sweep of the board
  for(int i = 0; i < 3; i++)
  {
      for(int j = 0; j < 3; j++)
      {
      if(board[j][i] == 'X')
      {
        CountX++;
      }
      if(board[j][i] == 'O')
      {
        CountO++;
      }
      }
    if(CountO == 3 || CountX == 3)
    {
      displayBoard();
      cout <<"Player Won!" << endl;
      return WIN;
    }
    CountX = CountO = 0;
  }
//if the move count = 9 and no winner was declared. It is a draw.
  if(noOfMoves == 9)
  {
    displayBoard();
    cout <<"This game is a draw!" << endl;
    return DRAW;
  }
return CONTINUE;//if no one was declared a winner and there are moves left
}

//the main function of the game
void ticTacToe::play(){
  bool player = 1;// use a bool variable to determine player, 0 = O and 1 = X
  //while game is still continuing we need to switch players
  while(gameStatus() == CONTINUE){
    
    char playerMarker; //marker used to represent player, X and O
    if(player == 1)//if bool is 1, set playerMarker to X 
    {
      playerMarker = 'X';
    }
    else //if bool is 0, set playerMarker to O
      playerMarker = 'O';
    displayBoard();//displayBoard so user can make a selection
    player = getXOMove(playerMarker);//ask user for a move and check if valid, return opposite bool
  } 
}

//ask user for input and check users move
bool ticTacToe::getXOMove(char moveSymbol){
  bool temp = false;//bool indicator
  string move;
  //ask user for move
  cout << "Player " << moveSymbol << " enter move (row col): ";
  getline(cin, move);// input into move variable
  int x, y;//variable to represent coordinates
  x = move[0] - '0';//pull x move
  y = move[2] - '0';//pull y move
  if(x < 1 || x > 3)//check valid X move
  {
    temp = true;
  }
  if(y < 1 || y > 3)//check valid Y move
  {
    temp = true;
  }
  //check if valid move
  while(!isValidMove(x, y) || temp == true)
  {
    temp = false;
    //ask for a new move because past move is invalid
    cout << "Please enter a new move (row col): ";
    getline(cin, move);
    //check new move
    x = move[0] - '0';
    y = move[2] - '0';
    if(x < 1 || x > 3)
    {
     temp = true;
    }
   if(y < 1 || y > 3)
    {
     temp = true;
    }
  }
  //now with a valid move place symbol
  board[x-1][y-1] = moveSymbol;//place move symbol on board
  noOfMoves++;//increase move count
  if(moveSymbol == 'X')//if moveSymbol is X return opposite
    return 0;
  else
    return 1;
}