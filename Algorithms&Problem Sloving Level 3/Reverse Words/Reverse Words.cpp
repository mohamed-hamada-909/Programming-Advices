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
	vector <string> vword;
	short pos = 0;
	string word;

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

string PrintReverseWord(string st)
{
	string word = "";
	vector <string> vword;

	vword = SplitString(st, " ");
	vector <string>::iterator iter = vword.end();

	while (iter != vword.begin())
	{
		iter--;

		word += *iter + " ";
    }
	word = word.substr(0, word.length() - 1);

	return word;
}

int main()
{
	string st = ReadString();

	cout << "\n\nString After Reversing Words:\n";
	cout << PrintReverseWord(st) << endl;

	return 0;
}
