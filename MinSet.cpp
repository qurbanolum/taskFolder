#include "pch.h"
#include<stdlib.h>
#include<iostream>
#include<windows.h>
#include<time.h>
#include<random>
using namespace std;

int* zadacha(int* massiv1, int* massiv2, int razmer1, int razmer2, int& razmer3)
{
    int index1 = 0;
    int index2 = 0;

    int* massiv3 = new int[razmer1];

    while (index1 < razmer1 && index2 < razmer2)
    {
        if (massiv1[index1] == massiv2[index2])
        {
            massiv3[razmer3] = massiv1[index1];
            ++index1;
            ++index2;
            ++razmer3;
        }
        else if (massiv1[index1] < massiv2[index2])
        {
            ++index1;
        }
        else if (massiv1[index1] > massiv2[index2])
        {
            ++index2;
        }
    }
    return massiv3;
}

void dobavit(int* massiv, int razmer)
{
    for (int i = 0; i < razmer; ++i)
    {
        cout << "Vvedite znachenie dlya massiva:";
        cin >> massiv[i];
    }
    
}

void vivesti(int* massiv, int razmer)
{
    cout << "tretiy massiv:";
    for (int i = 0; i < razmer; ++i)
    {
        cout << massiv[i] << ' ';
    }
}

void sortivrovka(int* massiv, int razmer) {
    for (int i = 0; i < razmer; i++) {
        for (int j = 0; j < razmer - 1; j++) {
            if (massiv[j] > massiv[j + 1]) {
                int temp = massiv[j];
                massiv[j] = massiv[j + 1];
                massiv[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int razmer1, razmer2;
    cout << "Vvedite razmer 1 massiva:";
    cin >> razmer1;
    cout << endl << "Vvedite razmer 2 massiva:";
    cin >> razmer2;


    int* massiv1 = new int[razmer1];
    int* massiv2 = new int[razmer2];

    dobavit(massiv1, razmer1);
    dobavit(massiv2, razmer2);
    sortivrovka(massiv1, razmer1);
    sortivrovka(massiv2, razmer2);

    int razmer3 = 0;
    int* massiv3 = zadacha(massiv1, massiv2, razmer1, razmer2, razmer3);

    vivesti(massiv3, razmer3);
    
    delete[] massiv1;
    delete[] massiv2;
    delete[] massiv3;

    return 0;
}

