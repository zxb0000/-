#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
template<typename T>
void myswap(T &a,T &b) {
	T temp = a;
	a = b;
	b = temp;

}
template<typename T>
void selectsort(T arr[],int num) {

	for (int i = 0; i < num; i++) {
		int max = i;
		for (int j = i+1; j < num; j++) {
			if (arr[max] < arr[j]) {
				max = j;
			}
		}
		if (max != i) {
			myswap(arr[i], arr[max]);
		}
	}
}
template<typename T>
void printarr(T arr[],int num) {
	for (int i = 0; i < num; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
void test() {
	int arr[] = { 5,6,8,2,4,3,1,5,9,23,4,5 };
	double arrd[] = { 5.21,85.23,1.26,56.002,5.412,3.14005601,2.66 };
	char arrc[] = "nsadjsdasdbbfkfgkdfkughdstkij";
	int num = sizeof(arrc) / sizeof(arrc[0]);
	selectsort(arrc, num);
	printarr(arrc, num);
}
void myprint(int a, int b) {
	cout << "��ͨ����" << endl;

}
template<typename T>
void myprint(T a, T b,T c) {
	cout << "����ģ��" << endl;
}
template<typename T>
void myprint(T a, T b) {
	cout << "ģ��" << endl;
}
template<class nametype,class agetype=int>//��ģ��,������Ĭ�ϲ���int
class person {
public:
	person(nametype n, agetype a);
	nametype name;
	agetype age;
};
template<class nametype,class agetype>//����������ģ���Ա����
person<nametype, agetype>::person(nametype n, agetype a){
	name = n;
	age = a;
}
template<typename T>
bool compare(T &a,T &b) {
	if (a==b) {
		return true;

	}
	else {
		return false;
	}
}
template<>bool compare(person<string,int> &p1, person<string,int>&p2) {//ģ������
	if (p1.age == p2.age && p1.name == p2.name) {
		return true;
		
	}
	else {
		return false;
	}
}
void test1() {
	int a = 1;
	int b = 2;
	//myprint<>(a,b,1);
	cout << compare(a, b) << endl;
}
void test2() {
	person<string,int> p1("asd", 20);
	person<string,int> p2("asd", 20);
	if (compare(p1, p2)) {
		cout <<1 <<endl;
	}
	else {
		cout << 0 <<endl;

	}

}
int main() {
	test2();
	test1();
	return 0;
}