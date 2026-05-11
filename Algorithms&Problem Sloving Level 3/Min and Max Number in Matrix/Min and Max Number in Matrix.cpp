#include <iostream>
#include <iomanip>

using namespace std;

int RandomNum(int from, int to)
{
    int randomnum = rand() % (to - from + 1) + from;
    return randomnum;
}

void FillMatrix(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            matrix[i][j] = RandomNum(1, 100);
        }
    }
}

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << setw(3) << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
}

int PrintMinNum(int matrix[3][3], short rows, short cols)
{
    short min = matrix[0][0];

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
            }
        }
    }
    return min;
}

int PrintMaxNum(int matrix[3][3], short rows, short cols)
{
    int max = matrix[0][0];

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
            }
        }
    }
    return max;
}

int main()
{
    srand((unsigned)time(NULL));

    int matrix[3][3];

    FillMatrix(matrix, 3, 3);
    cout << "Matrix 1 : \n";
    PrintMatrix(matrix, 3, 3);

    cout << "\nMinimum Number is: " << PrintMinNum(matrix, 3, 3) << endl;
   
    cout << "\nMax Number is: " << PrintMaxNum(matrix, 3, 3) << endl;

    return 0;
}
