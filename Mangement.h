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
	//启动管理类
	void run();
	//  menu
	int menu();
	//1 显示所有的学生
	void display();
	//2 添加学生
	void add();
	//3 delete
	void erase();
	//4 modify
	void modify();
	//5 seach
	void search();

	//绘制背景
	void drawBackground();
	void eventLoop();

	void readFile(const string& fileName);
	void saveFile(const string& fileName);

private:
	ExMessage m_msg;
	IMAGE m_bk;
	vector<PushButton*>menu_btns;
	//读取文件  保存学生信息
	std::string m_header;
	std::vector<Student> vec_stu;

};

