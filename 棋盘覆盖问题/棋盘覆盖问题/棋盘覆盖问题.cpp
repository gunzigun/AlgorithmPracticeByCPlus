// 棋盘覆盖问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;
// 先初始化一个很大的二维数组，把所有值都初始化为0
#define NMAX_ARRAY_NUM 101
int def[NMAX_ARRAY_NUM][NMAX_ARRAY_NUM] = {0};
// 定义骨牌的数值，每次增加一号数值
static int nGuPai = 0;

// 棋盘算法的程序
// nBeginX、nBeginY为子棋盘左上角坐标， nPosX、nPosY为特殊点坐标， nLength 为子棋盘长度
void chess(int nBeginX, int nBeginY, int nPosX, int nPosY, int nLength)
{
	if (nLength == 1)
	{
		return;
	}

	nGuPai++;
	// 暂存骨牌编号，因为递归调用时，全局变量会改变
	int temGuPai = nGuPai;

	// 将棋盘划分为一半的规模 
	int nLenDiv = nLength / 2;


	// 特殊点在左上的正方形中
	if (nPosX < nBeginX + nLenDiv && nPosY < nBeginY + nLenDiv)
	{ 
		// 继续划分
		chess(nBeginX, nBeginY, nPosX, nPosY, nLenDiv);
	}
	else
	{
		// 右下角点填上
		def[nBeginX + nLenDiv - 1][nBeginY + nLenDiv - 1] = temGuPai;
		// 填上后继续划分
		chess(nBeginX, nBeginY, nBeginX + nLenDiv - 1, nBeginY + nLenDiv - 1, nLenDiv);
	}


	// 特殊点在左下的正方形中
	if (nPosX >= nBeginX + nLenDiv && nPosY < nBeginY + nLenDiv)
	{
		// 继续划分
		chess(nBeginX + nLenDiv, nBeginY, nPosX, nPosY, nLenDiv);
	}
	else
	{
		// 右上角点填上
		def[nBeginX + nLenDiv][nBeginY + nLenDiv - 1] = temGuPai;
		// 填上后继续划分
		chess(nBeginX + nLenDiv, nBeginY, nBeginX + nLenDiv, nBeginY + nLenDiv - 1, nLenDiv);
	}


	// 特殊点在右上的正方形中
	if (nPosX < nBeginX + nLenDiv && nPosY >= nBeginY + nLenDiv)
	{
		// 继续划分
		chess(nBeginX, nBeginY + nLenDiv, nPosX, nPosY, nLenDiv);
	}
	else
	{
		// 左下角点填上
		def[nBeginX + nLenDiv - 1][nBeginY + nLenDiv] = temGuPai;
		// 填上后继续划分
		chess(nBeginX, nBeginY + nLenDiv, nBeginX + nLenDiv - 1, nBeginY + nLenDiv, nLenDiv);
	}


	// 特殊点在左下的正方形中
	if (nPosX >= nBeginX + nLenDiv && nPosY >= nBeginY + nLenDiv)
	{
		// 继续划分
		chess(nBeginX + nLenDiv, nBeginY + nLenDiv, nPosX, nPosY, nLenDiv);
	}
	else
	{
		// 左上角点填上
		def[nBeginX + nLenDiv][nBeginY + nLenDiv] = temGuPai;
		// 填上后继续划分
		chess(nBeginX + nLenDiv, nBeginY + nLenDiv, nBeginX + nLenDiv, nBeginY + nLenDiv, nLenDiv);
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	// nBeginX、nBeginY为子棋盘左上角坐标， 
	// nPosX、nPosY为特殊点坐标， nLevel 为子棋盘规模
	int nBeginX, nBeginY, nPosX, nPosY, nlevel;

	cout << "请输入阶数（建议1-5，不然显示不全）：";
	cin >> nlevel;
	int nLength = pow(2, nlevel);

	cout << "请输入特殊点行号nPosX:";
	cin >> nPosX;
	cout << "请输入特殊点列号nPosY:";
	cin >> nPosY;
	nBeginX = nBeginY = 1;

	// 暂存下棋盘的总长度，以便后续输出
	 int m = nLength;

	// 棋盘覆盖算法开始
	 chess(nBeginX, nBeginY, nPosX, nPosY, nLength);

	// 输出棋盘覆盖结果
	for (int i = 1; i <= m; i++)
	{ 
		for (int j = 1; j <= m; j++)
		{
			cout.width(3);
			cout << def[i][j];
			if (j == m){
				cout << endl;
			}
		}
	}
	
	return 0;
}

