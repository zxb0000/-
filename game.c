#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void Initbord(char arr[ROW][COL], int row, int col) {
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j< col; j++) {
			arr[i][j] = ' ';
		}
	}
}
void Display(char arr[ROW][COL], int row, int col) {
	int i=0;
	for (i = 0; i<row; i++) {
		int j = 0;
		for (j = 0; j < col; j++) {
			printf(" %c ", arr[i][j]);
			if (j < col - 1) printf("|");
		}
		printf("\n");
		if (i < row - 1) {
			for (j = 0; j < col; j++) {
				printf("---");
				if (j < col - 1) printf("|");
			}
		printf("\n");
		}
	}
}
void Playermove(char arr[ROW][COL], int row, int  col) {
	int x, y;
	printf("������壡\n");
	while (1) {
		printf("������Ҫ�µ�λ�����꣺");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (arr[x-1][y-1] != ' ') {
				printf("�Բ���������������Ѿ������ӣ����������룡\n");
			}
			else {
				arr[x-1][y-1] = 'O';
				system("CLS");
				Display(arr, ROW, COL);
				break;
			}
		}
		else {
			printf("������������������������룡\n");
		}
	}
}
void Computermove(char arr[ROW][COL], int row, int col) {
	int x, y;
	printf("�������壡\n");
	Sleep(1000);
	while (1) {
		x = rand() % row;
		y = rand() % col;
		if (arr[x][y] == ' ') {
			arr[x][y] = 'X';
			system("CLS");
			Display(arr, ROW, COL);
			break;
		}
	}
	
}
int isfull(char arr[ROW][COL], int row, int col) {
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (arr[i][j]==' ') {
				return 0;
			}
		}
	}
	return 1;
}
char Iswin(char arr[ROW][COL], int  row, int col) {
	int i;
	for (i = 0; i < row; i++)//����Ӯ
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][1] != ' ') {
			return arr[i][1];
			break;
		}
	}
	for (i = 0; i < col; i++)//����Ӯ
	{
		if (arr[0][i] == arr[1][i]&& arr[1][i] == arr[2][i] && arr[1][i] != ' ') {
			return arr[1][i];
			break;
		}
	}
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]&&arr[1][1]!=' ') {//�ж϶Խ�
		return arr[1][1];
	}
	if (arr[2][0] == arr[1][1]&& arr[1][1] == arr[0][2] && arr[1][1] != ' ') {
		return arr[1][1];
	}
	if (1== isfull(arr, ROW, COL)) {//��������Ƿ�Ϊ��
		return 'Q';//����ƽ��
	}
	else {
		return 'C';//����������Ϸ
	}
}

void meun() {
	printf("=============================\n");
	printf("===========1.��ʼ��Ϸ========\n");
	printf("===========0.�˳���Ϸ========\n");
	printf("=============================\n");
}
