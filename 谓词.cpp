#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class greaterfive {
public:
	bool operator()(int a) {//һ��������һԪν��
		return a > 5;
	}
};
void test() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	vector<int>::iterator pos = find_if(v.begin(), v.end(), greaterfive());//predν�ʣ�
		//find_if�ҵ����������ķ������ڵĵ�������û�ҷ���end����
		//greaterfive()Ϊ������������
		cout << *pos;
}
int main() {
	test();
	return 0;
}