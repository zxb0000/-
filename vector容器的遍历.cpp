#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void print(int v) {
	cout << v << endl;
}
class person {
public:
	person(string n, int a) :name(n), age(a) {};
	string name;
	int age;
};
void test() {
	vector<int> v;//������������ģ���ŵ�����Ϊint����Ҫ��������ͷ�ļ�vector
	v.push_back(10);//��������������������
	v.push_back(20);
	v.push_back(120);
	v.push_back(11);
	v.push_back(10);
	//�����ı���
	// ������Ҳ�����൱��ָ��
	//��һ��
	vector<int>::iterator itbegin = v.begin();//���ص����������������ָ�������е�һ��Ԫ��
	vector<int>::iterator itend = v.end();//���ص����������������ָ�����������һ��Ԫ�ص���һ��λ��
	while (itbegin != itend) {
		cout << *itbegin << endl;
		itbegin++;
	}
	//�ڶ���
	for (vector<int>::iterator begin = v.begin(); begin != v.end(); begin++) {
		cout << *begin << endl;
	}
	//������ �����㷨��Ҫ����ͷ�ļ�algorithm
	for_each(v.begin(), v.end(), print);//��Ҫ�ṩ��������ĵ�ַ��Ҳ���Ǻ�����,����qsort�еıȽϺ���
	
}
void test1() {//��������Զ�������
	vector<person> v;
	person p1("���ϴ���1", 10);
	person p2("���ϴ���2", 20);
	person p3("���ϴ���3", 30);
	person p4("���ϴ���4", 40);
	person p5("���ϴ���5", 50);
	person p6("���ϴ���6", 60);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	v.push_back(p6);
	for (vector<person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << it->name << " " << it->age << endl;
	}
}
void test2() {
	vector<person*> v;//ָ������
	person p1("���ϴ���1", 10);
	person p2("���ϴ���2", 20);
	person p3("���ϴ���3", 30);
	person p4("���ϴ���4", 40);
	person p5("���ϴ���5", 50);
	person p6("���ϴ���6", 60);
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);
	v.push_back(&p6);
	for (vector<person*>::iterator it = v.begin(); it != v.end(); it++) {
		cout << (*it)->name << "* " << (*it)->age << endl;
	}
}
void test3() {//������Ƕ��
	vector<vector<int>> bv;//�����д����vector<int>���͵����ݣ�
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	vector<int> v5;
	for (int i = 0; i < 5; i++) {//��ʼ�����С����������������
		v1.push_back(i+1);
		v2.push_back(i+2);
		v3.push_back(i+3);
		v4.push_back(i+4);
		v5.push_back(i+5);
	}
	bv.push_back(v1);//��С�������������bv��
	bv.push_back(v2);
	bv.push_back(v3);
	bv.push_back(v4);
	bv.push_back(v5);
	for (vector<vector<int>>::iterator bit = bv.begin(); bit != bv.end(); bit++) {
		//���ʴ������е�ÿ��С����
		for (vector<int>::iterator it = bit->begin(); it != bit->end(); it++) {
			//����ÿ��С�����е�Ԫ��int��*bit����ÿ��С����,����ͨ��->�������ຯ��begin��end��
			cout << *it << " ";
		}
		cout << endl;//ÿ����һ��С�������л���
	}
}
int main() {
	test3();
	return 0;
}