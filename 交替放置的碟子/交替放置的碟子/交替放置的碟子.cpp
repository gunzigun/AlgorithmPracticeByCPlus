// 交替放置的碟子.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

#define  PROBLEM_LARGE 10
#define  ALL_CATE_NUM PROBLEM_LARGE*2
static string arrAllCate[ALL_CATE_NUM];

//交替算法:方法1
void WayChange1()
{
	int nChangePosition = 0;
	int nCirCle = 0;

	for (int i = 0; i < PROBLEM_LARGE; ++i)
	{
		int nNow = i + 1;
		do
		{
			if (arrAllCate[nNow - 1] != arrAllCate[nNow])
			{
				//交换两个相邻元素值
				string strRange = arrAllCate[nNow - 1];
				arrAllCate[nNow - 1] = arrAllCate[nNow];
				arrAllCate[nNow] = strRange;

				//交换次数加1
				++nChangePosition;

			}
			++nNow;

			//循环次数加1
			++nCirCle;
		} 
		while (nNow < ALL_CATE_NUM);

		//每一趟的结果都输出出来
		cout << "第" << i + 1 << "趟结果：";
		for (int j = 0; j < ALL_CATE_NUM; ++j)
		{
			cout << arrAllCate[j] << " ";
		}
		cout << endl << endl;
	}

	cout << "交换次数：" << nChangePosition << endl;
	cout << "循环次数：" << nCirCle << endl;
}

//交替算法:方法2
void WayChange2()
{
	int nChangePosition = 0;
	int nCirCle = 0;
	
	for (int i = 0; i < PROBLEM_LARGE;++i)
	{
		int head = i;
		int tail = ALL_CATE_NUM - i - 1;
		do
		{
			if (tail - head == 1)
			{
				string strMid = arrAllCate[head];
				arrAllCate[head] = arrAllCate[tail];
				arrAllCate[tail] = strMid;

				//交换次数加1
				++nChangePosition;
			}
			else
			{
				string strRangehead = arrAllCate[head];
				arrAllCate[head] = arrAllCate[head + 1];
				arrAllCate[head + 1] = strRangehead;

				string strRangetail = arrAllCate[tail];
				arrAllCate[tail] = arrAllCate[tail - 1];
				arrAllCate[tail - 1] = strRangetail;

				//交换次数加2
				nChangePosition +=2;
			}

			head += 2;
			tail -= 2;

			//循环次数加1
			++nCirCle;
		} 
		while (head < tail);

		//每一趟的结果都输出出来
		cout << "第" << i + 1 << "趟结果：";
		for (int j = 0; j < ALL_CATE_NUM; ++j)
		{
			cout << arrAllCate[j] << " ";
		}
		cout << endl << endl;
	}

	cout << "交换次数：" << nChangePosition << endl;
	cout << "循环次数：" << nCirCle << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	// 初始化棋子
	cout << "初始化棋子如下：";
	for (int i = 0; i < ALL_CATE_NUM; ++i)
	{
		int nCount = i + 1;
		if (nCount % 2 == 0)
		{
			arrAllCate[i] = "☆";
		}
		else
		{
			arrAllCate[i] = "★";
		}

		cout << arrAllCate[i] << " ";
	}
	cout << endl << endl;

	//WayChange1();
	WayChange2();

	return 0;
}

