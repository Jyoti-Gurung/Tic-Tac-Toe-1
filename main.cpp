#include <iostream>
#include <cstring>
using namespace std;

//Global trackers and variables
char board[4][4];
char turn = 'x';
char x = 'x';
char o = 'o';
int xwins;
int owins;
int draws;
int tracker = 0; // this is for moves

//Initialize black board and reset tracker (for mobes)
void reset() {
  tracker = 0;
  for (int i = 0; i < 4; i++) {
    for (int a = 0; a < 4; a++) {
      board[i][a] = ' ';
    }
  }
  board[0][1]='a'; board[0][2]='b'; board[0][3]='c'; board[1][0]='1'; board[2][0]='2'; board[3][0]='3';
};

//Draw when you run out of moves & 8 configurations for wins
void windraw() {
  if (tracker == 9) {
    cout << "It's a draw!";
    draws++;
  }
  if ( (board[1][1]==x && board[1][2]==x && board[1][3]==x) || 
  (board[1][1]==o && board[1][2]==o && board[1][3]==o) ){
    if (turn == x) {cout << "o wins!"; owins++;} else {cout << "x wins!"; xwins++;}
    tracker = 9;
    cout << "\nx:" << xwins << " o:" << owins << " draws:" << draws << "\n";
  }
  if ( (board[2][1]==x && board[2][2]==x && board[2][3]==x) || 
  (board[2][1]==o && board[2][2]==o && board[2][3]==o) ){
    if (turn == x) {cout << "o wins!"; owins++;} else {cout << "x wins!"; xwins++;}
    tracker = 9;
    cout << "\nx:" << xwins << " o:" << owins << " draws:" << draws << "\n";
  }
  if ( (board[3][1]==x && board[3][2]==x && board[3][3]==x) || 
  (board[3][1]==o && board[3][2]==o && board[3][3]==o) ){
    if (turn == x) {cout << "o wins!"; owins++;} else {cout << "x wins!"; xwins++;}
    tracker = 9;
    cout << "\nx:" << xwins << " o:" << owins << " draws:" << draws << "\n";
  }
  if ( (board[1][1]==x && board[2][1]==x && board[3][1]==x) || 
  (board[1][1]==o && board[2][1]==o && board[3][1]==o) ){
    if (turn == x) {cout << "o wins!"; owins++;} else {cout << "x wins!"; xwins++;}
    tracker = 9;
    cout << "\nx:" << xwins << " o:" << owins << " draws:" << draws << "\n";
  }
  if ( (board[1][2]==x && board[2][2]==x && board[3][2]==x) || 
  (board[1][2]==o && board[2][2]==o && board[3][2]==o) ){
    if (turn == x) {cout << "o wins!"; owins++;} else {cout << "x wins!"; xwins++;}
    tracker = 9;
    cout << "\nx:" << xwins << " o:" << owins << " draws:" << draws << "\n";
  }
  if ( (board[1][3]==x && board[2][3]==x && board[3][3]==x) || 
  (board[1][3]==o && board[2][3]==o && board[3][3]==o) ){
    if (turn == x) {cout << "o wins!"; owins++;} else {cout << "x wins!"; xwins++;}
    tracker = 9;
    cout << "\nx:" << xwins << " o:" << owins << " draws:" << draws << "\n";
  }
  if ( (board[1][1]==x && board[2][2]==x && board[3][3]==x) || 
  (board[1][1]==o && board[2][2]==o && board[3][3]==o) ){
    if (turn == x) {cout << "o wins!"; owins++;} else {cout << "x wins!"; xwins++;}
    tracker = 9;
    cout << "\nx:" << xwins << " o:" << owins << " draws:" << draws << "\n";
  }
  if ( (board[1][3]==x && board[2][2]==x && board[3][1]==x) || 
  (board[1][3]==o && board[2][2]==o && board[3][1]==o) ){
    if (turn == x) {cout << "o wins!"; owins++;} else {cout << "x wins!"; xwins++;}
    tracker = 9;
    cout << "\nx:" << xwins << " o:" << owins << " draws:" << draws << "\n";
  }
}

char test[2] = {'\0','\0'};

//Checking if coordinates are proper/valid
void valid() {
  while (true) {
    cout << "\nTurn: " << turn << ":\n" ;
    cin >> test;
    if (strlen(test) == 2) {

      if ( (test[0] == 'a' || test[0] == 'b' ||test[0] == 'c') 
      && (test[1] == '1' || test[1] == '2' || test[1] == '3') ){

        int transfer[2];
        switch(test[0]) {
          case 'a':
            transfer[0] = 1;
            break;
          case 'b':
            transfer[0] = 2;
            break;
          case 'c':
            transfer[0] = 3;
        }
        switch(test[1]) {
          case '1':
            transfer[1] = 1;
            break;
          case '2':
            transfer[1] = 2;
            break;
          case '3':
            transfer[1] = 3; 
        }
        
        if (board[transfer[0]][transfer[1]] == ' ') {
          board[transfer[0]][transfer[1]] = turn;
          if (turn == x) {
          turn = o;
          break;
          }
          else {
          turn = x;
          break;
          }
        }

        else {
          cout << "Pick a empty spot!\n";
        }

      }

      else {
      cout << "Underscore and based on axis (eg: a1) \n";
      }

    }

    else {
    cout << "Underscore and based on axis (eg: a1) \n";
    }
  }
}

// print the board
void print() {
  for (int i = 0; i < 4; i++) {
    for (int a = 0; a < 4; a++) {
      cout << board[i][a];
    }
    cout << "\n";
  }
}

// run the code; runs for ever and starts out by resetting turn and tracker to normal after you win or draw or first start
int main() {


  while (true) {
  tracker = 0;
  turn = x;
  reset();
  print();
    while (tracker < 9) {
    valid();
    tracker++;
    cout << '\n';
    print();
    windraw();
    }
  }

}