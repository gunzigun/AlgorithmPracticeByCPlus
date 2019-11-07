// ����������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <algorithm>
#include <iomanip>
using namespace std;

#define MAX_DISTANCE 10000000
#define N_POINT_NUM 10

//���崢���Ľṹ
struct Node 
{
	double x;
	double y;
};

// Node��ıȽϺ���
bool cmpX(Node &a, Node &b)
{
	return a.x < b.x;
}

Node *PointsX;
Node *PointsY;

//������ɵ�
void CreatePoints(Node Points[], int pointNumber)
{
	srand(time(NULL));		//��������������
	for (int i = 0; i < pointNumber; i++)
	{
		Points[i].x = rand() / (double)RAND_MAX;
		Points[i].y = rand() / (double)RAND_MAX;
		//ÿ1000�����ݳ���һ���ض������������ݾ�����ɢ�������ظ�
		Points[i].x *= ((i / 1000) + 1);
		Points[i].y *= ((i / 1000) + 1);

		//���ݱ任
		Points[i].x *= 10;
		Points[i].y *= 10;
		Points[i].x = (int)Points[i].x;
		Points[i].y = (int)Points[i].y;

		//�����Ѿ����ɵ����е㣬һ�������غ����������ɸõ�
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

//�����㷨
double BruteForceMethod(Node p[], int length, Node &minPoint1, Node &minPoint2)
{
	if (length == 1)
	{
		//����Ϊ1��������
		return MAX_DISTANCE;
	}
	else if (length == 2)	//����Ϊ2ֱ��������
	{
		//����Ϊ2ֱ��������
		minPoint1 = p[0];
		minPoint2 = p[1];
		return ((p[0].x - p[1].x)*(p[0].x - p[1].x) + (p[0].y - p[1].y)*(p[0].y - p[1].y));

	}
	else
	{
		int i, j;
		double mindis, temp;
		//��ȡǰ������ĵ��Ϊ��С����
		mindis = (p[0].x - p[1].x)*(p[0].x - p[1].x) + (p[0].y - p[1].y)*(p[0].y - p[1].y);
		minPoint1 = p[0];
		minPoint2 = p[1];

		for (i = 0; i < length - 1; i++)
		{
			for (j = i + 1; j < length; j++)
			{
				temp = (p[i].x - p[j].x)*(p[i].x - p[j].x) + (p[i].y - p[j].y)*(p[i].y - p[j].y);	//���ÿ������ĵ��
				if (temp < mindis)
				{
					//�����ָ�С�ľ���ʱ���滻��С��࣬����¼���������Ϣ	
					mindis = temp;
					minPoint1 = p[i];
					minPoint2 = p[j];
				}
			}
		}

		//ֱ�����ؽ��ʱ����sqrt�õ��������룬����������
		return sqrt(mindis);
	}
}

//�鲢����
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

// �����㷨��T(n) = 2T(n/2)+O(n)����= O(nlogn)��
// p1,p2���ݵ������ã����ڷ�����С���
double MergeMethod(Node *px, int l, int r, Node &p1, Node &p2) 
{
	if (r - l <= 0)	
	{
		//����Ϊ1ʱ��������
		return MAX_DISTANCE;
	}
	else if (r - l == 1) 
	{
		//����Ϊ2ֱ��������ͬʱ��¼���
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
		int mid = (r + l) / 2;		//ǰ�����ź���ֱ��ƽ����

		double middlex = PointsX[mid].x;	//��¼���ߵ�xֵ�����ں����жϺʹ洢�м�����ĵ�

		double mindis1 = MergeMethod(px, l, mid, c, d);		//����߲��ֵ���̵��
		double mindis2 = MergeMethod(px, mid + 1, r, e, f);	//���ұ߲��ֵ���̵��

		if (mindis1 < mindis2)
		{
			//���߱Ƚ�ȡ��Сֵ������¼���
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

		Node *temp = new Node[r - l + 1];		//���������м��ĺ��������С��mindis�ĵ���������
		int number = 0;

		Merge(l, r);			//�Ե���кϲ�������֮����������ǰ�yֵ�źõ�����

		for (i = l; i <= r; i++)
		{
			if (fabs(px[i].x - middlex) <= mindis)
			{	
				//�����ڵ������൱���ں����귶Χ[middlex-mindis,middlex+mindis]֮��
				temp[number++] = px[i];
			}
		}

		double tempdis;		//�����м����飬ÿ����������������6�Σ���¼��̾���͵��
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
	CreatePoints(PointsX, N_POINT_NUM);			//����ɢ��	
	sort(PointsX, PointsX + N_POINT_NUM, cmpX);	//�Ե���X�����������
	PointsY = new Node[N_POINT_NUM];			//������������Merge�ϲ�����ʱ��

	Node PointsX1[N_POINT_NUM];
	for (int m = 0; m < N_POINT_NUM; ++m)
	{
		Node node = *(PointsX + m);
		PointsX1[m] = node;
		cout << "(" << node.x << "," << node.y << ")" << "   "; //�Ҷ���
		if ((m + 1) % 3 == 0)
		{
			cout << endl;
		}
	}
	cout << endl << endl;

	
	{
		cout << "ʹ�õ�����������" << endl;
		Node minPoint1, minPoint2;
		double dis = BruteForceMethod(PointsX, N_POINT_NUM, minPoint1, minPoint2);		//����������
		cout << "��С���룺" << dis << "������(" << minPoint1.x << "," << minPoint1.y << ")��(" << minPoint2.x << "," << minPoint2.y << ")" << endl;
	}
	

	{
		cout << "ʹ�õ��Ƿ��η���" << endl;
		Node minPoint11, minPoint22;
		double dis1 = MergeMethod(PointsX1, 0, N_POINT_NUM - 1, minPoint11, minPoint22);	//���÷��η�
		cout << "��С���룺" << dis1 << "������(" << minPoint11.x << "," << minPoint11.y << ")��(" << minPoint22.x << "," << minPoint22.y << ")" << endl;
	}

	return 0;
}

