//Написать функцию, которая получает указатель
//на статический массив и его размер.Функция распределяет положительные, 
//отрицательные и нулевые элементы
//в отдельные динамические массивы.
//#include<stdlib.h>
#include "pch.h"
//#include<iostream>
//#include<windows.h>
//#include<time.h>
//#include<random>
//using namespace std;
//
//int* positiveMassive;
//int* negativeMassive;
//int* zeroMassive;
//int* funcSeparate(int* massive, int size) {
//	int sizePositive = 0;
//	int sizeNegative = 0;
//	int sizeZero = 0;
//	for (int i = 0; i < size; i++) {
//		if (massive[i] > 0) sizePositive++;
//		else if (massive[i] < 0) sizeNegative++;
//		else sizeZero++;
//	}
//	positiveMassive = new int[sizePositive];
//	negativeMassive = new int[sizeNegative];
//	zeroMassive = new int[sizeZero];
//	for (int i = 0; i < size; i++) {
//		if (massive[i] > 0) positiveMassive[i] = massive[i];
//		else if (massive[i] < 0) negativeMassive[i] = massive[i];
//		else zeroMassive[i] = massive[i];
//	}
//	return positiveMassive, negativeMassive, zeroMassive;
//}
//
//int main() {
//	int size = 10;
//	int* spisok = new int[size];
//	for (int i = 0; i < size; i++) {
//		cout << "Vvedi znachenie dlya spiska";
//		int znachenie;
//		cin >> znachenie;
//		spisok[i] = znachenie;
//	}
//	funcSeparate(spisok, size);
//	for (int i = 0; i < sizeof(positiveMassive)/sizeof(int); i++) cout << "Znachenie polojitelnie" << positiveMassive[i] << endl;
//	for (int i = 0; i < sizeof(negativeMassive) / sizeof(int); i++) cout << "Znachenie polojitelnie" << negativeMassive[i] << endl;
//	for (int i = 0; i < sizeof(zeroMassive) / sizeof(int); i++) cout << "Znachenie polojitelnie" << zeroMassive[i] << endl;
//}