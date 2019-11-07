// 最小生成树（Kruskal）.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//定义一个无穷大的数字
#define INF 10000
//定义总共的结点数量
#define N 6

//并查集实现最小生成树
vector<int> u, v, weights, w_r, father;

// 自己实现一个比较函数，用于sort函数
int mycmp(int i, int j)
{
	return weights[i] < weights[j];
}

// 查找一个元素的根节点
int find(int x)
{
	return father[x] == x ? x : father[x] = find(father[x]);
}

// Kruskal算法代码
void Kruskal()
{
	vector<vector<int> > A(N, vector<int>(N));
	//初始化图（INF代表两点之间不可达）
	A[0] = { INF, 7, 4, INF, INF, INF };
	A[1] = { 7, INF, 6, 2, INF, 4 };
	A[2] = { 4, 6, INF, INF, 9, 8 };
	A[3] = { INF, 2, INF, INF, INF, 7 };
	A[4] = { INF, INF, 9, INF, INF, 1 };
	A[5] = { INF, 4, 8, 7, 1, INF };
	cout << "初始的图如下：" << endl;
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


	// 共计n*(n - 1)/2条边(记录下所有的节点和边)
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

	// 记录n个节点的根节点，初始化为各自本身
	for (int i = 0; i < N; ++i) 
	{
		father.push_back(i);
	}
	//以weight的大小来对索引值进行排序
	sort(w_r.begin(), w_r.end(), mycmp); 


	int min_tree = 0, cnt = 0;
	//不断找到最小的边，把节点一个个合并成树
	for (int i = 0; i < edges; ++i)
	{
		//e代表排序后的权值的索引
		int e = w_r[i];    
		int x = find(u[e]);
		int y = find(v[e]);
		//x不等于y表示u[e]和v[e]两个节点没有公共根节点，可以合并
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
		
	cout << "最小生成树的距离为：" << min_tree << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Kruskal();
	return 0;
}

