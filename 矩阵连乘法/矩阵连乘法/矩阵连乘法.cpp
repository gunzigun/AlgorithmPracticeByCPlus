// 矩阵连乘法.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX_SIZE 100

// 矩阵链乘法：算法代码
/* 函数参数
pArrayDemetion 矩阵链数组
nArrayNum 矩阵个数
arrMinTimes 保存最小乘法次数
arrPosition 保存分隔位置
*/
void DPMatrixChain(int pArrayDemetion[MAX_SIZE], int nArrayNum, int arrMinTimes[MAX_SIZE][MAX_SIZE], int arrPosition[MAX_SIZE][MAX_SIZE])
{
	//变量r表示矩阵链长的递增，如r=2，表示A(i)A(i+1)，此处处理2~n的所有矩阵链 
	for (int r = 2; r <= nArrayNum; ++r)
	{                         
		// 此处取矩阵子链，长度为r的矩阵子链共有nArrayNum - r + 1中组合方式
		for (int i = 1; i <= nArrayNum - r + 1; ++i)
		{
			// 确定长度为r的链的终点位置j，（i-j的矩阵链）
			int j = i + r - 1;
			
			// 初始化最小的分割位置（i）
			arrMinTimes[i][j] = arrMinTimes[i + 1][j] + pArrayDemetion[i - 1] * pArrayDemetion[i] * pArrayDemetion[j];
			arrPosition[i][j] = i;
			// 所有分隔位置中找出最好的分割位置
			for (int k = i + 1; k < j; k++)
			{
				int tmpMin = arrMinTimes[i][k] + arrMinTimes[k + 1][j] + pArrayDemetion[i - 1] * pArrayDemetion[k] * pArrayDemetion[j];
				if (tmpMin < arrMinTimes[i][j])
				{
					arrMinTimes[i][j] = tmpMin;
					arrPosition[i][j] = k;
				}
			}
		}
	}
}

// 输出最少数乘次数矩阵
void printM(int m[MAX_SIZE][MAX_SIZE], int n)
{
	cout << "最少数乘次数矩阵:" << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%d\t", m[i][j]);
		}
		printf("\n");
	}
}

// 输出最佳断开位置
void printS(int s[MAX_SIZE][MAX_SIZE], int n)
{
	cout << "最佳断开位置矩阵:" << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%d\t", s[i][j]);
		}
		printf("\n");
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	// 矩阵连乘积A1A2...An中矩阵的位数一维数组，其中Ai的维数为Pi-1*Pi，i=1,2,..,n
	int pArrayDemetion[MAX_SIZE];
	// 矩阵个数
	int nArrayNum;
	// 最少数乘次数 
	int arrMinTimes[MAX_SIZE][MAX_SIZE] = {0};
	// A[i,j]的 最佳断开位置 
	int arrPosition[MAX_SIZE][MAX_SIZE] = {0};

	cout << "请输入矩阵个数：" << endl;
	cin >> nArrayNum;	
	cout << "请输入矩阵的维度，如现在有一个10*20，20*30的矩阵，那么P0=10，P1=20，P2=30" << endl;
	for (int i = 0; i <= nArrayNum; i++)
	{
		cin >> pArrayDemetion[i];

		if (i >= 1)
		{
			cout << "第" << i << "个矩阵:[" << pArrayDemetion[i - 1] << "," << pArrayDemetion[i] << "]" << endl;
		}
	}

	// 矩阵链算法
	DPMatrixChain(pArrayDemetion, nArrayNum, arrMinTimes, arrPosition);
	
	// 输出最少数乘次数矩阵
	printM(arrMinTimes, nArrayNum);

	// 输出最佳断开位置矩阵
	printS(arrPosition, nArrayNum);

	// 输出最终结果
	cout << "最少的乘法次数为：" << arrMinTimes[1][nArrayNum] << endl;

	return 0;
}

