#pragma once
#include<iostream>
#include"speaker.h"
#include<vector>
#include<map>
#include<algorithm>
#include<deque>
#include<numeric>
#include<string>
#include<fstream>
using namespace std;
class manage {
public:
	manage();
	void showmenu();
	void system_exit();
	vector<int>v1;//��һ�غϵ���
	vector<int>v2;//�ڶ��غϵ���
	vector<int>v_win;//��ʤ��
	map<int, speaker>m;// ��ű���Լ�ѡ��
	int round;//��������
	map<int, vector<string>>m_record;
	void initspeech();
	void createspeaker();
	void speechcontest();
	void showscore();
	void starspeech();
	void stardraw();
	void save();
	void loadrecord();
	void showrecord();
	void clearrecord();
	bool fileisempty;
	~manage();
};
