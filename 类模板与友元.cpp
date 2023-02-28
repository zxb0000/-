#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"myarr.hpp"
using namespace std;
template<class T1,class T2>
class person;
template<class T1, class T2>
void printperson(person<T1, T2>& p) {
	cout << p.name << " " << p.age << endl;
}
template<class T1, class T2>
class person {
	//friend void printperson(person<T1, T2>& p) {//ȫ�ֺ�������ʵ��
	//	cout << p.name << " " << p.age << endl;
	//}
	//����ʵ��  ��Ҫ�ӿ�ģ���б�  �����ñ�������ǰ֪�������������printperson�������������ģ��֮ǰ��
	//������Ҫ�ں���֮ǰ������ģ��person;
	friend void printperson<>(person<T1, T2>& p);
public:
	person(T1 n, T2 a) {
		name = n;
		age = a;
	}
private:
	T1 name;
	T2 age;
};

void test(){
	person<string, int>p("����", 20);
	printperson(p);
}
void test1() {
	myarr<int>p(10);
	
}
int main() {
	test1();
	return 0;
}