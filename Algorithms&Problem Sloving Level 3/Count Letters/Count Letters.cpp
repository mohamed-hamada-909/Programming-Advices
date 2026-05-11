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

short CountLetter(string st, char chr)
{
    short count = 0;

    for (short i = 0; i < st.length(); i++)
    {
        if (st[i] == chr)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    string st = ReadString();
    char chr = ReadChar();
    
    cout << "\nLetter '" << chr << "' Count: " << CountLetter(st, chr) << endl;
    
    return 0;
}
