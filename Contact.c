#define _CRT_SECURE_NO_WARNINGS
#include"Contact.h"
void meun() {
	printf("--------------------------------------------------------\n");
	printf("----------1.�����ϵ��           2.ɾ����ϵ��-----------\n");
	printf("----------3.�޸���ϵ��           4.��ѯ��ϵ��-----------\n");
	printf("----------5.��ʾ��ϵ���б�       6.��ϵ����������-------\n");
	printf("--------------------------------------------------------\n");
	printf("---------------------0.�˳�ͨѶ¼-----------------------\n");
	printf("--------------------------------------------------------\n");
}
void initContact(struct Contact* ps) {
	memset(ps->data,0, sizeof(ps->data));
	ps->size = 0;
}
void addContact(struct Contact* ps) {
	if (ps->size == MAX) {
		printf("��ϵ���������޷���ӣ�\n");
	}
	else
	{
		printf("��������ϵ��������");
		scanf("%s", ps->data[ps->size].name);
		printf("��������ϵ���Ա�");
		scanf("%s", ps->data[ps->size].sex);
		printf("��������ϵ�����䣺");
		scanf("%d", &(ps->data[ps->size].age));
		printf("��������ϵ��סַ��");
		scanf("%s", ps->data[ps->size].addr);
		printf("��������ϵ�˵绰��");
		scanf("%s", ps->data[ps->size].tele);
		ps->size++;
		printf("��ϵ��\%s����ɹ���\n", ps->data[ps->size].name);
	}
}
static int FindebyName(const struct Contact*ps,char name[max_name]) {
	int i = 0;
	for (i = 0; i < ps->size; i++) {//����
		if (0 == strcmp(ps->data[i].name, name))
			return i;
	}
	return -1;
	
}
void ShowContact(const struct Contact*ps) {
	if (ps->size == 0) {
		printf("��ϵ���б�Ϊ�գ�\n");
	}

	else{
		printf("%-10s\t%-3s\t%-3s\t%-20s\t%-10s\n", "����", "�Ա�", "����", "סַ", "�绰");
		int i = 0;
		for (i = 0; i < ps->size; i++) {
			printf("%-10s\t%-3s\t%-3d\t%-20s\t%-10s\n",
				ps->data[i].name,
				ps->data[i].sex,
				ps->data[i].age,
				ps->data[i].addr,
				ps->data[i].tele
			);
		}
	}
	
}
void DelContact(struct Contact*ps) {
	char name[max_name] = {0};
	printf("������Ҫɾ����ϵ�˵�������");
	scanf("%s", name);
	int ret=FindebyName(ps, name);
	if (ret == -1) {
		printf("δ���ҵ�Ҫɾ������ϵ��!\n");
	}
	else {
		int j = 0;
		for (j = ret; j < ps->size - 1; j++) {//ɾ�����ƶ�����
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("��ϵ�ˣ�%s �ѳɹ�ɾ����\n", name);
	}
}
void SelectContact(const struct Contact*ps) {
	char name[max_name] = { 0 };
	printf("������Ҫ���ҵ���ϵ��������");
	scanf("%s", name);
	int ret = FindebyName(ps, name);
	if (ret == -1) {
		printf("δ���ҵ�����ϵ��!\n");
	}
	else {
		printf("%-10s\t%-3s\t%-3s\t%-20s\t%-10s\n", "����", "�Ա�", "����", "סַ", "�绰");
		printf("%-10s\t%-3s\t%-3d\t%-20s\t%-10s\n",
			ps->data[ret].name,
			ps->data[ret].sex,
			ps->data[ret].age,
			ps->data[ret].addr,
			ps->data[ret].tele
		);
	}
}
void AlterContact(struct Contact*ps) {
	char name[max_name] = { 0 };
	printf("������Ҫ�޸���Ϣ����ϵ��������");
	scanf("%s", name);
	int ret = FindebyName(ps, name);
	if (ret == -1) {
		printf("δ���ҵ�����ϵ��!\n");
	}
	else {
		printf("��������ϵ��������");
		scanf("%s", ps->data[ret].name);
		printf("��������ϵ���Ա�");
		scanf("%s", ps->data[ret].sex);
		printf("��������ϵ�����䣺");
		scanf("%d", &(ps->data[ret].age));
		printf("��������ϵ��סַ��");
		scanf("%s", ps->data[ret].addr);
		printf("��������ϵ�˵绰��");
		scanf("%s", ps->data[ret].tele);
		printf("��ϵ����Ϣ�޸ĳɹ���\n");
	}
}
static int com_name(const void* pa1,const void *pa2) {//����������
	return strcmp(((struct Contact*)pa1)->data->name,((struct Contact*)pa2)->data->name);
}
void SortContact(struct Contact*ps) {
	qsort(ps->data, ps->size, sizeof(ps->data[0]), com_name);
	printf("������ɣ�\n");
}


