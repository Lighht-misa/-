#pragma once

//通过预编译的方式去掉UNicode字符集
#ifdef UNICODE
#undef UNICODE
#endif 
#include <easyx.h>
#include<string>
using namespace std;
