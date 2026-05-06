#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const string FileClientsData = "Clients Data.txt";

struct stClient
{
    string accountname;
    string pincode;
    string name;
    string phone;
    double balance;
    bool markfordelete = false;
};

vector <string> SplitString(string st, string delim)
{
    vector <string> vstring;
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

stClient ConvertLineToRecord(string st, string seperator = "#//#")
{
    stClient client;

    vector <string> vdata;
    vdata = SplitString(st, seperator);

    client.accountname = vdata[0];
    client.pincode = vdata[1];
    client.name = vdata[2];
    client.phone = vdata[3];
    client.balance = stod(vdata[4]);

    return client;
}

string ConvertRecordToLine(stClient st, string seperator = "#//#")
{
    string word = "";

    word += st.accountname + seperator;
    word += st.pincode + seperator;
    word += st.name + seperator;
    word += st.phone + seperator;
    word += to_string(st.balance);

    return word;
}

vector <stClient> LoadClientDataFromFile(string filename)
{
    vector <stClient> vdata;

    fstream myfile;

    myfile.open(filename, ios::in);

    if (myfile.is_open())
    {
        string line;
        stClient client;

        while (getline(myfile, line))
        {
            client = ConvertLineToRecord(line);

            vdata.push_back(client);
        }
        myfile.close();
    }
    return vdata;
}

void ShowClientData(stClient client)
{
    cout << "The Following are The Client Details: \n\n";

    cout << "Account Number: " << client.accountname << endl;
    cout << "PIN Code      : " << client.pincode << endl;
    cout << "Name          : " << client.name << endl;
    cout << "Phone         : " << client.phone << endl;
    cout << "Balance       : " << client.balance << endl;
}

bool FindClientByAccountNumber(string accountnum, vector <stClient> vdata, stClient& client)
{    
    for (stClient data : vdata)
    {
        if (data.accountname == accountnum)
        {
            client = data;
            return true;
        }
    }
    return false;
}

bool MarkClientForDeleteByAccountNumber(string accountnum, vector <stClient>& vclient)
{
    for (stClient& client : vclient)
    {
        if (client.accountname == accountnum)
        {
            client.markfordelete = true;
            return true;
        }
    }
    return false;
}

vector <stClient> SaveClientsDataToFile(string filename, vector <stClient>& vclients)
{
    string dataline;
    
    fstream myfile;

    myfile.open(filename, ios::out);

    if (myfile.is_open())
    {
        for (stClient& client : vclients)
        {
            if (client.markfordelete == false)
            {
                dataline = ConvertRecordToLine(client);

                myfile << dataline << endl;
            }
        }
        myfile.close();
    }
    return vclients;
}

bool DeleteClientByAccountNumber(string accountnum, vector <stClient> &vclient)
{
    stClient client;
    char answer = 'n';

    if (FindClientByAccountNumber(accountnum, vclient, client))
    {
        ShowClientData(client);

        cout << "\n\nAre Your Sure You Want Delete This Client? ";
        cin >> answer;

        if (answer == 'Y' || answer == 'y')
        {
            MarkClientForDeleteByAccountNumber(accountnum, vclient);
            SaveClientsDataToFile(FileClientsData, vclient);

            //Refresh Clients
            vclient = LoadClientDataFromFile(FileClientsData);

            cout << "\n\nClient Deleted Successfully.\n";
            return true;
        }
    }
    else
    {
        cout << "\n\nClient With Account Number [" << accountnum << "] is Not Found!\n";
        return false;
    }
}

string ReadAccountNumber()
{
    string st;
    cout << "Please Enter Account Number? ";
    cin >> st;

    return st;
}

int main()
{
    vector <stClient> client;
    client = LoadClientDataFromFile(FileClientsData);

    string accountnum = ReadAccountNumber();

    DeleteClientByAccountNumber(accountnum, client);

    return 0;
}

