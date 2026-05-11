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

int main()
{
    vector <string> vname = { "Mohamed","Ahmed","Ali","Khalid" };

    cout << "Vector After Join:\n";
    cout << JoinString(vname, "  ") << endl;

    return 0;
}
