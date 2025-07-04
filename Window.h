#pragma once
#include "configure.h"
class Window
{
public :
	Window(int w, int s, int flag);
	void setWindowTilte(const string&tilte);
	int exec();
	static int width();
	static int height();
	static void clear();
	static void beginDraw();
	static void flushDraw();
	static void endDraw();

	//����������������
	//�ж���û����Ϣ
	inline static bool hasMag() { return ::peekmessage(&m_msg, EX_MOUSE | EX_KEY); }
	inline static const ExMessage& getMsg() { return m_msg; }
	 
private:
	HWND m_handle;//���ھ��
	inline static ExMessage m_msg;//�����Ϣ�ͼ�����Ϣ
};


