//Player inputs a string and the game can test it for various things.

#include <iostream>
#include <string>

using namespace std;

int main()
{
  string greeting = "\nWelcome to String Tester !!!\n";
  string farewell("\nThank you for playing !\n\n");
  string phrase, subPhrase = "";
  int position = 0;
  char charToReplace;
  int numCharsToErase = 0;

  cout << greeting;
  cout << "\nPlease input a phrase to test : ";
  getline(cin, phrase);

  cout << "Your phrase has " << phrase.size() << " characters in it.\n";

  // Ask player for a sub-phrase to search.
  cout << "\nPlease enter a sub-phrase to search : ";
  getline(cin, subPhrase);
  position = phrase.find(subPhrase);
  if (position == string::npos)
  {
    cout << "Sub-phrase is NOT found in your phrase.\n";
  }
  else
  {
    cout << "Sub-phrase found at position : " << position << "\n";
  }

  // Ask player a position to replace a character at.
  cout << "\nPosition to replace a character at : ";
  cin >> position;
  cout << "Character at position " << position << " is " << phrase[position] << "\n";
  cout << "Character to replace : ";
  cin >> charToReplace;
  phrase[position] = charToReplace;
  cout << "Now phrase is : " << phrase << "\n";

  // Ask player a position to erase character(s) at and how many character(s).
  cout << "\nPosition to erase character(s) at : ";
  cin >> position;
  cout << "How many character(s) to erase : ";
  cin >> numCharsToErase;
  phrase.erase(position, numCharsToErase);
  cout << "Now phrase is : " << phrase << "\n";

  cout << farewell;
  return 0;
}
