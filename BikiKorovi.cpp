#include "pch.h"
#include<stdlib.h>
#include<iostream>
#include<windows.h>
#include<time.h>
#include <random>
using namespace std;

void bikiKorovi(int chislo) {
	int biki = 0, korovi = 0;
	int slCifri[4];
	slCifri[0] = chislo / 1000;
	slCifri[1] = chislo % 1000 / 100;
	slCifri[2] = chislo % 100 / 10;
	slCifri[3] = chislo % 10;
	/*for (int i = 0; i < 4; i++) {
		cout << slCifri[i] << endl;
	}*/
	int naweChislo;
	cout << "Vvedite 4 znachnoe chislo" << endl; 
	cin >> naweChislo;
	int nawiCifri[4];
	nawiCifri[0] = naweChislo / 1000;
	nawiCifri[1] = naweChislo % 1000 / 100;
	nawiCifri[2] = naweChislo % 100 / 10;
	nawiCifri[3] = naweChislo % 10;
	
	for (int i = 0; i < 4; i++) {
		cout << nawiCifri[i] << endl;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if ((nawiCifri[i] == slCifri[j]) && (i==j)) {
				biki += 1;
				break;
			}
			else if ((nawiCifri[i] == slCifri[j]) && (nawiCifri[j] != nawiCifri[j-1])) {
				korovi += 1;
				break;
			}
		}
	}
	if (biki == 4){
		cout << "Pozdravlyayu vi nawli vsex bikov";
	}
	else {
		cout << "Kolichestvo bikov " << biki << endl;
		cout << "Kolichestvo korov " << korovi << endl;
		bikiKorovi(chislo);
	}
}

int main() {
	random_device random_device;
	mt19937 generator(random_device());
	uniform_int_distribution<> distribution(1000, 10000);
	int slChislo = distribution(generator);
	cout << slChislo << endl;
	bikiKorovi(slChislo);
}