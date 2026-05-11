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

short CountWord(string st)
{
    short count = 0, pos = 0;

    string space = " ", word;
    
    while ((pos = st.find(space)) != string::npos)
    {
        word = st.substr(0, pos);

        if (word != "")
        {
            count++;
        }
        st.erase(0, pos + space.length());
    }
    if (st != "")
    {
        count++;
    }
    return count;
}

int main()
{
    string st = ReadString();

    cout << "Number of Word in Your String: ";
    cout << CountWord(st) << endl;

    return 0;
}
