#include "wortspiegel.h"
#include <iostream>
void wortspiegel(string &text, int pos)
{
	int posLinks = 0, posRechts = 0, counter = -1;
	string tmp = text;
	if (text[pos] != ' ' && text[pos] != '.')
	{
		for (int i = 0; i <= text.length(); i++)
		{
			if (text[i] == ' ' && i < pos)
			{
				counter = -1;
				posLinks = i + 1;
			}
			else if (i < pos) counter++;
			else if ((text[i] == ' ' || i == text.length() || text[i] == '.') && i > pos)
			{
				posRechts = i - 1;
				break;
			}
		}
		counter = 0;
		for (int i = posLinks; i <= posRechts; i++)
		{
			text[i] = tmp[posRechts - counter];
			counter++;
		}
	}
}