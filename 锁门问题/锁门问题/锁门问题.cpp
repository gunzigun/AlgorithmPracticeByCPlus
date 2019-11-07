// 锁门问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

#define TOTAL_DOOR_NUM 1000
#define EACH_LINE_SHOW 5
int doorchangeNum[TOTAL_DOOR_NUM];


// 计算出所有门的开关次数，保存在全局doorchangeNum中
void CacuAllDoorKind()
{
	for (int i = 1; i <= TOTAL_DOOR_NUM; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			if (i%j == 0)
			{
				++doorchangeNum[i - 1];
			}
		}
	}
}

// 方法1：检测某一扇门是不是关闭的
bool CheckDoorOpen(int n)
{
	if (n >= 1 && n <= TOTAL_DOOR_NUM)
	{
		int index = n - 1;
		int nTimes = doorchangeNum[index];
		// 偶素次的开关后，门还是关闭的
		if (nTimes%2==0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	return false;
}

// 方法2：根据规律可以发现，1，4，9这些平方项目是开着的，所以可以用这个函数来判断
bool CheckDoorOpenCool(int n)
{
	double sq, a;
	sq = sqrt(n); // sq赋值为根号n
	a = (int)sq;	  // a取根号n的整数部分
	if (a == sq)	  // 如果a和根号n还相等，那么根号n是整数
	{
		return true;
	}
	return false;
}


int _tmain(int argc, _TCHAR* argv[])
{
	// 初始化，把所有门开关次数都设置成0次
	for (int i = 1; i <= TOTAL_DOOR_NUM; ++i)
	{
		doorchangeNum[i - 1] = 0;
	}
	
	// 计算出所有门的开关次数，保存在全局doorchangeNum中
	CacuAllDoorKind();

	int nAllDoorOpenNum = 0;
	// 输出所有打开的门编号
	cout << "打开的门有这些：" << endl;
	for (int i = 1; i <= TOTAL_DOOR_NUM; ++i)
	{
		//if (CheckDoorOpen(i))
		if (CheckDoorOpenCool(i))
		{
			cout << i << "  ";
			++nAllDoorOpenNum;

			//每EACH_LINE_SHOW个就换一行
			if (nAllDoorOpenNum%EACH_LINE_SHOW == 0)
			{
				cout << endl;
			}
		}
	}
	cout << endl << "打开的门的总数目是：" << nAllDoorOpenNum << endl;

	return 0;
}

