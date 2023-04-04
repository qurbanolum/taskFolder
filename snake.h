#pragma once
#include<stdlib.h>
#include "pch.h"
#include<iostream>
#include<windows.h>
#include<time.h>
#include<random>
#include<conio.h>
#include<ctime>
struct Coordinates {
	int X;
	int Y;
};
int mapSize[30][60];
int snakeMoveDirection;
int snakeSpeed;
int leaderBoard[5] = {};
using namespace std;
char mainMenu();
void cleanScreen();
void initFood(int mapHeight, int mapWidth);
void deleteFood(int mapHeight, int mapWidth);
void initMap(Coordinates snakeCoordinates[], int mapHeight, int mapWidth, int* snakeSize);
void showMap(int mapHeight, int mapWidth);
void snakeMove(int xDirection, int yDirection, Coordinates snakeCoordinates[], int* timeForFood, int* snakeScore, int* snakeSize, bool* snakeIsAlive);
void changeDirection(char button);
void updateGame(Coordinates snakeCoordinates[], int* timeForFood, int* snakeScore, int* snakeSize, bool* snakeIsAlive);
void writeLeaderboard(int leaderboard[5]);
void showLeaderBoard();
void readLeaderboard(int leaderboard[5]);
void addLeader(int score);
void game();
char mainMenu();