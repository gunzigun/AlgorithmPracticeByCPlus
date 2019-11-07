// 最速下降法（无约束优化）.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

// 数据是2维的，定义一个数据类
class Example
{
public:
	// 默认构造函数
	Example():x1(0),x2(0){}
	// 参数构造函数
	Example(float num1, float num2):x1(num1),x2(num2){}
	// 优化函数
	float Function()
	{
		return x1*x1 + 25*x2*x2;
	}
	// 梯度函数
	Example GridianFunction()
	{
		Example Exam;
		Exam.x1 = 2 * this->x1;
		Exam.x2 = 100 * this->x2;
	}
private:
	// 两个参数变量
	float x1;
	float x2;
};



int _tmain(int argc, _TCHAR* argv[])
{
	Example X(2,2);
	float f = X.Function();
	Example Gridiant = X.GridianFunction();



	return 0;
}

