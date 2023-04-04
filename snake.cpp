#include "pch.h"
#include "snake.h"
void cleanScreen() {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
}

void initFood(int mapHeight, int mapWidth) {
	int x, y;
	srand(time(NULL));
	do {
		x = rand() % (mapHeight - 1) + 1;
		y = rand() % (mapWidth - 1) + 1;
	} while (mapSize[x][y] != 0);
	mapSize[x][y] = -2;
}

void deleteFood(int mapHeight, int mapWidth) {
	for (int i = 0; i < mapHeight; i++) {
		for (int k = 0; k < mapWidth; k++) {
			if (mapSize[i][k] == -2) {
				mapSize[i][k] = 0;
				break;
			}
		}
	}
	initFood(30, 60);
}

void initMap(Coordinates snakeCoordinates[], int mapHeight, int mapWidth, int* snakeSize) {
	snakeCoordinates[0].X = 15;
	snakeCoordinates[0].Y = 30;
	snakeCoordinates[1].X = 15;
	snakeCoordinates[1].Y = 31;
	snakeCoordinates[2].X = 15;
	snakeCoordinates[2].Y = 32;
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
	for (int i = 0; i < *snakeSize; i++) {
		mapSize[snakeCoordinates[i].X][snakeCoordinates[i].Y] = 1;
	}

	initFood(30, 60);
}

void showMap(int mapHeight, int mapWidth) {
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

void snakeMove(int xDirection, int yDirection, Coordinates snakeCoordinates[], int* timeForFood, int* snakeScore, int* snakeSize, bool* snakeIsAlive) {
	int tailX;
	int tailY;
	tailX = snakeCoordinates[*snakeSize - 1].X;
	tailY = snakeCoordinates[*snakeSize - 1].Y;
	for (int i = 1; i < *snakeSize; i++) {
		snakeCoordinates[*snakeSize - i].X = snakeCoordinates[*snakeSize - (i + 1)].X;
		snakeCoordinates[*snakeSize - i].Y = snakeCoordinates[*snakeSize - (i + 1)].Y;
	}
	snakeCoordinates[0].X = snakeCoordinates[0].X + xDirection;
	snakeCoordinates[0].Y = snakeCoordinates[0].Y + yDirection;

	*timeForFood += snakeSpeed;
	if ((*timeForFood % 10000) == 0) {
		initFood(30, 60);
	}
	else if (((*timeForFood % 7000) == 0)) {
		deleteFood(30, 60);
	}

	if (mapSize[snakeCoordinates[0].X][snakeCoordinates[0].Y] == -2) {
		deleteFood(30, 60);
		*snakeScore += 100;
		*snakeSize = *snakeSize + 1;
		snakeSpeed = snakeSpeed > 50 ? snakeSpeed - 50 : snakeSpeed;
	}
	else if (mapSize[snakeCoordinates[0].X][snakeCoordinates[0].Y] != 0) {
		*snakeIsAlive = false;
	}


	for (int i = 0; i < *snakeSize; i++) {
		mapSize[snakeCoordinates[i].X][snakeCoordinates[i].Y] = 1;
	}
	mapSize[tailX][tailY] = 0;

}

void changeDirection(char button) {
	switch (button) {
	case 'w':
	case 'W':
	case 72:
		snakeMoveDirection = 1;
		break;
	case 'd':
	case 'D':
	case 77:
		snakeMoveDirection = 2;
		break;
	case 's':
	case 'S':
	case 80:
		snakeMoveDirection = 3;
		break;
	case 'a':
	case 'A':
	case 75:
		snakeMoveDirection = 4;
		break;
	}
}

void updateGame(Coordinates snakeCoordinates[], int* timeForFood, int* snakeScore, int* snakeSize, bool* snakeIsAlive) {
	switch (snakeMoveDirection) {
	case 1:
		snakeMove(-1, 0, snakeCoordinates, timeForFood, snakeScore, snakeSize, snakeIsAlive);
		break;
	case 2:
		snakeMove(0, 1, snakeCoordinates, timeForFood, snakeScore, snakeSize, snakeIsAlive);
		break;
	case 3:
		snakeMove(1, 0, snakeCoordinates, timeForFood, snakeScore, snakeSize, snakeIsAlive);
		break;
	case 4:
		snakeMove(0, -1, snakeCoordinates, timeForFood, snakeScore, snakeSize, snakeIsAlive);
		break;
	}
}

void writeLeaderboard(int leaderboard[5]) {
	FILE* file = fopen("leaderboard.txt", "w");
	if (file == NULL) {
		printf("Error opening file.\n");
		return;
	}
	for (int i = 0; i < 5; i++) {
		fprintf(file, "%d\n", leaderboard[i]);
	}
	fclose(file);
}

void showLeaderBoard() {
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << ":" << leaderBoard[i] << endl;
	}
	system("pause");
	mainMenu();
}
void readLeaderboard(int leaderboard[5]) {
	FILE* file = fopen("leaderboard.txt", "r");
	if (file == NULL) {
		printf("Error opening file.\n");
		return;
	}
	for (int i = 0; i < 5; i++) {
		fscanf(file, "%d", &leaderboard[i]);
	}
	fclose(file);
}

void addLeader(int score) {
	for (int i = 0; i < 5; i++) {
		if (leaderBoard[i] == 0) {
			leaderBoard[i] = score;
			break;
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (leaderBoard[i] < leaderBoard[j]) {
				int temp = leaderBoard[i];
				leaderBoard[i] = leaderBoard[j];
				leaderBoard[j] = temp;
			}
		}
	}
	writeLeaderboard(leaderBoard);
}

void game() {
	cout << "Select dificulty:" << endl;
	cout << "1:Easy" << endl << "2:Normal" << endl << "3:Hard" << endl;
	int choice;
	cin >> choice;

	switch (choice) {
	case 1: snakeSpeed = 300;
		break;
	case 2:	snakeSpeed = 200;
		break;
	case 3:	snakeSpeed = 100;
		break;
	default: snakeSpeed = 300;
	}
	int timeForFood = 0;
	int snakeScore = 0;
	int snakeSize = 3;
	Coordinates snakeCoordinates[100] = {};
	initMap(snakeCoordinates, 30, 60, &snakeSize);
	bool snakeIsAlive = true;
	while (snakeIsAlive) {
		if (_kbhit()) {
			changeDirection(_getch());
		}
		updateGame(snakeCoordinates, &timeForFood, &snakeScore, &snakeSize, &snakeIsAlive);
		cleanScreen();
		showMap(30, 60);
		Sleep(snakeSpeed);
	}
	addLeader(snakeScore);
	mainMenu();
}



char mainMenu() {
	cleanScreen();
	readLeaderboard(leaderBoard);
	cout << "Press N to New Game." << endl << "Press L to Leader Board." << endl << "Press X to Exit" << endl;
	char choice;
	choice = _getch();
	while (choice != 'n' && choice != 'l' && choice != 'x' && choice != 'N' && choice != 'L' && choice != 'X') {
		cout << "Invalid input. Please enter 'n', 'l', or 'x': " << endl;
		choice = _getch();
	}
	if (choice == 'n' || choice == 'N') game();
	else if (choice == 'l' || choice == 'L') showLeaderBoard();
	else if (choice == 'x' || choice == 'X') exit(0);
}