#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
struct stu {
	char name[10];
	int age;
};
int com_int(void* e1, void* e2) {
	return *(int*)e1 - *(int*)e2;
}
int com_age(const void* e1, const void* e2) {
	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
}
int com_name(const void* e1, const void* e2) {
	return strcmp(((struct stu*)e1)->name, (((struct stu*)e2)->name));//strcmp e1����e2�������������ڷ���0��С�ڷ��ظ���
}
void swap( char* e1, char* e2,int width) {
	int i = 0;
	
	for (i = 0; i < width; i++) {
		char temp=0;
		temp = *e1;
		*e1 = *e2;
		*e2 = temp;
		e1++;//�����������ַ�
		e2++;
	}
}
void bubble_sort(void* base, int sz, int width, int (*cmp)(const void* e1, const void* e2)) {//cmpָ��ĺ����Ƚ�e1��e2��e1����e2���ش��������������---0��С��---����
	int i;
	for (i = 0; i < sz - 1; i++) {
		int j;
		for (j = 0; j < sz - 1 - i; j++) {
			if (cmp((char*)base+j*width,(char*) base+(j+1)*width)>0) 
			{//��ָ��ת��Ϊchar���ͣ�һ���ֽڣ��ķ�����бȽϣ�ÿ���ƶ��ľ���Ϊ��Ҫ�Ƚ�Ԫ�ص����ʹ�С
				swap((char*)base + j * width, (char*)base + (j + 1) * width,width);
				//һ���ֽ�һ���ֽڵĽ��н�����widthΪԪ�����͵��ֽڴ�С������Ҫ�������ٸ��ֽ�
			}
		}
	}
}

int main() {
	struct stu s[3] = {{"zhang",10},{"li",15},{"scan",24}};
	//int sz = sizeof(arr) / sizeof(arr[0]);
	///qsort(arr, sz, sizeof(arr[0]), com_age);
	//��һ�������������������Ԫ�ص�ַ
	//2������Ԫ�صĸ���
	//3:	 ����Ԫ����ռ�ռ��С���ֽ�
	//4���ȽϺ���ָ��
	//int arr[10] = { 1,5,7,3,4,6,8,9,2,8 };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz, sizeof(s[0]),com_name);
	return 0;
}