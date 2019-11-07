// ���̸�������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;
// �ȳ�ʼ��һ���ܴ�Ķ�ά���飬������ֵ����ʼ��Ϊ0
#define NMAX_ARRAY_NUM 101
int def[NMAX_ARRAY_NUM][NMAX_ARRAY_NUM] = {0};
// ������Ƶ���ֵ��ÿ������һ����ֵ
static int nGuPai = 0;

// �����㷨�ĳ���
// nBeginX��nBeginYΪ���������Ͻ����꣬ nPosX��nPosYΪ��������꣬ nLength Ϊ�����̳���
void chess(int nBeginX, int nBeginY, int nPosX, int nPosY, int nLength)
{
	if (nLength == 1)
	{
		return;
	}

	nGuPai++;
	// �ݴ���Ʊ�ţ���Ϊ�ݹ����ʱ��ȫ�ֱ�����ı�
	int temGuPai = nGuPai;

	// �����̻���Ϊһ��Ĺ�ģ 
	int nLenDiv = nLength / 2;


	// ����������ϵ���������
	if (nPosX < nBeginX + nLenDiv && nPosY < nBeginY + nLenDiv)
	{ 
		// ��������
		chess(nBeginX, nBeginY, nPosX, nPosY, nLenDiv);
	}
	else
	{
		// ���½ǵ�����
		def[nBeginX + nLenDiv - 1][nBeginY + nLenDiv - 1] = temGuPai;
		// ���Ϻ��������
		chess(nBeginX, nBeginY, nBeginX + nLenDiv - 1, nBeginY + nLenDiv - 1, nLenDiv);
	}


	// ����������µ���������
	if (nPosX >= nBeginX + nLenDiv && nPosY < nBeginY + nLenDiv)
	{
		// ��������
		chess(nBeginX + nLenDiv, nBeginY, nPosX, nPosY, nLenDiv);
	}
	else
	{
		// ���Ͻǵ�����
		def[nBeginX + nLenDiv][nBeginY + nLenDiv - 1] = temGuPai;
		// ���Ϻ��������
		chess(nBeginX + nLenDiv, nBeginY, nBeginX + nLenDiv, nBeginY + nLenDiv - 1, nLenDiv);
	}


	// ����������ϵ���������
	if (nPosX < nBeginX + nLenDiv && nPosY >= nBeginY + nLenDiv)
	{
		// ��������
		chess(nBeginX, nBeginY + nLenDiv, nPosX, nPosY, nLenDiv);
	}
	else
	{
		// ���½ǵ�����
		def[nBeginX + nLenDiv - 1][nBeginY + nLenDiv] = temGuPai;
		// ���Ϻ��������
		chess(nBeginX, nBeginY + nLenDiv, nBeginX + nLenDiv - 1, nBeginY + nLenDiv, nLenDiv);
	}


	// ����������µ���������
	if (nPosX >= nBeginX + nLenDiv && nPosY >= nBeginY + nLenDiv)
	{
		// ��������
		chess(nBeginX + nLenDiv, nBeginY + nLenDiv, nPosX, nPosY, nLenDiv);
	}
	else
	{
		// ���Ͻǵ�����
		def[nBeginX + nLenDiv][nBeginY + nLenDiv] = temGuPai;
		// ���Ϻ��������
		chess(nBeginX + nLenDiv, nBeginY + nLenDiv, nBeginX + nLenDiv, nBeginY + nLenDiv, nLenDiv);
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	// nBeginX��nBeginYΪ���������Ͻ����꣬ 
	// nPosX��nPosYΪ��������꣬ nLevel Ϊ�����̹�ģ
	int nBeginX, nBeginY, nPosX, nPosY, nlevel;

	cout << "���������������1-5����Ȼ��ʾ��ȫ����";
	cin >> nlevel;
	int nLength = pow(2, nlevel);

	cout << "������������к�nPosX:";
	cin >> nPosX;
	cout << "������������к�nPosY:";
	cin >> nPosY;
	nBeginX = nBeginY = 1;

	// �ݴ������̵��ܳ��ȣ��Ա�������
	 int m = nLength;

	// ���̸����㷨��ʼ
	 chess(nBeginX, nBeginY, nPosX, nPosY, nLength);

	// ������̸��ǽ��
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

