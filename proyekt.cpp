// proyekt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include<stdlib.h>
#include <iostream>
#include<windows.h>
#include<time.h>
using namespace std;

void swapellowka(int* a) {
	for (int i = 0, j = 9; i < 10; i++,j--) {
		if (i >= j) break;
		int temp = *(a+i);
		*(a + i) = *(a + j);
		*(a + j) = temp;

		
	}
}
//prosto comment
int main()
{
	int massiv[] = {1,2,3,4,5,6,7,8,9,10};
	swapellowka(massiv);
	for (int i = 0; i < 10; i++) {
		cout << massiv[i] << endl;
	}

}

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
