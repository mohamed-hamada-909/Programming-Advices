#include <iostream>
#include <string>

using namespace std;

string ReadString()
{
	string st;
	cout << "Please Enter Your String\n";
	getline(cin, st);

	return st;
}

char ReadChar()
{
	char chr;
	cout << "Please Enter a Character?\n";
	cin >> chr;

	return chr;
}

char InverLetterCase(char chr)
{
	return isupper(chr) ? tolower(chr) : toupper(chr);
}

short CountLetter(string st, char chr, bool matchcase = true)
{
	short count = 0;

	for (short i = 0; i < st.length(); i++)
	{
		if (matchcase)
		{
			if (st[i] == chr)
				count++;
		}
		else
		{
			if (tolower(st[i]) == tolower(chr))
				count++;
		}
	}
	return count;
}

int main()
{
	string st = ReadString();
	char chr = ReadChar();

	cout << "Letter '" << chr << "' Count: " << CountLetter(st, chr) << endl;

	cout << "Letter '" << chr << "' or '" << InverLetterCase(chr) << "' Count: ";
	cout << CountLetter(st, chr, false) << endl;

	return 0;
}
