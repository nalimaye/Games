// Classic Number Guessing Game

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

  int numTries = 0;
  int guess = 0;

  // set the seed
  srand((unsigned)time(NULL));
  // generate random number between 1-100
  int secretNumber = (rand() % 100) + 1;

  cout << endl
       << "Welcome to \"Guess My Number\" between 1-100 !!!" << endl
       << endl;

  do
  {
    cout << "Enter a guess : ";
    cin >> guess;
    ++numTries;

    if (guess < secretNumber)
    {
      cout << "Too Low" << endl;
    }
    else if (guess > secretNumber)
    {
      cout << "Too High" << endl;
    }
    else
    {
      cout << "You got it !!!" << endl;
    }
  } while (guess != secretNumber);
}