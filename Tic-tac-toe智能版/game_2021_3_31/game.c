#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
int rel = 0;
//打印分割行函数
void DividingLine(int x)
{
	int i;
	for(i=0; i<x; i++)
	{
		printf("---");
		if(i != x-1)
			printf("|");
	}
	printf("\n");
}
//初始化棋盘函数
void InitBoard(char str[ROW][LINE],int x,int y)
{
	int i, j;
	for(i=0; i<x; i++)
	{
		for(j=0; j<y; j++)
			str[i][j] = ' ';
	}
}
//打印棋盘函数
void DisplayBoard(char str[ROW][LINE], int x, int y)
{
	int i, j;
	for(i=0; i<x; i++)
	{
		//打印数据
		for(j=0; j<y; j++)
		{
			printf(" %c ",str[i][j]);
			if(j != y-1)
				printf("|");
		}
		printf("\n");
		//打印分割行
		if(i != x-1)
			DividingLine(LINE);
		//printf("\n");
	}
}
//玩家下棋
void PlayerMove(char str[ROW][LINE], int x, int y)
{
	int i, j;
	while(1)
	{
		printf("请输入您想下的位置坐标(先行后列):\n");
		scanf("%d%d",&i,&j);
		//判断坐标合理性
		if((i>=1 && i<=x)&&(j>=1 && j<=y))
		{
			if(str[i-1][j-1] != ' ')
				printf("此位置已经下过，请重新输入!\n");
			else
			{
				str[i-1][j-1]='*';
				break;
			}
		}
		else
			printf("输入错误，请重新输入!\n");
	}
}
//电脑下棋
void ComputerMove(char str[ROW][LINE], int x, int y)
{
	printf("电脑下：\n");
	while(1)
	{
		rel = 0;
		//电脑行判断
		ComputerRow(str,x,y);
		//判断电脑是否下棋
		if (rel == 1)
			break;//电脑下棋，退出下棋循环
		//否则继续运行
		//电脑列判断
		ComputerLine(str,x,y);
		//判断电脑是否下棋
		if(rel == 1)
			break;//电脑下棋，退出下棋循环
		//否则继续运行
		//电脑对角判断
		if(str[1][1] == '#')
		{
			if((str[0][2]== '#' && str[2][0] == ' ') || (str[0][2]== ' ' && str[2][0] == '#'))
			{
				str[0][2] = '#';
				str[2][0] = '#';
				break;
			}
			if((str[0][0]== '#' && str[2][2]==' ')||(str[0][0]== ' ' && str[2][2]=='#'))
			{
				str[0][0] = '#';
				str[2][2] = '#';
				break;
			}
		}
		if(((str[0][0] == str[2][2] && str[0][0] == '#') || (str[0][2] == str[2][0] && str[0][2] == '#')) && (str[1][1] == ' '))
		{
			str[1][1] = '#';
			break;
		}
		//玩家行判断
		PlayerRow(str,x,y);
		//判断电脑是否下棋
		if (rel == 1)
			break;//电脑下棋，退出下棋循环
		//否则继续运行
		//玩家列判断
		PlayerLine(str,x,y);
		//判断电脑是否下棋
		if(rel == 1)
			break;//电脑下棋，退出下棋循环
		//否则继续运行
		//玩家对角判断
		if(str[1][1] == '*')
		{
			if(str[0][2]== '*' && str[2][0] == ' ')
			{
				str[2][0] = '#';
				break;
			}
			if(str[0][2]== ' ' && str[2][0] == '*')
			{
				str[0][2] = '#';
				break;
			}
			if(str[0][0]== '*' && str[2][2]==' ')
			{
				str[2][2] = '#';
				break;
			}
			if(str[0][0]== ' ' && str[2][2]=='*')
			{
				str[0][0] = '#';
				break;
			}
		}
		if(((str[0][0] == str[2][2] && str[0][0] == '*') || (str[0][2] == str[2][0] && str[0][2] == '*')) && (str[1][1] == ' '))
		{
			str[1][1] = '#';
			break;
		}
		if(str[ROW/2][LINE/2] == ' ')
		{
			str[ROW/2][LINE/2] = '#';
			break;
		}
		//电脑随机
		Computer(str,x,y);
		if(rel == 1)
			break;//电脑下棋，退出下棋循环
	}
}
//判断函数
char IsWin(char str[ROW][LINE], int x, int y, int z)
{
	int i;
	for(i=0; i<x; i++)
	{
		if(str[i][0] == str[i][1] && str[i][1] ==str[i][2] && str[i][0] != ' ')
			return 'w';
	}
	for(i=0; i<y; i++)
	{
		if(str[0][i] == str[1][i] && str[1][i]  == str[2][i] && str[0][i] != ' ')
			return 'w';
	}
	if((str[0][0] == str[1][1] && str[1][1] == str[2][2] && str[0][0] != ' ')||(str[0][2] == str[1][1] && str[1][1] == str[2][0] && str[0][2] != ' '))
		return 'w';
	if(z == x * y)
		return 'p';
}
//电脑行判断
void ComputerRow(char str[ROW][LINE], int x, int y)
{
	int i, j;
	for(i=0; i<x; i++)
	{
		if((str[i][0] == str[i][1] && str[i][0]== '#') || (str[i][1] ==str[i][2] && str[i][1]== '#') || (str[i][0] ==str[i][2] && str[i][0]== '#'))
		{
			for(j=0; j<y; j++)
			{
				if(str[i][j] == ' ')
				{
					str[i][j] = '#';
					rel = 1;
					break;
				}
			}
		}
		if(rel == 1)
			break;
	}
}
//电脑列判断
void ComputerLine(char str[ROW][LINE], int x, int y)
{
	int i, j;
	for(j=0; j<y; j++)
	{
		if((str[0][j] == str[1][j] && str[0][j] == '#') || (str[1][j]  == str[2][j] && str[1][j] == '#') || (str[0][j]  == str[2][j] && str[0][j] == '#'))
		{
			for(i=0; i<x; i++)
			{
				if(str[i][j] == ' ')
				{
					str[i][j] = '#';
					rel = 1;
					break;
				}
			}
		}
		if(rel == 1)
			break;
	}
}
//玩家行判断
void PlayerRow(char str[ROW][LINE], int x, int y)
{
	int i, j;
	for(i=0; i<x; i++)
	{
		if((str[i][0] == str[i][1] && str[i][0]== '*') || (str[i][1] ==str[i][2] && str[i][1]== '*') || (str[i][0] ==str[i][2] && str[i][0]== '*'))
		{
			for(j=0; j<y; j++)
			{
				if(str[i][j] == ' ')
				{
					str[i][j] = '#';
					rel = 1;
					break;
				}
			}
		}
		if(rel == 1)
			break;
	}
}
//玩家列判断
void PlayerLine(char str[ROW][LINE], int x, int y)
{
	int i, j;
	for(j=0; j<y; j++)
	{
		if((str[0][j] == str[1][j] && str[0][j] == '*') || (str[1][j]  == str[2][j] && str[1][j] == '*') || (str[0][j]  == str[2][j] && str[0][j] == '*'))
		{
			for(i=0; i<x; i++)
			{
				if(str[i][j] == ' ')
				{
					str[i][j] = '#';
					rel = 1;
					break;
				}
			}
		}
		if(rel == 1)
			break;
	}
}
//电脑随机
void Computer(char str[ROW][LINE], int x, int y)
{
	int i, j;
	srand((unsigned int)time(NULL));
	while(1)
	{
		i = rand() % x;
		j = rand() % y;
		if(str[i][j] == ' ')
		{
			str[i][j] = '#';
			rel = 1;
			break;
		}
	}
}