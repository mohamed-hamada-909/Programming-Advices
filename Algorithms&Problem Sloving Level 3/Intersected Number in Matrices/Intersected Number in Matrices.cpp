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
            cout << setw(3) << matrix[i][j] << "    ";
        }
        cout << "\n";
    }
}

bool IsNumInMatrix(int matrix[3][3], short num, short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (matrix[i][j] == num)
            {
                return true;
            }
        }
    }
    return false;
}

void PrintSameNum(int matrix1[3][3], int matrix2[3][3], short rows, short cols)
{
    int num;

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            num = matrix1[i][j];
            if (IsNumInMatrix(matrix2, num, rows, cols))
            {
                cout << setw(3) << num << "    ";
            }
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int matrix1[3][3], matrix2[3][3];

    FillMatrix(matrix1, 3, 3);
    cout << "Matrix 1\n";
    PrintMatrix(matrix1, 3, 3);

    FillMatrix(matrix2, 3, 3);
    cout << "\nMatrix 2 \n";
    PrintMatrix(matrix2, 3, 3);

    cout << "\nIntersected Number are:\n";
    PrintSameNum(matrix1, matrix2, 3, 3);

    return 0;
}
