#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//int main() {
//	FILE* fp = fopen("text.txt", "r");
//	if (fp == NULL) {
//		printf("%s", strerror(errno));
//		return 0;
//	}
//	fputc('s', fp);//д��ʱ�ַ�Ӧʹ��'s'������
//	fputc('s', fp);
//	fputc('a', fp);
//	fputc('w', fp);
//	printf("%c",fgetc(fp));//��ȡ�ַ�
//	printf("%c",fgetc(fp));
//	printf("%c",fgetc(fp));
//	printf("%c",fgetc(fp));
//	fclose(fp);
//	fp = NULL;
//	return 0;
//}
//int main() {
//	char buf[1024] = { 0 };
//	FILE* fp = fopen("text.txt", "w");
//	if (fp == NULL) {
//		printf("%s", strerror(errno));
//		return 0;
//	}
//	//fgets(buf, 1024, fp);
//	//printf("%s", buf);
//	//fgets(buf, 1024, fp);
//	//printf("%s", buf);
//	//fgets(buf, 1024, fp);
//	//puts(buf);//puts��ӡ��ɺ����л���
//	//fclose(fp);
//	fputs("hello\n", fp);//���ỻ�У���Ҫ�Լ���
//	fputs("word", fp);
//	fp = NULL;
//	return 0;
//}
int main() {
	char buf[1024] = { 0 };
	struct S {
		char a[20];
		int b;
		float f;
	};
	//fgets(buf, 1024, stdin);//����������ȡ��Ϣ�������buf������Ϊ1024
	//fputs(buf, stdout);//��������ȼ�������gets��puts
	//gets(buf);
	//puts(buf);
	struct S S = {"dd",20,3.14f};
	struct S temp = { 0 };
	FILE*fp=fopen("text.txt", "rb");
	if (fp == NULL) {
		return 0;
	}
	//��ʽ���������
	//fprintf(fp, "%s %d %f", S.a, S.b, S.f);//fp������� ���������ļ��������������  д��ĸ�ʽ   ������Դ
	//��ʽ������
	//fscanf(fp, "%s %d %f", &S.a, &S.b, &S.f);
	fwrite(&S,sizeof(struct S),1, fp);//Writes data to a stream.
	fread(&temp,sizeof(struct S),1,fp);//Reads data from a stream
	printf("%s %d %f", temp.a, temp.b, temp.f);
	fclose(fp);
	fp == NULL;
	return 0;
}