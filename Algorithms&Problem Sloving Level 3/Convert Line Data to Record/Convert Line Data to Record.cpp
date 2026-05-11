#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct sClient
{
    string accountnum;
    string pincode;
    string name;
    string phone;
    double balance;
};

vector <string> SplitString(string st, string delim)
{
    vector <string> vword;
    string word = "";
    short pos = 0;

    while ((pos = st.find(delim)) != string::npos)
    {
        word = st.substr(0, pos);

        if (word != "")
        {
            vword.push_back(word);
        }
        st.erase(0, pos + delim.length());
    }
    if (st != "")
    {
        vword.push_back(st);
    }
    return vword;
}

sClient ConvertLineToRecord(string st, string seperator = "#//#")
{
    sClient client;

    vector <string> vdata;
    vdata = SplitString(st, seperator);

    client.accountnum = vdata[0];
    client.pincode = vdata[1];
    client.name = vdata[2];
    client.phone = vdata[3];
    client.balance = stod(vdata[4]);
    
    return client;
}

void PrintData(sClient client)
{
    cout << "\n\nThe Following is the Extrcted Client Record:\n";

    cout << "Account Number: " << client.accountnum << endl;
    cout << "PIN Code      : " << client.pincode << endl;
    cout << "Name          : " << client.name << endl;
    cout << "Phone         : " << client.phone << endl;
    cout << "Balance       : " << client.balance << endl;
}

int main()
{
    string line = "a150#//#159206#//#Mohamed Hamada#//#01155584557#//#712.458";

    cout << "Line Record is:\n";
    cout << line << endl;

    sClient client = ConvertLineToRecord(line);
    
    PrintData(client);

    return 0;
}
