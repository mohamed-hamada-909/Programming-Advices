#include <iostream>

using namespace std;

void FillMatrix(int arr[3][3], short rows, short cols)
{
	int counter = 0;

	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols; j++)
		{
			counter++;
			arr[i][j] = counter;
		}
	}
}

void PrintMatrix(int arr[3][3], short rows, short cols)
{
	for (short i = 0; i < rows; i++)
	{
		for (short  j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "    ";
		}
		cout << "\n";
	}
}

void TransposeMatrix(int arr[3][3], int arrTransposed[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arrTransposed[i][j] = arr[j][i];
		}
	}
}

int main()
{
	int arr[3][3];
	int arrTransposed[3][3];

	FillMatrix(arr, 3, 3);

	cout << "\nThe following is a 3x3 ordered matrix:\n";

	PrintMatrix(arr, 3, 3);

	TransposeMatrix(arr, arrTransposed, 3, 3);

	cout << "\n\nThe following is the transposed matrix:\n";
	PrintMatrix(arrTransposed, 3, 3);

	return 0;
}
