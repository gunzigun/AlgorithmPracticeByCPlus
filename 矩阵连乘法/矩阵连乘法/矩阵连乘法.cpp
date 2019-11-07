// �������˷�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX_SIZE 100

// �������˷����㷨����
/* ��������
pArrayDemetion ����������
nArrayNum �������
arrMinTimes ������С�˷�����
arrPosition ����ָ�λ��
*/
void DPMatrixChain(int pArrayDemetion[MAX_SIZE], int nArrayNum, int arrMinTimes[MAX_SIZE][MAX_SIZE], int arrPosition[MAX_SIZE][MAX_SIZE])
{
	//����r��ʾ���������ĵ�������r=2����ʾA(i)A(i+1)���˴�����2~n�����о����� 
	for (int r = 2; r <= nArrayNum; ++r)
	{                         
		// �˴�ȡ��������������Ϊr�ľ�����������nArrayNum - r + 1����Ϸ�ʽ
		for (int i = 1; i <= nArrayNum - r + 1; ++i)
		{
			// ȷ������Ϊr�������յ�λ��j����i-j�ľ�������
			int j = i + r - 1;
			
			// ��ʼ����С�ķָ�λ�ã�i��
			arrMinTimes[i][j] = arrMinTimes[i + 1][j] + pArrayDemetion[i - 1] * pArrayDemetion[i] * pArrayDemetion[j];
			arrPosition[i][j] = i;
			// ���зָ�λ�����ҳ���õķָ�λ��
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

// ����������˴�������
void printM(int m[MAX_SIZE][MAX_SIZE], int n)
{
	cout << "�������˴�������:" << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%d\t", m[i][j]);
		}
		printf("\n");
	}
}

// �����ѶϿ�λ��
void printS(int s[MAX_SIZE][MAX_SIZE], int n)
{
	cout << "��ѶϿ�λ�þ���:" << endl;
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
	// �������˻�A1A2...An�о����λ��һά���飬����Ai��ά��ΪPi-1*Pi��i=1,2,..,n
	int pArrayDemetion[MAX_SIZE];
	// �������
	int nArrayNum;
	// �������˴��� 
	int arrMinTimes[MAX_SIZE][MAX_SIZE] = {0};
	// A[i,j]�� ��ѶϿ�λ�� 
	int arrPosition[MAX_SIZE][MAX_SIZE] = {0};

	cout << "��������������" << endl;
	cin >> nArrayNum;	
	cout << "����������ά�ȣ���������һ��10*20��20*30�ľ�����ôP0=10��P1=20��P2=30" << endl;
	for (int i = 0; i <= nArrayNum; i++)
	{
		cin >> pArrayDemetion[i];

		if (i >= 1)
		{
			cout << "��" << i << "������:[" << pArrayDemetion[i - 1] << "," << pArrayDemetion[i] << "]" << endl;
		}
	}

	// �������㷨
	DPMatrixChain(pArrayDemetion, nArrayNum, arrMinTimes, arrPosition);
	
	// ����������˴�������
	printM(arrMinTimes, nArrayNum);

	// �����ѶϿ�λ�þ���
	printS(arrPosition, nArrayNum);

	// ������ս��
	cout << "���ٵĳ˷�����Ϊ��" << arrMinTimes[1][nArrayNum] << endl;

	return 0;
}

