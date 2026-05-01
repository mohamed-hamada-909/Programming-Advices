#pragma once

#include <iostream>
#include <string>

using namespace std;

namespace st
{
    string ReadString()
    {
        string st;

        cout << "Please Enter Your String\n";
        getline(cin, st);

        return st;
    }

    string UpperLetter(string st)
    {
        for (short i = 0; i < st.length(); i++)
        {
            if (st[i] != ' ')
            {
                st[i] = toupper(st[i]);
            }
        }
        return st;
    }

    string LowerLetter(string st)
    {
        for (short i = 0; i < st.length(); i++)
        {
            if (st[i] != ' ')
            {
                st[i] = tolower(st[i]);
            }
        }
        return st;
    }

}
