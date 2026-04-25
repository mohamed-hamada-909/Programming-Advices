#include <iostream>
#include <iomanip>
#include <cstdlib>

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
		cout << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];

	FillMatrix(arr, 3, 3);

	cout << "\nThe Following is a 3*3 Random Matrix:\n";

	PrintMatrix(arr, 3, 3);

	return 0;
}
