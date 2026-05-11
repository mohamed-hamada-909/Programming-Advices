#include <iostream>
#include <iomanip>

using namespace std;

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols; j++)
		{
			cout << setw(3) << matrix[i][j] << "   ";
		}
		cout << "\n";
	}
}

bool IsScalarMarix(int matrix[3][3], short rows, short cols)
{
	int firstelement = matrix[0][0];

	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols; j++)
		{
			if (i == j && matrix[i][j] !=firstelement)
			{
				return false;
			}
			else if (i != j && matrix[i][j] != 0)
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	int matrix[3][3] = { {9,0,0},{0,9,0},{ 0,0,9 } };

	cout << "Matrix 1:\n";
	PrintMatrix(matrix, 3, 3);

	if (IsScalarMarix(matrix, 3, 3))
	{
		cout << "\nYes: Matrix is Scalar\n";
	}
	else
	{
		cout << "\nNo: Matrix is NOT Scalar\n";
	}

    return 0;
}
