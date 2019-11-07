// ��С��������Prim�㷨��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//����һ������������
#define INF 10000
//�����ܹ��Ľ������
#define N 6
//���������¼�Ѿ����ʹ��Ľڵ� 
bool visit[N];
//�����������
int dist[N] = { 0, };
//����ͼ��ͼ��ľ���
int graph[N][N] =
{
	{ INF, 7, 4, INF, INF, INF },  //INF��������֮�䲻�ɴ�
	{ 7, INF, 6, 2, INF, 4 },
	{ 4, 6, INF, INF, 9, 8 },
	{ INF, 2, INF, INF, INF, 7 },
	{ INF, INF, 9, INF, INF, 1 },
	{ INF, 4, 8, 7, 1, INF }
};

// Prim�㷨
int Prim(int cur)
{
	//�ѳ�ʼͼ���
	cout << "��ʼ��ͼ���£�" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int nWeight = graph[i][j];
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

	cout << "��������ڵ㣺" << endl;
	// �����ʼ�ڵ�
	int index = cur;
	int sum = 0;
	cout << index << " ";
	
	//�����нڵ����ó�δ����
	memset(visit, false, sizeof(visit));
	//��ʼ�ڵ�����Ϊ���ʹ�
	visit[cur] = true;

	//��ʼ����ÿ����a�ڽӵĵ�ľ������dist
	for (int i = 0; i < N; i++)
	{
		dist[i] = graph[cur][i];
	}
		
	//��ʼ����������
	for (int i = 1; i < N; i++)
	{
		int minor = INF;
		for (int j = 0; j < N; j++)
		{
			//�ҵ�δ���ʵĵ��У����뵱ǰ��С������������С�ĵ�
			if (!visit[j] && dist[j] < minor)
			{
				minor = dist[j];
				index = j;
			}
		}
		visit[index] = true;
		cout << index << " ";
		sum += minor;


		for (int j = 0; j < N; j++)
		{
			//ִ�и��£��������뵱ǰ��ľ���������͸���dist
			if (!visit[j] && dist[j] > graph[index][j])      
			{
				dist[j] = graph[index][j];
			}
		}
	}
	cout << endl;
	//������С����������·��ֵ
	return sum;               
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "��С����������С����Ϊ��" << Prim(0) << endl;
	return 0;
}

