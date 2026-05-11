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

void PrintWord(string st)
{
    string space = " ";

    cout << "Your String Words are: \n";

    short pos = 0;
    string word;

    while ((pos = st.find(space)) != std::string::npos)
    {
        word = st.substr(0, pos);

        if (word != "")
        {
            cout << word << endl;
        }
        st.erase(0, pos + space.length());
    }
    if (st != " ")
    {
        cout << st << endl;
    }
}

int main()
{
    PrintWord(ReadString());

    return 0;
}
