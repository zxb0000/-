#include<iostream>
using namespace std;
////����ģʽ����
//class Chariman {
//public:
//	static Chariman* getInstance() {//�ṩ�ⲿ�ӿڣ�������ȡ����Ĭ�Ϲ涨�Ľӿ���ΪgetInstance��
//		return Singleman;
//	}
//private:
//	Chariman(Chariman &){}//����������˽�л�
//	Chariman() { cout << "���캯����" << endl; }//�����캯��˽�л�
//	static Chariman* Singleman;
//};
//Chariman * Chariman::Singleman = new Chariman;
//int main() {
//	cout << "'main'";
//	Chariman *s =Chariman::getInstance();
//	Chariman* a = Chariman::getInstance();
//	//Chariman a = Chariman(*s);
//	if (s == a) {
//		cout << "s==a" << endl;
//	}
//	return 0;
//
//}
//class building;//�������
//class goodgay {
//public:
//	goodgay();//���캯������
//	void vist1();//��Ա��������
//	void vist2();
//private:
//	building* build;
//};
//
//class building {
//public:
//	friend void goodgay::vist1();//�������еĺ�������Ԫ
//	building();//���캯������
//	string sittingroom;
//private:
//	string bedroom;
//};
//building::building() {//���캯��
//	sittingroom = "����";
//	bedroom = "����";
//}
//
//goodgay::goodgay() {//���캯��
//	build = new building;
//}
//void goodgay::vist1() {
//	cout << "vist1" << endl;
//	cout << build->sittingroom << endl;
//	cout << build->bedroom << endl;
//}
//void goodgay::vist2() {
//	cout << "vist2" << endl;
//	//cout << build->bedroom << endl;
//	cout << build->sittingroom << endl;
//
//}
//void test() {
//	goodgay p;
//	p.vist1();//vist1�ܹ����� vist2����
//	p.vist2();
//}
//class person {
//	
//public:
//	person(){}
//	person(int a, int b) :a(a), b(b) {
//	}
//	int a;
//	int b;
//	//person operator+(person& a1) {//��Ա������ʽ����
//	//	person temp;
//	//	temp.a = a1.a + this->a;
//	//	temp.b = a1.b + this->b;
//	//	return temp;
//	//}
//};
//person operator+(person& s1, person& s2) {//ȫ�ֺ���������
//	person temp;
//	temp.a = s1.a + s2.a;
//	temp.b = s1.b + s2.b;
//	return temp;
//}
//void test() {
//	person a1(10, 10);
//	person a2(10, 10);
//	person a3 = a1 + a2;//ȫ�ֺ��������� �൱��person a3=operator+(a1,a2);
//	person a3 = a1 + a2;//��Ա��������  �൱��a3=a1.operator+(a2) 
//	cout << a3.a << ' ' << a3.b << endl;
//}
class person {
public:
	friend ostream& operator<<(ostream& o, person& s);

	person(int a,int b):a(a),b(b) {
	}
	/*void operator<<(ostream &o) {
		cout << a << '-' <<b << endl;
	}*/
private:
	int a;
	int b;
};
ostream& operator<<(ostream & o, person& s) {
	cout << s.a << '-' << s.b << endl;
	return o;
}
void test() {
	person s1(10,20);
	person s2(10,20);
	cout << s1;
}
int main() {
	test();
	return 0;
}