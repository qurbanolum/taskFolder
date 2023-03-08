#include<stdlib.h>
#include "pch.h"
#include<iostream>
#include<windows.h>
#include<time.h>
#include<random>
#include<conio.h>
#include<ctime>
using namespace std;
//Map parameters
const int mapWidth = 60;
const int mapHeight = 30;
int mapSize[mapHeight][mapWidth];
//Snake parameters
int snakeXpos[mapWidth * mapHeight];
int snakeYpos[mapWidth * mapHeight];
int snakeMoveDirection;
int snakeSize = 3;
int snakeSpeed = 300;
bool snakeIsAlive;
int snakeScore = 0;
int leaderBoard[5] = {};
int timeForFood = 0;
char mainMenu();

void cleanScreen() {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
}

void initFood() {
	int x, y;
	srand(time(NULL));
	do {
		x = rand() % (mapHeight - 1) + 1;
		y = rand() % (mapWidth - 1) + 1;
	} while (mapSize[x][y] != 0);
	mapSize[x][y] = -2;
}

void deleteFood() {
	for (int i = 0; i < mapHeight; i++) {
		for (int k = 0; k < mapWidth; k++) {
			if (mapSize[i][k] == -2) {
				mapSize[i][k] = 0;
				break;
			}
		}
	}
	initFood();
}

void initMap() {
	snakeXpos[0] = 15;
	snakeYpos[0] = 30;
	snakeXpos[1] = 15;
	snakeYpos[1] = 31;
	snakeXpos[2] = 15;
	snakeYpos[2] = 32;
	for (int i = 0; i < mapHeight; i++) {
		for (int k = 0; k < mapWidth; k++) {
			if (i == 0 || i == mapHeight - 1) {
				mapSize[i][k] = -1;
			}
			else if ((i != 0 || i != mapHeight - 1) && (k == 0 || k == mapWidth - 1)) {
				mapSize[i][k] = -1;
			}
			else {
				mapSize[i][k] = 0;
			}
		}
	}
	for (int i = 0; i < snakeSize; i++){
		mapSize[snakeXpos[i]][snakeYpos[i]] = 1;
	}
	
	initFood();
}

void showMap() {
	for (int i = 0; i < mapHeight; i++) {
		for (int k = 0; k < mapWidth; k++) {
			if (mapSize[i][k] == -1) {
				cout << "#";
			}
			else if (mapSize[i][k] == -2) {
				cout << "&";
			}
			else if (mapSize[i][k] == 0) {
				cout << " ";
			}
			else if (mapSize[i][k] == 1) {
				cout << "@";
			}
		}
		cout << endl;
	}
}

void snakeMove(int xDirection, int yDirection) {
	int tailX;
	int tailY;
	tailX = snakeXpos[snakeSize - 1];
	tailY = snakeYpos[snakeSize - 1];
	for (int i = 1; i < snakeSize; i++) {
		snakeXpos[snakeSize - i] = snakeXpos[snakeSize - (i + 1)];
		snakeYpos[snakeSize - i] = snakeYpos[snakeSize - (i + 1)];
	}
	snakeXpos[0] = snakeXpos[0] + xDirection;
	snakeYpos[0] = snakeYpos[0] + yDirection;

	timeForFood += snakeSpeed;
	if ((timeForFood % 10000) == 0) {
		initFood();
	}
	else if (((timeForFood % 7000) == 0)) {
		deleteFood();
	}

	if (mapSize[snakeXpos[0]][snakeYpos[0]] == -2) {
		deleteFood();
		snakeScore += 100;
		snakeSize++;
		snakeSpeed = snakeSpeed > 50 ? snakeSpeed - 50 : snakeSpeed;
	}
	else if (mapSize[snakeXpos[0]][snakeYpos[0]] != 0) {
		snakeIsAlive = false;
	}

	
	for (int i = 0; i < snakeSize; i++) {
		mapSize[snakeXpos[i]][snakeYpos[i]] = 1;
	}
	mapSize[tailX][tailY] = 0;
	
}

void changeDirection(char button) {
	switch (button) {
	case 'w':
		snakeMoveDirection = 1;
		break;
	case 'd':
		snakeMoveDirection = 2;
		break;
	case 's':
		snakeMoveDirection = 3;
		break;
	case 'a':
		snakeMoveDirection = 4;
		break;
	}
}

void updateGame() {
	switch (snakeMoveDirection) {
	case 1:
		snakeMove(-1,0);
		break;
	case 2:
		snakeMove(0,1);
		break;
	case 3:
		snakeMove(1,0);
		break;
	case 4:
		snakeMove(0,-1);
		break;
	}
}

void addLeader(int score) {
	for (int i = 0; i < 5; i++) {
		if (leaderBoard[i] < score) {
			leaderBoard[i] = score;
			break;
		}
	}
}

void game() {
	snakeSpeed = 300;
	initMap();
	snakeIsAlive = true;
	while (snakeIsAlive) {
		if (_kbhit()) {
			changeDirection(_getch());
		}
		updateGame();
		cleanScreen();
		showMap();
		Sleep(snakeSpeed);
	}
	addLeader(snakeScore);
	mainMenu();
}

void showLeaderBoard() {
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << ":" << leaderBoard[i] << endl;
	}
	system("pause");
}

char mainMenu() {
	cout << "Press N to New Game." << endl << "Press L to Leader Board." << endl << "Press X to Exit" << endl;
	char choice;
	choice = _getch();
	if (choice == 'n') game();
	else if (choice == 'l') showLeaderBoard();
	else if (choice == 'x') exit(0);
}

int main() {
	mainMenu();
	return 0;
}

