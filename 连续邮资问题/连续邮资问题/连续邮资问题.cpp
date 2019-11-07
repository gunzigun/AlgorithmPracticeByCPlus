// ������������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>  
#include <string.h>
#include <iostream>
using namespace std;

//nΪ��Ʊ����,mΪһ���������������Ʊ����
int n, m;
//���������������
int Maxvalue;
//���������ֵ����
int bestx[100]; 


//�ܷ���t����Ʊ����ֵ��x������,�����m�ţ�
//��ʾ��sum(�Ǹ���̬�滮���⣬���������y[t][sum]�����Ƿ�С��m,
//״̬ת�Ʒ���y[i][j]=min(y[i-1][j-k*x[i]]+k)����y[i][j]��ʾ�õ���i����Ʊ����ʾ����Ϊj��������Ʊ��
int judge(int x[100], int t, int sum)
{
	int j, k;
	int y[10][1000];
	for (int i = 0; i <= t; i++)
	{
		y[i][0] = 0;
	}
	for (int i = 0; i <= sum; i++)
	{
		y[1][i] = i;
	}
	for (int i = 2; i <= t; i++)
	{
		for (int j = 1; j <= sum; j++)
		{
			//��k=0ʱ��yֵ��ȡ��
			y[i][j] = 10000;

			//Ҫyȡ��С������Ӧ�þ����ܵ�ʹ�������ֵ��x[i],�������j/x[i]��
			for (int k = 0; k <= j / x[i]; k++)
			{
				//����С��y
				if (y[i][j] > y[i - 1][j - x[i] * k] + k)
				{
					y[i][j] = y[i - 1][j - x[i] * k] + k;
				}
			}
		}
	}
	if (y[t][sum] > m)
	{
		return 0;
	}
	return 1;
}

// 
void Backtrack(int x[100], int cur, int max)
{
	int i, j, next;
	//����Ѿ��ó���n����Ʊ 
	if (cur == n) 
	{
		//�����������ֵ�Ѿ����ڵ�ǰ��������� 
		if (max > Maxvalue) 
		{
			Maxvalue = max;
			for (i = 1; i <= cur; i++)
			{
				//���´����� 
				bestx[i] = x[i];
			} 
		}
		return;
	}

	//�����û�õ�n����Ʊ����ô��x[cur]+1~max+1ѡһ����Ϊ��һ�����ʣ���Ϊmax+1û����ʾ�����Աض���max+1Ϊֹ  
	for (next = x[cur] + 1; next <= max + 1; next++)
	{
		//������Ϊcur+1,��Ŀ�ֱ�Ϊx[1..cur+1]����Ʊ,���ʹ��m�ţ��ܷ��ʾ������max��ĳ����
		x[cur + 1] = next;  
		//iΪ��������Ʊ֮���ܴﵽ�����ֵ�����������ҪΪmax+1,�����x[cur+1]*m 
		for (i = max + 1; i <= m * x[cur + 1]; i++)
		{
			//����0˵��������m,��ʱ��i����������������򷵻�1��i++
			if (judge(x, cur + 1, i) == 0)
			{
				break;
			}
		}
		//������������ֵ������һ��(���ֵ�������£�����������һ����Ʊ)
		if (i > max + 1)
		{
			//�ϲ�forѭ���õ�i֮�����ж���i+1,����i-1
			Backtrack(x, cur + 1, i - 1);
		}
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	int i, j, max, cur;
	int x[100];//�м䴫�ݵ����飬�洢��ǰ����Ʊֵ�Ľ�
	
	cout << "�����뷢����Ʊ�����ࣺ" << endl;
	cin >> n;
	cout << "������ÿ���ŷ��������������Ʊ������" << endl;
	cin >> m;

	Maxvalue = 0;
	//max��ʾ��ĿǰΪֹ�����ɵ�������
	max = m;
	cur = 1;
	x[cur] = 1;
	//x�洢��ǰ�Ľ�,cur��ʾ��ǰ���ݵ��ڼ�����Ʊ,max��ʾĿǰ�ܱ�ʾ�������ֵ 
	Backtrack(x, cur, max); 
	
	cout << "�����Ʒ�����" << endl;
	for (i = 1; i <= n; i++)
	{
		cout << bestx[i] << " ";
	}	
	cout << endl << "�����������Ϊ " << Maxvalue << endl;
	return 0;
}

