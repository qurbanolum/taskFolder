#include<stdlib.h>
#include "pch.h"
#include<iostream>
#include<windows.h>
#include<time.h>
#include<random>
using namespace std;

int SAYZ;
int* dynMas;
int memory() {
	cout << "Vvedite razmer massiva:";
	cin >> SAYZ;
	dynMas = new int[SAYZ];
	return *dynMas;
}

void initialize() {
	cout << "Inicializaciya massiva->" << endl;
	for (int i = 0; i < SAYZ; i++) {
		cout << "Vvedite " << i << " element:" << endl;
		int element;
		cin >> element;
		dynMas[i] = element;
	}
}

void destroy(int* massiv) {
	delete[] massiv;
}

void show() {
	for (int i = 0; i < SAYZ; i++) {
		cout << "Element " << i << " = " << dynMas[i] << endl;
	}
}

void pushEnd() {
	cout << "Kakoe znachenie pribavit v konec massiva:";
	int element;
	cin >> element;
	int* newMas = new int[SAYZ + 1];
	for (int i = 0; i < SAYZ; i++) {
		newMas[i] = dynMas[i];
	}
	newMas[SAYZ] = element;
	dynMas = newMas;
	SAYZ++;
}

void pushIndex(int index, int element) {
	int newIndex = 0;
	cout << "Vstavlyayem znachenie v " << index << " index." << endl;
	int* newMas = new int[SAYZ + 1];
	for (int i = 0; i < SAYZ + 1; i++) {
		if (index == i) {
			newMas[i] = element;
			newIndex--;
		}
		else {
			newMas[i] = dynMas[newIndex];
		}
		newIndex++;
	}
	dynMas = newMas;
	SAYZ++;
}

void deleteIndex(int index) {
	int newIndex = 0;
	cout << "Udalyayem znachenie iz " << index << " indexa." << endl;
	int* newMas = new int[SAYZ - 1];
	for (int i = 0; i < SAYZ - 1; i++) {
		if (index == i) {
			newIndex++;
			newMas[i] = dynMas[newIndex];
			newIndex++;
		}
		else {
			newMas[i] = dynMas[newIndex];
			newIndex++;
		}
	}
	delete[] dynMas;
	dynMas = newMas;
	SAYZ--;
}

int main() {
	
	memory();
	initialize();
	show();
	pushEnd();
	show();
	pushIndex(3, 100);
	show();
	deleteIndex(3);
	show();
}
