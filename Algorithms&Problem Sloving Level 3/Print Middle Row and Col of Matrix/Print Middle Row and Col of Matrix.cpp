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
		cout << endl;
	}
}

void PrintMiddleRow(int arr[3][3], short rows, short cols)
{
	short middlerow = rows / 2;

	for (short i = 0; i < rows; i++)
	{
		printf("%0*d  ", 2, arr[middlerow][i]);
	}
	cout << "\n";
}

void PrintMiddleCol(int arr[3][3], short rows, short cols)
{
	short middlecol = cols / 2;

	for (short i = 0; i < rows; i++)
	{
		printf("%0*d  ", 2, arr[i][middlecol]);
	}
	cout << "\n";
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];

	FillMatrix(arr, 3, 3);

	cout << "Matrix 1:\n";
	PrintMatrix(arr, 3, 3);

	cout << "\nMiddle Row of Matrix 1 is: \n";
	PrintMiddleRow(arr, 3, 3);

	cout << "\nMiddle Col of Matrix 1 is: \n";
	PrintMiddleCol(arr, 3, 3);

    return 0;
}
