#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const string FileDataClient = "Clients Data.txt";

struct stClient
{
    string accountnum;
    string pincode;
    string name;
    string phone;
    double balance;
    bool markforupdate = false;
};

stClient UpdateClientData(string accountnum)
{
    stClient client;

    client.accountnum = accountnum;

    cout << "\nEnter PIN Code? ";
    getline(cin >> ws, client.pincode);

    cout << "Enter Your Name? ";
    getline(cin, client.name);

    cout << "Enter Your Phone? ";
    getline(cin, client.phone);

    cout << "Enter Your Balance? ";
    cin >> client.balance;

    return client;
}

vector <string> SplitString(string st, string delim)
{
    vector <string>vdata;
    string word = "";
    short pos = 0;

    while ((pos = st.find(delim)) != string::npos)
    {
        word = st.substr(0, pos);

        if (word != "")
        {
            vdata.push_back(word);
        }
        st.erase(0, pos + delim.length());
    }
    if (st != "")
    {
        vdata.push_back(st);
    }
    return vdata;
}

stClient ConvertLineToRecord(string st, string seperator = "#//#")
{
    stClient client;

    vector <string> vdata;
    vdata = SplitString(st, seperator);

    client.accountnum = vdata[0];
    client.pincode = vdata[1];
    client.name = vdata[2];
    client.phone = vdata[3];
    client.balance = stod(vdata[4]);

    return client;
}

string ConverRecordToLine(stClient client, string seperator = "#//#")
{
    string word = "";

    word += client.accountnum + seperator;
    word += client.pincode + seperator;
    word += client.name + seperator;
    word += client.phone + seperator;
    word += to_string(client.balance);

    return word;
}

vector <stClient> LoadClientDataFromFile(string filename)
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
            client = ConvertLineToRecord(line);

            vdata.push_back(client);
        }
        myfile.close();
    }
    return vdata;
}

bool FindClientByAccountNumber(string accountnum, vector <stClient> vdata, stClient& client)
{
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
    cout << "\nThe Following are The Client Details: \n\n";

    cout << "Account Number: " << client.accountnum << endl;
    cout << "PIN Code      : " << client.pincode << endl;
    cout << "Name          : " << client.name << endl;
    cout << "Phone         : " << client.phone << endl;
    cout << "Balance       : " << client.balance << endl;
}

vector <stClient> SaveClientsDataToFile(string filename, vector <stClient>& vclients)
{
    string linedata;

    fstream myfile;

    myfile.open(filename, ios::out);

    if (myfile.is_open())
    {
        for (stClient& client : vclients)
        {
            if (client.markforupdate == false)
            {
                linedata = ConverRecordToLine(client);

                myfile << linedata << endl;
            }
        }
        myfile.close();
    }
    return vclients;
}

string ReadAccountNumber()
{
    string st;
    cout << "Please Enter Your Account Number? ";
    cin >> st;

    return st;
}

bool UpdateClientDataByAccountNumber(string accountnum, vector<stClient>& vdata)
{
    stClient client;
    char answer = 'n';

    if (FindClientByAccountNumber(accountnum, vdata, client))
    {
        PrintClientData(client);

        cout << "Are You Sure You Want Update This Client? Y/N  ";
        cin >> answer;

        if (answer == 'Y' || answer == 'y')
        {
            for (stClient& c : vdata)
            {
                if (c.accountnum == accountnum)
                {
                    c = UpdateClientData(accountnum);

                    break; //if use return not break it will out from function 
                }
            }
            SaveClientsDataToFile(FileDataClient, vdata);

            //Refresh Clients
            vdata = LoadClientDataFromFile(FileDataClient);
            cout << "\n\nClient Updated Successfully.\n";

            return true;
        }
    }
    else
    {
        cout << "Client With Account Number [" << accountnum << "] Not Found!\n";
        return false;
    }
}

int main()
{
    string accountnum = ReadAccountNumber();

    vector <stClient> client;
    client = LoadClientDataFromFile(FileDataClient);

    UpdateClientDataByAccountNumber(accountnum, client);

    return 0;
}
