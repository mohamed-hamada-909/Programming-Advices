#include <iostream>

using namespace std;

char ReadChar()
{
	char chr;
	cout << "Please Enter a Character?\n";
	cin >> chr;

	return chr;
}

bool IsVowel(char chr)
{
	chr = tolower(chr);

	return ((chr == 'a') || (chr == 'e') || (chr == 'i') || (chr == 'o') || (chr == 'u'));
}

int main()
{
	char chr = ReadChar();

	if (IsVowel(chr))
	{
		cout << "\nYes, Letter '" << chr << "' is Vowel\n";
	}
	else
	{
		cout << "\nNo, Letter '" << chr << "' is NOT Vowel\n";
	}

	return 0;
}
