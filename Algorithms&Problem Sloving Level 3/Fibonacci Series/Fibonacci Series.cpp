#include <iostream>

using namespace std;

void PrintFibonacciUsingForLoop(int num)
{
    int febnum = 0;
    int prev2 = 0, prev1 = 1;

    cout << "1   ";

    for (int i = 2; i <= num; i++)
    {
        febnum = prev1 + prev2;
        cout << febnum << "   ";

        prev2 = prev1;
        prev1 = febnum;
    }
}

int main()
{
    PrintFibonacciUsingForLoop(10);
    
    return 0;
}
