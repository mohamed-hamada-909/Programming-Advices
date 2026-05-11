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

void MatrixResult(int matrix1[3][3], int matrix2[3][3], int matrixresult[3][3], short rows, short cols)
{
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols; j++)
		{
			matrixresult[i][j] = matrix1[i][j] * matrix2[i][j];
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int matrix1[3][3], matrix2[3][3], result[3][3];

	FillMatrix(matrix1, 3, 3);

	cout << "Matrix 1\n\n";
	PrintMatrix(matrix1, 3, 3);

	FillMatrix(matrix2, 3, 3);
	cout << "\nMatrix 2\n\n";
	PrintMatrix(matrix2, 3, 3);

	MatrixResult(matrix1, matrix2, result, 3, 3);
	cout << "\nResult\n\n";
	PrintMatrix(result, 3, 3);

	return 0;
}
