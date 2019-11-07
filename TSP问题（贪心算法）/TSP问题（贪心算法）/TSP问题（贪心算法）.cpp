// TSP问题（贪心算法）.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#define N_TOTAL_CITY_NUM 4


int _tmain(int argc, _TCHAR* argv[])
{

	//用于存储已访问过的城市
	int S[N_TOTAL_CITY_NUM];
	//用于记算已访问过的城市的最小路径长度
	int sum = 0;
	//用于存储两个城市之间的距离
	int D[N_TOTAL_CITY_NUM][N_TOTAL_CITY_NUM] = {0};

	/*初始化:最短距离为0*/
	S[0] = 0;
	/*初始化:各个城市之间的距离*/
	D[0][1] = 2; D[0][2] = 6; D[0][3] = 5; D[1][0] = 2; D[1][2] = 4;
	D[1][3] = 4; D[2][0] = 6; D[2][1] = 4; D[2][3] = 2; D[3][0] = 5;
	D[3][1] = 4; D[3][2] = 2;
	cout << "各个城市的距离矩阵为：" << endl;
	for (int m = 0; m < N_TOTAL_CITY_NUM; ++m)
	{
		for (int n = 0; n < N_TOTAL_CITY_NUM; ++n)
		{
			cout << D[m][n] << "  ";
		}
		cout << endl;
	}

	// 贪心算法开始
	int j; // 一个临时变量
	int i = 1;  //(起始点访问的城市数)
	do
	{
		// Dtemp设定为一个很大的数值，表示无穷大
		int Dtemp = 10000;
		int k = 1;  //(终点访问的城市数)
		do
		{
			int l = 0;
			//最为访问的标志，若被访问过则为1，从未被访问过则为0
			int flag = 0;
			do
			{
				if (S[l] == k)
				{
					//判断该城市是否已被访问过，若被访问过，
					flag = 1;//则flag为1
					break;//跳出循环，不参与距离的比较
				}
				else
				{
					l++;
				}
					
			}while (l < i);

			if (flag == 0 && D[k][S[i - 1]] < Dtemp)
			{
				/*D[k][S[i - 1]]表示当前未被访问的城市k与上一个已访问过的城市i-1之间的距离*/
				j = k;//j用于存储已访问过的城市k
				Dtemp = D[k][S[i - 1]];//Dtemp用于暂时存储当前最小路径的值
			}

			k++;

		} while (k < N_TOTAL_CITY_NUM);

		S[i] = j;//将已访问过的城市j存入到S[i]中
		i++;
		sum += Dtemp;//求出各城市之间的最短距离，注意：在结束循环时，该旅行商尚未回到原出发的城市

	} while (i < N_TOTAL_CITY_NUM);


	sum += D[0][j];//D[0][j]为旅行商所在的最后一个城市与原出发的城市之间的距离
	cout << "最终输出的路径为：";
	for (j = 0; j < N_TOTAL_CITY_NUM; j++)
	{ 
		//输出经过的城市的路径
		cout << j << " ";
	}
	cout << endl << "最短路径的值为：" << sum << endl; //求出最短路径的值

}

