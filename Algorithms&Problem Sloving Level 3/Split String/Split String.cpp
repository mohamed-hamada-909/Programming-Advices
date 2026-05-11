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

vector <string> SplitString(string st, string space)
{
    vector <string> vword;
    
    short pos = 0;
    string word;

    while ((pos = st.find(space)) != string::npos)
    {
        word = st.substr(0, pos);

        if (word != "")
        {
            vword.push_back(word);
        }
        st.erase(0, pos + space.length());
    }
    if (st != "")
    {
        vword.push_back(st);
    }
    return vword;
}

int main()
{
    vector <string> vword;

    vword = SplitString(ReadString(), " ");

    cout << "Tokens = " << vword.size() << endl;

    for (string& word : vword)
    {
        cout << word << endl;
    }

    return 0;
}
