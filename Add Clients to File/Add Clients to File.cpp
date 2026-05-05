#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const string FileDataName = "Clients Data.txt";

struct stClient
{
    string accountnumber;
    string pincode;
    string name;
    string phone;
    double salary;
};

stClient ReadDataClient()
{
    stClient client;

    cout << "Enter Account Number? ";
    getline(cin >> ws, client.accountnumber);
    cout << "Enter PIN Code? ";
    getline(cin, client.pincode);
    cout << "Enter Your Name? ";
    getline(cin, client.name);
    cout << "Enter Your Phone? ";
    getline(cin, client.phone);
    cout << "Enter Your Salary? ";
    cin >> client.salary;

    return client;
}

string ConvertRecordToLine(stClient client, string seperator = "#//#")
{
    string data = "";
    data += client.accountnumber + seperator;
    data += client.pincode + seperator;
    data += client.name + seperator;
    data += client.phone + seperator;
    data += to_string(client.salary);

    return data;
}

void AddDataToFile(string filename, string dataline)
{
    fstream myfile;

    myfile.open(filename, ios::out | ios::app);

    if (myfile.is_open())
    {
        myfile << dataline << endl;

        myfile.close();
    }
}

void AddNewClient()
{
    stClient client;

    client = ReadDataClient();

    AddDataToFile(FileDataName, ConvertRecordToLine(client));
}

void AddClients()
{
    char addmore = 'Y';

    do
    {
        system("cls");
        cout << "Adding New Client: \n";
        AddNewClient();

        cout << "Client Added Successfully, Do You Want To Add More Client? Y/N\n";
        cin >> addmore;
    } while (toupper(addmore)=='Y');
}

int main()
{
    AddClients();

    return 0;
}
