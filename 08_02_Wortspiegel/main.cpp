#include <iostream>
#include <string>
#include "wortspiegel.h"
using namespace std;
void writeOut(string myString, int position)
{
	bool foundPosition = false;			// um auf Wahr zu springen, wenn Position gefunden wurde
	cout << myString << endl;			// gibt den eingegebenen Text aus
	for (int i = 0; i < myString.length(); i++)	// schleife soll bis länge des Textes gehen
	{
		if (position < 0) {}
		else if (i == position)
		{
			cout << "*" << endl;		// Sternchen unter dem Text
			foundPosition = true;		// solange die Postition gefunden werden kann
		}
		else if (!foundPosition) cout << " "; // wenn über die Länge hinaus gearbeitet wird, erscheint kein
	}											// Sternchen mehr
}
char getCommand()			// char Funktion, um Befehl entgegen zu nehmen
{
	char myChar;
	cout << "Befehl (l: links, r : rechts, s : spiegeln, q : Ende) ?- "; // Die Befehle zur Auswahl einblenden
	cin >> myChar;
	cout << endl;
	return myChar; // char wird übergeben
}
int main()
{
	string myString;		//String wird definiert
	int stringPosition = 0;	//es wird von Position 0 ausgegangen
	char myCommand;			//myCommand wird definiert
	cout << "Bitte geben Sie den Text ein: ? ";
	getline(cin, myString);
	do
	{
		writeOut(myString, stringPosition);
		myCommand = getCommand();
		if (myCommand == 'l')								// wenn l eingegeben wird
		{
			if (stringPosition > 0) stringPosition -= 1;	// Sternchen nach links, wenn größer als 1
		}
		else if (myCommand == 'r')							// wenn r eingegeben wird
		{
			if (stringPosition < myString.length())			// funktioniert, solange es innerhalb der Länge ist
			{
				stringPosition += 1;						// Sternchen nach rechts
			}
		}
		else if (myCommand == 's')							// Funktion wortspiegel wird benutzt
			wortspiegel(myString, stringPosition);
	} while (myCommand != 'q');								// Schleife endet, wenn q eingegeben wird

	system("pause");
	return 0;
}
