#pragma once
#include "BasicWidget.h"
#include "configure.h"
class PushButton :
    public BasicWidget
{
public :
    PushButton(const std::string& text = "BUTTON", int x = 0, int y = 0, int w = 30, int h = 150);

    void show() override;

    bool isin();//�ж�����Ƿ��ڵ�ǰ��ť��
    bool isCilcked();//�ж�����Ƿ����˰�ť

    void eventLoop(const ExMessage& msg);
    void setBackgroundColor(COLORREF c);
    void setHoverColor(COLORREF c);
private:
    std::string m_text;
    ExMessage m_msg;

    COLORREF cur_c = RGB(232, 232, 233);
    COLORREF norman_c = RGB(232, 232, 233);
    COLORREF hover_c = RED;

};

