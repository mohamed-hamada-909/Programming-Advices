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

string UpperFirstLetterOfEachWord(string s1)
{
    bool isfirstletter = true;

    for (short i = 0; i < s1.length(); i++)
    {
        if (s1[i] != ' ' && isfirstletter)
        {
            s1[i] = toupper(s1[i]);
        }
        isfirstletter = (s1[i] == ' ' ? true : false);
    }
    return s1;
}

int main()
{
    string s1 = ReadString();

    cout << "\nString After Conversion\n";

    s1 = UpperFirstLetterOfEachWord(s1);
    cout << "\n" << s1 << endl;

    return 0;
}
