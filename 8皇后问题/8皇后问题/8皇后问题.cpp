// 8皇后问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

// 这个数等于几，就是几皇后。
const int ArSize = 4;
// 累积总共的解的数目
int num = 0;


// 判断皇后的落点是否合规
bool check(bool arr[ArSize][ArSize], int row, int column)
{
	if (row == 0)
	{
		return true;
	}

	int i, j;
	// 判断纵向是否有冲突
	for (i = 0; i < row; ++i)
	{
		if (arr[i][column])
		{
			return false;
		}
	}

	i = row - 1;
	j = column - 1;
	// 判断正斜对角线是否有冲突
	while (i >= 0 && j >= 0)
	{
		if (arr[i][j])
		{
			return false;
		}
		--i;
		--j;
	}

	i = row - 1;
	j = column + 1;
	// 判断负斜对角线是否有冲突
	while (i >= 0 && j <= ArSize - 1)
	{
		if (arr[i][j])
		{
			return false;
		}
		--i;
		++j;
	}
	return true;
}


// 打印每种正确的解法
void outPut(bool arr[ArSize][ArSize])
{
	++num;
	cout << "********************** " << num << " begin *********************" << endl;
	for (int i = 0; i < ArSize; ++i)
	{
		for (int j = 0; j < ArSize; ++j)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "********************** " << num << "  end  *********************" << endl;
}

// 回溯法
void solve(bool arr[ArSize][ArSize], int row)
{
	for (int column = 0; column < ArSize; ++column)
	{
		arr[row][column] = true;
		if (check(arr, row, column))
		{
			// 所有行都找到了
			if (row + 1 == ArSize)
			{
				// 输出当前的排列
				outPut(arr);
			}
			// 没找完就找下一行
			else
			{
				solve(arr, row + 1);
			}
		}
		arr[row][column] = false;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	bool chessboard[ArSize][ArSize];

	// 数组初始化
	for (auto &i : chessboard)
	{
		for (auto &j : i)
		{
			j = false;
		}
	}

	solve(chessboard, 0);
	cout << "八皇后问题共有" << num << "种解！" << endl;
	system("pause");
	return 0;
}

