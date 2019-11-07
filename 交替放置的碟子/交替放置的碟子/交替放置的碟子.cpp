// ������õĵ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

#define  PROBLEM_LARGE 10
#define  ALL_CATE_NUM PROBLEM_LARGE*2
static string arrAllCate[ALL_CATE_NUM];

//�����㷨:����1
void WayChange1()
{
	int nChangePosition = 0;
	int nCirCle = 0;

	for (int i = 0; i < PROBLEM_LARGE; ++i)
	{
		int nNow = i + 1;
		do
		{
			if (arrAllCate[nNow - 1] != arrAllCate[nNow])
			{
				//������������Ԫ��ֵ
				string strRange = arrAllCate[nNow - 1];
				arrAllCate[nNow - 1] = arrAllCate[nNow];
				arrAllCate[nNow] = strRange;

				//����������1
				++nChangePosition;

			}
			++nNow;

			//ѭ��������1
			++nCirCle;
		} 
		while (nNow < ALL_CATE_NUM);

		//ÿһ�˵Ľ�����������
		cout << "��" << i + 1 << "�˽����";
		for (int j = 0; j < ALL_CATE_NUM; ++j)
		{
			cout << arrAllCate[j] << " ";
		}
		cout << endl << endl;
	}

	cout << "����������" << nChangePosition << endl;
	cout << "ѭ��������" << nCirCle << endl;
}

//�����㷨:����2
void WayChange2()
{
	int nChangePosition = 0;
	int nCirCle = 0;
	
	for (int i = 0; i < PROBLEM_LARGE;++i)
	{
		int head = i;
		int tail = ALL_CATE_NUM - i - 1;
		do
		{
			if (tail - head == 1)
			{
				string strMid = arrAllCate[head];
				arrAllCate[head] = arrAllCate[tail];
				arrAllCate[tail] = strMid;

				//����������1
				++nChangePosition;
			}
			else
			{
				string strRangehead = arrAllCate[head];
				arrAllCate[head] = arrAllCate[head + 1];
				arrAllCate[head + 1] = strRangehead;

				string strRangetail = arrAllCate[tail];
				arrAllCate[tail] = arrAllCate[tail - 1];
				arrAllCate[tail - 1] = strRangetail;

				//����������2
				nChangePosition +=2;
			}

			head += 2;
			tail -= 2;

			//ѭ��������1
			++nCirCle;
		} 
		while (head < tail);

		//ÿһ�˵Ľ�����������
		cout << "��" << i + 1 << "�˽����";
		for (int j = 0; j < ALL_CATE_NUM; ++j)
		{
			cout << arrAllCate[j] << " ";
		}
		cout << endl << endl;
	}

	cout << "����������" << nChangePosition << endl;
	cout << "ѭ��������" << nCirCle << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	// ��ʼ������
	cout << "��ʼ���������£�";
	for (int i = 0; i < ALL_CATE_NUM; ++i)
	{
		int nCount = i + 1;
		if (nCount % 2 == 0)
		{
			arrAllCate[i] = "��";
		}
		else
		{
			arrAllCate[i] = "��";
		}

		cout << arrAllCate[i] << " ";
	}
	cout << endl << endl;

	//WayChange1();
	WayChange2();

	return 0;
}

