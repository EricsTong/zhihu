#pragma once
#define ROW 3
#define LINE 3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
void game();
void InitBoard(char str[ROW][LINE], int, int);
void DisplayBoard(char str[ROW][LINE], int, int);
void PlayerMove(char str[ROW][LINE], int, int);
void ComputerMove(char str[ROW][LINE], int, int);
char IsWin(char str[ROW][LINE], int, int, int);