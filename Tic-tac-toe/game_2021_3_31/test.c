//������
#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void game()
{
	char win;
	int count = 0;//����
	//�����������û��������λ��
	char board[ROW][LINE];
	printf("��Ϸ��ʼ\n");
	//��ʼ������
	InitBoard(board, ROW, LINE);
	//��ӡ����
	DisplayBoard(board, ROW, LINE);
	//����
	while(1)
	{
		//�������
		PlayerMove(board, ROW, LINE);
		DisplayBoard(board, ROW, LINE);
		count ++;
		//�ж�����Ƿ�Ӯ
		win = IsWin(board, ROW, LINE, count);
		Sleep(1000);
		if(win == 'w')
		{
			printf("YOU WIN��\n");
			break;
		}
		else if(win == 'p')
		{
			printf("The Game Is a Draw��\n");
			break;
		}
		//��������
		Sleep(1000);
		ComputerMove(board, ROW, LINE);
		Sleep(1000);
		DisplayBoard(board, ROW, LINE);
		count ++;
		//�жϵ����Ƿ�Ӯ
		win = IsWin(board, ROW, LINE, count);
		Sleep(1000);
		if(win == 'w')
		{
			printf("YOU LOSE��\n");
			break;
		}
		else if(win == 'p')
		{
			printf("The Game Is a Draw!\n");
			break;
		}
	}
}
//ѡ�������̿�ʼ�˵�֮���û�����ѡ��
int Choose()
{
	int input;
	while(1)
	{
		printf("��ѡ��:\n");
		scanf("%d",&input);
		switch(input)
		{
		case 1:
			return 1;
		case 2:
			printf("��Ϸ��������:\n");
			printf("�����壨Tic Tac Toe�����ɵ¹��˷�������������Ϸ\n");
			printf("Ҫ�����������һ�оŸ����ϻ����ֻ�ԲȦ��˭�Ȱ�����ͬһ�Ǻ��ųɺ��ߡ�ֱ�ߡ�б�ߣ�����ʤ�ߣ�\n");
			printf("���ھ�����Ϸ������׶������κεط��������棬��������Ч��ʱ��ıر�������Ϸ��\n");
			break;
		case 0:
			printf("�˳���Ϸ\n");
			return 0;
		default:
			printf("ѡ�����,");
			break;
		}
	}
}
//��ʼ�˵�����
void menu()
{
	Sleep(1000);
	printf("************************************\n");
	printf("*********    Tic-tac-toe   *********\n");
	printf("**   1��Play   2��Rule   0��Exit  **\n");
	printf("************************************\n");
}
//���Ժ���
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