// 8�ʺ�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

// ��������ڼ������Ǽ��ʺ�
const int ArSize = 4;
// �ۻ��ܹ��Ľ����Ŀ
int num = 0;


// �жϻʺ������Ƿ�Ϲ�
bool check(bool arr[ArSize][ArSize], int row, int column)
{
	if (row == 0)
	{
		return true;
	}

	int i, j;
	// �ж������Ƿ��г�ͻ
	for (i = 0; i < row; ++i)
	{
		if (arr[i][column])
		{
			return false;
		}
	}

	i = row - 1;
	j = column - 1;
	// �ж���б�Խ����Ƿ��г�ͻ
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
	// �жϸ�б�Խ����Ƿ��г�ͻ
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


// ��ӡÿ����ȷ�Ľⷨ
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

// ���ݷ�
void solve(bool arr[ArSize][ArSize], int row)
{
	for (int column = 0; column < ArSize; ++column)
	{
		arr[row][column] = true;
		if (check(arr, row, column))
		{
			// �����ж��ҵ���
			if (row + 1 == ArSize)
			{
				// �����ǰ������
				outPut(arr);
			}
			// û���������һ��
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

	// �����ʼ��
	for (auto &i : chessboard)
	{
		for (auto &j : i)
		{
			j = false;
		}
	}

	solve(chessboard, 0);
	cout << "�˻ʺ����⹲��" << num << "�ֽ⣡" << endl;
	system("pause");
	return 0;
}

