#include "BOOS.h"

Boss::Boss(int id, string name, int deid)
{
	w_ID = id;
	w_name = name;
	w_deID = deid;
}

void Boss::showInfo()
{
	cout << "ID��" << w_ID << "\t"
		<< "������" << w_name << "\t"
		<< "����ID��" << w_deID << "\t"
		<< "�������� " << get_deName() << "\t"
		<< "��λְ��" << get_duty() << endl;
}

string Boss::get_deName()
{
	return string("���²�");
}

string Boss::get_duty()
{
	return string("����˾��������");
}
