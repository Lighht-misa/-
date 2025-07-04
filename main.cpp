#include "Mangement.h"
#include "Window.h"
int main() {
	Window w(960,640,EX_SHOWCONSOLE);
	w.setWindowTilte("学生成绩管理系统"); 
	Mangement m;
	m.run();
	return 0;
}