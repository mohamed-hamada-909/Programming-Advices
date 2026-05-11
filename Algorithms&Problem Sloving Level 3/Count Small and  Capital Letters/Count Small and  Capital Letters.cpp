#include <iostream>
#include <string>

using namespace std;

enum encount { capital = 0, small = 1 };

//create in one function
short CountLetter(string st,encount count)
{
    short lcount = 0;

    for (short i = 0; i < st.length(); i++)
    {
        if (count == encount::capital && isupper(st[i]))
        {
            lcount++;
        }
        else if(count==encount::small&&islower(st[i]))
        {
            lcount++;
        }
    }
    return lcount;
}

string ReadString()
{
    string st;
    cout << "Please Enter Your String\n";
    getline(cin, st);

    return st;
}

short CountCapitalLetter(string st)
{
    short count = 0;

    for (short i = 0; i < st.length(); i++)
    {
        if (isupper(st[i]))
        {
            count++;
        }
    }
    return count;
}

short CountSmallLetter(string st)
{
    short count = 0;

    for (short i = 0; i < st.length(); i++)
    {
        if (islower(st[i]))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    string st = ReadString();

    cout << "String Length: " << st.length() << endl;

    cout << "Capital Letter Count: " << CountCapitalLetter(st) << endl;

    cout << "Small Letter Count: " << CountSmallLetter(st) << endl;

    //solution 2
    cout << "Capital Letter Count: " << CountLetter(st,encount::capital) << endl;

    cout << "Small Letter Count: " << CountLetter(st,encount::small) << endl;

    return 0;
}
