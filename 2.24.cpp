#include<iostream>
#include<stdio.h>
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
//class person {
//public:
//	friend ostream& operator<<(ostream& o, person& s);
//
//	person(int a,int b):a(a),b(b) {
//	}
//	/*void operator<<(ostream &o) {
//		cout << a << '-' <<b << endl;
//	}*/
//private:
//	int a;
//	int b;
//};
//ostream& operator<<(ostream & o, person& s) {
//	cout << s.a << '-' << s.b << endl;
//	return o;
//}
//void test() {
//	person s1(10,20);
//	person s2(10,20);
//	cout << s1;
//}
//int main() {
//	test();
//	return 0;
//}
//�������������//
//class person {
//public:
//	friend ostream& operator<<(ostream& o, person a);
//	person() {
//		a = 0;
//	}
//	person& operator++() {//++a
//		this->a++;
//		return *this;
//	}
//	person operator++(int) {//++a
//		person temp;
//		temp = *this;
//		this->a++;
//		return temp;
//	}
//private:
//	int a;
//};
//ostream& operator<<(ostream& o, person a) {
//	cout << a.a << endl;
//	return o;
//}
//void test() {
//	person n;
//	
//	//(++n);//�൱��n.operator++();
//	//n++;
//	cout<< n++;//�൱��n.operator++(int)
//	cout << n;
//}
//class person {
//public:
//	person(int a) {
//		age = new int(a);
//	}
//	int* age;
//	
//	~person() {
//		if (age != NULL) {
//			delete age;
//			age = NULL;
//		}
//	}
//	person& operator=(person& s) {
//		if (age != NULL) {
//			delete age;
//			age = NULL;
//		}
//		age = new int(*s.age);
//		return *this;
//	}
//};
//void test(){
//	person a1(10);
//	person a2(12);
//	person a3(5);
//		a3=a2 = a1;
//	cout << *a1.age << endl;
//	cout << *a2.age << endl;
//	cout << *a3.age << endl;
//}
//class person {
//public:
//	person(string name,int age):m_age(age),m_name(name) {
//
//	}
//	string m_name;
//	int m_age;
//	bool operator==(person &s) {//==����
//		if (m_age == s.m_age && m_name == s.m_name) {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//	bool operator!=(person& s) {//!=����
//		if (m_age == s.m_age && m_name == s.m_name) {
//			return false;
//		}
//		else {
//			return true;
//		}
//	}
//};
//void test() {
//	person a1("tom", 25);
//	person a2("tom", 25);
//	if (a1 == a2) {
//		cout << "һ��" << endl;
//	}
//	else {
//		cout << "��һ��" << endl;
//	}
//	if (a1 != a2) {
//		cout << "��һ��" << endl;
//	}
//	else {
//		cout << "һ��" << endl;
//	}
//}
//class person {
//public:
//	person(int n) {
//		cout << "person���캯��" << endl;
//		age = n;
//	}
//	void showage() {
//		cout << "����Ϊ��" << age << endl;
//	}
//	~person() {
//		cout << "person����������" << endl;
//	}
//	int age;
//};
//class smartPoint {//����ָ����������ָ�룬�����������������Զ��ͷ�ָ����ָ��Ŀռ�
//public:
//	person* operator->() {//ʵ��->����
//		return this->point;
//	}
//	person operator*() {//ʵ�ֽ����÷���
//		return *this->point;
//	}
//	smartPoint(person* p) {
//		cout << "����ָ��Ĺ��캯��" << endl;
//		this->point = p;
//	}
//	~smartPoint() {//�������������ͷ�ָ��
//		cout << "smartPOint��������" << endl;
//		if (this->point != NULL) {
//			delete point;
//			point = NULL;
//		}
//	}
//
//	person* point;
//};
//void test() {
//	//person* p1 = new person(20);//new����Ŀռ��ڶ��������û��Լ��ͷ�
//	//p1->showage();	//�û��������ͷ�ָ�룬������ý���������
//	//(*p1).showage();
//	smartPoint p(new person(20));//������ָ��p������person���͵Ķ���
//	p->showage();
//	(*p).showage();
//
//}
void test() {
	int s[5] = { 1,2,3,4,5 };
	int* ptr = (int*)((int)s + 1);
	printf("%x\n", *ptr);
}
int main() {
	test();
	return 0;
}