#include <iostream>

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
            matrix[i][j] = RandomNum(1, 99);
        }
    }
}

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            printf("%0*d  ", 2, matrix[i][j]);
        }
    cout << endl;
    }
}

short CountMatrix(int matrix[3][3],short num, short row, short cols)
{
    int count = 0;

    for (short i = 0; i < row; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (matrix[i][j] == num)
            {
                count++;
            }
        }
    }
    return count;
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

int main()
{
    srand((unsigned)time(NULL));

    int matrix[3][3];

    FillMatrix(matrix, 3, 3);
    cout << "Matrix 1: \n";
    PrintMatrix(matrix, 3, 3);

    int num;
    cout << "Please Enter The Number to Look for in Matrix\n";
    cin >> num;

    //using counter is a slower method
    if (CountMatrix(matrix, num, 3, 3) > 0)
    {
        cout << "\nYes, it is there\n";
    }
    else
    {
        cout << "\nNo, it's NOT there\n";
    }

    //this is a faster method
    if (IsNumInMatrix(matrix,num, 3, 3))
    {
        cout << "\nYes, it is there\n";
    }
    else
    {
        cout << "\nNo, it's NOT there\n";
    }

    return 0;
}
