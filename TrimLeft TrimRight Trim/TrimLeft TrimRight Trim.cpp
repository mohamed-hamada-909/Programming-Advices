#include <iostream>
#include <string>
#include "Trim.h";

using namespace std;

int main()
{
    string st = "    Mohamed Hamada    ";

    cout << "String = " << st << endl;
    cout << "\nTrim Left:" << trim::TrimLeft(st) << endl;
    cout << "Trim Right:" << trim::TrimRight(st) << endl;
    cout << "Trim:" << trim::Trim(st) << endl;

    return 0;
}
