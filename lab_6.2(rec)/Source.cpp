#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <iostream>
#include <iomanip>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

int maxEven(int* a, const int size, int max, int i)
{
    if (a[i] > max && a[i] % 2 == 0)
        max = a[i];
    if (i < size - 1)
        return maxEven(a, size, max, i + 1);
    else
        return max;
}


int Find(int* a, const int size, const int x, int i)
{
    if (i == size - 1)
        return -1;
    if (a[i] == x)
        return i;
    else
        return  Find(a, size, x, i + 1);

}

int main()
{
    srand((unsigned)time(NULL));


    const int n = 20;
    int a[n];
    int low = -10;
    int high = 50;
    Create(a, n, low, high,0);

    cout << "==================================================================================" << endl;
    cout <<
        "|";
    for (int i = 0; i < n; i++)
    {
        cout << setw(3) << a[i] << " ";
    }
    cout << "|\n";
    cout << "==================================================================================" << endl;

    int MaxEven = maxEven(a, n, n - 1,0);

    cout << " |Max even number : " << MaxEven << " | " << endl;
    cout << " |Index of max even number : " << Find(a, n, MaxEven,0) << " | " << endl;

}