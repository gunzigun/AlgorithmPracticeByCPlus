// 最小生成树（Prim算法）.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//定义一个无穷大的数字
#define INF 10000
//定义总共的结点数量
#define N 6
//定义数组记录已经访问过的节点 
bool visit[N];
//定义距离数组
int dist[N] = { 0, };
//定义图和图间的距离
int graph[N][N] =
{
	{ INF, 7, 4, INF, INF, INF },  //INF代表两点之间不可达
	{ 7, INF, 6, 2, INF, 4 },
	{ 4, 6, INF, INF, 9, 8 },
	{ INF, 2, INF, INF, INF, 7 },
	{ INF, INF, 9, INF, INF, 1 },
	{ INF, 4, 8, 7, 1, INF }
};

// Prim算法
int Prim(int cur)
{
	//把初始图输出
	cout << "初始的图如下：" << endl;
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

	cout << "挨个输出节点：" << endl;
	// 输出初始节点
	int index = cur;
	int sum = 0;
	cout << index << " ";
	
	//把所有节点设置成未访问
	memset(visit, false, sizeof(visit));
	//初始节点设置为访问过
	visit[cur] = true;

	//初始化，每个与a邻接的点的距离存入dist
	for (int i = 0; i < N; i++)
	{
		dist[i] = graph[cur][i];
	}
		
	//开始遍历各个点
	for (int i = 1; i < N; i++)
	{
		int minor = INF;
		for (int j = 0; j < N; j++)
		{
			//找到未访问的点中，距离当前最小生成树距离最小的点
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
			//执行更新，如果点距离当前点的距离更近，就更新dist
			if (!visit[j] && dist[j] > graph[index][j])      
			{
				dist[j] = graph[index][j];
			}
		}
	}
	cout << endl;
	//返回最小生成树的总路径值
	return sum;               
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "最小生成树的最小距离为：" << Prim(0) << endl;
	return 0;
}

