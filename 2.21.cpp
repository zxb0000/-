#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
//using namespace std;
//class student {
//	friend ostream& operator<<(ostream& o, student s);//������Ԫ����,ʹ��������ܹ�����˽�г�Ա
//	friend istream& operator>>(istream& in, student&s);
//	string name;
//	double score;
//public://�������г�Ա
//	void printf() {
//		cout << name << '\t' << score<<endl;
//	}
//	string get_name() { return name; }
//	double get_score() { return score; }
//	void set_name(string n) {
//		name = n;
//	}
//	void set_score(double n) {
//		score = n;
//	}
//	student(string n, double s) {
//		name = n, score = s;
//	}//Ĭ�Ϲ��캯����һ���Զ����죬�����캯���в���ʱ��Ҫ�ֶ�����
//};
//ostream& operator<<(ostream& o, student s) {//<<���������
//	cout << s.name << ',' << s.score << endl;
//	return o;
//}
//istream& operator>>(istream& in, student& s) {
//	cin >> s.name >> s.score;
//	return in;
//}
//class point {
//	friend ostream& operator<<(ostream& o, point p);
//	int x, y;
//public:
//	point operator+( point b) {//��Ϊ�ڲ�����
//		return point(this->x + b[1],this-> y + b[2]); //
//	}
//	point(int n1, int n2) {
//		x = n1; y = n2;
//	}
//	int operator[](int n) const{//������������ر�������ĳ�Ա����
//		if (n == 1)return x;
//		else if (n == 2)return y;
//		else throw "С�����@";//�׳��쳣
//	}
//	int& operator[](int n) {//
//		if (n == 1)return x;
//		else if (n == 2)return y;
//		else throw "С�����";//�׳��쳣
//	}
//};
//ostream& operator<<(ostream&o,point p){
//	cout << p.x << ' ' << p.y << endl;
//	return o;
//}
////point operator+(point a,point b){//��Ϊ�ⲿ����
////	return point (a[1] + b[1], b[2] + a[2]); //�൱��point s(a[1] + b[1], b[2] + a[2]);return s;
////}
//int main(){
//	//student stu("asjd", 52);
//	//cout << stu;//operator<<(cout,stu)
//	//cin >> stu;//operator>>(cout,stu)
//	//cout << stu;
//	point su(1,20),s2(2,3);
//	cout << su;
//	cout << su[1] <<"--" << su[2]<<endl;//�൱��su.operator[](1)����
//	//su[1] = 5, su[2] = 55;
//	//cout << su;
//	point s = su + s2;//su.operator+(s2)�ڲ� | operator+(su,s2)�ⲿ
//	cout << s;
//	return 0;
//}

//int main() {
//	vector<student> students;
//	student stu;
//	while (1) {
//		cout << "����������������\n";
//		cin >> stu.name >> stu.score;
//		if (stu.score == EOF)
//			break;
//		students.push_back(stu);
//	}
//	for (int i = 0; i < students.size(); i++) {
//		students[i].printf();
//	}
//	int max = students[0].score;
//	int min = students[0].score;
//	double average = 0;
//	for (int i = 0; i < students.size(); i++) {
//		if (students[i].score > max) max = students[i].score;
//		if (students[i].score < min) min = students[i].score;
//		average += students[i].score;
//	}
//	average /= students.size();
//	cout << "ƽ����" << average << "'��߷�' " << max << "'��ͷ�'" << min << endl;
//	return 0;
//}
//using namespace std;
//class String {
//	char* data;
//	int n;
//public:
//	String(const String& s) {
//		cout << "����������\n";
//		data = new char[s.n];
//		n = s.n;
//		for (int i = 0; i < n; i++) {
//			data[i] = s.data[i]; 
//		}
//		
//	}
//	//String(const String& s) {//Ĭ�ϵĿ�������Ӳ����g
//	//	cout << "����������\n";
//	//	data = s.data;
//	//	n = s.n;
//	//}
//	String(const char* s = NULL) {
//		if (s == NULL) {
//			n = 0, data = NULL; return;
//		}
//		const char* p = s;
//		while (*p++);
//		n = p - s;//�����ַ�������
//		data = new char[n];//
//		for (int i = 0; i < n; i++) {//����
//			data[i] = s[i];
//		}
//	}
//	char operator[](int i) const{
//		if (i<0 || i>=n) throw "xiaobiao";
//		return data[i];
//	}
//	char& operator[](int i)  {//����
//		if (i < 0 || i >= n) throw "xiaobiao";
//		return data[i];
//	}
//	int size() { return n; }
//	//~String() {}//����������ʱ�Զ�����Ĭ�ϵ���������
//	~String() {
//		cout << "��������" << endl;
//		delete[] data;
//	}
//};
//ostream& operator<<(ostream& o,String s) {
//	for (int i = 0; i < s.size(); i++) {
//		cout << s[i];
//	}
//	return o;
//}
//int j() {
//	String str,str2("abcd ef");
//	cout << str2<<endl;
//	String str3 = str2;//�������캯����Ĭ�ϵĿ������캯��ΪӲ����
//	cout << str3 << endl;
//	str3[1] = 'B';
//	cout << str3 << endl;
//	cout << str2 << endl;
//	return 0;
//}
#include<errno.h>
using namespace std;
class student {
	friend ostream& operator<<(ostream& o, student s);
	string name;
	double score;
public:
	student(string n = "no", double s = 0) {
		name = n, score = s;
	}

};
ostream& operator<<(ostream& o, student s) {
	cout << s.name << '\t' << s.score << endl;
	return o;
}

//��ģ��
template<typename T>
class Vector {
	T* data;
	int capacity;
	int n;
public:
	Vector(int cap=3) {//���캯��,Ĭ�Ͽռ�Ϊ3��
		data = new T[cap];
		if (data == NULL) { 
			cap = 0;
			n = 0;
			return; 
		}
		capacity = cap;
		n = 0;
	}
	void push_back(T e) {
		if (n == capacity) {//����
			cout << "���ݣ�\n";
			T* p = new T[capacity + 3];
			if (p) {
				for (int i = 0; i < capacity; i++) {//ת������
					p[i] = data[i];
				}
				delete[]data;//�ͷ�ԭ���Ŀռ�
				data = p;//���������¿ռ�
				capacity += 2;//��������
			}
			else {
				cout<<strerror(errno);
				return;
			}
		}
		data[n] = e;
		n++;
	}
	T operator[](int i)const {
		if (i < 0 || i >= n) throw "�±�Ƿ���";
		return 	data[i];

	}
	T& operator[](int i) {
		if (i < 0 || i >= n) throw "�±�Ƿ���";
		return 	data[i];
	}
	int size() {
		return n;
	}

};
//ostream& operator<<(ostream& o, Vector<string> v) {
//	for (int i = 0; i < v.n; i++) {
//		cout << v.data[i] << '\t';
//	}
//	return o;
//}


int main() {
	/*Vector<string> v;
	v.push_back("hello");
	v.push_back("sd");
	v.push_back("sad");
	cout<<v;*/
	Vector<student> v;
	v.push_back(student("lis",52));
	v.push_back(student("zhangsn", 62));
	v.push_back(student("wang", 82));
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];//���v.data[i]Ҳ�����൱��student[i]
	}
	return 0;
}