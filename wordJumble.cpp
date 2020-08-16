// Puzzle game in which the computer creates a version of a word
// where its letters are in random order.
// Player has to guess the correct word to win.
// Player can ask for a hint, if stuck.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  enum fields
  {
    WORD,
    HINT,
    NUM_FIELDS
  };
  const int NUM_WORDS = 5;
  const string WORDS[NUM_WORDS][NUM_FIELDS] =
      {
          {"doorknob", "Please use me to open the door."},
          {"backpack", "Do you see kids carrying it on their backs ?"},
          {"snowballs", "Oh, you need these for a snowfight !"},
          {"shuttlecock", "Let's play a game of badminton !"},
          {"honeybee", "Who's making that buzzing sound ?"}};

  // Set the seed
  srand((unsigned)time(NULL));
  // Generate a random number between (0 to NUM_WORDS-1)
  int choice = (rand() % NUM_WORDS);
  string theWord = WORDS[choice][WORD]; // word to guess
  string theHint = WORDS[choice][HINT]; // hint for the word to guess

  string jumble = theWord;
  int length = jumble.size();
  for (int i = 0; i < length; i++)
  {
    int index1 = rand() % length;
    int index2 = rand() % length;
    char temp = jumble[index1];
    jumble[index1] = jumble[index2];
    jumble[index2] = temp;
  }

  cout << "\n\tWelcome to Word Jumble !!!\n\n";
  cout << "Unscramble the letters to make a word.\n";
  cout << "Enter \"hint\" for a hint.\n";
  cout << "Enter \"quit\" to quit the game.\n\n";
  cout << "The Jumble is : " << jumble << "\n\n";

  string guess;
  cout << "Enter your guess : ";
  cin >> guess;

  // Game loop
  while ((guess != theWord) && (guess != "quit"))
  {
    if (guess == "hint")
    {
      cout << "Hint: " << theHint << "\n";
    }
    else
    {
      cout << "Sorry, that's not it.\n";
    }
    cout << "\nEnter your guess : ";
    cin >> guess;
  }

  if (guess == theWord)
  {
    cout << "\nCongratulations ! You guessed it !!\n";
  }
  cout << "Thanks for playing. See you soon.\n\n";
  return 0;
}
