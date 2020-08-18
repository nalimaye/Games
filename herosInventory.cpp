// Player inputs the weapons for a Hero's Inventory.
// Player can then add (in front or back), find, remove or replace a weapon in it.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  vector<string> inventory;
  vector<string>::iterator myIterator;
  vector<string>::const_iterator iter;
  string weapon;

  cout << "\n\tWelcome to Hero's Inventory !!!\n\n";
  cout << "Enter the weapons for your Hero's Inventory.\n";
  cout << "Enter \"done\" when you are done adding the weapons.\n\n";

  // Loop to add weapons
  do
  {
    cout << "Enter a weapon : ";
    getline(cin, weapon);
    inventory.push_back(weapon);
  } while (weapon != "done");
  // remove "done" from inventory
  inventory.pop_back();

  // Loop to display the initial inventory
  cout << "\nYour Hero's Inventory :\n";
  for (iter = inventory.begin(); iter != inventory.end(); ++iter)
  {
    if (iter != inventory.begin())
    {
      cout << ",  ";
    }
    cout << *iter;
  }

  cout << "\n\n\tEnter \"display\" to display the inventory.\n";
  cout << "\tEnter \"find\" to look for a weapon in it.\n";
  cout << "\tEnter \"addfront\" to add a weapon at the beginning.\n";
  cout << "\tEnter \"addback\" to add a weapon at the end.\n";
  cout << "\tEnter \"remove\" to remove a weapon.\n";
  cout << "\tEnter \"replace\" to replace a weapon.\n";
  cout << "\tEnter \"quit\" to quit the game.\n";

  string choice;
  do
  {
    cout << "\nWhat do you want to do ? : ";
    getline(cin, choice);

    // Display the inventory.
    if (choice == "display")
    {
      cout << "Your Hero's Inventory is now :\n";
      for (iter = inventory.begin(); iter != inventory.end(); ++iter)
      {
        if (iter != inventory.begin())
        {
          cout << ",  ";
        }
        cout << *iter;
      }
      cout << endl;
    }

    // Find a weapon.
    if (choice == "find")
    {

      cout << "Enter the weapon to find : ";
      getline(cin, weapon);
      iter = find(inventory.begin(), inventory.end(), weapon);
      if (iter != inventory.end())
      {
        cout << "The " << weapon << " is found !\n";
      }
      else
      {
        cout << "The " << weapon << " is NOT found....\n";
      }
    }
  } while (choice != "quit");

  cout << "\nThanks for playing. See you soon.\n\n";
  return 0;
}
