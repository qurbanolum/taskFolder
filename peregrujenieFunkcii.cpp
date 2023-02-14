/*Написать перегруженные функции(int, double,
char) для выполнения следующих задач :
■ Инициализация квадратной матрицы;
■ Вывод матрицы на экран;
■ Определение максимального и минимального элемента
на главной диагонали матрицы;
■ Сортировка элементов по возрастанию отдельно для
каждой строки матрицы.*/
#include "pch.h"
#include<stdlib.h>
#include<iostream>
#include<windows.h>
#include<time.h>
using namespace std;
//funkciya dlya int
int matrix(int size, int massiv[5][5])
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << "Vvedite element massiva [" << i << "] [" << j << "] - "; cin >> massiv[i][j];
		}
	}
	int maximal = 0, minimal = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << massiv[i][j] << " ";
			maximal = ((i == j) && (maximal < massiv[i][j])) ? massiv[i][j] : maximal;
			minimal = ((i == j) && (minimal > massiv[i][j])) ? massiv[i][j] : minimal;
		}
		cout << endl;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size-1; k++) {
				if (massiv[j][k] > massiv[j][k + 1]) {
					int temp = massiv[j][k];
					massiv[j][k] = massiv[j][k + 1];
					massiv[j][k + 1] = temp;
				}
			}
		}
	}
	cout << "Otsortirovannie" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << massiv[i][j] << " ";
		}
		cout << endl;
	}
	return minimal, maximal;
}
//funkciya dlya double
double matrix(int size, double massiv[5][5])
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << "Vvedite element massiva [" << i << "] [" << j << "] - "; cin >> massiv[i][j];
		}
	}
	double maximal = 0, minimal = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << massiv[i][j] << " ";
			maximal = ((i == j) && (maximal < massiv[i][j])) ? massiv[i][j] : maximal;
			minimal = ((i == j) && (minimal > massiv[i][j])) ? massiv[i][j] : minimal;
		}
		cout << endl;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size - 1; k++) {
				if (massiv[j][k] > massiv[j][k + 1]) {
					int temp = massiv[j][k];
					massiv[j][k] = massiv[j][k + 1];
					massiv[j][k + 1] = temp;
				}
			}
		}
	}
	cout << "Otsortirovannie" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << massiv[i][j] << " ";
		}
		cout << endl;
	}
	return minimal, maximal;
}
//не смог придумать добавление, сравнение и сортировку для типа char
char matrix(int size, char massiv[5][5])
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			char simvol;
			cout << "Vvedite element massiva [" << i << "] [" << j << "] - "; cin >> simvol;
			strcpy_s(&massiv[i][j],1,&simvol);
		}
	}
	char maximal = 0, minimal = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << massiv[i][j] << " ";
			maximal = ((i == j) && ((int)maximal < (int)massiv[i][j])) ? massiv[i][j] : maximal;
			minimal = ((i == j) && ((int)minimal > (int)massiv[i][j])) ? massiv[i][j] : minimal;
		}
		cout << endl;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size - 1; k++) {
				if ((int)massiv[j][k] > (int)massiv[j][k + 1]) {
					int temp = massiv[j][k];
					massiv[j][k] = massiv[j][k + 1];
					massiv[j][k + 1] = temp;
				}
			}
		}
	}
	cout << "Otsortirovannie" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << massiv[i][j] << " ";
		}
		cout << endl;
	}
	return minimal, maximal;
}

int main() {
	int massiv[5][5];
	matrix(5, massiv);
	return 0;
}