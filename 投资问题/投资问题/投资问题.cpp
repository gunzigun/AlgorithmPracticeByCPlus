// Ͷ������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int nMoney;
	cout << "�������ܽ�Ǯ������" << endl;
	cin >> nMoney;
	int nProc;
	cout << "��������Ŀ����" << endl;
	cin >> nProc;

	// �������룬��������ĿͶ�ʲ�ͬ���ʱ������
	//f[i][x], 0<i<=nProc,0<=x<=nMoney��
	vector<vector<int>> f(nProc, vector<int>(nMoney + 1));
	/*
	for (int i = 0; i < nProc; ++i)
	{
		//�ڵ�(i+1)����Ŀ��Ͷ��0Ԫ������Ϊ0��ע��i��0��ʼ
		f[i][0] = 0;
	}
	for (int i = 0; i < nProc; ++i)
	{
		for (int j = 1; j < nMoney + 1; ++j)
		{
			//j��1��ʼ��Ҳ���Ǵ�f[0][1]��ʼ
			cin >> f[i][j];
		}
	}
	*/
	///* Ҳ����ֱ�ӳ�ʼ����
	f[0] = { 0, 11, 12, 13, 14, 15 };
	f[1] = { 0, 0, 5, 10, 15, 20 };
	f[2] = { 0, 2, 10, 30, 32, 40 };
	f[3] = { 0, 20, 21, 22, 23, 24 };
	//*/

	//F[i][x]����xԪǮͶ�뵽ǰi����Ŀ����������
	vector<vector<int>> F(nProc, vector<int>(nMoney + 1));

	//��F[0][0-m]��ֵ
	for (int j = 0; j < nMoney + 1; ++j)
	{
		F[0][j] = f[0][j];//��һ����Ŀ��Ͷ��0-mԪǮ������������f[0][0-m]
	}

	// tmp_F����һ��ѭ���е�Ǯ��
	int tmp_F = 0;
	// i��ʾͶ��ǰi����Ŀ,i=0��֮ǰ�Ѿ���ʼ�����ˣ�������
	for (int i = 1; i < nProc; ++i) 
	{
		// j��ʾͶ�Ľ��
		for (int j = 0; j < nMoney + 1; ++j) 
		{
			// tmp_m�������i����ĿͶ���Ǯ��
			int tmp_m;
			// �������ӵ�i����Ŀ��Ͷ�ʣ�����ǰi-1��Ŀ��Ͷ�ʣ�ֱ���ҵ�һ�����ֵΪֹ
			for (tmp_m = 0; tmp_m <= j; ++tmp_m) 
			{
				tmp_F = F[i - 1][j - tmp_m] + f[i][tmp_m];
				if (tmp_F > F[i][j])
				{
					F[i][j] = tmp_F;
				}
			}
		}
	}
	cout << "�������Ϊ:" << F[nProc-1][nMoney] << endl;

	for (int i = 0; i < nProc; ++i)
	{
		for (int j = 0; j <= nMoney; ++j)
		{
			cout << F[i][j] << "  ";
		}
		cout << endl;
	}
	
}

