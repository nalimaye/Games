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
  char answer = 'n';

  // Set the seed
  srand((unsigned)time(NULL));
  // Generate a random number between (1 - MAX_NUMBER)
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

    // Check if player guess is a valid number between (1 - MAX_NUMBER)
    if ((guess <= 0) || (guess > MAX_NUMBER))
    {
      cout << "Invalid guess. Guess again..." << endl;
      continue;
    }

    if (guess < secretNumber)
    {
      cout << "Too Low..." << endl;
    }
    else if (guess > secretNumber)
    {
      cout << "Too High..." << endl;
    }
    else
    {
      cout << endl
           << "You got it !!!";
      // EXIT the game loop, if player guess is CORRECT
      break;
    }

    // Ask if player wants to continue or not.
    cout << "Continue ? (y/n) : ";
    cin >> answer;
    if ((answer == 'Y') || (answer == 'y'))
      continue;
    else
      // EXIT the game loop, if player does NOT want to continue
      break;
  };

  // Print final statistics before exiting

  // Depending on whether player guessed it correctly or not
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
  // and the number of player guess(es)
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

  return 0;
}
