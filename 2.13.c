#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
enum sex {
	male,
	famale
};

int check_sys() {
	union Un{
		int i;
		char a;
	};
	union Un u = {1};// ��ֵ��Ҫ�� ��{}�� ��������
	return u.a;//����1С�ˣ�����0���
}
int main() {
	//enum sex sex1 = male;
	int rect = check_sys();
	printf("%d", rect);
}