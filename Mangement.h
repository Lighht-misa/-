#pragma once
#include "Window.h"
#include <vector>
#include "PushButton.h"
#include "Student.h"
class Mangement
{
	enum Operator {
		Display,
		Insert,
		Remove,
		Modify,
		Search,
		Menu=66,
	 };
public:
	Mangement();
	//����������
	void run();
	//  menu
	int menu();
	//1 ��ʾ���е�ѧ��
	void display();
	//2 ���ѧ��
	void add();
	//3 delete
	void erase();
	//4 modify
	void modify();
	//5 seach
	void search();

	//���Ʊ���
	void drawBackground();
	void eventLoop();

	void readFile(const string& fileName);
	void saveFile(const string& fileName);

private:
	ExMessage m_msg;
	IMAGE m_bk;
	vector<PushButton*>menu_btns;
	//��ȡ�ļ�  ����ѧ����Ϣ
	std::string m_header;
	std::vector<Student> vec_stu;

};

