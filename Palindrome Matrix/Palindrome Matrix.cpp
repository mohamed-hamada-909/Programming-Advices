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
			matrix[i][j] = RandomNum(1, 10);
		}
	}
}

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols; j++)
		{
			cout << setw(2) << matrix[i][j] << "\t";
		}
		cout << "\n";
	}
}

bool IsPalindromeMatrix(int matrix[3][3], short rows, short cols)
{
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols / 2; j++)
		{
			if (matrix[i][j] != matrix[i][cols - 1 - j])
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	srand((unsigned)time(NULL));

	int matrix[3][3];

	FillMatrix(matrix, 3, 3);
	cout << "Matrix 1 \n";
	PrintMatrix(matrix, 3, 3);

	if (IsPalindromeMatrix(matrix, 3, 3))
	{
		cout << "\nYes, Matrix is Palindrome\n";
	}
	else
	{
		cout << "\nNo, Matrix is NOT Palindrome\n";
	}

	return 0;
}
