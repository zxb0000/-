#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void game() {
	char bord[ROW][COL] = { 0 };
	Initbord(bord,ROW,COL);
	system("CLS");
	Display(bord,ROW,COL);
	char rec;
	while(1){
		Computermove(bord, ROW, COL);
		rec=Iswin(bord, ROW, COL);
		if (rec != 'C') {
			break;
		}
		Playermove(bord, ROW, COL);
		rec = Iswin(bord, ROW, COL);
		if (rec != 'C') {
			break;
		}
		
	}
	if (rec == 'O') {
		printf("��ϲ��Ӯ�ˣ�\n");
	}
	if (rec == 'X') {
		printf("�����ˣ�\n");
	}
	if (rec == 'Q') {
		printf("ƽ�֣���\n");
	}
	

}
int main() {
	int input;
	srand((unsigned int) time(NULL));
	do
	{
		meun();
		printf("������ѡ�");
		scanf("%d", &input);
		switch(input) 
		{
		case 1: {
				game();
				break;
			}
			case 0:
				printf("�Ѿ��˳���Ϸ��\n");
				break;
			default:
				printf("������󣡣����������룡\n");
				break;
		}
	}while(input);
	return 0;
}