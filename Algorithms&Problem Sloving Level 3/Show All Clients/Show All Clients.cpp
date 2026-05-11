#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

const string ClientsFileName = "Clients Data.txt";

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
    vector <string> vclientdata;

    vclientdata = SplitString(st, seperator);

    client.accountnum = vclientdata[0];
    client.pincode = vclientdata[1];
    client.name = vclientdata[2];
    client.phone = vclientdata[3];
    client.balance = stod(vclientdata[4]);

    return client;
}

vector <stClient> LoadClientsDataFromFile(string filename)
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

void PrintClientRecord(stClient client)
{
    cout << "|" << setw(15) << left << client.accountnum;
    cout << "|" << setw(12) << left << client.pincode;
    cout << "|" << setw(42) << left << client.name;
    cout << "|" << setw(10) << left << client.phone;
    cout << "|" << setw(12) << left << client.balance;
}

void PrintAllClientsData(vector <stClient> vclient)
{
    cout << "\n\t\t\t\t\tClient List (" << vclient.size() << ") Client(s).";
              
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout <<
        "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    for (stClient client : vclient)
    {
        PrintClientRecord(client);
        cout << endl;
    }
    
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}

int main()
{
    vector <stClient> client;

    client = LoadClientsDataFromFile(ClientsFileName);
    
    PrintAllClientsData(client);

    return 0;
}
