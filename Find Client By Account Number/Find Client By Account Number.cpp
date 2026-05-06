#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

const string FileClientData = "Clients Data.txt";

struct stClient
{
    string accountnum;
    string pincode;
    string name;
    string phone;
    double balance;
};

vector <string> SplitString(string st, string delim)
{
    vector <string>vstring;
    string word = "";
    short pos = 0;

    while ((pos = st.find(delim)) != string::npos)
    {
        word = st.substr(0, pos);

        if (word != "")
        {
            vstring.push_back(word);
        }
        st.erase(0, pos + delim.length());
    }
    if (st != "")
    {
        vstring.push_back(st);
    }
    return vstring;
}

stClient ConverLineToRecord(string st, string seperator = "#//#")
{
    stClient client;

    vector <string> data;
    data = SplitString(st, seperator);

    client.accountnum = data[0];
    client.pincode = data[1];
    client.name = data[2];
    client.phone = data[3];
    client.balance = stod(data[4]);

    return client;
}

vector <stClient> LoadDataFromFile(string filename)
{
    vector <stClient> vdata;
     
    fstream myfile;
    myfile.open(filename, ios::in);//read mode

    if (myfile.is_open())
    {
        string line;
        stClient client;

        while (getline(myfile, line))
        {
            client = ConverLineToRecord(line);

            vdata.push_back(client);
        }
        myfile.close();
    }
    return vdata;
}

string ReadAccountNumber()
{
    string num;
    cout << "Please Enter Account Number? ";
    cin >> num;

    return num;
}

bool FindClientByAccountNumber(string accountnum,stClient &client)
{
    vector <stClient> vdata;
    vdata = LoadDataFromFile(FileClientData);

    for (stClient data : vdata)
    {
        if (data.accountnum == accountnum)
        {
            client = data;
            return true;
        }
    }
    return false; 
}

void PrintClientData(stClient client)
{
    cout << "\nThe following are the client details:\n\n";

    cout << "Account Number: " << client.accountnum << endl;
    cout << "PIN Code      : " << client.pincode << endl;
    cout << "Name          : " << client.name << endl;
    cout << "Phone         : " << client.phone << endl;
    cout << "Balance       : " << client.balance << endl;
}

int main()
{
    stClient client;

    string accountnum = ReadAccountNumber();

    if (FindClientByAccountNumber(accountnum,client))
    {
        PrintClientData(client);
    }
    else
    {
        cout << "Client With Account Number (" << accountnum << ") is NOT Found\n";
    }

    return 0;
}
