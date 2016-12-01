#include "wortspiegel.h"
#include <iostream>
void wortspiegel(string &text, int pos)
{
	int posLinks = 0, posRechts = 0, counter = -1; //Pos Links & Rechts ist 0, Counter -1
	string tmp = text;			//String wird tmp zugwiesen
	if (text[pos] != ' ' && text[pos] != '.') // für den Fall, dass kein Leerzeichen oder Punkt
	{
		for (int i = 0; i <= text.length(); i++) // solange wie Text Länge
		{
			if (text[i] == ' ' && i < pos)	// für den Fall, das auf der Pos ein Leerzeichen oder ein Punkt ist
			{
				counter = -1;				// soll -1 beibehalten
				posLinks = i + 1;			// soll eine Position weiter prüfen
			}
			else if (i < pos) // wenn i kleiner als die Position ist soll der Counter hoch gehen
				counter++;
			else if ((text[i] == ' ' || i == text.length() || text[i] == '.') && i > pos) // 
			{
				posRechts = i - 1;	// wenn ein Punkt, ein Leerzeichen oder die Text länge gleich i ist
				break;				//	i -1 aus schleife raus
			}
		}
		counter = 0; // WEITER SCHREIBEN
		for (int i = posLinks; i <= posRechts; i++)		
		{
			text[i] = tmp[posRechts - counter];
			counter++;
		}
	}
}
