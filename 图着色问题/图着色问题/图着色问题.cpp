// 图着色问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;


//定义一个无穷大的数字
#define INF 10000
//定义总共的结点数量
#define N 6
//定义数组记录已经访问过的节点（0表示无颜色）
int visit[N];
//定义图和图间的距离
int graph[N][N] =
{
	{ INF, 1, 1, 1, INF, INF },  //INF代表两点之间不可达
	{ 1, INF, 1, INF, INF, INF },
	{ 1, 1, INF, INF, 1, 1 },
	{ 1, INF, INF, INF, INF, INF },
	{ INF, INF, 1, INF, INF, INF },
	{ INF, INF, 1, INF, INF, INF }
};

// 是否还有未着色的点
bool HaveNoColor(int& index)
{
	for (int i = 0; i < N; i++)
	{
		if (visit[i] == 0)
		{
			index = i;
			return true;
		}
	}
	return false;
}

// 图着色函数
void Function(int cur)
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

	//把所有节点设置成未访问(0)
	memset(visit, 0, sizeof(visit));

	//算法开始
	int nColor = 1;
	int nCunIndex = cur;
	// 不断循环，直到所有点都着色为止
	do 
	{
		cout << "颜色" << nColor << "号的节点：";
		for (int i = 0; i < N; i++)
		{
			if (visit[i] == 0 && graph[nCunIndex][i] == INF)
			{
				visit[i] = nColor;
				cout << i << " ";
			}
		}
		cout << endl;
		++nColor;

	} while (HaveNoColor(nCunIndex));

}


int _tmain(int argc, _TCHAR* argv[])
{

	//从第0个点开始着色
	Function(0);
	return 0;
}

