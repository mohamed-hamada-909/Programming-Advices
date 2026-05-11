#include <iostream>
#include <string>

using namespace std;

string ReadString()
{
    string s1;
    cout << "Please Enter Your String\n";
    getline(cin, s1);

    return s1;
}

void PrintFirstLetters(string s1)
{
    cout << "\nFirst Letters of this String\n";

    bool isfirstletter = true;

    for (short i = 0; i < s1.length(); i++)
    {
        if (s1[i] != ' ' && isfirstletter)
        {
            cout << s1[i] << endl;
        }
        
        isfirstletter = (s1[i] == ' ' ? true : false);
    }
}

int main()
{
    PrintFirstLetters(ReadString());

    return 0;
}
