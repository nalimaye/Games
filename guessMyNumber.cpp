// Classic Number Guessing Game

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  const int MAX_NUMBER = 100;

  int numTries = 0;
  int guess = 0;
  char answer = 'N';

  // Set the seed
  srand((unsigned)time(NULL));
  // Generate random number between (1 - MAX_NUMBER)
  int secretNumber = (rand() % MAX_NUMBER) + 1;

  cout << endl
       << "Welcome to \"Guess My Number\" between 1-" << MAX_NUMBER << " !!!" << endl
       << endl;

  // Game loop
  while (true)
  {
    cout << "Enter a guess : ";
    cin >> guess;
    ++numTries;

    // Check if user guess is a valid number between (1 - MAX_NUMBER)
    if (!((guess > 0) && (guess <= MAX_NUMBER)))
    {
      cout << "Invalid guess. Guess again..." << endl;
      continue;
    }

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
