#include <iostream>
#include <string>
#include <vector>

using namespace std;

string JoinString(vector <string> vname, string delim)
{
    string st = "";

    for (string& name : vname)
    {
        st = st + name + delim;
    }
    return st.substr(0, st.length() - delim.length());
}

string JoinString(string name[], short length, string delim)
{
    string st = "";
    for (short i = 0; i < length; i++)
    {
        st = st + name[i] + delim;
    }
    return st.substr(0, st.length() - delim.length());
}

int main()
{
    vector <string> vname = { "Mohamed","Mahmoud","Abdelrahman" };
    string arrstring[] = { "Mohamed","Mahmoud","Abdelrahman" };

    cout << "Vector After Join: \n";
    cout << JoinString(vname, "  ") << endl;

    cout << "\nArray After Join:\n";
    cout << JoinString(arrstring, 3, "  ") << endl;

    return 0;
}
