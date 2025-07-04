#include "Student.h"
#include <sstream>
Student::Student()
{
}

Student::Student(uint32 number, const string& name, const string& grade, uint32 math, uint32 Chinese, uint32 english)
	:number(number),name(name),grade(grade),math(math),Chinese(Chinese),english(english)
{
	 
}

std::string Student::formatInfo()
{
	std::stringstream ss;
	ss << number << "t" << "t" << name << "t" << grade << "t" << math << "t" << Chinese << "t" << english << std::endl;
	return ss.str();
}
