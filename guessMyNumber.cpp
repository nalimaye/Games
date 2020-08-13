// Classic Number Guessing Game

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

  int numTries = 0;
  int guess = 0;
  char answer = 'N';

  // Set the seed
  srand((unsigned)time(NULL));
  // Generate random number between 1-100
  int secretNumber = (rand() % 100) + 1;

  cout << endl
       << "Welcome to \"Guess My Number\" between 1-100 !!!" << endl
       << endl;

  // Game loop
  while (guess <= 100)
  {
    cout << "Enter a guess : ";
    cin >> guess;
    ++numTries;

    if (guess < secretNumber)
    {
      cout << guess << ": Too Low..." << endl;
    }
    else if (guess > secretNumber)
    {
      cout << guess << ": Too High..." << endl;
    }
    else
    {
      cout << endl
           << "You got it !!!";
      // EXIT the game loop, if user guess is CORRECT
      break;
    }

    // Ask if user wants to continue or not.
    cout << "Continue ? (y/n) : ";
    cin >> answer;
    if ((answer == 'Y') || (answer == 'y'))
      continue;
    else
      // EXIT the game loop, if user does NOT want to continue
      break;
  };

  // Print final statistics before exiting

  // Depending on whether user guessed it right or not
  if (guess == secretNumber)
  {
    cout << endl
         << "You guessed it in " << numTries;
  }
  else
  {
    cout << endl
         << "Better luck next time! Number was " << secretNumber << ". "
         << "You had " << numTries;
  }
  // and the number of user guess(es)
  if (numTries == 1)
  {
    cout << " guess."
         << endl
         << endl;
  }
  else
  {
    cout << " guesses."
         << endl
         << endl;
  }
}
