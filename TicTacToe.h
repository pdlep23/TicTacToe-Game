#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <string>

using namespace std;
enum status {WIN, DRAW, CONTINUE};//used to determine game status

class ticTacToe
{
  public:
    void play();
    //Function to start the play.

    void displayBoard() const;
    //Function to print the board.

    bool isValidMove(int x, int y) const;
    //Function to determine if a move is valid.

    bool getXOMove(char moveSymbol);
    //Function to determine the current status of the game.

    status gameStatus();
    //Function to determine if a move is valid.
    
    void reStart();
    //Function to reStart the game.

    ticTacToe();
    //default constructor
    //Postcondition: Initializes the board to an empty state.

 
  private:
    char board[3][3];
    int noOfMoves;
};

#endif