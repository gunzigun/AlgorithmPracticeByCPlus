// �����½�������Լ���Ż���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

// ������2ά�ģ�����һ��������
class Example
{
public:
	// Ĭ�Ϲ��캯��
	Example():x1(0),x2(0){}
	// �������캯��
	Example(float num1, float num2):x1(num1),x2(num2){}
	// �Ż�����
	float Function()
	{
		return x1*x1 + 25*x2*x2;
	}
	// �ݶȺ���
	Example GridianFunction()
	{
		Example Exam;
		Exam.x1 = 2 * this->x1;
		Exam.x2 = 100 * this->x2;
	}
private:
	// ������������
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

