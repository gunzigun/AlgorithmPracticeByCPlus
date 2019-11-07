// 子串匹配问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 蛮力算法
int BF(string ts, string ps) 
{
	int i = 0; // 主串的位置
	int j = 0; // 模式串的位置

	while (i < ts.length() && j < ps.length())
	{
		if (ts[i] == ps[j]) 
		{ 
			// 当两个字符相同，就比较下一个
			i++;
			j++;
		}
		else 
		{
			i = i - j + 1; // 一旦不匹配，i后退
			j = 0; // j归0
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


// KMP算法计算KMP值（Next值）
//当T[i] != P[j]时
//有T[i - j ~i - 1] == P[0 ~j - 1]
//由P[0 ~k - 1] == P[j - k ~j - 1]
//必然：T[i - k ~i - 1] == P[0 ~k - 1]
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

// KMP算法
int KMP(string ts, string ps)
{
	int i = 0; // 主串的位置
	int j = 0; // 模式串的位置

	vector<int> next = getNext(ps);
	while (i < ts.length() && j < ps.length()) 
	{
		if (j == -1 || ts[i] == ps[j])
		{
			// 当j为-1时，要移动的是i，当然j也要归0
			i++;
			j++;
		}
		else
		{
			// i不需要回溯了
			j = next[j]; // j回到指定位置
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

	//使用蛮力算法求解
	//int nPosition = BF(A, B);
	
	//使用KMP算法求解
	int nPosition = KMP(A, B);

	if (nPosition != -1)
	{
		cout << "在第" << nPosition + 1 << "个位置，找到了子串！\n";
	}
	else
	{
		cout << "没有找到子串！\n";
	}

	return 0;
}

