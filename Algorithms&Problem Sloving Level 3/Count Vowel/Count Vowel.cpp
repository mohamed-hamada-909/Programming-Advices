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

bool IsVowel(char chr)
{
	chr = tolower(chr);

	return ((chr == 'a') || (chr == 'e') || (chr == 'i') || (chr == 'o') || (chr == 'u'));
}

short CountVowel(string st)
{
	short count = 0;

	for (short i = 0; i < st.length(); i++)
	{
		if (IsVowel(st[i]))
		{
			count++;
		}
	}
	return count;
}

int main()
{
	string st = ReadString();

	cout << "Number of Vowel is: " << CountVowel(st);

	return 0;
}
