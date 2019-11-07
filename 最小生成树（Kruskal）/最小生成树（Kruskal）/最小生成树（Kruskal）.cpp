// ��С��������Kruskal��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//����һ������������
#define INF 10000
//�����ܹ��Ľ������
#define N 6

//���鼯ʵ����С������
vector<int> u, v, weights, w_r, father;

// �Լ�ʵ��һ���ȽϺ���������sort����
int mycmp(int i, int j)
{
	return weights[i] < weights[j];
}

// ����һ��Ԫ�صĸ��ڵ�
int find(int x)
{
	return father[x] == x ? x : father[x] = find(father[x]);
}

// Kruskal�㷨����
void Kruskal()
{
	vector<vector<int> > A(N, vector<int>(N));
	//��ʼ��ͼ��INF��������֮�䲻�ɴ
	A[0] = { INF, 7, 4, INF, INF, INF };
	A[1] = { 7, INF, 6, 2, INF, 4 };
	A[2] = { 4, 6, INF, INF, 9, 8 };
	A[3] = { INF, 2, INF, INF, INF, 7 };
	A[4] = { INF, INF, 9, INF, INF, 1 };
	A[5] = { INF, 4, 8, 7, 1, INF };
	cout << "��ʼ��ͼ���£�" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int nWeight = A[i][j];
			if (nWeight == INF)
			{
				cout << "*" << "  ";
			}
			else
			{
				cout << nWeight << "  ";
			}
		}
		cout << endl;
	}


	// ����n*(n - 1)/2����(��¼�����еĽڵ�ͱ�)
	int edges = 0;
	for (int i = 0; i < N - 1; ++i) 
	{
		for (int j = i + 1; j < N; ++j)
		{
			u.push_back(i);
			v.push_back(j);
			weights.push_back(A[i][j]);
			w_r.push_back(edges++);
		}
	}

	// ��¼n���ڵ�ĸ��ڵ㣬��ʼ��Ϊ���Ա���
	for (int i = 0; i < N; ++i) 
	{
		father.push_back(i);
	}
	//��weight�Ĵ�С��������ֵ��������
	sort(w_r.begin(), w_r.end(), mycmp); 


	int min_tree = 0, cnt = 0;
	//�����ҵ���С�ıߣ��ѽڵ�һ�����ϲ�����
	for (int i = 0; i < edges; ++i)
	{
		//e����������Ȩֵ������
		int e = w_r[i];    
		int x = find(u[e]);
		int y = find(v[e]);
		//x������y��ʾu[e]��v[e]�����ڵ�û�й������ڵ㣬���Ժϲ�
		if (x != y) 
		{
			min_tree += weights[e];
			father[x] = y;
			++cnt;
		}
	}

	if (cnt < N - 1)
	{
		min_tree = 0;
	}
		
	cout << "��С�������ľ���Ϊ��" << min_tree << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Kruskal();
	return 0;
}

