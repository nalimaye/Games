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
  const int NUM_WORDS = 15;
  const string WORDS[NUM_WORDS][NUM_FIELDS] =
      {
          {"doorknob", "Please use me to open the door."},
          {"backpack", "Do you see kids carrying it on their backs ?"},
          {"snowballs", "Oh, you need these for a snowfight !"},
          {"shuttlecock", "Let's play a game of badminton !"},
          {"honeybee", "Who's making that buzzing sound ?"},
          {"telescope", "See the stars !"},
          {"abbreviation", "Make it short, please...."},
          {"perpendicular", "Oh yes, at right angle !"},
          {"telephone", "Ring, Ring, Ring...."},
          {"atmosphere", "Surrounds the whole earth, no less...."},
          {"dinosaurs", "Remember Jurassic Park ?!"},
          {"dictionary", "Look up the words !"},
          {"strawberries", "The only fruit with seeds on the skin !"},
          {"vacillate", "Please....will you decide something ?"},
          {"pendulum", "Oh, don't swing so much...."}};

  cout << "\n\tWelcome to Word Jumble !!!\n\n";
  cout << "Unscramble the letters to make a word.\n";
  cout << "Enter \"hint\" for a hint.\n";
  cout << "Enter \"next\" for next word.\n";
  cout << "Enter \"quit\" to quit the game.\n";

  string guess;
  string jumble;

  // Main Game loop
  do
  {
    // Set the seed
    srand((unsigned)time(NULL));
    // Generate a random number between (0 to NUM_WORDS-1)
    int choice = (rand() % NUM_WORDS);
    string theWord = WORDS[choice][WORD]; // word to guess
    string theHint = WORDS[choice][HINT]; // hint for the word to guess

    jumble = theWord;
    int length = jumble.size();
    for (int i = 0; i < length; i++)
    {
      int index1 = rand() % length;
      int index2 = rand() % length;
      char temp = jumble[index1];
      jumble[index1] = jumble[index2];
      jumble[index2] = temp;
    }

    cout << "\nThe Jumble is : " << jumble << "\n\n";

    cout << "Enter your guess : ";
    cin >> guess;

    // Game loop for a word
    while ((guess != theWord) && (guess != "quit") && (guess != "next"))
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
      cout << "Congratulations ! You guessed it !!\n";
    }
    if (guess == "next")
      continue;

    if (guess == "quit")
      break;

  } while (guess != "quit");

  cout << "\nThanks for playing. See you soon.\n\n";
  return 0;
}
