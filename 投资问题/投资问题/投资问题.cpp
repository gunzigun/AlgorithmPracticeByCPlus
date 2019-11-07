// 投资问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int nMoney;
	cout << "请输入总金钱数量：" << endl;
	cin >> nMoney;
	int nProc;
	cout << "请输入项目数：" << endl;
	cin >> nProc;

	// 接收输入，即各个项目投资不同金额时的收益
	//f[i][x], 0<i<=nProc,0<=x<=nMoney；
	vector<vector<int>> f(nProc, vector<int>(nMoney + 1));
	/*
	for (int i = 0; i < nProc; ++i)
	{
		//在第(i+1)个项目上投入0元，收益为0，注意i从0开始
		f[i][0] = 0;
	}
	for (int i = 0; i < nProc; ++i)
	{
		for (int j = 1; j < nMoney + 1; ++j)
		{
			//j从1开始，也就是从f[0][1]开始
			cin >> f[i][j];
		}
	}
	*/
	///* 也可以直接初始化了
	f[0] = { 0, 11, 12, 13, 14, 15 };
	f[1] = { 0, 0, 5, 10, 15, 20 };
	f[2] = { 0, 2, 10, 30, 32, 40 };
	f[3] = { 0, 20, 21, 22, 23, 24 };
	//*/

	//F[i][x]，将x元钱投入到前i个项目上最大的收益
	vector<vector<int>> F(nProc, vector<int>(nMoney + 1));

	//给F[0][0-m]赋值
	for (int j = 0; j < nMoney + 1; ++j)
	{
		F[0][j] = f[0][j];//第一个项目上投入0-m元钱的最大收益等于f[0][0-m]
	}

	// tmp_F代表一次循环中的钱数
	int tmp_F = 0;
	// i表示投给前i个项目,i=0的之前已经初始化过了，不用了
	for (int i = 1; i < nProc; ++i) 
	{
		// j表示投的金额
		for (int j = 0; j < nMoney + 1; ++j) 
		{
			// tmp_m代表给第i个项目投入的钱数
			int tmp_m;
			// 不断增加第i个项目的投资，减少前i-1项目的投资，直至找到一个最大值为止
			for (tmp_m = 0; tmp_m <= j; ++tmp_m) 
			{
				tmp_F = F[i - 1][j - tmp_m] + f[i][tmp_m];
				if (tmp_F > F[i][j])
				{
					F[i][j] = tmp_F;
				}
			}
		}
	}
	cout << "最大利润为:" << F[nProc-1][nMoney] << endl;

	for (int i = 0; i < nProc; ++i)
	{
		for (int j = 0; j <= nMoney; ++j)
		{
			cout << F[i][j] << "  ";
		}
		cout << endl;
	}
	
}

