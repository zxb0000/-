#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class abstractcalculator {//����ļ����
public:
	virtual int getresult() {//�麯�������ڶ�̬��ʵ��
		return 0;
	}
	int a;
	int b;
};
class addcalculator :public abstractcalculator{
public:
	int getresult() {//�麯����д  ʵ�ֶ�̬
		return a + b;
	}
};
class subcalculator :public abstractcalculator {
public:
	int getresult() {//�麯����д  ʵ�ֶ�̬
		return a - b;
	}
};
class mulcalculator :public abstractcalculator {
public:
	int getresult() {//�麯����д  ʵ�ֶ�̬
		return a * b;
	}
};
void test() {
	//abstractcalculator* add = new addcalculator;//ͨ�������ָ�����
	addcalculator add;//add��ֱ����
	add.a = 10;
	add.b = 20;
	cout<<add.a<<"+"<<add.b <<"="<<add.getresult()<<endl;
	abstractcalculator* sub = new subcalculator;//ͨ�������ָ�����
	sub->a = 10;
	sub->b = 20;
	cout << sub->a << "-" << sub->b << "=" << sub->getresult()<<endl;
	delete sub;
	sub = new mulcalculator;
	sub->a = 10;
	sub->b = 20;
	cout << sub->a << "*" << sub->b << "=" << sub->getresult() << endl;
	delete sub;

}
int main() {
	test();
	return 0;
}