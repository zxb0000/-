#include "manager.h"

Manager::Manager(int id, string name, int deid)
{
	w_ID = id;
	w_name = name;
	w_deID = deid;
}

void Manager::showInfo()
{
	cout << "ID��" << w_ID << "\t"
		<< "������" << w_name << "\t"
		<< "����ID��" << w_deID << "\t"
		<< "�������� " << get_deName() << "\t"
		<< "��λְ��" << get_duty() << endl;
}

string Manager::get_deName()
{
	return string("�����");
}

string Manager::get_duty()
{
	return string("�ϴ��´");
}
