#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
//��ӡ�ָ��к���
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
//��ʼ�����̺���
void InitBoard(char str[ROW][LINE],int x,int y)
{
	int i, j;
	for(i=0; i<x; i++)
	{
		for(j=0; j<y; j++)
			str[i][j] = ' ';
	}
}
//��ӡ���̺���
void DisplayBoard(char str[ROW][LINE], int x, int y)
{
	int i, j;
	for(i=0; i<x; i++)
	{
		//��ӡ����
		for(j=0; j<y; j++)
		{
			printf(" %c ",str[i][j]);
			if(j != y-1)
				printf("|");
		}
		printf("\n");
		//��ӡ�ָ���
		if(i != x-1)
			DividingLine(LINE);
		//printf("\n");
	}
}
//�������
void PlayerMove(char str[ROW][LINE], int x, int y)
{
	int i, j;
	while(1)
	{
		printf("�����������µ�λ������(���к���):\n");
		scanf("%d%d",&i,&j);
		//�ж����������
		if((i>=1 && i<=x)&&(j>=1 && j<=y))
		{
			if(str[i-1][j-1] != ' ')
				printf("��λ���Ѿ��¹�������������!\n");
			else
			{
				str[i-1][j-1]='*';
				break;
			}
		}
		else
			printf("�����������������!\n");
	}
}
//��������
void ComputerMove(char str[ROW][LINE], int x, int y)
{
	int i, j;
	printf("�����£�\n");
	srand((unsigned int)time(NULL));
	while(1)
	{
		i = rand() % x;
		j = rand() % y;
		if(str[i][j] == ' ')
		{
			str[i][j] = '#';
			break;
		}
	}
}
//�жϺ���
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