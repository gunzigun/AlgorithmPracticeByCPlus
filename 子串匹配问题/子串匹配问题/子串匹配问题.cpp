// �Ӵ�ƥ������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// �����㷨
int BF(string ts, string ps) 
{
	int i = 0; // ������λ��
	int j = 0; // ģʽ����λ��

	while (i < ts.length() && j < ps.length())
	{
		if (ts[i] == ps[j]) 
		{ 
			// �������ַ���ͬ���ͱȽ���һ��
			i++;
			j++;
		}
		else 
		{
			i = i - j + 1; // һ����ƥ�䣬i����
			j = 0; // j��0
		}
	}

	if (j == ps.length()) 
	{
		return i - j;
	}
	else 
	{
		return -1;
	}
}


// KMP�㷨����KMPֵ��Nextֵ��
//��T[i] != P[j]ʱ
//��T[i - j ~i - 1] == P[0 ~j - 1]
//��P[0 ~k - 1] == P[j - k ~j - 1]
//��Ȼ��T[i - k ~i - 1] == P[0 ~k - 1]
vector<int> getNext(string ps) 
{
	vector<int> next;
	next.push_back(-1);
	int j = 0;
	int k = -1;
	while (j < ps.length() - 1) 
	{
		if (k == -1 || ps[j] == ps[k]) 
		{
			++j;
			next.push_back(++k);
		}
		else
		{
			k = next[k];
		}
	}

	return next;
}

// KMP�㷨
int KMP(string ts, string ps)
{
	int i = 0; // ������λ��
	int j = 0; // ģʽ����λ��

	vector<int> next = getNext(ps);
	while (i < ts.length() && j < ps.length()) 
	{
		if (j == -1 || ts[i] == ps[j])
		{
			// ��jΪ-1ʱ��Ҫ�ƶ�����i����ȻjҲҪ��0
			i++;
			j++;
		}
		else
		{
			// i����Ҫ������
			j = next[j]; // j�ص�ָ��λ��
		}
	}

	if (j == ps.length())
	{
		return i - j;
	}
	else 
	{
		return -1;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	string A = "aaaaaaaaaaaababAAAAA";
	string B = "abab";

	//ʹ�������㷨���
	//int nPosition = BF(A, B);
	
	//ʹ��KMP�㷨���
	int nPosition = KMP(A, B);

	if (nPosition != -1)
	{
		cout << "�ڵ�" << nPosition + 1 << "��λ�ã��ҵ����Ӵ���\n";
	}
	else
	{
		cout << "û���ҵ��Ӵ���\n";
	}

	return 0;
}

