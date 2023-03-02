#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
//void printdeque(const deque<int>&d) {//�޶��������޸�
//	for (deque<int>::const_iterator it=d.begin(); it != d.end(); it++) {
//		cout << *it << " ";
//	}
//	cout<<endl;
//}
//ͨ���±����
void printdeque(const deque<int>& d) {
	for (int i = 0; i < d.size(); i++) {
		//d[i] = 20;//�����޸�
		cout << d.at(i) << " ";
		//Ҳ������d[i]

	}
	cout << endl;
}
void test() {
	deque<int>d1;
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
	}
	printdeque(d1);
	deque<int>d2 = d1;
	printdeque(d2);
	deque<int>d3;
	d3.assign(d2.begin(),d2.end());
	printdeque(d3);
	deque<int>d4;
	d4.assign(10, 99);
	printdeque(d4);
}
void test1() {
	deque<int>v1;
	deque<int>v2;
	v1.push_front(10);
	v1.push_front(20);
	v1.push_front(30);
	v1.push_front(40);
	v1.push_front(50);
	printdeque(v1);
	v1.pop_front();
	v1.insert(v1.begin(), 1000);
	v1.insert(v1.begin(),2, 99);
	v2.push_back(10);
	v2.push_back(10);
	v2.push_back(10);
	v2.push_back(10);
	v2.insert(v2.begin(), v1.begin(), v1.end());
	printdeque(v1);
	printdeque(v2);
	//v2.erase(++++v2.begin());
	//v2.erase(v2.begin(), v2.end());
	v2.clear();
	printdeque(v2);

	if (v1.empty()) {
		cout << "����" << endl;
	}
	else {
		cout << v1.size() << endl;
	}
}

void test2() {
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_back(30);
	d1.push_front(100);
	d1.push_front(3000);
	printdeque(d1);
	cout << "��һ��" << d1.front() << endl;
	cout << "����" << d1.back() << endl;
	sort(d1.begin(), d1.end());//�����㷨��Ĭ�ϴ�С������Ҫ������׼�㷨ͷ�ļ�algorithm
	printdeque(d1);

}
int main() {
	test2();
	return 0;
}