#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//class base {
//public:
//	int a;int b=20;
//protected:
//	
//private:
//	int c;
//};
//class son : public base{
//public:
//	int b=10;
//};
class animal {
public:
	virtual void speak() {//�麯��--��������ͬ�ĺ�������д����������γɺ�����ַ�� ��� 
		cout << "���ﶼ��˵��" << endl;
	}
};
class cat :public animal {
public:
	void speak() {
		cout << "Сè����˵��" << endl;
	}
};
class dog :public animal {
public:
	void speak() {
		cout << "С������˵��" << endl;
	}
};
void dosepak(animal& an) {//�����ָ��������� ��ָ�����࣬���Խ���������Ҳ�ܽ���,�γɶ�̬��̬
	an.speak();
}
void test() {
	cat cat;
	dog dog;
	dosepak(cat);
	dosepak(dog);
}