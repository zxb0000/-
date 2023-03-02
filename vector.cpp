#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
void print(vector<int>v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
void test() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	if (v1.empty()) {
		cout << "�յ�" << endl;
	}
	else {
		cout << "����Ϊ" << v1.capacity()<<endl;
		cout << "��СΪ" << v1.size()<<endl;
	}
	print(v1);
	v1.resize(15,1);//��չ��15���ռ䣬����1�����
	print(v1);
	v1.resize(5);
	v1.insert(v1.begin(), 2,1000);
	print(v1);

}
void test2() {
	vector<int>v1;
	for (int i = 0; i < 1100; i++) {
		v1.push_back(i);
	}
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;
	v1.resize(5);//���������ô�С����ռ���������Ǻ�ԭ��һ���󣬻���ɿռ���˷�
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;
	vector<int>(v1).swap(v1);
		//���������󻥻���ʵ���ڴ����������������ʹ��һ�κ�ϵͳ�ͻ��Զ�����
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;
}
void test3() {
	vector<int>v1;
	v1.reserve(10000);//��ǰԤ��10000���ռ䣬�ͻ�һ�ο���
	int num = 0;//ͳ�ƿ��ٿռ�Ĵ���
	int* p = NULL;//
	for (int i = 0; i < 10000; i++) {
		v1.push_back(i);
		if (p != &v1[0]) {
			p = &v1[0];//ÿ����һ�οռ�p��ָ���һ��Ԫ�صĵ�ַ
			num++;
		}
	}
	cout << num;//������24��

	
}
void test4() {
	int* s, p;
	int sp;
	cout << typeid(s).name();
	cout << sp;
}
int main(){
	test4();		
	return 0;
}