 #pragma once
#include<stdio.h>
#include<string.h>
#define max_name 20
#define MAX 1000//ͨѶ¼��󴢴�����
#define max_sex 6
#define max_addr 30
#define max_tele 12
enum Opiton {
	EXIT,
	ADD,
	DELE,
	ALTER,
	SELECT,
	SHOW,
	SORT
};
void meun();
struct people {
	char name[max_name];
	char sex[max_sex];
	char addr[max_addr];
	char tele[max_tele];
	int age;
};
struct Contact {
	struct people data[MAX];
	int size;
};
void initContact(struct Contact*);//��ʼ���ṹ��
void addContact(struct Contact*);//�����ϵ��
void ShowContact(const struct Contact*);//��ʾ��ϵ��
void DelContact(struct Contact*);//ɾ����ϵ��
void SelectContact(const struct Contact*);//������ϵ��
void AlterContact(struct Contact*);//�޸���ϵ��
void SortContact(struct Contact*);//��ϵ������


