// Hangman
// The classic game of hangman game, where the player tries to guess a word
// one character at a time, and within a certain number of maximum guesses.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

int main()
{
  // Setup
  const int MAX_WRONG = 8; // maximum number of incorrect guesses allowed.

  vector<string> words;
  words.push_back("HANGMAN");
  words.push_back("DIFFICULT");
  words.push_back("PREFERENCE");
  words.push_back("OVERLOOK");
  words.push_back("VENTILATION");
  words.push_back("ABSTRACT");
  words.push_back("CALCULATE");
  words.push_back("GARDENING");
  words.push_back("PERSPECTIVE");
  words.push_back("MOUNTAIN");

  srand((unsigned int)time(NULL));
  int randomIndex = (rand() % words.size());
  const string THE_WORD = words[randomIndex]; // Word to guess
  int wrong = 0;                              // Number of incorrect guesses
  string soFar(THE_WORD.size(), '-');         // Word guessed so far
  string used = "";                           // Letters already guessed

  cout << "\n\tWelcome to Hangman. Good Luck !\n";

  // Main game loop
  while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
  {
    cout << "\ncYou have " << (MAX_WRONG - wrong) << " incorrect guesses left.\n";
    cout << "You have used the following letters : " << used << endl;
    cout << "So far, the word is : " << soFar << endl;

    char guess;
    cout << "\nEnter your guess : ";
    cin >> guess;
    guess = toupper(guess); // Since secret word is in uppercase.

    while (used.find(guess) != string::npos)
    {
      cout << "You have already guessed " << guess << endl;
      cout << "\nEnter your guess : ";
      cin >> guess;
      guess = toupper(guess); // Since secret word is in uppercase.
    }

    used += guess;

    if (THE_WORD.find(guess) != string::npos)
    {
      cout << "That's right! " << guess << " is in the word.\n";
      // Update soFar to include newly guessed letter.
      for (int i = 0; i < THE_WORD.length(); ++i)
      {
        if (THE_WORD[i] == guess)
        {
          soFar[i] = guess;
        }
      }
    }
    else
    {
      cout << "Sorry, " << guess << " is not in the word.\n";
      ++wrong;
    }
  }

  // Final result
  if (wrong == MAX_WRONG)
  {
    cout << "\nYou have been hanged!\n\n";
  }
  else
  {
    cout << "\nCongratulations !!! You guessed " << THE_WORD << " !\n\n";
  }

  return 0;
}
