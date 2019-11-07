// 单纯形法（徐广隆）.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

// 基变换次数
int nBaseChangeTime = 0;

/*
// 定义问题的规模
// ①定义参数的个数
#define N_PARAM 6
// ②定义约束条件的个数
#define N_SUBJECT_TO 4
// 定义基数组
int arrBase[N_SUBJECT_TO + 1] = { 0, 3, 4, 5, 6 };
// 定义约束条件的等式
float arrSubject[N_SUBJECT_TO + 1][N_PARAM + 1] =
{
	{ 0, -2, -3, 0, 0, 0, 0 },
	{ 6, 1, 1, 1, 0, 0, 0 },
	{ 8, 1, 2, 0, 1, 0, 0 },
	{ 4, 1, 0, 0, 0, 1, 0 },
	{ 3, 0, 1, 0, 0, 0, 1 }
};
*/

// 定义问题的规模
// ①定义参数的个数
#define N_PARAM 5
// ②定义约束条件的个数
#define N_SUBJECT_TO 3
// 定义基数组
int arrBase[N_SUBJECT_TO + 1] = { 0, 3, 4, 5};
// 定义约束条件的等式
float arrSubject[N_SUBJECT_TO + 1][N_PARAM + 1] =
{
	{ 0, 1500, 2500, 0, 0, 0 },
	{ 65, 3, 2, 1, 0, 0},
	{ 40, 2, 1, 0, 1, 0},
	{ 75, 0, 3, 0, 0, 1},
};

// 判断判别数是否完成(算法中止条件)
bool CheckAllJudgeFinish(const float *arrSubject, int nSize)
{
	for (int i = 1; i < nSize; ++i)
	{
		float nNum = *(arrSubject + i);
		if (nNum > 0)
		{
			return false;
		}
	}

	return true;
}


// 查找最大判别数所在的列号
int FindMaxJudgeSerial(const float *arrSubject, int nSize)
{
	float nMaxNum = *(arrSubject + 1);
	int nMaxSerial = 1;

	for (int i = 1; i < nSize; ++i)
	{
		float nNum = *(arrSubject + i);
		if (nNum > 0 && nNum >= nMaxNum)
		{
			nMaxNum = nNum;
			nMaxSerial = i;
		}
	}
	
	return nMaxSerial;
}


// 找出要替换的基序号
int FindWrapBaseSerial(const float(*arrSubject)[N_PARAM + 1], int nMaxNumSerial)
{
	// 定义优化数数组
	float arrJudge[N_SUBJECT_TO + 1];
	for (int l = 0; l <= N_SUBJECT_TO; ++l)
	{
		arrJudge[l] = 0.0;
	}

	// 求出o值
	for (int o = 1; o <= N_SUBJECT_TO; ++o)
	{

		float b = arrSubject[o][0];
		float a = arrSubject[o][nMaxNumSerial];
		if (a == 0)
		{
			arrJudge[o] = 0;
			continue;
		}
		arrJudge[o] = b / a;
	}

	// 最小值即为要替换的基
	float nMinNum = arrJudge[1];
	int nMinSerial = 1;
	for (int m = 1; m <= N_SUBJECT_TO; ++m)
	{
		float nNum = arrJudge[m];
		if (nNum > 0 && nNum <= nMinNum)
		{
			nMinNum = nNum;
			nMinSerial = m;
		}
	}

	return nMinSerial;
}


// 基变换函数
void BaseChangeFunction(int nWrapBaseSerial, int nMaxNumSerial)
{
	float  nDiv = arrSubject[nWrapBaseSerial][nMaxNumSerial];
	// 先把要替换的的行归一化
	for (int m = 0; m <= N_PARAM; ++m)
	{
		float nNum = arrSubject[nWrapBaseSerial][m];
		arrSubject[nWrapBaseSerial][m] = nNum / nDiv;
	}

	// 再把各行进行变换
	for (int i = 0; i <= N_SUBJECT_TO; ++i)
	{
		if (i == nWrapBaseSerial)
		{
			continue;
		}

		float nRate = arrSubject[i][nMaxNumSerial] / arrSubject[nWrapBaseSerial][nMaxNumSerial];
		for (int j = 0; j <= N_PARAM; ++j)
		{
			float nPre = arrSubject[i][j];
			float nBase = arrSubject[nWrapBaseSerial][j];
			arrSubject[i][j] = nPre - nBase*nRate;
		}
	}

	nBaseChangeTime += 1;
}


// 输出当前的单纯形表
void PrintNowState()
{
	cout << "这是第 " << nBaseChangeTime << " 个状态时的单纯形表:" << endl;

	for (int i = 0; i <= N_SUBJECT_TO; ++i)
	{
		for (int j = 0; j <= N_PARAM; ++j)
		{
			cout << arrSubject[i][j] << "  ";
		}
		cout << endl;
	}
}


// 算法主函数
int _tmain(int argc, _TCHAR* argv[])
{
	PrintNowState();

	// 需要满足的算法进行条件
	while (!CheckAllJudgeFinish(arrSubject[0], N_PARAM + 1))
	{
		// 查找最大判别数所在的列号
		int nMaxNumSerial = FindMaxJudgeSerial(arrSubject[0], N_PARAM + 1);
		
		// Aik是否全都是非正(是的话，则直接结束输出无最优解)
		bool bAllParamNagetive = true;
		for (int k = 1; k <= N_PARAM; ++k)
		{
			if (arrSubject[k][nMaxNumSerial] > 0)
			{
				bAllParamNagetive = false;
				break;
			}
		}
		if (bAllParamNagetive)
		{
			cout << "不存在最优解" << endl;
			return 0;
		}

		// 找出要替换的基序号
		int nWrapBaseSerial = FindWrapBaseSerial(arrSubject, nMaxNumSerial);
		arrBase[nWrapBaseSerial] = nMaxNumSerial;

		// 进行基变换
		BaseChangeFunction(nWrapBaseSerial, nMaxNumSerial);
		// 输出当前的单纯形表
		PrintNowState();
	}

	// 找到了最优解
	float arrResult[N_PARAM + 1];   //用于保存最优解
	for (int i = 0; i < N_PARAM + 1; ++i)
	{
		arrResult[i] = 0;
	}
	for (int j = 1; j < N_SUBJECT_TO + 1; ++j)
	{
		int nBaseNum = arrBase[j];
		arrResult[nBaseNum] = arrSubject[j][0];
	}
	cout << "最优解为：";

	// 则输出最优解结果
	for (int i = 1; i <= N_PARAM; ++i)
	{
		cout << "x" << i << " = " << arrResult[i] << "; ";
	}


	cout << endl << "最优化值为：" << -arrSubject[0][0] << endl;

	return 0;
}

