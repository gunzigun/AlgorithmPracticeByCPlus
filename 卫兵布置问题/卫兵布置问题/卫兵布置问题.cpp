// 卫兵布置问题.cpp : 定义控制台应用程序的入口点。
//
/*
使用回溯法,从上到下从左到右依次使得每个访问过的格子都进入监视状态.
让未进入监视状态的当前格点进入监视状态只有三种情况,在当前节点放置机器人,在右侧节点放置机器人,在下方节点放置机器人,依次递归判断.
记录初始的最优值为一个最大值,每次放完后与当前最优值比较并更新答案.
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

// 定义一个数组最大值MAX_ARRAY_DEM
const int MMAX_ARRAY_DEM = 100;
// 定义5个方向{0，0}原位置，{0，1}下边，{0，-1}上边，{1，0}右边，{-1，0}左边
const int go[5][2] = { { 0, 0 }, { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
// 行数n，列数m
int n, m;
// 结果记录数组，结果记录卫兵个数
int anx[MMAX_ARRAY_DEM][MMAX_ARRAY_DEM], ans;
// put为放置数组，spy为监控数组，spys为监控位置数
int put[MMAX_ARRAY_DEM][MMAX_ARRAY_DEM], spy[MMAX_ARRAY_DEM][MMAX_ARRAY_DEM], tmp, spys = 0;

// 因为Search中要用到Puta，Puta中又需要用到Search，所以先在前面声明Search，不然Puta函数报错
void Search(int i, int j);

// 卫兵放置函数
// x,y为放置卫兵的位置
// i,j为待监控点的位置
void Puta(int x, int y, int i, int j)
{
	// 先占位（5各方向）
	put[x][y] = 1;
	tmp++;
	for (int i = 0; i < 5; ++i)
	{
		if (++spy[x + go[i][0]][y + go[i][1]] == 1)
		{
			spys++;
		}
	}

	// 查找下一个位置
	Search(i, j + 1);

	// 再清位（5各方向）
	put[x][y] = 0;
	tmp--;
	for (int i = 0; i < 5; ++i)
	{
		if (--spy[x + go[i][0]][y + go[i][1]] == 0)
		{
			spys--;
		}
	}
}

// 检查某个监控位置，添加监控
void Search(int i, int j)
{
	// 当前卫兵数大于已有最小卫兵数，则不用再做下去了
	if (tmp >= ans)
	{
		return;
	}

	//已放置的不再被搜索
	while (i <= n && spy[i][j]) 
	{
		++j;
		if (j > m)
		{
			++i, j = 1;
		}
	}

	//更新答案
	if (i > n)					
	{
		ans = tmp;
		memcpy(anx, put, sizeof(put));
		return;
	}

	//这里是一个优化减枝策略（放置的机器人个数不会超过nm/3+1个
	//(按每个机器人仅辐射左右或上下考虑,堆叠这样的小长条,最后只会剩下11,12,22三种剩余,都满足).
	//以n*m/3+2为初始最优值,当放置的个数超过当前最优值时,剪去.）
	/*
	int lim1 = n * m;
	int lim2 = n * m + m / 4 + 5;
	int reach = spys + (ans - tmp) * 5;
	if (reach <= lim1)
	{
		return;
	}
	if (i < n - 1 && reach <= lim2)
	{
		return;
	}
	*/


	//若(i, j + 1)已被监视, 则在(i, j)放置一定不会比在(i + 1, j)放置的情况好.
	//所以当且仅当(i, j)在网格右下角或者(i, j + 1)未被监视时才考虑放置在(i, j)的情况.
	if ((i == n&&j == m) || spy[i][j + 1] == 0)
	{
		// 放在原位置
		Puta(i, j, i, j);
	}
	//当i=n时,不考虑放置在(i+1,j)的情况,所以i<n时放在右边
	if (i < n)
	{
		// 放在右边
		Puta(i + 1, j, i, j);
	}
	//若(i, j + 1)和(i, j + 2)均被监视, 则在(i + 1, j)放置一定不会比在(i + 1, j)放置的情况好, 
	//所以当且仅当(i, j + 1)或(i, j + 2)未被监视时才考虑放置在(i, j + 1)的情况.
	if (j < m && (spy[i][j + 1] == 0 || spy[i][j + 2] == 0))
	{
		// 放在下面
		Puta(i, j + 1, i, j);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "请输出行号：";
	cin >> n;
	cout << "请输出列号：";
	cin >> m;

	// 卫兵数设置成一个最大值
	ans = n * m / 3 + 2;
	for (int i = 0; i <= n + 1; ++i)
	{
		spy[i][0] = spy[i][m + 1] = 1;
	}
	for (int i = 0; i <= m + 1; ++i)
	{
		spy[0][i] = spy[n + 1][i] = 1;
	}
		
	// 算法开始
	Search(1, 1);

	// 输出结果
	cout << "最少需要" << ans << "个卫兵" << endl;
	cout << "卫兵位置为：" << endl;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cout << anx[i][j] << (j == m ? '\n' : ' ');
		}
	}
	return 0;
}

