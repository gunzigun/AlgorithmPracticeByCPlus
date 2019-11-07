// 连续邮资问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>  
#include <string.h>
#include <iostream>
using namespace std;

//n为邮票种类,m为一封信上最多贴的邮票个数
int n, m;
//最终最大邮资区间
int Maxvalue;
//最终最佳面值方案
int bestx[100]; 


//能否用t种邮票，面值在x数组中,最多贴m张，
//表示出sum(是个动态规划问题，方法是求出y[t][sum]看它是否小于m,
//状态转移方程y[i][j]=min(y[i-1][j-k*x[i]]+k)其中y[i][j]表示用到第i种邮票，表示邮资为j的最少邮票数
int judge(int x[100], int t, int sum)
{
	int j, k;
	int y[10][1000];
	for (int i = 0; i <= t; i++)
	{
		y[i][0] = 0;
	}
	for (int i = 0; i <= sum; i++)
	{
		y[1][i] = i;
	}
	for (int i = 2; i <= t; i++)
	{
		for (int j = 1; j <= sum; j++)
		{
			//把k=0时的y值获取到
			y[i][j] = 10000;

			//要y取最小，所以应该尽可能的使用最大面值的x[i],最多能用j/x[i]张
			for (int k = 0; k <= j / x[i]; k++)
			{
				//找最小的y
				if (y[i][j] > y[i - 1][j - x[i] * k] + k)
				{
					y[i][j] = y[i - 1][j - x[i] * k] + k;
				}
			}
		}
	}
	if (y[t][sum] > m)
	{
		return 0;
	}
	return 1;
}

// 
void Backtrack(int x[100], int cur, int max)
{
	int i, j, next;
	//如果已经得出了n种邮票 
	if (cur == n) 
	{
		//并且它的最大值已经大于当前最大邮资数 
		if (max > Maxvalue) 
		{
			Maxvalue = max;
			for (i = 1; i <= cur; i++)
			{
				//更新答案数组 
				bestx[i] = x[i];
			} 
		}
		return;
	}

	//如果还没得到n种邮票，那么从x[cur]+1~max+1选一个作为下一个邮资，因为max+1没法表示，所以必定到max+1为止  
	for (next = x[cur] + 1; next <= max + 1; next++)
	{
		//用种类为cur+1,数目分别为x[1..cur+1]的邮票,最多使用m张，能否表示出大于max的某个数
		x[cur + 1] = next;  
		//i为加入新邮票之后能达到的最大值，这个数最少要为max+1,最多是x[cur+1]*m 
		for (i = max + 1; i <= m * x[cur + 1]; i++)
		{
			//等于0说明超过了m,此时的i不成立，如果成立则返回1，i++
			if (judge(x, cur + 1, i) == 0)
			{
				break;
			}
		}
		//如果至少让最大值更新了一次(最大值有所更新，继续加入下一个邮票)
		if (i > max + 1)
		{
			//上层for循环得到i之后又判断了i+1,所以i-1
			Backtrack(x, cur + 1, i - 1);
		}
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	int i, j, max, cur;
	int x[100];//中间传递的数组，存储当前的邮票值的解
	
	cout << "请输入发行邮票的种类：" << endl;
	cin >> n;
	cout << "请输入每张信封最多允许贴的邮票张数：" << endl;
	cin >> m;

	Maxvalue = 0;
	//max表示到目前为止的最大可到达邮资
	max = m;
	cur = 1;
	x[cur] = 1;
	//x存储当前的解,cur表示当前传递到第几种邮票,max表示目前能表示到的最大值 
	Backtrack(x, cur, max); 
	
	cout << "最佳设计方案：" << endl;
	for (i = 1; i <= n; i++)
	{
		cout << bestx[i] << " ";
	}	
	cout << endl << "最大邮资区间为 " << Maxvalue << endl;
	return 0;
}

