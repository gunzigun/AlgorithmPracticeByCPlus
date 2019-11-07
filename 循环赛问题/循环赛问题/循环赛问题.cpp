// 循环赛问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

// 循环赛赛函数
void GameTable(vector<vector<int>> &vec)  // 传入引用，保证参数可以再函数中改变
{
	// 无队伍，则返回
	if (vec.size() == 0)
	{
		return;
	}
	size_t s = vec.size();

	// 计算是2的多少次方
	int k = 0;
	while (s = s >> 1)  // 向右移动一位，相当于除以2
	{
		k++;	
	}

	//初始化（最小组数为两组，可以直接初始化）
	vec[0][0] = 1;
	vec[0][1] = 2;
	vec[1][0] = 2;
	vec[1][1] = 1;

	// 这里使用循环，每次将规模增大一倍
	for (int i = 2; i <= k; i++)
	{
		// length = 2^i次方
		int length = 0x1 << i;
		// half为其一半
		int half = length >> 1;

		//把一个表分为4个子表，左上角已知，左下，右上，右下未知

		//① 左下 = 左上 + helf
		//左下角的子表中项为左上角子表对应项加half=2^(i-1)
		for (int row = 0; row < half; row++)
		{
			for (int col = 0; col < half; col++)
			{
				vec[row + half][col] = vec[row][col] + half;
			}
		}
		
		//② 右上 = 左下 
		//右上角的子表等于左下角子表
		for (int row = 0; row < half; row++)
		{
			for (int col = 0; col < half; col++)
			{
				vec[row][col + half] = vec[row + half][col];
			}
		}

		//③ 右下 = 左上
		//右下角的子表等于左上角子表
		for (int row = 0; row < half; row++)
		{
			for (int col = 0; col < half; col++)
			{
				vec[row + half][col + half] = vec[row][col];
			}
		}
	}
}



int _tmain(int argc, _TCHAR* argv[])
{
	cout << "共有2^k个选手参加比赛，输入k（k>0）：" << endl;
	int k;
	do
	{
		cin >> k;
	} 
	while (k < 0 || k > 31); // 输入太大，会显示不下，爆内存

	int s = 0x1 << k; // 求出2的k次方（数字1左移位k次）
	vector<vector<int> > vec(s, vector<int>(s, 0));//把vector表示的二维数组全部初始化成0

	GameTable(vec);

	// 输出分组情况表
	for (size_t i = 0; i < vec.size(); i++)
	{
		for (size_t j = 0; j < vec[i].size(); j++)
		{
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

