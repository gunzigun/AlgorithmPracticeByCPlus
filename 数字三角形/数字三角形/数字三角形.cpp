// ����������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	// �Ȱ������γ�ʼ��
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
	// ����������������
	cout << "��Ŀ�����������Σ�" << endl;
	for (int i = 0; i < nLevel; ++i)
	{
		for (int j = 0; j < nLevel; ++j)
		{
			cout << arrNum[i][j] << " ";
		}
		cout << endl;
	}

	// �����滻
	for (int i = 0; i < nLevel; ++i)
	{
		// ��������ĸ���Ԫ��
		for (int j = 0; j < nLevel; ++j)
		{
			int preLevel = i - 1;
			int nLeft = j - 1;
			int nRight = j;
			if (preLevel >= 0)
			{
				// �Ƚ����Ҹ������Լ��ĺͣ�ȡ���ı���
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

	cout << "���������������Σ�" << endl;
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

	cout << "��ͼ��֪������ֵΪ:" << nMax << endl;

	return 0;
}

