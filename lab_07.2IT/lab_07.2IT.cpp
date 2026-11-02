#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// Створення матриці
void Create(int** a, int rows, int cols, int low, int high)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            a[i][j] = low + rand() % (high - low + 1);
}

// Виведення матриці
void Print(int** a, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << setw(5) << a[i][j];

        cout << endl;
    }

    cout << endl;
}

// Пошук мінімального елемента рядка
int MinInRow(int** a, int row, int cols)
{
    int minimum = a[row][0];

    for (int j = 1; j < cols; j++)
        if (a[row][j] < minimum)
            minimum = a[row][j];

    return minimum;
}

// Сума мінімальних елементів усіх рядків
int SumRowMins(int** a, int rows, int cols)
{
    int sum = 0;

    for (int i = 0; i < rows; i++)
        sum += MinInRow(a, i, cols);

    return sum;
}

int main()
{
    srand((unsigned)time(0));

    // rows — кількість рядків, cols — кількість стовпців
    const int rows = 7;
    const int cols = 6;

    // Межі значень елементів матриці
    const int low = -20;
    const int high = 30;

    int** a = new int* [rows];

    for (int i = 0; i < rows; i++)
        a[i] = new int[cols];

    Create(a, rows, cols, low, high);

    cout << "Matrix:" << endl;
    Print(a, rows, cols);

    int sum = SumRowMins(a, rows, cols);

    cout << "Sum of row minimums = " << sum << endl;

    for (int i = 0; i < rows; i++)
        delete[] a[i];

    delete[] a;

    return 0;
}