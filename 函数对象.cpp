#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class myadd {
public:
	int operator()(int a,int b) {
		return a + b;
	}
};
void test() {
	myadd myadd;
	std::cout<<myadd(10, 5);//�����в���������ֵ
}
class myprint {
public:
	void operator()(std::string test) {
		cout << test << endl;
		num++;
	}
	int num = 0;
};
void test2() {
	myprint print;
	print("hello word");
	print("hello word");
	print("hello word");
	print("hello word");//
	cout << print.num;//�������Լ���״̬
}
void func(myprint my,string s) {
	my(s);
}
void test3() {
	myprint m;
	func(m, "�������������Ϊ�����Ĳ�������");
}
int main() {
	test3();
	return 0;
}