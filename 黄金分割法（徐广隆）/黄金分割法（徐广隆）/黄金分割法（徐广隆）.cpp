// 黄金分割法（徐广隆）.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#define INIT_MIN_NUM  -1
#define INIT_MAX_NUM  3
#define GOLD_CUT_RATE 0.618
#define ERROR_ACURATE 0.32

// 图形计算函数
float CurvefunctionNum(float fX)
{
	return fX * fX - fX + 2;
}


int _tmain(int argc, _TCHAR* argv[])
{
	// 初始化问题范围
	float xa = INIT_MIN_NUM;
	float xb = INIT_MAX_NUM;

	int n = 0;
	while ((xb - xa)*(xb - xa) > ERROR_ACURATE*ERROR_ACURATE)
	{
		cout << "第" << n << "次迭代：a = " << xa << ", b = " << xb << ", ";

		float x1 = xa + (1 - GOLD_CUT_RATE) * (xb - xa);
		float x2 = xa + GOLD_CUT_RATE * (xb - xa);

		cout << "x1 = " << x1 << ", x2 = " << x2 << ", ";

		float y1 = CurvefunctionNum(x1);
		float y2 = CurvefunctionNum(x2);

		cout << "y1 = " << y1 << ", y2 = " << y2 << endl;

		if (y1 < y2)
		{
			xb = x2;
		}
		else if (y1 == y2)
		{
			xa = x1;
			xb = x2;
		}
		else if (y1 > y2)
		{
			xa = x1;
		}

		++n;
	}

	cout << "循环结束时：a = " << xa << ", b = " << xb << endl;
	cout << "找到的值为：" << (xb + xa)/2 << endl;

	return 0;
}

