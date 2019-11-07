// ��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

#define TOTAL_DOOR_NUM 1000
#define EACH_LINE_SHOW 5
int doorchangeNum[TOTAL_DOOR_NUM];


// ����������ŵĿ��ش�����������ȫ��doorchangeNum��
void CacuAllDoorKind()
{
	for (int i = 1; i <= TOTAL_DOOR_NUM; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			if (i%j == 0)
			{
				++doorchangeNum[i - 1];
			}
		}
	}
}

// ����1�����ĳһ�����ǲ��ǹرյ�
bool CheckDoorOpen(int n)
{
	if (n >= 1 && n <= TOTAL_DOOR_NUM)
	{
		int index = n - 1;
		int nTimes = doorchangeNum[index];
		// ż�شεĿ��غ��Ż��ǹرյ�
		if (nTimes%2==0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	return false;
}

// ����2�����ݹ��ɿ��Է��֣�1��4��9��Щƽ����Ŀ�ǿ��ŵģ����Կ���������������ж�
bool CheckDoorOpenCool(int n)
{
	double sq, a;
	sq = sqrt(n); // sq��ֵΪ����n
	a = (int)sq;	  // aȡ����n����������
	if (a == sq)	  // ���a�͸���n����ȣ���ô����n������
	{
		return true;
	}
	return false;
}


int _tmain(int argc, _TCHAR* argv[])
{
	// ��ʼ�����������ſ��ش��������ó�0��
	for (int i = 1; i <= TOTAL_DOOR_NUM; ++i)
	{
		doorchangeNum[i - 1] = 0;
	}
	
	// ����������ŵĿ��ش�����������ȫ��doorchangeNum��
	CacuAllDoorKind();

	int nAllDoorOpenNum = 0;
	// ������д򿪵��ű��
	cout << "�򿪵�������Щ��" << endl;
	for (int i = 1; i <= TOTAL_DOOR_NUM; ++i)
	{
		//if (CheckDoorOpen(i))
		if (CheckDoorOpenCool(i))
		{
			cout << i << "  ";
			++nAllDoorOpenNum;

			//ÿEACH_LINE_SHOW���ͻ�һ��
			if (nAllDoorOpenNum%EACH_LINE_SHOW == 0)
			{
				cout << endl;
			}
		}
	}
	cout << endl << "�򿪵��ŵ�����Ŀ�ǣ�" << nAllDoorOpenNum << endl;

	return 0;
}

