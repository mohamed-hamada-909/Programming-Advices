#include <iostream>
#include <iomanip>

using namespace std;

void PrintMatrix(int matrix[3][3], short row, short col)
{
	for (short i = 0; i < row; i++)
	{
		for (short j = 0; j < col; j++)
		{
			cout << setw(2) << matrix[i][j] << "   ";
		}
		cout << "\n";
	}
}

short CountNumInMatrix(int matrix[3][3],short num, short row, short col)
{
	short count = 0;

	for (short i = 0; i < row; i++)
	{
		for (short j = 0; j < col; j++)
		{
			if (matrix[i][j] == num)
			{
				count++;
			}
		}
	}
	return count;
}

bool IsSparseMatrix(int matrix[3][3], short row, short col)
{
	short matrixsize = row * col;

	return (CountNumInMatrix(matrix, 0, 3, 3) >= (matrixsize / 2));
}

int main()
{
	int Matrix1[3][3] = { {0,0,12},{0,0,1},{0,0,9} };

	cout << "Matrix1\n";
	PrintMatrix(Matrix1, 3, 3);

	if (IsSparseMatrix(Matrix1, 3, 3))
	{
		cout << "\nYes, it's Sparse\n";
	}
	else
	{
		cout << "\nNo, it's NOT Sparse\n";
	}

	return 0;
}
