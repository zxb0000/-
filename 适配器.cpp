#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
class print:public binary_function<int,int,void> {//�ڶ������º����̳и���
public:
	void operator()(int a,int star) const {//����������д����ķº�����Ҫ��const
		//�����ʱ����Ҫ��һ����ֵ������ͨ����������ʵ��
		cout << a<<" " <<star << " "<<a+star<<endl;
	}
};
void test() {
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	cout << "��������Ҫ��ӵĻ�ֵ" << endl;
	int star;
	cin >> star;
	for_each(v.begin(), v.end(), bind2nd(print(),star));//��һ���󶨲���
								//bind1st�ǽ������󶨵��º����ĵ�һ������
								//bind1nd�ǽ������󶨵��º����ĵڶ�������

}
class greaterFive :public unary_function<int,bool>{
	//�ڶ����̳У�ֻ��һ�������̳�һԪ�̳�unary_functiom,������Ԫ�̳�binary_function
public:
	bool operator()(int a) const{//��������const ��д����
		return a > 5;
	}
};
void test2() {
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	//vector<int>::iterator it=find_if(v.begin(), v.end(), not1(greaterFive()));
	//notlȡ�������� ----��һ����not1  not1һԪȡ����not2��Ԫȡ��
	vector<int>::iterator it=find_if(v.begin(), v.end(), not1(bind2nd(greater<int>(),5 )));
	//Ҳ���������ڽ����������а󶨺�ȡ�����䣬��ʱ��ֻ��Ҫ�����������ƾͺ�
	
	if (it == v.end()) {
		cout << "û�ҵ�" << endl;
	}
	else {
		cout << "�ҵ��ˣ�" << *it << endl;
	}
	sort(v.begin(), v.end(), not2(greater<int>()));//not2��Ԫȡ��
	for_each(v.begin(), v.end(), [](int a) {cout << a << " "; });
	// [](int a) {cout << a << " "; }��������
}
void  print(int a,int star) {
	cout << a+star << " ";
}
void test3(){//����ָ��������
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	cout << "��������Ҫ��ӵĻ�ֵ" << endl;
	int star;
	cin >> star;
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(print),star));
	//for_each����������÷º���Ҳ�����ú����������ú�����ʱ���޷�������º������в����İ�
	//��˿���ͨ������ָ�����������κ���ָ����в����İ� ptr_fun(������),Ȼ����ܹ����а󶨲���
	//Ҳ����Ҫ��º���һ���̳и��ֱ࣬�Ӿ���ʹ��
}
class person {
public:
	person(string n,int a):name(n),age(a){

	}
	void show() {
		cout << name << " " << age << endl;
	}
	void addage() {
		age++;
	}
	string name;
	int age;
};
void test4() {
	vector<person >v;
	person p1("aaa", 10);
	person p2("bbb", 20);
	person p3("ccc", 30);
	person p4("ddd", 40);
	person p5("eee", 50);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	for_each(v.begin(), v.end(), mem_fun_ref(&person::show));
	for_each(v.begin(), v.end(), mem_fun_ref(&person::addage));
	for_each(v.begin(), v.end(), mem_fun_ref(&person::show));
	//men_fun_ref��Ա�������������ܹ�ͨ���ⲿֱ�����ó�Ա������
	//��Ҫȡ��Ա�����ĵ�ַ���в���&
}
int main() {
	test4();
	return 0;
}