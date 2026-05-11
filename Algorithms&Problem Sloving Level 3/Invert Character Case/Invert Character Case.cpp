#include <iostream>
#include <string>

using namespace std;

char ReadChar()
{
    char chr;
    cout << "Please Enter a Character?\n";
    cin >> chr;

    return chr;
}

char InvertChar(char chr)
{
    return isupper(chr) ? tolower(chr) : toupper(chr);
}

int main()
{
    char chr = ReadChar();
    
    cout << "Character After Invet Case " << InvertChar(chr) << endl;

    return 0;
}
