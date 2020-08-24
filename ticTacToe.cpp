// The classic Tic-Tac-Toe game.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Global constants
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

// Function prototypes
void instructions();
char askYesNoQuestion(string question);
int askNumber(string question, int high, int low = 0);
char humanPiece();
char opponent(char piece);
void displayBoard(const vector<char> &board);

// Main function
int main()
{
  int move;
  const int NUM_SQUARES = 9;
  vector<char> board(NUM_SQUARES, EMPTY);

  instructions();
  char human = humanPiece();
  char computer = opponent(human);
  char turn = X;

  displayBoard(board);
  return 0;
}

// Function definitions

void instructions()
{
  cout << "\n\tWelcome to the ultimate man-machine showdown: Tic-Tac-Toe\n";
  cout << "\t---where human brain is pit against silicon processor---\n\n";

  cout << "Make your move known by entering a number, 0-8. ";
  cout << "The number corresponds to the desired board position, as illustrated:\n\n";

  cout << "0 | 1 | 2\n";
  cout << "---------\n";
  cout << "3 | 4 | 5\n";
  cout << "---------\n";
  cout << "6 | 7 | 8\n\n";

  cout << "Prepare yourself, human ! The battle is about to begin....\n\n";
}

// Function to ask a yes/no question to player.
// It will keep asking until the answer is either a y or an n.
char askYesNoQuestion(string question)
{
  char response;
  do
  {
    cout << question << " (y/n) : ";
    cin >> response;
  } while ((response != 'y') && (response != 'n'));
  return response;
}

// Function to ask for a number within a range.
// It will keep asking until the answer is indeed within that range.
int askNumber(string question, int high, int low)
{
  int number;
  do
  {
    cout << question << " (" << low << " - " << high << ") : ";
    cin >> number;
  } while ((number > high) && (number < low));
  return number;
}

// Function to ask the player if (s)he wants to go first.
// It returns the human's piece based on the answer.
// Traditionally, the X goes first in a Tic-Tac-Toe game.
char humanPiece()
{
  char go_first = askYesNoQuestion("Do you want to make the first  move ?");
  if (go_first == 'y')
  {
    cout << "Then take the first move. You will need it...\n";
    return X;
  }
  else
  {
    cout << "Your bravery can cost you.... OK, I will go first.\n";
    return O;
  }
}

// Function to get the opponent's piece, based on the input parameter piece.
char opponent(char piece)
{
  if (piece == X)
    return O;
  else
    return X;
}

// Function to display the game board.
void displayBoard(const vector<char> &board)
{
  cout << "\n\t"
       << board[0] << " | " << board[1] << " | " << board[2];
  cout << "\n\t"
       << "---------";
  cout << "\n\t"
       << board[3] << " | " << board[4] << " | " << board[5];
  cout << "\n\t"
       << "---------";
  cout << "\n\t"
       << board[6] << " | " << board[7] << " | " << board[8];
  cout << "\n\n";
}
