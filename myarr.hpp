#include<iostream>
using namespace std;
template<class T>
class myarr {
public:
	myarr(int cap) {
		cout << "���캯��" << endl;
		this->m_capacity = cap;
		this->m_size = 0;
		this->parr = new T[cap];
	}
	myarr(const myarr& arr) {
		cout << "��������" << endl;
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		this->parr = new T[m_capacity];
		for (int i = 0; i < m_size; i++) {
			this->parr[i] = arr.parr[i];
		}
	}
	myarr& operator=(const myarr &arr) {
		cout << "=����" << endl;
		if (this->parr != NULL) {
			delete[]parr;
			parr = NULL;
			this->m_capacity = 0;
			this->m_size = 0;
		}
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		this->parr = new T[m_capacity];
		for (int i = 0; i < m_size; i++) {
			this->parr[i] = arr.parr[i];
		}
		return *this;
	}
	void push_data(const T &n) {
		if (this->m_size ==this->m_capacity) {
			cout << "����������" << endl;
			return;
		}
		//cout << "push��" << endl;

		this->parr[this->m_size] = n;
		this->m_size++;
	}
	int get_size() {
		return m_size;
	}
	int get_capacity() {
		return m_capacity;
	}
	void pop_data() {
		if (this->m_size == 0) {
			cout << "����Ϊ�գ�" << endl;
			return;
		}
		//cout << "pop��" << endl;

		m_size--;

	}
	~myarr() {
		cout << "��������" << endl;
		delete[] parr;
		parr = NULL;
	}
	T& operator[](int n) {
		if (n < 0 || n >= m_size) {
			cout << "�±�Ƿ���" << endl;
		}
		else {
				
		return this->parr[n];
		}
	
	}
private:
	T* parr=NULL;
	int m_size;
	int m_capacity;
};