// ƽ�ַ������¡��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#define INIT_MIN_NUM  -1
#define INIT_MAX_NUM  3
#define ERROR_ACURATE 0.32

// ͼ�μ��㺯��
float CurvefunctionNum(float fX)
{
	return fX * fX - fX + 2;
}

// �󵼺���
float CurveDaoFunction(float fX)
{
	return 2 * fX - 1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	float a = INIT_MIN_NUM;
	float b = INIT_MAX_NUM;

	int n = 0;
	while (b > (ERROR_ACURATE + a))
	{
		float c = (a + b) / 2;
		float fc = CurveDaoFunction(c);

		cout << "��" << n << "�ε�����a = " << a << ", b = " << b << ", c = " << c << ", fc = " << fc << endl;

		if (fc > 0)
		{
			b = c;
		}
		else if (fc == 0)
		{
			cout << "�ҵ���ֵΪ��" << c << endl;
			return 0;
		}
		else if (fc < 0)
		{
			a = c;
		}

		++n;
	}

	cout << "�ҵ���ֵΪ��" << (a + b) / 2 << endl;

	return 0;
}

