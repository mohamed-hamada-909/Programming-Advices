#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadString()
{
	string st;
	cout << "Please Enter Your String\n";
	getline(cin, st);

	return st;
}

vector <string> SplitString(string st, string delim)
{
	vector<string> vword;
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

string JoinString(vector<string>vst, string delim)
{
	string word = "";

	for (string& s : vst)
	{
		word += s + delim;
	}
	return word.substr(0, word.length() - delim.length());
}

string LowerAllString(string st)
{
	for (short i = 0; i < st.length(); i++)
	{
		st[i] = tolower(st[i]);
	}
	return st;
}

string ReplaceWord(string st, string stringfrom, string stringto, bool match)
{
	vector <string> vstring;

	vstring = SplitString(st, " ");

	for (string& word : vstring)
	{
		if (match)
		{
			if (word == stringfrom)
			{
				word = stringto;
			}
		}
		else
		{
			if (LowerAllString(word) == LowerAllString(stringfrom))
			{
				word = stringto;
			}
		}
	}
	return JoinString(vstring, " ");
}

int main()
{
	string st = ReadString();

	cout << "\nOrigin String\n";
	cout << st << "\n";

	cout << "\nReplace With Match Case:\n";
	cout << ReplaceWord(st, "china", "Egypt",true) << endl;

	cout << "\nReplace With Not Match Case:\n";
	cout << ReplaceWord(st, "china", "Egypt",false) << endl;

	return 0;
}
