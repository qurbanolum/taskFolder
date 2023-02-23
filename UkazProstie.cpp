//Ќаписать функцию, котора€ получает указатель на динамический массив и его размер.‘ункци€
//должна удалить из массива все простые числа и вернуть
//указатель на новый динамический массив.


//#include<stdlib.h>
#include "pch.h"
//#include<iostream>
//#include<windows.h>
//#include<time.h>
//#include<random>
//using namespace std;
//
//int* exceptPrime(int* massive,int size) {
//	int* newDynMas = new int[size];
//	for (int i = 0; i < size; i++) {
//		newDynMas[i] = -1;
//	}
//    
//	for (int k = 0; k < size; k++) {
//		if (massive[k] == 0 || massive[k] == 1) {
//		}
//		else {
//			for (int i = 2; i <= massive[k] / 2; ++i) {
//				if (massive[k] % i == 0) {
//					newDynMas[k] = massive[k];
//					break;
//				}
//			}
//		}
//	}
//	int newSize = 0;
//	for (int i = 0; i < size; i++) {
//		if (newDynMas[i] != -1) {
//			newSize++;
//		}
//	}
//	int* newestDynMas = new int[newSize];
//	int newestDynMasIndex = 0;
//	for (int i = 0; i < size; i++) {
//		if (newDynMas[i] != -1) {
//			newestDynMas[newestDynMasIndex] = newDynMas[i];
//			newestDynMasIndex++;
//		}
//	}
//	return newestDynMas;
//}
//
//int main() {
//	int size = 10;
//	int* dynMas = new int[size];
//	for (int i = 0; i < size; i++) {
//		cout << "Enter value for list:";
//		int value;
//		cin >> value;
//		dynMas[i] = value;
//	}
//	dynMas = exceptPrime(dynMas, size);
//	for (int i = 0; i < sizeof(dynMas)/sizeof(dynMas[0]); i++) {
//		cout << dynMas[i] << endl;
//	}
//}