#define  _CRT_SECURE_NO_WARNINGS
#include"game.h"
void game() {
		char mine[ROWS][COLS];//��Ϸ����
		char show[ROWS][COLS];//��ʾ����
		Initbord(mine, ROWS, COLS,'0');//��ʼ��������������
		Initbord(show, ROWS, COLS,'*');//��ʼ��������������
		Initmine(mine, ROW, COL);//��ʼ�����׵�λ��
		//Displaybord(mine, ROW, COL);//���׵�λ��
		Displaybord(show, ROW, COL);//��ʾ����
		Findmine(mine, show, ROW, COL);
}
void test() {
	int input;
	do{
		meun();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input) {
		case 1: 
			system("CLS");
			game();
			break;
		case 0:
			printf("�˳���Ϸ��\n");
			break;
		default:
			printf("�����������������룡\n");
			break;
		}
	
	} while (input);
}

int main() {
	srand((unsigned int)time(NULL));
	test();
	return 0;
}