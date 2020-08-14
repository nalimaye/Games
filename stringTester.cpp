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

  cout << greeting;
  cout << "\nPlease input a phrase to test : ";
  getline(cin, phrase);

  cout << "Your phrase has " << phrase.size() << " characters in it.\n";

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

  cout << farewell;
  return 0;
}
