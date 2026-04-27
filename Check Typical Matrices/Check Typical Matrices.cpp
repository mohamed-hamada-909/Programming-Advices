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
		cout << "\n";
	}
}

bool AreTypicalMatrices(int Matrix1[3][3], int Matrix2[3][3], short rows, short cols)
{
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols; j++)
		{
			if (Matrix1[i][j] != Matrix2[i][j])
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

	int arr[3][3], arr2[3][3];

	FillMatrix(arr, 3, 3);
	cout << " Matrix 1: \n";
	PrintMatrix(arr, 3, 3);

	FillMatrix(arr2, 3, 3);
	cout << "\n Matrix 2: \n";
	PrintMatrix(arr2, 3, 3);

	if (AreTypicalMatrices(arr, arr, 3, 3))
	{
		cout << "\nYES: both martices are typical.\n";
	}
	else
	{
		cout << "\nNo: martices are NOT typical.\n";
	}

	return 0;
}
