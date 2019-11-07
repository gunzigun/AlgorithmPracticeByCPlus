// ͼ��ɫ����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;


//����һ������������
#define INF 10000
//�����ܹ��Ľ������
#define N 6
//���������¼�Ѿ����ʹ��Ľڵ㣨0��ʾ����ɫ��
int visit[N];
//����ͼ��ͼ��ľ���
int graph[N][N] =
{
	{ INF, 1, 1, 1, INF, INF },  //INF��������֮�䲻�ɴ�
	{ 1, INF, 1, INF, INF, INF },
	{ 1, 1, INF, INF, 1, 1 },
	{ 1, INF, INF, INF, INF, INF },
	{ INF, INF, 1, INF, INF, INF },
	{ INF, INF, 1, INF, INF, INF }
};

// �Ƿ���δ��ɫ�ĵ�
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

// ͼ��ɫ����
void Function(int cur)
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

	//�����нڵ����ó�δ����(0)
	memset(visit, 0, sizeof(visit));

	//�㷨��ʼ
	int nColor = 1;
	int nCunIndex = cur;
	// ����ѭ����ֱ�����е㶼��ɫΪֹ
	do 
	{
		cout << "��ɫ" << nColor << "�ŵĽڵ㣺";
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

	//�ӵ�0���㿪ʼ��ɫ
	Function(0);
	return 0;
}

