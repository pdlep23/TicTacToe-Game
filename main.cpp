#include <iostream>
#include "TicTacToe.h"
int main() {
  ticTacToe game;//object of class ticTacToe
  char continuePlay = 'y';//do-while condition char
  do{
  game.play();//play function (game)
  game.reStart();//reset the game
  cout << "Do you wish to play again? (y/n): ";//ask user to continue game
  cin >> continuePlay;// input in char variable
  cin.ignore();//ignore the buffer issue with getline/cin use
  }while(continuePlay == 'y');//exit out if the user wishes to stop
  return 0;
}