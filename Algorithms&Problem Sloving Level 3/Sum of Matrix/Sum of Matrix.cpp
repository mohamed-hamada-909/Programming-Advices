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

int PrintSum(int arr[3][3], short rows, short cols)
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

int main()
{
	srand((unsigned)time(NULL));

	int matrix1[3][3];

	FillMatrix(matrix1, 3, 3);

	cout << "Matrix 1\n";
	PrintMatrix(matrix1, 3, 3);

	cout << "Sum of Matrix is: " << PrintSum(matrix1, 3, 3);

	return 0;
}
