#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cmath>
#include<iostream>
#if 0
int main() {
	printf("helsld!\n");
	double x = 3.14;
	printf("%lf,%lf \n",sqrt(x),sin(x));
	char he[] = "hesss !";
	puts(he);
		return 0;
}
#endif
////using namespace std;//Ҳ����ֱ���������ֿռ�
////using std::cout;//������������
////int main() {
////	cout << "helllsd"<<std::endl;//endl�൱�ڻ��з�
////	std::cout << 1+2 <<std::endl;
////	double radius;
////	std::cin >> radius;//������>>
////	cout << radius *radius* 3.14<<endl;
////	return 0;
////}
////#include<fstream>
////using namespace std;
////int main() {
////	int a = 3;
////	int& r = a;
////	cout << a << endl;
////	cout << r<< endl;
////	r = 6;
////	cout << a << endl;
////	cout << r << endl;
////	return 0;
////}
////void print(char ch, int n = 1) {
////	for (int i = 0; i < n; i++) {
////		std::cout << ch;
////	}
////}
////int main() {
////	print('#'); std::cout << std::endl;
////	print('#',3);
////	print('#',5);
////
////	return 0;
////}
////����ģ��
//#include<string>
//using namespace std;
//template<typename T>
//T add(T a, T b) {
//	return a + b;
//}
//int main() {
//	std::cout<<add<int>(1 ,3)<<endl;
//	std::cout<<add<double>(3.5 ,5)<<endl;
//	std::cout<<add<string>("ss", "aaa"); 
//}
//int main() {
//	std::cout << add(1, 3) << endl;
//	std::cout << add(3.5, 5.0) << endl;//��ʹ��д����Ҳ���Զ��ƶ����ͽ�����Ӧ�ĺ���ģ��
//	std::cout << add(3.5, (double)5) << endl;//����������ݵ����Ͳ�һ���ͻ����������
//	
//}
//#include<iostream>
//using namespace std;
//int main() {
//	string s1 = "hello,bit", s2("hello word!"), s3{ "���ʹ�v" },s4;
//	cout << s1.size() << endl;
//	cout << s1.substr(2,4) << endl;//��ȡ�ڶ����ַ�����4���ַ�
//	s4=s1.substr(2,4) ;
//	cout << s2+" "+s3<<endl;//�ܹ����мӵ�ƴ��
//	s2[2] = 'X';//��s2���±�Ϊ2���滻Ϊ��X
//	int pos=s1.find("llo");//����llo ���������Ŀ�ʼ�±�
//	cout << pos<<endl;
//	cout << s2.insert(5,"the") << endl;//���±�Ϊ5��λ�ò���
//	for (int i = 0; i < s2.size(); i++) {
//		cout << s2[i] << '-';
//	}
//	return 0;
//}
#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<int>v1 = {1, 2, 3, 4, 5};//����һ��int����
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << '\t';
	}
	cout << '\n';
	v1.push_back(25);//����������һ��25
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << '\t';
	}
	cout << '\n';
	v1.pop_back();//�������һ��Ԫ��
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << '\t';
	}
	cout << '\n';
	v1.resize(3);//���¶����СΪ3
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << '\t';
	}
	cout << '\n';
	return 0;
}