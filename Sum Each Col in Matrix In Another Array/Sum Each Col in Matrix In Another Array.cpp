#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int RandomNum(int from, int to)
{
    int randomnum = rand() % (to - from + 1) + from;
    return randomnum;
}

void FillMatrix(int arr[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            arr[i][j] = RandomNum(1, 100);
        }
    }
}

void PrintMatrix(int arr[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << setw(3) << arr[i][j] << "    ";
        }
        cout << endl;
    }
}

int ColSum(int arr[3][3], short rows, short colsnum)
{
    int sum = 0;

    for (short i = 0; i < rows; i++)
    {
        sum += arr[i][colsnum];
    }
    return sum;
}

void SumColsInArray(int arr[3][3], int arrsum[3], short rows, short cols)
{
    for (short i = 0; i < cols; i++)
    {
        arrsum[i] = ColSum(arr, rows, i);
    }
}

void PrintSumInArray(int arr[3], short cols)
{
    cout << "\nThe Following are the Sum of Each Col in the Matrix: \n";

    for (short i = 0; i < cols; i++)
    {
        cout << "Col " << i + 1 << " Sum: " << arr[i] << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];
    int arrsum[3];

    FillMatrix(arr, 3, 3);

    cout << "The Following is a 3*3 Random Matrix\n";
    PrintMatrix(arr, 3, 3);

    SumColsInArray(arr, arrsum, 3, 3);

    PrintSumInArray(arrsum, 3);

    return 0;
}
