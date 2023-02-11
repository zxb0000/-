#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
int my_strlen(char* str) {
	if (*str != '\0') {
		return 1 + my_strlen(str + 1);
	}
	else return 0;
}
char* my_strcpy(char* dest, const char* src) {
	assert(dest != NULL);
	assert(src != NULL);
	char* ret = dest;
		while (*dest++ = *src++);
	return ret;
}
char* my_strcat(char* dest, const char* src) {
	assert(dest != NULL);
	assert(src != NULL);
	char* ret = dest;
	while (*dest != '\0') {//�ҵ�Ŀ���ַ�����'\0'
		dest++;
	}
	while (*dest++ = *src++);//׷��
	return ret;
}
int my_strcmp(const char* arr1, const char* arr2) {
	while (*arr1 == *arr2) {
		if (*arr1 == '\0')
			return 0;
		arr1++;
		arr2++;
	};
	return *arr1 - *arr2;
}
char* my_strstr(const char* arr, const char* arr2) {
	assert(arr!= NULL);
	assert(arr2!=NULL);
	char* p1 = NULL;//����ָ��	p1  p2	
	char* p2 = NULL;
	char* p =(char*) arr;//��¼ָ�룬��¼��ǰ�Ƚϵ�λ��duan 20 p30
	if (!*p2) return p1;
	while (*p) {
		p1 = p;
		p2 = (char*)arr2;
		while (*p1&&*p1 == *p2) {//��p2��p1��ָ��Ԫ�ز���0������ͬʱ�����Ƚ�
			p1++;
			p2++;
		}
		if (!*p2) {//��*p2Ϊ��\0��ʱ���Ƚϳɹ���������ʼλ��
			return p;
		}
		p++;
	}
	return NULL;
}
int main() {
	char s[20] = "a";
	char s2[] = "aaas";
	char a = 's';
	printf("%s ",my_strstr(s,s2));
	return 0;
}