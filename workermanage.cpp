#include "workermanage.h"
void WorkerManage::init_data()
{
	ifstream ifs(FILEDATA, ios::in | ios::binary);
	int id;
	string name;
	int deid;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> deid) {
		Worker* worker = NULL;
		switch (deid)
		{
		case 1:worker = new employee(id, name, deid); break;
		case 2:worker = new Manager(id, name, deid); break;
		case 3:worker = new Boss(id, name, deid); break;
		default:
			break;
		}
		workerarr[index++] = worker;
	}
	ifs.close();
}
void WorkerManage::show_woker()
{
	if (fileisempty) {
		cout << "û�����ݣ�" << endl;
	}
	else {
		for (int i=0; i < w_Num; i++) {
			workerarr[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
void WorkerManage::Addworker()
{
	cout << "������Ҫ��ӵ�Ա������:" << endl;
	int addnum;
	cin >> addnum;
	if (addnum > 0) {
		int newnum = this->w_Num + addnum;
		Worker** newspace = new Worker * [newnum];
		if (this->workerarr != NULL) {//���ԭ���������ݣ���ԭ��������ת�Ƶ��µĿռ���
			for (int i = 0; i < this->w_Num; i++) {
				newspace[i] = workerarr[i];
				}
		}
		for (int i = 0; i < addnum; i++) {//���������
			int id;
			int selectdeid;
			string name;
			cout << "�������" << i +1<< "���˵�ID" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "���˵�����" << endl;
			cin >>name;

			cout << "��ѡ���" << i + 1 << "���˵Ĳ���" << endl;
			cout << "1.һ��Ա��" << endl;
			cout << "2.������" << endl;
			cout << "3.���²�" << endl;
			cin >> selectdeid;
			Worker* worker=NULL;
			switch (selectdeid)
			{
			case 1:
				worker = new employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				cout<<"��������";
				break;
			}
			//���´�����Ա��������ӵ�������
			newspace[this->w_Num + i] = worker;
		}
		//�ͷ�ԭ���Ŀռ�
		delete []this->workerarr;
		workerarr = newspace;
		this->w_Num = newnum;
		save();
		fileisempty = false;
		cout << "�ɹ������" << addnum << "����Ա��" << endl;
		
	}
	else {
		cout << "��������";
		return;
	}
	system("pause");
	system("cls");
}

int WorkerManage::isexist(int id)
{
	int index = -1;
	for (int i = 0; i < w_Num; i++) {
		if (workerarr[i]->w_ID == id) {
			index = i;
		}
	 }
	return index;
}

void WorkerManage::del_worker()
{
	
	if (fileisempty) {
		cout << "���ݿ�,�޷�������" << endl;
	}
	else {
		int id;
		cout << "������Ҫɾ��Ա����ID:" << endl;
		cin >> id;
		int index = isexist(id);
		if (index == -1) {
			cout << "ʧ�ܣ���ѯ�޴�id" << endl;
			
		}
		else {
			for (int i = index; i < w_Num-1; i++) {
				workerarr[i] = workerarr[i + 1];
			}
			w_Num--;
			save();
			cout << "ɾ���ɹ���" << endl;
			
		}
	}
	system("pause");
	system("cls");
}

void WorkerManage::mod_worker()
{
	if (fileisempty) {
		cout << "����Ϊ�գ��޷��޸ģ�" << endl;
	}
	else {
		int id;
		cout << "������Ҫ�޸��˵�ID:" << endl;
		cin >> id;
		int index = isexist(id);
		if (index == -1) {
			cout << "���޴��ˣ��޷��޸ģ�" << endl;
		}
		else{
			delete workerarr[index];
			Worker* worker=NULL;
			int newid;
			string newname;
			int newdeid;
			cout << "�������µ�id" << endl;
			cin >> newid;
			cout << "�������µ�����" << endl;
			cin >> newname;
			
			cout << "��ѡ���µĲ���:" << endl;
			cout << "1.һ��Ա��" << endl;
			cout << "2.������" << endl;
			cout << "3.���²�" << endl;
			cin >> newdeid;
			switch (newdeid)
			{
			case 1:
				worker = new employee(newid, newname, newdeid);
				break;
			case 2:
				worker = new Manager(newid, newname, newdeid);
				break;
			case 3:
				worker = new Boss(newid, newname, newdeid);
				break;
			default://�����⣡
				cout << "�������" << endl;
				break;
			}
			workerarr[index] = worker;
			save();
			cout << "�޸���ɣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManage::find_worker()
{
	if (fileisempty) {
		cout << "����Ϊ�գ�" << endl;
	}
	else {
		int select = -1;
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1.����ID����" << endl;
		cout << "2.������������" << endl;
		cin >> select;
		if (select == 1) {
			cout << "������ID��" << endl;
			int id;
			cin >> id;
			int index = isexist(id);
			if (index == -1) {
				cout << "��ѯ�޴�ID��" << endl;
				return;
			}
			else {
				workerarr[index]->showInfo();
			}
		}
		else if (select == 2) {
			cout << "������������" << endl;
			string name;
			cin >> name;
			int flag = 0;
			for (int i = 0; i < w_Num; i++) {
				if (workerarr[i]->w_name == name) {
					workerarr[i]->showInfo();
					flag = 1;
				}
			}
			if (flag == 0) {
				cout << "û���ҵ����˵������Ϣ!" << endl;
			}
		}
		else {
			cout << "�������" << endl;
		}
	}
	system("pause");
	system("cls");
}
int cmp_id_up(const void* e1, const void* e2) {
	return (*((Worker**)e1))->w_ID - (*((Worker**)e2))->w_ID;
}
int cmp_id_down(const void* e1, const void* e2) {
	return  (*((Worker**)e2))->w_ID - (*((Worker**)e1))->w_ID;
}
void WorkerManage::sort()
{
	if (fileisempty) {
		cout << "����Ϊ�գ��޷�����" << endl;
		system("pause");
		system("cls");
	}
	else {
		int select=0;
		cout << "������Ҫ����ķ���" << endl;
		cout << "1.����ID����" << endl;
		cout << "2.����ID����" << endl;
		//cout << "1.������������" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			qsort(workerarr, w_Num, sizeof(Worker*), cmp_id_up);
			break;
		case 2:
			qsort(workerarr, w_Num, sizeof(Worker*), cmp_id_down);
			break;
		default:
			break;
		}
		cout << "������ɣ�" << endl;
		show_woker();
		save();
		
	}

}

void WorkerManage::clean()
{
	cout << "ȷ��Ҫ������е�������" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.ȡ��" << endl;
	int choice;
	cin >> choice;
	if (choice == 1) {
		ofstream ofs(FILEDATA, ios::trunc);
		ofs.close();
		if(workerarr!=NULL){
			for (int i = 0; i < w_Num; i++) {
				delete workerarr[i];
				workerarr[i] = NULL;
			}
			delete[]workerarr;
			workerarr = NULL;
			w_Num = 0;
			fileisempty = true;
		}
		cout << "����ɹ���" << endl;
		system("pause");
		system("cls");
	}
	else {
		system("cls");
		return;
	}
}

int WorkerManage::getnum()
{
	ifstream ifs(FILEDATA, ios::in | ios::binary);
	int id;
	string name;
	int deid;
	int num=0;
	while (ifs >> id && ifs >> name && ifs >> deid) {
		num++;
	}
	ifs.close();
	return num;
}

void WorkerManage::save()
{
	ofstream ofs(FILEDATA, ios::out | ios::binary);
	if (!ofs.is_open()) {
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	for (int i = 0; i < this->w_Num; i++) {
		ofs << this->workerarr[i]->w_ID << " " << workerarr[i]->w_name << " " << workerarr[i]->w_deID << endl;
	}
	ofs.close();
}

WorkerManage::WorkerManage()
{
	ifstream ifs(FILEDATA, ios::in | ios::binary);
	if(!ifs.is_open()){
		//cout << "�����ļ�������" << endl;
		w_Num = 0;
		workerarr = NULL;
		fileisempty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//cout << "�ļ�Ϊ��" << endl;
		w_Num = 0;
		workerarr = NULL;
		fileisempty = true;
		ifs.close();
		return;
	}
	ifs.close();
	int num = getnum();
	//cout << "ְ������Ϊ" << num << "��" << endl;
	w_Num = num;
	workerarr = new Worker * [w_Num];
	init_data();
	fileisempty = false;
	/*for (int i = 0; i < w_Num; i++) {
		cout << "ID��        " << workerarr[i]->w_ID << "\t"
			<< "������      " << workerarr[i]->w_name << "\t"
			<< "����ID��    " << workerarr[i]->w_deID << "\t"
			<< "��������    " << workerarr[i]->get_deName() << "\t"
			<< "��λְ��  " << workerarr[i]->get_duty() << endl;
	}*/
	
	
}

WorkerManage::~WorkerManage()
{
	if (workerarr != NULL) {
		delete[]workerarr;
		workerarr = NULL;
	}
}

void WorkerManage::exitststem()
{
	cout << "ϵͳ�Ѿ��˳���" << endl;
	exit(0);
	system("pause");
}

void WorkerManage::Worker_showmenu()
{
	cout << "----------------------------------------" << endl;
	cout << "-------  ��ӭʹ��ְ������ϵͳ! ---------" << endl;
	cout << "---------   1.����ְ����Ϣ     ---------" << endl;
	cout << "---------   2.��ʾְ����Ϣ     ---------" << endl;
	cout << "---------   3.ɾ��ְ����Ϣ     ---------" << endl;
	cout << "---------   4.�޸�ְ����Ϣ     ---------" << endl;
	cout << "---------   5.����ְ����Ϣ     ---------" << endl;
	cout << "---------   6.����ְ����Ϣ     ---------" << endl;
	cout << "---------   7.�������ְ����Ϣ ---------" << endl;
	cout << "---------   0.�˳�����        ----------" << endl;
	cout << "----------------------------------------" << endl;
}
