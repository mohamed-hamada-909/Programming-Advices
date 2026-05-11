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

string RemovePauncuations(string st)
{
    string word = "";

    for (short i = 0; i < st.length(); i++)
    {
        if (!ispunct(st[i]))
        {
            word += st[i];
        }
    }
    return word;
}

int main()
{
    string st = ReadString();

    cout << "\nOrigin String\n";
    cout << st << endl;

    cout << "\nString After Remove All Pauncuations\n";
    cout << RemovePauncuations(st) << endl;

    return 0;
}
