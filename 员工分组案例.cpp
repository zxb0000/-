#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<map>
#include<string>
enum {
	�߻� = 1, ���� = 2, �з� = 3
};
using namespace std;
class worker {
public:
	string name;
	int salary;
};
void createworker(vector<worker> &v) {
	for (int i = 0; i < 10; i++) {
		string nameseek = "ABCDEFGHIJ";
		string name = "Ա����" ;
		name += nameseek[i];
		int salary = rand() % 10000 + 10000;
		worker w;
		w.name = name;
		w.salary = salary;
		v.push_back(w);
	}

}
void selectdepartment(vector<worker>&v,multimap<int, worker>&m) {
	for (int i = 0; i < v.size(); i++) {
		int depid = rand() % 3 + 1;
		m.insert(make_pair(depid, v[i]));
	}
}
void showdepatment(multimap<int,worker>m) {
	multimap<int,worker>::iterator pos=m.find(�߻�);
	int count = m.count(�߻�);
	int index = 0;
	cout << "�߻�������Ա��"<<endl;
	while (index != count) {
		cout << pos->second.name << ' ' << pos->second.salary << endl;
		pos++;
		index++;
	}
	cout << "����������Ա��" << endl;
	count = m.count(����);
	index = 0;
	while (index != count) {
		cout << pos->second.name << ' ' << pos->second.salary << endl;
		pos++;
		index++;
	}
	cout << "�з�������Ա��" << endl;
	count = m.count(�з�);
	index = 0;
	while (index != count) {
		cout << pos->second.name << ' ' << pos->second.salary << endl;
		pos++;
		index++;
	}
}
int main() {
	srand((unsigned int)time(NULL));
	//����ʮ��Ա��
	vector<worker>v;
	createworker(v);
	//����Ա������
	multimap<int, worker>m;
	selectdepartment(v,m);
	//չʾ������Ϣ
	showdepatment(m);
	/*for (int i = 0; i < v.size(); i++) {
		cout << "name:" << v[i].name << " salary:" << v[i].salary <<endl;
	}*/
}