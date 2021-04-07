//井字棋
#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void game()
{
	char win;
	int count = 0;//次数
	//定义数组存放用户的下棋的位置
	char board[ROW][LINE];
	printf("游戏开始\n");
	//初始化棋盘
	InitBoard(board, ROW, LINE);
	//打印棋盘
	DisplayBoard(board, ROW, LINE);
	//下棋
	while(1)
	{
		//玩家下棋
		PlayerMove(board, ROW, LINE);
		DisplayBoard(board, ROW, LINE);
		count ++;
		//判断玩家是否赢
		win = IsWin(board, ROW, LINE, count);
		Sleep(1000);
		if(win == 'w')
		{
			printf("YOU WIN！\n");
			break;
		}
		else if(win == 'p')
		{
			printf("The Game Is a Draw！\n");
			break;
		}
		//电脑下棋
		Sleep(1000);
		ComputerMove(board, ROW, LINE);
		Sleep(1000);
		DisplayBoard(board, ROW, LINE);
		count ++;
		//判断电脑是否赢
		win = IsWin(board, ROW, LINE, count);
		Sleep(1000);
		if(win == 'w')
		{
			printf("YOU LOSE！\n");
			break;
		}
		else if(win == 'p')
		{
			printf("The Game Is a Draw!\n");
			break;
		}
	}
}
//选择函数，继开始菜单之后用户做出选择
int Choose()
{
	int input;
	while(1)
	{
		printf("请选择:\n");
		scanf("%d",&input);
		switch(input)
		{
		case 1:
			return 1;
		case 2:
			printf("游戏规则如下:\n");
			printf("井字棋（Tic Tac Toe）是由德国人发明的三连棋游戏\n");
			printf("要求玩家轮流在一有九格方盘上划加字或圆圈，谁先把三个同一记号排成横线、直线、斜线，即是胜者！\n");
			printf("由于井字游戏规则简单易懂，在任何地方都可以玩，所以是有效打发时间的必备休闲游戏。\n");
			break;
		case 0:
			printf("退出游戏\n");
			return 0;
		default:
			printf("选择错误,");
			break;
		}
	}
}
//开始菜单函数
void menu()
{
	Sleep(1000);
	printf("************************************\n");
	printf("*********    Tic-tac-toe   *********\n");
	printf("**   1、Play   2、Rule   0、Exit  **\n");
	printf("************************************\n");
}
//测试函数
void test()
{
	while(1)
	{
		int choose;
		menu();
		choose = Choose();
		if(choose == 1)
			game();
		else if(choose == 0)
			break;
	}
}
int main()
{
	test();
	return 0;
}