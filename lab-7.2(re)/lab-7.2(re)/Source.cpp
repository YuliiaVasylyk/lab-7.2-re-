// Lab_07_2(re).cpp
// <Василик Юлія>
// Лабораторна робота №7.2(рекурсивний спосіб)
// Опрацювання багатовимірних масивів
// Варіант 2


#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount,
	const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < colCount - 1)
		Create(a, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
			Create(a, rowCount, colCount, Low, High, i + 1, 0);
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

int Max(int** a, const int n, int i, int j, int max)
{
	if (a[i][j] > max)
		max = a[i][j];
	if (j < n - 1)
		return Max(a, n, i, j + 1, max);
	else
		return max;
}

int SumMax(int** a, const int k, const int n, int i, int s, int max)
{
	max = Max(a, n, i, 0, a[0][0]);
	s += max;
	if (i < k - 1)
		return SumMax(a, k, n, i + 1, s, max);
	else
		return s;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned)time(NULL));
	int Low, High;
	cout << "Low = "; cin >> Low;
	cout << "High = "; cin >> High;
	int k, n;
	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;

	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];
	Create(a, k, n, Low, High, 0, 0);
	cout << "a[" << k << "][" << n << "] = " << endl;
	Print(a, k, n, 0, 0);

	cout << "Сума максимальних елементів по всіх рядках матриці = " << SumMax(a, k, n, 0, 0, a[0][0]) << endl;

	for (int i = 0; i < k; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}

