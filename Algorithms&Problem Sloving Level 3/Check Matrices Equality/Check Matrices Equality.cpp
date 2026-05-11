#include <iostream>

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
            arr[i][j] = RandomNum(1, 10);
        }
    }
}

void PrintMatrix(int arr[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            printf("%0*d  ", 2, arr[i][j]);
        }
        cout << endl;
    }
}

int SumMatrix(int arr[3][3], short rows, short cols)
{
    int sum = 0;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}

bool AreEqualMatrices(int arr[3][3], int arr2[3][3], short rows, short cols)
{
    return (SumMatrix(arr, rows, cols) == SumMatrix(arr2, rows, cols));
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];
    int arr2[3][3];

    FillMatrix(arr, 3, 3);
    cout << "  Matrix 1 \n";
    PrintMatrix(arr, 3, 3);

    FillMatrix(arr2, 3, 3);
    cout << "\n  Matrix 2 \n";
    PrintMatrix(arr2, 3, 3);

    if (AreEqualMatrices(arr, arr2, 3, 3))
        cout << "\nYES: both martices are equal.\n";
    else
        cout << "\nNo: martices are NOT equal.\n";

    return 0;
}
