#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class abstractdrinking {//������
public:
	//��ˮ
	virtual void absboiling() = 0;//���麯��
	//������Ʒ
	virtual void absbeverage() = 0;
    //װ�뱭��
	virtual void abscup() = 0;
	//�������
	virtual void absseasoning()=0;
	void makedrinking(){
		absboiling();
		absbeverage();
		abscup();
		absseasoning();
		cout << "������ɣ�" << endl;
	}
};
class tea:public abstractdrinking {
	//��ˮ
	virtual void absboiling() {//���麯��
	
		cout << "������ȻȪˮ��" << endl;
	}
	//������Ʒ
	virtual void absbeverage() {
		cout << "�����Ҷ" << endl;
	}
	//װ�뱭��
	virtual void abscup() {
		cout << "����豭��" << endl;
	}
	//�������
	virtual void absseasoning() {
		cout << "������轣�" << endl;
	}
};
class coffee :public abstractdrinking {
	//��ˮ
	virtual void absboiling() {//���麯��

		cout << "����Ȫˮ��" << endl;
	}
	//������Ʒ
	virtual void absbeverage() {
		cout << "����èʺ����" << endl;
	}
	//װ�뱭��
	virtual void abscup() {
		cout << "���뿧�ȱ���" << endl;
	}
	//�������
	virtual void absseasoning() {
		cout << "�����ǿ飡" << endl;
	}
};
void dodrinking(abstractdrinking * abs) {
	abs->makedrinking();
	delete abs;
}
int main() {
	dodrinking(new coffee);
	dodrinking(new tea);
	return 0;
}