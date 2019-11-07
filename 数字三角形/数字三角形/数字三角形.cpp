// 数字三角形.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	// 先把三角形初始化
	int nLevel = 5;
	vector<vector<int>> arrNum(nLevel, vector<int>(nLevel,-1));
	arrNum[0][0] = 7;
	arrNum[1][0] = 3;
	arrNum[1][1] = 8;
	arrNum[2][0] = 8;
	arrNum[2][1] = 1;
	arrNum[2][2] = 0;
	arrNum[3][0] = 2;
	arrNum[3][1] = 7;
	arrNum[3][2] = 4;
	arrNum[3][3] = 4;
	arrNum[4][0] = 4;
	arrNum[4][1] = 5;
	arrNum[4][2] = 2;
	arrNum[4][3] = 6;
	arrNum[4][4] = 5;
	// 输出这个数字三角形
	cout << "题目的数字三角形：" << endl;
	for (int i = 0; i < nLevel; ++i)
	{
		for (int j = 0; j < nLevel; ++j)
		{
			cout << arrNum[i][j] << " ";
		}
		cout << endl;
	}

	// 挨层替换
	for (int i = 0; i < nLevel; ++i)
	{
		// 遍历各层的各个元素
		for (int j = 0; j < nLevel; ++j)
		{
			int preLevel = i - 1;
			int nLeft = j - 1;
			int nRight = j;
			if (preLevel >= 0)
			{
				// 比较左右父亲与自己的和，取最大的保留
				int nTemp = arrNum[i][j];
				if (nLeft >= 0 && (arrNum[preLevel][nLeft] + arrNum[i][j] > nTemp))
				{
					nTemp = arrNum[preLevel][nLeft] + arrNum[i][j];
				}

				if (nRight <= preLevel && (arrNum[preLevel][nRight] + arrNum[i][j] > nTemp))
				{
					nTemp = arrNum[preLevel][nRight] + arrNum[i][j];
				}
				arrNum[i][j] = nTemp;
			}
		}
	}

	cout << "处理后的数字三角形：" << endl;
	int nMax = 0;
	for (int i = 0; i < nLevel; ++i)
	{
		for (int j = 0; j < nLevel; ++j)
		{
			cout << arrNum[i][j] << " ";

			if (i == nLevel-1 && arrNum[i][j] > nMax)
			{
				nMax = arrNum[i][j];
			}
		}
		
		cout << endl;
	}

	cout << "由图可知最大的数值为:" << nMax << endl;

	return 0;
}

