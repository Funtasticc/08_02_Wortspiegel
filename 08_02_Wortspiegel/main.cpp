#include <iostream>
#include <string>
#include "wortspiegel.h"
using namespace std;
void writeOut(string myString, int position)
{
	bool foundPosition = false;
	cout << myString << endl;
	for (int i = 0; i < myString.length(); i++)
	{
		if (position < 0) {}
		else if (i == position)
		{
			cout << "*" << endl;
			foundPosition = true;
		}
		else if (!foundPosition) cout << " ";
	}
}
char getCommand()
{
	char myChar;
	cout << "Befehl (l: links, r : rechts, s : spiegeln, q : Ende) ?- ";
	cin >> myChar;
	cout << endl;
	return myChar;
}
int main()
{
	string myString;
	int stringPosition = 0;
	char myCommand;
	cout << "Bitte geben Sie den Text ein: ? ";
	getline(cin, myString);
	do
	{
		writeOut(myString, stringPosition);
		myCommand = getCommand();
		if (myCommand == 'l')
		{
			if (stringPosition > 0) stringPosition -= 1;
		}
		else if (myCommand == 'r')
		{
			if (stringPosition < myString.length())
			{
				stringPosition += 1;
			}
		}
		else if (myCommand == 's') 
				wortspiegel(myString, stringPosition);
	} while (myCommand != 'q');

	system("pause");
	return 0;
}