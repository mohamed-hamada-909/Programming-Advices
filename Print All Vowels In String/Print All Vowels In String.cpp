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

bool IsVowels(char chr)
{
    chr = tolower(chr);

    return ((chr == 'a') || (chr == 'e') || (chr == 'i') || (chr == 'o') || (chr == 'u'));
}

void PrintAllVowels(string st)
{
    cout << "Vowels in String are: ";
    for (short i = 0; i < st.length(); i++)
    {
        if (IsVowels(st[i]))
        {
            cout << st[i] << "   ";
        }
    }
}

int main()
{
    string st = ReadString();

    PrintAllVowels(st);

    return 0;
}
