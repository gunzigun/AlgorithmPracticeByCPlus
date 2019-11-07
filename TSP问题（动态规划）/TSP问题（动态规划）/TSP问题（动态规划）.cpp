// TSP���⣨��̬�滮��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <vector>
using namespace std;

#define MAX_IFN_NUM 100000

int _tmain(int argc, _TCHAR* argv[])
{
	int temp;
	int minDis = 0;
	
	int n;
	cout << "��������и�����" << endl;
	cin >> n;
	vector<vector<int>> dis(n, vector<int>(n,0));
	for (int i = 0; i<n; i++)
	{
		//����Ϊ�������ĳ�ʼ��
		for (int j = 0; j<n; j++)
		{
			if (j != i)
			{
				cout << "���������(" << i << "," << j << ")֮��ľ���,�޾���������" << MAX_IFN_NUM << "��" << endl;
				cin >> temp;
				dis[i][j] = temp;
			}
			else
			{
				dis[i][j] = MAX_IFN_NUM;
			}
		}
	}

	// �����������ͼ
	cout << "�����ǳ��еľ���ͼ��" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << dis[i][j] << "  ";
		}
		cout << endl;
	}

	//1<<(n-1)]��ʾ2��n-1�η���d[]Ϊ��̬�滮�洢�ĳ��о�������
	int nLager = 1 << (n - 1);
	vector<vector<int>> d(n, vector<int>(nLager));
	//�����г��е���0�����е�·����ʼ��Ϊ���м�ľ���
	for (int i = 1; i<n; i++)
	{
		d[i][0] = dis[i][0];
	}


	for (int j = 1; j<nLager; j++)
	{
		for (int i = 1; i<n; i++)
		{   
			//j�ö����Ʊ�ʾ�ĳ��м���
			if (((1 << (i - 1))&j) == 0)
			{         
				//i����j��ʾ�ĳ��м�����
				minDis = MAX_IFN_NUM;
				for (int k = 1; k<n; k++)
				{
					if (((1 << (k - 1))&j) != 0)  
					{
						//k��ʾ�ĳ�����j��ʾ�ĳ��м�����
						temp = dis[i][k] + d[k][j - (1 << (k - 1))];
						if (temp<minDis)
						{
							minDis = temp;   //����k����С�ľ���
						}
					}
				}
			}
			d[i][j] = minDis;
		}
	}
	minDis = MAX_IFN_NUM;
	for (int k = 1; k<n; k++)
	{
		temp = dis[0][k] + d[k][(nLager-1) - (1 << (k - 1))];
		if (minDis>temp)
		{
			minDis = temp;
		}
	}
	
	d[0][(1 << (n - 1)) - 1] = minDis;
	cout << "��̵ľ���Ϊ��" << d[0][(1 << (n - 1)) - 1] << endl;

	return 0;
}

