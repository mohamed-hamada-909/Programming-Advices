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
        cout << "\n";
    }
}

int ColSum(int arr[3][3], short rows, short colsnum)
{
    int sum = 0;

    for (int i = 0; i < rows; i++)
    {
        sum += arr[i][colsnum];
    }
    return sum;
}

void PrintSumCols(int arr[3][3], short rows, short cols)
{
    cout << "\nThe Following are the sum of each col in the matrix: \n";

    for (int i = 0; i < cols; i++)
    {
        cout << "Col " << i + 1 << " Sum: " << ColSum(arr, rows, i) << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];

    FillMatrix(arr, 3, 3);

    cout << "The Following is a 3*3 Random Matrix: \n";
    PrintMatrix(arr, 3, 3);

    PrintSumCols(arr, 3, 3);



    return 0;
}
