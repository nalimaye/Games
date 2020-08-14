// Classic Number Guessing Game with a twist.
// Here the player and the computer switch roles.
// Player picks a number and the computer has to guess what it is.
// Player will provide guidance such as range and feedback ("Too Low" or "Too High").

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  int maxNum = 0;
  int lowNum = 1;
  int numTries = 0;
  int guess = 0;
  char answer = 'n';
  char lowOrHigh = 'h';

  cout << "\nI will guess your number between the range (1-maxNumber).\n";
  cout << "Please provide maxNumber : ";
  cin >> maxNum;

  // Game loop
  while (true)
  {
    ++numTries;

    // Set the seed
    srand((unsigned)time(NULL));
    // Generate a random guess between lowNum-maxNum
    guess = (rand() % maxNum) + lowNum;

    // Tell player a guess, and ask if guessed number is correct or not.
    cout << "\nIs it " << guess << " ? (y/n) : ";
    cin >> answer;

    // EXIT the game loop, if player says yes
    if ((answer == 'Y') || (answer == 'y'))
    {
      // Print final statistics before exiting
      cout << endl
           << "I guessed it in " << numTries;
      if (numTries == 1)
        cout << " guess.";
      else
        cout << " guesses.";
      cout << " Thank you for playing !\n\n";
      break;
    }

    // Otherwise ask player if guess is Too Low OR Too High ?
    else
    {
      cout << "Is it \"Too Low (l)\" OR \"Too High (h)\" ? (l/h) : ";
      cin >> lowOrHigh;
      // If Too Low, then change lowNum to guess
      if ((lowOrHigh == 'L') || (lowOrHigh == 'l'))
        lowNum = guess;
      // Else if Too High, then change maxNum to guess
      else if ((lowOrHigh == 'H') || (lowOrHigh == 'h'))
        maxNum = guess;
    }
  }

  return 0;
}
