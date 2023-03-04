#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>
using namespace std;
void printset(set<int> s) {
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test(){
	set<int >s;
	s.insert(12);
	s.insert(15);
	s.insert(4);
	s.insert(13);
	s.insert(1);
	s.insert(31);
	pair<set<int>::iterator,bool>p=s.insert(31);//�ظ������ݲ����ᱻ�����ȥ
	printset(s);
	cout << p.second << endl;
	s.erase(s.begin());
	printset(s);
	set<int >::iterator it=s.find(0);
	if (it == s.end()) {
		cout << "not find" << endl;
	}
	else {
		cout << *it << endl;
	}
}
class mycmpare {
public:
	bool operator()(int p1,int p2)const{//��Ҫ��const
		return p1 > p2;
	}
};
void printset(set<int,mycmpare> s) {
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
void test2() {
	set<int, mycmpare>s;//mycmpare�º��������Ƚ�
	s.insert(12);
	s.insert(15);
	s.insert(4);
	s.insert(13);
	s.insert(1);
	s.insert(31);
	printset(s);
}
class person {
public:
	person(string n, int a) {
		name = n;
		age = a;
	}
	string name;
	int age;
};
class mycompare {
public:
	bool operator()(person p1,person p2)const {
		return p1.age<p2.age;
	}
};
void printset(set<person, mycompare> s) {
	for (set<person, mycompare>::const_iterator it = s.begin(); it != s.end(); it++) {
		cout << it->name << ' ' << it->age << endl;
	}
}
void test3() {//�Զ������͵�������set����ʱ��Ҫָ���º������򣬷����޷�����
	person p1("ad", 51);
	person p2("hd", 32);
	person p3("fd", 41);
	person p4("fas",25);
	person p5("mod",23);
	set<person, mycompare>s;//������������
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	s.insert(p5);
	printset(s);
}
int main(){
	test3();
	return 0;
}