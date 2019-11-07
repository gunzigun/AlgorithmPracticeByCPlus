// 完全背包问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_VOLE 2001
#define MAX_ITEM_NUM 101

int _tmain(int argc, _TCHAR* argv[])
{
	// 背包容量
	int nBagVole;
	cout << "请输入背包容量：" << endl;
	cin >> nBagVole;
	// 物品种类
	int nItemKind;
	cout << "请输入物品种类：" << endl;
	cin >> nItemKind;

	// 用于记录各个物品的重量和价值
	int arrWeight[MAX_ITEM_NUM], arrValue[MAX_ITEM_NUM];
	// 记录各个容量时的价值
	int f[MAX_VOLE] = { 0 };

	// 输入各个物品的重量和价值
	for (int i = 1; i <= nItemKind; i++)
	{
		cout << "请输入第" << i << "种物品的重量和价值：" << endl;
		cin >> arrWeight[i] >> arrValue[i];
	}

	// 分别考虑加入前i个物品
	for (int i = 1; i <= nItemKind; i++)
	{
		for (int v = arrWeight[i]; v <= nBagVole; v++)          //设 f[v]表示重量不超过v公斤的最大价值
		{
			f[v] = max(f[v - arrWeight[i]] + arrValue[i], f[v]);
		}
	}

	cout << "最高的价值为：" << f[nBagVole] << endl;

	return 0;
}

