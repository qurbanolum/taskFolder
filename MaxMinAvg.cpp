//Написать программу, которая содержит функцию Action, принимающую в качестве аргумента,
//указатели на два массива(А и В) и размеры массивов, а также
//указатель на функцию.
//Пользователю отображается меню, в котором он
//может выбрать max, min, avg.Если выбран max — передается указатель на функцию, которая ищет максимум,
//если выбран min — передается указатель на функцию,
//которая ищет минимум, если выбран avg — передается
//указатель на функцию, которая ищет среднее.
//Возвращаемое значение функции Action результат
//выбора пользователя max, min, avg.

//#include<stdlib.h>
#include "pch.h"
//#include<iostream>
//#include<windows.h>
//#include<time.h>
//#include<random>
//using namespace std;
//
//int Action(int* mA, int* mB, int sizeA, int sizeB, int(*function)(int* m1, int* m2, int s1, int s2)) {
//	return function(mA, mB, sizeA, sizeB);
//}
//
//int Min(int* mA, int* mB, int sizeA, int sizeB) {
//	int minimal = 100;
//	for (int i = 0; i < sizeA; i++){
//		minimal = minimal > mA[i] ? mA[i] : minimal;
//	}
//	for (int i = 0; i < sizeB; i++) {
//		minimal = minimal > mB[i] ? mB[i] : minimal;
//	}
//	return minimal;
//}
//
//int Max(int* mA, int* mB, int sizeA, int sizeB) {
//	int maximal = 0;
//	for (int i = 0; i < sizeA; i++) {
//		maximal = maximal < mA[i] ? mA[i] : maximal;
//	}
//	for (int i = 0; i < sizeB; i++) {
//		maximal = maximal < mB[i] ? mB[i] : maximal;
//	}
//	return maximal;
//}
//
//int Avg(int* mA, int* mB, int sizeA, int sizeB) {
//	int average = 0;
//	int summ = 0;
//	for (int i = 0; i < sizeA; i++) {
//		summ += mA[i];
//	}
//	for (int i = 0; i < sizeB; i++) {
//		summ += mB[i];
//	}
//	average = summ / (sizeA + sizeB);
//	return average;
//}
//
//int main() {
//	srand(time(NULL));
//	int massiveAsize = 5;
//	int massiveBsize = 5;
//	int* massiveA = new int[massiveAsize];
//	int* massiveB = new int[massiveBsize];
//	for (int i = 0; i < massiveAsize; i++) {
//		massiveA[i] = rand() % 100;
//		cout << massiveA[i] << "\n";
//	}
//	for (int i = 0; i < massiveBsize; i++) {
//		massiveB[i] = rand() % 100;
//		cout << massiveB[i] << "\n";
//	}
//	int choose;
//	int answer;
//	cout << "1:min, 2:max, 3:avg";
//	cin >> choose;
//	switch (choose)
//	{
//	case 1:
//		answer = Action(massiveA, massiveB, massiveAsize, massiveBsize, Min);
//		break;
//	case 2:
//		answer = Action(massiveA, massiveB, massiveAsize, massiveBsize, Max);
//		break;
//	case 3:
//		answer = Action(massiveA, massiveB, massiveAsize, massiveBsize, Avg);
//		break;
//	}
//	cout << answer;
//}