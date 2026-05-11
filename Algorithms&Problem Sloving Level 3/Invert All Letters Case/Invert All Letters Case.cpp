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

char InvertLetterCase(char chr)
{
    return isupper(chr) ? tolower(chr) : toupper(chr);
}

string InvertLetters(string st)
{
    for (short i = 0; i < st.length(); i++)
    {
        st[i] = InvertLetterCase(st[i]);
    }
    return st;
}

int main()
{
    string st = ReadString();

    cout << "\nString After Invert All Letters Case\n";
    cout << InvertLetters(st) << endl;

    return 0;
}
