#pragma once

#include <iostream>

using namespace std;

namespace trim
{
    string TrimLeft(string st)
    {
        for (short i = 0; i < st.length(); i++)
        {
            if (st[i] != ' ')
            {
                return st.substr(i, st.length() - i);
            }
        }
        return "";
    }

    string TrimRight(string st)
    {
        for (short i = st.length() - 1; i >= 0; i--)
        {
            if (st[i] != ' ')
            {
                return st.substr(0, i + 1);
            }
        }
        return "";
    }

    string Trim(string st)
    {
        return TrimLeft(TrimLeft(st));
    }

}
