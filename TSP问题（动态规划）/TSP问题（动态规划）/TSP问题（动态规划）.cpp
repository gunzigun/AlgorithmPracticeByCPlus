// TSP问题（动态规划）.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <vector>
using namespace std;

#define MAX_IFN_NUM 100000

int _tmain(int argc, _TCHAR* argv[])
{
	int temp;
	int minDis = 0;
	
	int n;
	cout << "请输入城市个数：" << endl;
	cin >> n;
	vector<vector<int>> dis(n, vector<int>(n,0));
	for (int i = 0; i<n; i++)
	{
		//以下为距离矩阵的初始化
		for (int j = 0; j<n; j++)
		{
			if (j != i)
			{
				cout << "请输入城市(" << i << "," << j << ")之间的距离,无距离请输入" << MAX_IFN_NUM << "：" << endl;
				cin >> temp;
				dis[i][j] = temp;
			}
			else
			{
				dis[i][j] = MAX_IFN_NUM;
			}
		}
	}

	// 输出城市走向图
	cout << "以下是城市的距离图：" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << dis[i][j] << "  ";
		}
		cout << endl;
	}

	//1<<(n-1)]表示2的n-1次方，d[]为动态规划存储的城市经过矩阵
	int nLager = 1 << (n - 1);
	vector<vector<int>> d(n, vector<int>(nLager));
	//将所有城市到第0个城市的路径初始化为两市间的距离
	for (int i = 1; i<n; i++)
	{
		d[i][0] = dis[i][0];
	}


	for (int j = 1; j<nLager; j++)
	{
		for (int i = 1; i<n; i++)
		{   
			//j用二进制表示的城市集合
			if (((1 << (i - 1))&j) == 0)
			{         
				//i不在j表示的城市集合中
				minDis = MAX_IFN_NUM;
				for (int k = 1; k<n; k++)
				{
					if (((1 << (k - 1))&j) != 0)  
					{
						//k表示的城市在j表示的城市集合中
						temp = dis[i][k] + d[k][j - (1 << (k - 1))];
						if (temp<minDis)
						{
							minDis = temp;   //所有k中最小的距离
						}
					}
				}
			}
			d[i][j] = minDis;
		}
	}
	minDis = MAX_IFN_NUM;
	for (int k = 1; k<n; k++)
	{
		temp = dis[0][k] + d[k][(nLager-1) - (1 << (k - 1))];
		if (minDis>temp)
		{
			minDis = temp;
		}
	}
	
	d[0][(1 << (n - 1)) - 1] = minDis;
	cout << "最短的距离为：" << d[0][(1 << (n - 1)) - 1] << endl;

	return 0;
}

