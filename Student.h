#pragma once
#include "configure.h"
#include <string>
using uint32 = unsigned int;
class Student
{
public:
	Student();
	Student(uint32 number, const string& name, const string& grade,
		uint32 math, uint32 Chinese, uint32 english);
	uint32 number;
	std::string name;
	std::string grade;
	uint32 math;
	uint32 Chinese;
	uint32 english;

	std::string formatInfo();//格式化数据

private:

};

