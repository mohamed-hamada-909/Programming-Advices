#include <iostream>
#include <iomanip>

using namespace std;

void PrintMatrix(int matrix[3][3], short row, short col)
{
	for (short i = 0; i < row; i++)
	{
		for (short j = 0; j < col; j++)
		{
			cout << setw(3) << matrix[i][j] << "   ";
		}
		cout << "\n";
	}
}

short CountNumInMatrix(int matrix[3][3],short num, short row, short col)
{
	short counter = 0;

	for (short i = 0; i < row; i++)
	{
		for (short j = 0; j < col; j++)
		{
			if (matrix[i][j] == num)
			{
				counter++;
			}
		}
	}
	return counter;
}

int main()
{
    int Matrix1[3][3] = { {9,1,12},{0,9,1},{0,9,9} };

	PrintMatrix(Matrix1, 3, 3);

	short num;
	cout << "Enter Number to Count in Matrix?\n";
	cin >> num;

	cout << "Number " << num << " Count in Matrix is: " << CountNumInMatrix(Matrix1, num, 3, 3);
	cout << "\n";

    return 0;
}
