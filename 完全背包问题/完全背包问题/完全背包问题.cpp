// ��ȫ��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_VOLE 2001
#define MAX_ITEM_NUM 101

int _tmain(int argc, _TCHAR* argv[])
{
	// ��������
	int nBagVole;
	cout << "�����뱳��������" << endl;
	cin >> nBagVole;
	// ��Ʒ����
	int nItemKind;
	cout << "��������Ʒ���ࣺ" << endl;
	cin >> nItemKind;

	// ���ڼ�¼������Ʒ�������ͼ�ֵ
	int arrWeight[MAX_ITEM_NUM], arrValue[MAX_ITEM_NUM];
	// ��¼��������ʱ�ļ�ֵ
	int f[MAX_VOLE] = { 0 };

	// ���������Ʒ�������ͼ�ֵ
	for (int i = 1; i <= nItemKind; i++)
	{
		cout << "�������" << i << "����Ʒ�������ͼ�ֵ��" << endl;
		cin >> arrWeight[i] >> arrValue[i];
	}

	// �ֱ��Ǽ���ǰi����Ʒ
	for (int i = 1; i <= nItemKind; i++)
	{
		for (int v = arrWeight[i]; v <= nBagVole; v++)          //�� f[v]��ʾ����������v���������ֵ
		{
			f[v] = max(f[v - arrWeight[i]] + arrValue[i], f[v]);
		}
	}

	cout << "��ߵļ�ֵΪ��" << f[nBagVole] << endl;

	return 0;
}

