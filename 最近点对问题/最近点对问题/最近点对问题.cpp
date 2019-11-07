// 最近点对问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <algorithm>
#include <iomanip>
using namespace std;

#define MAX_DISTANCE 10000000
#define N_POINT_NUM 10

//定义储存点的结构
struct Node 
{
	double x;
	double y;
};

// Node类的比较函数
bool cmpX(Node &a, Node &b)
{
	return a.x < b.x;
}

Node *PointsX;
Node *PointsY;

//随机生成点
void CreatePoints(Node Points[], int pointNumber)
{
	srand(time(NULL));		//随机化随机数种子
	for (int i = 0; i < pointNumber; i++)
	{
		Points[i].x = rand() / (double)RAND_MAX;
		Points[i].y = rand() / (double)RAND_MAX;
		//每1000个数据乘以一个特定的数，将数据尽量分散，减少重复
		Points[i].x *= ((i / 1000) + 1);
		Points[i].y *= ((i / 1000) + 1);

		//数据变换
		Points[i].x *= 10;
		Points[i].y *= 10;
		Points[i].x = (int)Points[i].x;
		Points[i].y = (int)Points[i].y;

		//遍历已经生成的所有点，一旦发现重合则重新生成该点
		for (int j = 0; j < i; j++)
		{
			if (Points[j].x == Points[i].x && Points[j].y == Points[i].y)
			{
				i--;
				break;
			}
		}
	}
}

//蛮力算法
double BruteForceMethod(Node p[], int length, Node &minPoint1, Node &minPoint2)
{
	if (length == 1)
	{
		//点数为1输出无穷大
		return MAX_DISTANCE;
	}
	else if (length == 2)	//点数为2直接输出点距
	{
		//点数为2直接输出点距
		minPoint1 = p[0];
		minPoint2 = p[1];
		return ((p[0].x - p[1].x)*(p[0].x - p[1].x) + (p[0].y - p[1].y)*(p[0].y - p[1].y));

	}
	else
	{
		int i, j;
		double mindis, temp;
		//先取前两个点的点距为最小距离
		mindis = (p[0].x - p[1].x)*(p[0].x - p[1].x) + (p[0].y - p[1].y)*(p[0].y - p[1].y);
		minPoint1 = p[0];
		minPoint2 = p[1];

		for (i = 0; i < length - 1; i++)
		{
			for (j = i + 1; j < length; j++)
			{
				temp = (p[i].x - p[j].x)*(p[i].x - p[j].x) + (p[i].y - p[j].y)*(p[i].y - p[j].y);	//算出每两个点的点距
				if (temp < mindis)
				{
					//当发现更小的距离时，替换最小点距，并记录两个点的信息	
					mindis = temp;
					minPoint1 = p[i];
					minPoint2 = p[j];
				}
			}
		}

		//直到返回结果时才求sqrt得到真正距离，减少运算量
		return sqrt(mindis);
	}
}

//归并排序
void Merge(int left, int right) 
{

	int mid = (left + right) / 2;
	int i = left, j = mid + 1;
	int idx = left;

	while (i <= mid && j <= right) {
		if (PointsX[i].y < PointsX[j].y)
			PointsY[idx++] = PointsX[i++];
		else
			PointsY[idx++] = PointsX[j++];
	}

	while (i <= mid)
		PointsY[idx++] = PointsX[i++];
	while (j <= right)
		PointsY[idx++] = PointsX[j++];

	for (i = left; i <= right; i++)
		PointsX[i] = PointsY[i];
}

// 分治算法（T(n) = 2T(n/2)+O(n)递推= O(nlogn)）
// p1,p2传递的是引用，用于返回最小点对
double MergeMethod(Node *px, int l, int r, Node &p1, Node &p2) 
{
	if (r - l <= 0)	
	{
		//点数为1时输出无穷大
		return MAX_DISTANCE;
	}
	else if (r - l == 1) 
	{
		//点数为2直接输出点距同时记录点对
		Merge(l, r);
		p1 = px[l];
		p2 = px[r];
		return sqrt((px[r].x - px[l].x)*(px[r].x - px[l].x) + (px[r].y - px[l].y)*(px[r].y - px[l].y));
	}
	else 
	{
		Node c, d, e, f;
		double mindis;
		int i, j;
		int mid = (r + l) / 2;		//前面已排好序，直接平均分

		double middlex = PointsX[mid].x;	//记录中线的x值，用于后面判断和存储中间区域的点

		double mindis1 = MergeMethod(px, l, mid, c, d);		//求左边部分的最短点距
		double mindis2 = MergeMethod(px, mid + 1, r, e, f);	//求右边部分的最短点距

		if (mindis1 < mindis2)
		{
			//两边比较取最小值，并记录点对
			mindis = mindis1;
			p1 = c;
			p2 = d;
		}
		else
		{
			mindis = mindis2;
			p1 = e;
			p2 = f;
		}

		Node *temp = new Node[r - l + 1];		//将所有与中间点的横坐标距离小于mindis的点纳入数组
		int number = 0;

		Merge(l, r);			//对点进行合并操作，之后的数组已是按y值排好的数组

		for (i = l; i <= r; i++)
		{
			if (fabs(px[i].x - middlex) <= mindis)
			{	
				//数组内的数据相当于在横坐标范围[middlex-mindis,middlex+mindis]之间
				temp[number++] = px[i];
			}
		}

		double tempdis;		//遍历中间数组，每个点最多遍历其他点6次，记录最短距离和点对
		for (i = 0; i < number; i++) 
		{
			for (j = i + 1; j < i + 1 + 6 && j < number; j++)
			{
				tempdis = sqrt((temp[i].x - temp[j].x)*(temp[i].x - temp[j].x) + (temp[i].y - temp[j].y)*(temp[i].y - temp[j].y));
				if (tempdis < mindis) 
				{
					mindis = tempdis;
					p1 = temp[i];
					p2 = temp[j];
				}
			}
		}
		delete[]temp;
		return mindis;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	PointsX = new Node[N_POINT_NUM];
	CreatePoints(PointsX, N_POINT_NUM);			//创建散点	
	sort(PointsX, PointsX + N_POINT_NUM, cmpX);	//对点以X坐标进行排序
	PointsY = new Node[N_POINT_NUM];			//创建新数组在Merge合并操作时用

	Node PointsX1[N_POINT_NUM];
	for (int m = 0; m < N_POINT_NUM; ++m)
	{
		Node node = *(PointsX + m);
		PointsX1[m] = node;
		cout << "(" << node.x << "," << node.y << ")" << "   "; //右对齐
		if ((m + 1) % 3 == 0)
		{
			cout << endl;
		}
	}
	cout << endl << endl;

	
	{
		cout << "使用的是蛮力法：" << endl;
		Node minPoint1, minPoint2;
		double dis = BruteForceMethod(PointsX, N_POINT_NUM, minPoint1, minPoint2);		//调用蛮力法
		cout << "最小距离：" << dis << "，介于(" << minPoint1.x << "," << minPoint1.y << ")和(" << minPoint2.x << "," << minPoint2.y << ")" << endl;
	}
	

	{
		cout << "使用的是分治法：" << endl;
		Node minPoint11, minPoint22;
		double dis1 = MergeMethod(PointsX1, 0, N_POINT_NUM - 1, minPoint11, minPoint22);	//调用分治法
		cout << "最小距离：" << dis1 << "，介于(" << minPoint11.x << "," << minPoint11.y << ")和(" << minPoint22.x << "," << minPoint22.y << ")" << endl;
	}

	return 0;
}

