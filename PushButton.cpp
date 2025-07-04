#include "PushButton.h"
#include <iostream>
using namespace std;

PushButton::PushButton(const std::string& text, int x, int y, int w, int h) 
	:BasicWidget(x,y,h,w),m_text(text)
{

}

void PushButton::show()
{
	setfillcolor(cur_c);
	::fillroundrect(m_x, m_y, m_x + m_w, m_y + m_h, 10, 10);

	settextcolor(BLACK);
	//把文字剧中显示在按钮中间
	int tx = m_x+(m_w - textwidth(m_text.c_str())) / 2 ;
	int ty = m_y + (m_h - textheight(m_text.c_str())) / 2;
	::outtextxy(tx, ty, m_text.c_str());
}

bool PushButton::isin()
{
	if (m_msg.x >= m_x && m_msg.x < m_x + m_w && m_msg.y >= m_y && m_msg.y <= m_y + m_h)//判断鼠标是不是在按钮上
	{
		return true;
	}
	return false;
}

bool PushButton::isCilcked()
{
	if (isin())
	{
		if (m_msg.message == WM_LBUTTONDOWN)//判断按钮是否被点击
		{
			cout << "按钮被点击\n"; 
			return true;
		}
	}
	return false;
}

void PushButton::eventLoop(const ExMessage& msg)
{
	m_msg = msg;
	//如果鼠标没有在按钮上
	if (!isin()) {
		cur_c = norman_c;
	}
	else {
		cur_c = hover_c;
	}
}

void PushButton::setBackgroundColor(COLORREF c)
{
	norman_c = c;
}

void PushButton::setHoverColor(COLORREF c)
{
	hover_c = c;
}
