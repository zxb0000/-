#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
//int main() {
//	int arr[] = { 1,2,3,4,5 };//�ڴ���//01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00 05 00 00 00
//	int* parr = (int*)(&arr + 1);
//	int* parr2 = (int*)((int)arr + 1);//arr��ֵ��һ���൱�ڼ���һ���ֽڣ�
//	printf("%x ", parr[-1]);//5
//	printf("%x ", *parr2);//2000000
//	return 0;
//}
//int main() {
//	int a[5][5];
//	int(*p)[4];
//	p = a;
//	//pָ�����ĸ�����Ԫ�ص����飬����a��5*5=25������Ԫ�أ����Խ�p+1�൱���ƶ�4������
//	//*��p+4����p[4]�ĵ�һ��Ԫ��
//	printf("%p %d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);//p[4][2]=*(p+4)[2]=*(*(p+4)+2)
//	return 0;
//}
//int main() {
//	char* a[] = { "work","at","alibaba" };//ָ�����飬��ŵ����ַ������ַ��ĵ�ַ
//	char** pa = a;
//	pa++;//��aָ��ĵ�ַ��һ����ָ��������ĵڶ���
//	printf("%s\n", *pa);//%s���ӵ�ַ��ʼ��ӡ��ֱ��������\n��
//	return 0;
//}
int main() {
	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = cp;
	printf("%s\n", **++cpp);//POINT
	printf("%s\n", *--*++cpp+3);
	//ER
	printf("%s\n", *cpp[-2]+3);
	//ST ----cpp[-2]=*(cpp-2)
	printf("%s\n", cpp[-1][-1]+1);
	//EW------cpp[-1][-1]+1===*(cpp-1)[-1]+1==*((*cpp-1)-1)+1
	return 0;
}