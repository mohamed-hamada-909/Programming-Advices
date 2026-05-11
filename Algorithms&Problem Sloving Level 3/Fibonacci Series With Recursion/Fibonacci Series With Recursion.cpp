#include <iostream>

using namespace std;

void PrintFibonacciUsingRecursion(int num, int prev1, int prev2)
{
    int febnum = 0;

    if (num > 0)
    {
        febnum = prev2 + prev1;

        prev2 = prev1;
        prev1 = febnum;

        cout << febnum << "   ";

        PrintFibonacciUsingRecursion(num - 1, prev1, prev2);
    }
}

int main()
{
    PrintFibonacciUsingRecursion(10, 0, 1);

    return 0;
}
