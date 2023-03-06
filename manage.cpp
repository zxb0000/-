#include "manage.h"
manage::manage()
{
	initspeech();
	loadrecord();
	createspeaker();
}

void manage::showmenu()
{
	cout << "------------------------------------------------" << endl;
	cout << "---------------  1.��ʼ�ݽ�����  ---------------" << endl;
	cout << "---------------  2.�鿴�����¼  ---------------" << endl;
	cout << "---------------  3.��ձ�����¼  ---------------" << endl;
	cout << "---------------  0.�˳���������  ---------------" << endl;
	cout << "--------------- ---------------- ---------------" << endl;
}

void manage::system_exit()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

void manage::initspeech()
{
	
	this->v1.clear();
	this->v2.clear();
	this->v_win.clear();
	this->m.clear();
	this->round = 1;
	this->m_record.clear();
}

void manage::createspeaker()
{
	string nameseed = "ABCDEFGHIJKL";
	for (int i = 0; i < 12; i++) {
		string name = "ѡ��:";
		name += nameseed[i];
		speaker s;
		s.name = name;
		for (int i = 0; i < 2; i++) {
			s.sorce[i] = 0;
		}
		v1.push_back(10001 + i);
		m.insert(make_pair(10001 + i, s));
	}

}

void manage::speechcontest()
{
	cout << "--------      >>>>>    " << "��" << round << "�ֱ�����ʽ��ʼ��" << "      <<<<<    --------" << endl;
	vector<int>var;
	if (round == 1) {
		var = v1;
	}
	else if (round == 2) {
		var = v2;
	}
	int num = 0;
	multimap<double, int, greater<double>>groupScore;
	for (vector<int>::iterator it = var.begin(); it != var.end(); it++) {
		num++;
		deque<double>de;
		double score;
		for (int i = 0; i < 10; i++) {
			score = (rand() % 401 + 600) / 10.f;
			//cout << score << " ";
			de.push_back(score);
		}
		//cout << endl;
		sort(de.begin(), de.end(), greater<double>());
		de.pop_back();
		de.pop_front();
		double sum = accumulate(de.begin(), de.end(), 0.0);
		double avg = sum / (double)de.size();
		this->m[*it].sorce[this->round - 1] = avg;
		/*cout << "��ţ�" << *it << " " << "������" << this->m[*it].name << " "
			<< "ƽ���֣�" << this->m[*it].sorce[this->round - 1] << endl;*/
		groupScore.insert(make_pair(avg, *it));
		
		if (num % 6 == 0) {
			cout << "--------------------- ��" << num / 6 << "С��ı����ɼ��������� ---------------------" << endl;
			for (multimap<double, int>::iterator it = groupScore.begin(); it != groupScore.end() ; it++) {
				cout << "��ţ�" << it->second << " " << "������" << this->m[it->second].name << " "
					<< "�ɼ���" << this->m[it->second].sorce[this->round - 1] << endl;
			}
			
			int count = 0;//ȡ��ǰ����
			for (multimap<double, int,greater<double>>::iterator it = groupScore.begin(); it != groupScore.end()&&count<3; it++,count++) {
				if (round == 1) {
					v2.push_back(it->second);
				}
				else if (round == 2) {
					v_win.push_back(it->second);
				}
			}
			groupScore.clear();//��ղ��������ݣ���ֹ�´��ڶ�ȡ
			cout << endl;
		}

	}
	cout << "--------      >>>>>    " << "��" << round << "�ֱ���������" << "      <<<<<    --------" << endl;
	system("pause");
}

void manage::showscore()
{
	cout << "--------------------------  ��" << round << "�ֵĽ�������Ϊ --------------------------" << endl;
	vector<int>v;
	if (round == 1) {
		v = v2;
	}
	else {
		v = v_win;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "��ţ�" << *it << "  ������"<<this->m[*it].name<< "�ɼ���" <<this-> m[*it].sorce[round-1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
}

void manage::starspeech()
{
	//1.��ǩ
	this->stardraw();
	//2.����
	this->speechcontest();
	//3.��ʾ���
	this->showscore();
	this->round++;
	//1.��ǩ
	this->stardraw();
	//2.����
	this->speechcontest();
	//3.��ʾ���
	this->showscore();
	//������
	this->save();
	//��������
	initspeech();
	loadrecord();
	createspeaker();

}

void manage::stardraw()
{
	if (round == 1) {
		cout << "ѡ�������ڽ��е�" << round << "�ֳ�ǩ!" << endl;
		cout << "--------------------------------------------" << endl;
		cout<<"������£�"<<endl;
		random_shuffle(v1.begin(), v1.end());
		for_each(v1.begin(), v1.end(), [](int a) {cout << a << " "; });
		cout << endl;
	}
	if (round == 2) {
		cout << "ѡ�������ڽ��е�" << round << "�ֳ�ǩ!" << endl;
		random_shuffle(v2.begin(), v2.end());
		for_each(v2.begin(), v2.end(), [](int a) {cout << a << " "; });
		cout << endl;
	}
	cout << "--------------------------------------------" << endl;
	system("pause");
}

void manage::save()
{
	ofstream ofs("speech.csv", ios::out | ios::app);
	for (vector<int>::iterator it = v_win.begin(); it != v_win.end(); it++) {
		ofs<< *it <<","<< m[*it].sorce[1] << ",";
	}
	ofs << endl;
	ofs.close();
	fileisempty = false;
	cout << "����ɹ���" << endl;
}

void manage::loadrecord()
{
	
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open()) {
		//cout << "�ļ���ʧ�ܣ�" << endl;
		fileisempty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//cout << "�ļ�Ϊ�գ�" << endl;
		fileisempty = true;
		ifs.close();
		return;
	}
	fileisempty = false;
	ifs.putback(ch);
	string data;
	int index = 0;
	while (ifs>>data) {
		//cout << data;
		int star = 0;
		int pos = -1;
		vector<string>v;
		while (1) {
			pos = data.find(",", star);
			if (pos == -1) {
				break;
			}
			string temp = data.substr(star, pos-star);
			//cout << temp << endl;
			v.push_back(temp);
			star = pos + 1;
		}
		this->m_record.insert(make_pair(index,v));
		index++;
	}
	/*for (map<int, vector<string>>::iterator it = m_record.begin(); it != m_record.end(); it++) {
		cout << "��" << it->first <<"�� " << " �ھ��ı�ţ�" 
			<< it->second[0] << " ����Ϊ��" << it->second[1] << endl;
	}*/
	ifs.close();
	
}

void manage::showrecord()
{
	if (this->fileisempty) {
		cout << "�ļ�Ϊ�գ�" << endl;
	}
	else {
		for (int i = 0; i < this->m_record.size(); i++) {
			cout << "��" << i + 1 << "��"
				<< "  �ھ���� ��" << m_record[i][0] << " �ɼ�: " << m_record[i][1]
				<< "  �Ǿ���� ��" << m_record[i][2] << " �ɼ�: " << m_record[i][3]
				<< "  ������� ��" << m_record[i][4] << " �ɼ�: " << m_record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
}

void manage::clearrecord()
{
	int choice;
	cout << "�Ƿ�ȷ����գ�" << endl;
	cout << "1.��" << endl;
	cout << "2.��" << endl;
	cin >> choice;
	if (choice == 1) {
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		initspeech();
		loadrecord();
		createspeaker();
		cout << "�����ɣ�" << endl;
	}
	system("pause");
	system("cls");
}

manage::~manage()
{
}
