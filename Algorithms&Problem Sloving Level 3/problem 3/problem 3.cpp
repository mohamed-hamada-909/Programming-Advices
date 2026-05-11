#include <iostream>
#include <iomanip>

using namespace std;

int RandomNum(int from, int to)
{
    int randomnum = rand() % (to - from + 1) + from;
    return randomnum;
}

void FillMatrix(int arr[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = RandomNum(1, 100);
        }
    }
}

void PrintMatrix(int arr[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(3) << arr[i][j] << "    ";
        }
        cout << endl;
    }
}

int RowSum(int arr[3][3], short numofrow, short cols)
{
    int sum = 0;

    for (int i = 0; i < cols; i++)
    {
        sum += arr[numofrow][i];
    }
    return sum;
}

void SumMatrixInArray(int arr[3][3], int arrsum[3], short rows, short  cols)
{
    for (short i = 0; i < rows; i++)
    {
        arrsum[i] = RowSum(arr, i, cols);
    }
}

void PrintRowSumArray(int arr[3],short rows)
{
    cout << "\nThe Following are the Sum of Each Row in the Matrix:\n";

    for (short i = 0; i < rows; i++)
    {
        cout << "Row " << i + 1 << " Sum: " << arr[i] << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];
    int arrsum[3];

    FillMatrix(arr, 3, 3);

    cout << "The Following is a 3*3 Random Matrix:\n";
    PrintMatrix(arr, 3, 3);

    SumMatrixInArray(arr, arrsum, 3, 3);

    PrintRowSumArray(arrsum, 3);

    return 0;
}
