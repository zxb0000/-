#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;
void test() {
	plus<int> p;//�ӷ��º���
	cout<<p(10, 255)<<endl;
	negate<int>n;
	cout<<n(501);//ȡ���º���
}
void test1() {
	vector<int>v;
	v.push_back(52);
	v.push_back(213);
	v.push_back(631);
	v.push_back(24);
	v.push_back(53);
	v.push_back(63);
	v.push_back(81);
	sort(v.begin(), v.end(),greater<int>());//greater<int>()�����º���,ʵ�ֽ���
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

}
void test3() {
	vector<bool>v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(false);
	v.push_back(false);
	v.push_back(true);
	vector<bool>v2;
	v2.resize(v.size());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
	//logical_not<bool>()�߼�ȡ��  transform������֮�������ת�Ƹ�Ŀ�ĵص�����
	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << " ";
	}
	cout << endl;
}
int main() {
	test3();
	return 0;
}