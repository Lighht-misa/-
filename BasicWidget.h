#pragma once
class BasicWidget
{
public:
	BasicWidget(int x, int y, int w, int h);
	int width();
	int height();
	int setFixedSize(int w ,int h);


	int X();
	int Y();
	void move(int x, int y);

	virtual void show() = 0;
protected:
	int m_x;
	int m_y;
	int m_w;
	int m_h;

};

