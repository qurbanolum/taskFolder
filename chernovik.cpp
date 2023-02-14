#include "pch.h"
/*#include <iostream>
using namespace std;

bool isEqual(int** array, int n)
{
    int a = array[0][0];
    int y = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i][i] == a)
            y++;
    }
    return (y == n);
}

void fun_plus(int** array, int n)
{
    int a = array[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            array[i][j] += a;
        }
    }

}

void ccout(int** array, int n)
{
    cout << "matrix T \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << array[i][j] << "\t";
        cout << endl;
    }
}
int** fill(int n)
{
    int** array = new int* [n];
    for (int i = 0; i < n; i++)
    {
        array[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> array[i][j];
        }
    }
    return array;
}

int main()
{
    int n;
    cin >> n;
    int** array;
    array = fill(n);
    if (isEqual(array, n))
        fun_plus(array, n), ccout(array, n);
    else
        cout << "Elements ne sovpadaut";
}*/