// ����ȷһά���������¡��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

// ����һ����ά�����Ľṹ
struct TwoVisionVector
{
	float x1;
	float x2;

public:
	TwoVisionVector(void){}
	TwoVisionVector(float num1, float num2) { x1 = num1; x2 = num2; }
};

// ���㺯��ֵ
float GetFunctionNum(TwoVisionVector tmpvector)
{
	float x1 = tmpvector.x1;
	float x2 = tmpvector.x2;
	float f = 100 * (x2 - x1*x1)*(x2 - x1*x1) + (1 - x1)*(1 - x1);
	return f;
}

// ���㺯�����ݶ�ֵ
TwoVisionVector GetGradiantVector(TwoVisionVector tmpvector)
{	
	TwoVisionVector returnVector;
	float x1 = tmpvector.x1;
	float x2 = tmpvector.x2;
	returnVector.x1 = -400 * (x2 - x1*x1)*x1 - 2*(1 - x1);
	returnVector.x2 = 200 * (x2 - x1*x1);

	return returnVector;
}

// ��ȡ���������ĵ��
float GetVectorPointMult(TwoVisionVector vector1, TwoVisionVector vector2)
{
	return vector1.x1*vector2.x1 + vector1.x2*vector2.x2;
}


int _tmain(int argc, _TCHAR* argv[])
{

	TwoVisionVector xk(-1,1);
	float fk = GetFunctionNum(xk);
	TwoVisionVector Grak = GetGradiantVector(xk);
	TwoVisionVector pk(1,1);
	float a = 0;
	float b = 100000000;
	float qw = 0.1;
	float bzc = 0.5;
	float d = 1;

	int n = 0;
	while (1)
	{
		cout << "��" << n << "�˼��㣺";

		TwoVisionVector xkpie;
		xkpie.x1 = xk.x1 + d * pk.x1;
		xkpie.x2 = xk.x2 + d * pk.x2;
		
		cout << "d = " << d << ", ";
		cout << "x(k+1) = " << "(" << xkpie.x1 << "," << xkpie.x2 << "), ";
		
		float fkpie = GetFunctionNum(xkpie);
		TwoVisionVector Grakpie = GetGradiantVector(xkpie);
		cout << "fx = " << fkpie << ", ";

		float comparenum1 = -qw*d*GetVectorPointMult(Grak, pk);
		float comparenum2 = bzc*GetVectorPointMult(Grak, pk);
		bool bOK1 = (fk - fkpie >= comparenum1);
		bool bOK2 = (GetVectorPointMult(Grakpie, pk) >= comparenum2);

		if (bOK1)
		{
			cout << "Ŀ�꺯���½�����,";
			if (bOK2)
			{
				cout << "����½�����" << endl;
				cout << "�ҵ��˺��ʵĲ�����" << d << endl;
				break;
			}
			else
			{
				a = d;
				d = (2 * d) < ((a + b) / 2) ? (2 * d) : ((a + b) / 2);
				++n;
				cout << "����½�������" << endl;
				continue;
			}
		}
		else
		{
			b = d;
			d = (a + d) / 2;
			++n;
			cout << "Ŀ�꺯���½�������" << endl;
			continue;
		}
	}

	return 0;
}

