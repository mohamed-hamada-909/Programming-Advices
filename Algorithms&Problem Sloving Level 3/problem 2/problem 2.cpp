#include <iostream>
#include <iomanip>

using namespace std;

int RandomNum(int from, int to)
{
	int randomnum = rand() % (to - from + 1) + from;
	return randomnum;
}

void FillMatrix(int arr[3][3], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = RandomNum(1, 100);
		}
	}
}

void PrintMatrix(int arr[3][3], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(3) << arr[i][j] << "    ";
		}
		cout << "\n";
	}
}

int RowSum(int arr[3][3], short rownumber, short cols)
{
	int sum = 0;
	for (short i = 0; i < cols; i++)
	{
		sum += arr[rownumber][i];
	}
	return sum;
}

void PrintRowSum(int arr[3][3], int rows, int cols)
{
	cout << "\nThe Following are the Sum of Each Row in the Matrix: \n";

	for (int i = 0; i < rows; i++)
	{
		cout << "Row " << i + 1 << " Sum: " << RowSum(arr, i, cols) << endl;
	}
	cout << endl;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];

	FillMatrix(arr, 3, 3);

	cout << "The Following is a 3*3 Random Matrix\n";

	PrintMatrix(arr, 3, 3);

	PrintRowSum(arr, 3, 3);

	return 0;
}
