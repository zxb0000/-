#include "employee.h"

employee::employee(int id, string name, int deid)
{
	this->w_ID = id;
	this->w_name = name;
	this->w_deID = deid;
}

void employee::showInfo()
{
	cout << "ID��" << w_ID << "\t"
		<< "������" << w_name << "\t"
		<< "����ID��" << w_deID << "\t"
		<< "�������� " << get_deName() << "\t"
		<< "��λְ��" << get_duty() << endl;
}

string employee::get_deName()
{
	return string("һ��Ա��");
}

string employee::get_duty()
{
	return string("����ϼ�������");
}
