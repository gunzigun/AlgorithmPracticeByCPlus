// 不精确一维搜索（徐广隆）.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

// 定义一个二维向量的结构
struct TwoVisionVector
{
	float x1;
	float x2;

public:
	TwoVisionVector(void){}
	TwoVisionVector(float num1, float num2) { x1 = num1; x2 = num2; }
};

// 计算函数值
float GetFunctionNum(TwoVisionVector tmpvector)
{
	float x1 = tmpvector.x1;
	float x2 = tmpvector.x2;
	float f = 100 * (x2 - x1*x1)*(x2 - x1*x1) + (1 - x1)*(1 - x1);
	return f;
}

// 计算函数的梯度值
TwoVisionVector GetGradiantVector(TwoVisionVector tmpvector)
{	
	TwoVisionVector returnVector;
	float x1 = tmpvector.x1;
	float x2 = tmpvector.x2;
	returnVector.x1 = -400 * (x2 - x1*x1)*x1 - 2*(1 - x1);
	returnVector.x2 = 200 * (x2 - x1*x1);

	return returnVector;
}

// 获取两个向量的点积
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
		cout << "第" << n << "趟计算：";

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
			cout << "目标函数下降成立,";
			if (bOK2)
			{
				cout << "充分下降成立" << endl;
				cout << "找到了合适的步长：" << d << endl;
				break;
			}
			else
			{
				a = d;
				d = (2 * d) < ((a + b) / 2) ? (2 * d) : ((a + b) / 2);
				++n;
				cout << "充分下降不成立" << endl;
				continue;
			}
		}
		else
		{
			b = d;
			d = (a + d) / 2;
			++n;
			cout << "目标函数下降不成立" << endl;
			continue;
		}
	}

	return 0;
}

