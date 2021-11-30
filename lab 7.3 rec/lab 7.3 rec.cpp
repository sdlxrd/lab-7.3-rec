#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
int ZeroElem(int** a, const int rowCount, const int colCount, int i, int j, int k, int nom, int max);


int main()
{
	srand((unsigned)time(NULL));
	int n;
	
	cout << "n = "; cin >> n;

	int rowCount = n;
	int colCount = n;
	int Low = -1;
	int High = 1;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	Create(a, rowCount, colCount, Low, High, 0, 0);
	Print(a, rowCount, colCount, 0, 0);

	cout << "j w max 0 = " << ZeroElem(a, rowCount, colCount, 0, 0, 0, 0, 0)+ 1 << endl;

	return 0;
}


void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < colCount - 1)
		Create(a, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
			Create(a, rowCount, colCount, Low, High, i + 1, 0);
		else
			cout << endl;
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
		Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}

int Zero(int** a, const int rowCount, const int colCount, int i, int j, int& k)
{
	

	if (a[i][j] == 0)
		k++;

	if (j < colCount - 1)
		return Zero(a, rowCount, colCount, i, j + 1, k);
	else 
	
		if (i < rowCount - 1)
			return Zero(a, rowCount, colCount, i + 1, 0, k);
		else 
			return k;
}

int Col(int** a, const int rowCount, const int colCount, int number, int maxk)
{
	
	if (colCount > 1) 
	{
		int number = 0;
		number = Col(a, rowCount, colCount - 1, number, maxk);
		if (a[rowCount][number] == 0)
		maxk++;

		return number;
	}
	return 0;

}

int ZeroElem(int** a, const int rowCount, const int colCount, int k, int nomr, int maxk, int j, int i)
{
	if (j < colCount)
	{

		if (i < rowCount)
		{
			if (a[i][j] == 0)
				k++;
			return ZeroElem(a, rowCount, colCount, k, nomr, maxk, j, i + 1);
		}

		if (k >= maxk)
		{
			maxk = k;
			nomr = j;
		}
		return ZeroElem(a, rowCount, colCount, 0, nomr, maxk, j + 1, 0);
	}
	return nomr;
}