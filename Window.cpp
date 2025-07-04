#include "Window.h"
#include <iostream>
#include "BasicWidget.h"
Window::Window(int w, int s, int flag)
{
	m_handle = ::initgraph(w, s, flag);
	::setbkmode(TRANSPARENT); 
}

void Window::setWindowTilte(const string& title)
{
	::SetWindowText(m_handle, title.c_str());
}

int Window::exec()
{
	return getchar();
}



int Window::width()
{
	return ::getwidth();
}

int Window::height()
{
	return ::getheight();
}

void Window::clear() {
	::cleardevice();
}

void Window::beginDraw()
{
	::BeginBatchDraw();
}

void Window::flushDraw()
{
	::FlushBatchDraw();
}

void Window::endDraw()
{
	::EndBatchDraw();
}
