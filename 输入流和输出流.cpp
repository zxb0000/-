#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
void test() {
	cout << "������һ���ַ���������";
	char a = cin.peek();
	if (a >= '0' && a <= '9') {
		int num;
		cin>>num;
		cout << "������������֣�" << num << endl;
	}
	else {
		char buff[1024];
		cin >> buff;
		cout << "����������ַ�����" << buff<< endl;
	}
}
void test1() {
	int num=-1;
	cout << "������0-10֮������֣�" << endl;
	while (1) {
		cin >> num;//cin��д������ʧ��ʱ���Ὣԭ�������㣬���ҵ����ʱ����д��std::numeric_limits::max() �� std::numeric_limits::min()��
		//cout << num << endl;
		if(!cin.fail()&& num >= 0 && num <= 10)
		 {
			//cout << num << endl;
			cout << "������ȷ��" <<endl;
			cout << cin.fail() << endl;//fail��־λ,�����һ��cin������󷵻�1�����򷵻�0
			break;
		}
		cout << cin.fail() << endl;//fail��־λ
		cin.clear();//��־λ���
		//cin.sync();//ˢ�»�����  vs2015���ϲ����ã�����ʹ��getlinne
		char p[1024] = { 0 };
		cin.getline(p,1024);
		
		cout << "��������ȷ�����֣�" << endl;
	}
}
int main() {
	test1();
	int *p=&014��
	return 0;
}