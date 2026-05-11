#include <iostream>
#include <string>

using namespace std;

struct stClientData
{
	string accountnumber;
	string pincode;
	string name;
	string phone;
	double accountbalance;
};

stClientData ReadData()
{
	stClientData data;

	cout << "Enter Account Number\n";
	getline(cin, data.accountnumber);
	cout << "Enter PIN Code\n";
	getline(cin, data.pincode);
	cout << "Enter Your Name\n";
	getline(cin, data.name);
	cout << "Enter Phone\n";
	getline(cin, data.phone);
	cout << "Enter Account Balance\n";
	cin >> data.accountbalance;

	return data;
}

string ConvertRecordToLine(stClientData client, string seperator = "#//#")
{
	string Data = "";

	Data += client.accountnumber + seperator;
	Data += client.pincode + seperator;
	Data += client.name + seperator;
	Data += client.phone + seperator;
	Data += to_string(client.accountbalance);

	return Data;
}

int main()
{
	cout << "Please Enter Client Data:\n\n";
	
	stClientData data;
	data = ReadData();

	cout << "\n\nClient Record for Saving is:\n";
	cout << ConvertRecordToLine(data) << endl;

	return 0;
}