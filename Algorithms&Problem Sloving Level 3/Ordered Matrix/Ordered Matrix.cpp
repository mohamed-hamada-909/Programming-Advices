#include <iostream>
#include <iomanip>

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
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "   ";
		}
		cout << endl;
	}
}

int main()
{
	int arr[3][3];

	FillMatrix(arr, 3, 3);

	cout << "\nThe following is a 3x3 ordered matrix:\n";

	PrintMatrix(arr, 3, 3);


	return 0;
}
