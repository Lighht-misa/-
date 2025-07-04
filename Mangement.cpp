#include "Mangement.h"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <sstream>

using namespace std;
 Mangement::Mangement()
{
	::loadimage(&m_bk, "./image/bk.png", Window::width(), Window::height());

	//���ļ�
	readFile("./image/student.txt");
	//�����水ť��ʼ��
	menu_btns.push_back(new PushButton("�鿴ѧ��"));
	menu_btns.push_back(new PushButton("���ѧ��"));
	menu_btns.push_back(new PushButton("ɾ��ѧ��"));
	menu_btns.push_back(new PushButton("�޸�ѧ��"));
    menu_btns.push_back(new PushButton("����ѧ��"));
	menu_btns.push_back(new PushButton("�˳�ϵͳ"));
	for (int i = 0; i < menu_btns.size(); i++) {
		menu_btns[i]->setFixedSize(250, 50);
		int bx = (Window::width()-menu_btns[i]->width()) / 2;
		int vspace = (Window::height() - menu_btns.size() * menu_btns[i]->height()) / 2;
		int by = vspace + i * menu_btns[i]->height();
		menu_btns[i]->move(bx,by);
	}
}
int Mangement::menu()
{
	for (int i = 0; i < menu_btns.size(); i++)
	{
		menu_btns[i]->show();
		menu_btns[i]->eventLoop(m_msg);
		if (menu_btns[i]->isCilcked()) //�����ť�����
		{
			return i;
		}
	}
	return Menu;
}
void Mangement::run() 
{
	//��ȡ�˵��ķ���ֵ
	int op = Menu;
	Window::beginDraw();
	while (true) 
     {
	Window::clear();
	drawBackground();
	if (Window::hasMag()) 
		{
			m_msg = Window::getMsg();
			switch (m_msg.message)
			{
			case WM_KEYDOWN://�жϰ����Ƿ���
				//��ESC �˳�����������������
				if (m_msg.vkcode == VK_ESCAPE)
				{
					op = Menu;
				}
				break;
			default: //������
				break;
			}
		}
	switch (op)
	{
	case Menu:
		op = menu();
		break;
	case Mangement::Display:
		display();
		break;
	case Mangement::Insert:
		add();
		break;
	case Mangement::Remove:
		erase();
		break;
	case Mangement::Modify:
		modify();
		break;
	case Mangement::Search:
		search();
		break;
	default:
		saveFile("./image/test.txt");
		exit(666);
		break;
	}
	Window::flushDraw();
	}
	Window::endDraw();
}
void Mangement::display()
{
	outtextxy(0, 0, "display");
	cout << "display" << endl;
}

void Mangement::add()
{
	outtextxy(0, 0, "add");
	cout << "add" << endl;
}

void Mangement::erase()
{
	outtextxy(0, 0, "erase");
	cout << "erase" << endl;
}

void Mangement::modify()
{
	outtextxy(0, 0, "modify");
	cout << "modify" << endl;
}

void Mangement::search()
{
	outtextxy(0, 0, "search");
	cout << "search" << endl;
}

void Mangement::drawBackground()
{
	::putimage(0, 0, &m_bk);
}

void Mangement::eventLoop()
{

}

void Mangement::readFile(const string& fileName)
{
	fstream read(fileName, ios::in);
	if (!read.is_open()) {
		return;
	}
	//��ȡ��ͷ
	char buf[1024] = { 0 };
	read.getline(buf, 1024);
	m_header = buf;
	//��ȡ����
	while (!read.eof())
	{
		char data[1024] = { 0 };
		read.getline(buf, 1024);

		std::stringstream ss(data);
		Student stu;
		ss >> stu.number >> stu.name>>  stu.grade >> stu.math >> stu.Chinese >> stu.english;
		vec_stu.push_back(stu);
	}
	read.close();
}

void Mangement::saveFile(const string& fileName)
{
	fstream write(fileName, ios::out | ios::trunc);
	if (!write.is_open())
	{
		cerr << fileName << "File open failed" << endl;
		return;
	}

	//дͷ������
	m_header;
	write.write(m_header.c_str(), m_header.size());

	//д����
	for(auto & val:vec_stu)
		{
		std::string info = val.formatInfo();
		write.write( val.formatInfo().c_str(),info.size());
		}

	write.close();
}
