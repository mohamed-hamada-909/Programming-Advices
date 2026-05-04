#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadString()
{
    string st;
    cout << "Please Enter Your String\n";
    getline(cin, st);

    return st;
}

string ReplaceWord(string st, string stringfrom, string stringto)
{
    short pos = st.find(stringfrom);

    while (pos != string::npos)
    {
        st.replace(pos, stringfrom.length(), stringto);
        pos = st.find(stringfrom);
    }
    return st;
}

int main()
{
    string st = ReadString();

    cout << "\nOrigin String\n";
    cout << st << endl;

    cout << "String After Replace\n";
    cout << ReplaceWord(st, "Mohamed", "Hamada") << endl;

    return 0;
}