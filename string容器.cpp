#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
void test() {
	string s1("me");
	string s2(" hahameahbsdjmef");
	string s3 = s1 + s2;
	int pos=s3.find("cb");//�鲻������-1
	s2.append(s1);
	s2.replace(1, 4, "00000");//���±�1��ʼ����Ϊ4���ַ��滻Ϊ00000
	cout << s2 << endl;
	cout << "pos=" << pos << endl;
}
void test2() {//�������н�ȡ�û���
	string email = "ajsdajk@qq.com";
	int pos = email.find("@");
	string name = email.substr(0, pos);
	cout << name << endl;
}
int main() {
	test2();
	return 0;
}