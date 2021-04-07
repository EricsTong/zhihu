#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
int rel = 0;
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
	printf("�����£�\n");
	while(1)
	{
		rel = 0;
		//�������ж�
		ComputerRow(str,x,y);
		//�жϵ����Ƿ�����
		if (rel == 1)
			break;//�������壬�˳�����ѭ��
		//�����������
		//�������ж�
		ComputerLine(str,x,y);
		//�жϵ����Ƿ�����
		if(rel == 1)
			break;//�������壬�˳�����ѭ��
		//�����������
		//���ԶԽ��ж�
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
		//������ж�
		PlayerRow(str,x,y);
		//�жϵ����Ƿ�����
		if (rel == 1)
			break;//�������壬�˳�����ѭ��
		//�����������
		//������ж�
		PlayerLine(str,x,y);
		//�жϵ����Ƿ�����
		if(rel == 1)
			break;//�������壬�˳�����ѭ��
		//�����������
		//��ҶԽ��ж�
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
		//�������
		Computer(str,x,y);
		if(rel == 1)
			break;//�������壬�˳�����ѭ��
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
//�������ж�
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
//�������ж�
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
//������ж�
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
//������ж�
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
//�������
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