// Բ��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

float CirclePerm(int n, float *a);

template <class Type>
inline void Swap(Type &a, Type &b);


class Circle
{
	// ����һ����Ԫ����������ʹ�����˽�з���
	friend float CirclePerm(int, float *);
private:
	//���㵱ǰ��ѡ���Բ�ڵ�ǰԲ������Բ�ĵĺ�����
	float Center(int t);
	//���㵱ǰԲ���еĳ���
	void Compute();
	void Backtrack(int t);

	float min,	//��ǰ����ֵ
		*x,   //��ǰԲ����Բ�ĺ�����
		*r;   //��ǰԲ����
	//Բ������Բ�ĸ���
	int n;
};

// ���㵱ǰ��ѡ��Բ��Բ�ĺ�����
float Circle::Center(int t)
{
	float temp = 0;
	for (int j = 1; j < t; j++)
	{
		//��x^2 = sqrt((r1+r2)^2-(r1-r2)^2)�Ƶ�����
		float valuex = x[j] + 2.0*sqrt(r[t] * r[j]);
		if (valuex > temp)
		{
			temp = valuex;
		}
	}
	return temp;
}

// ���㵱ǰԲ���еĳ���
void Circle::Compute(void)
{
	float low = 0, high = 0;
	for (int i = 1; i <= n; i++)
	{
		if (x[i] - r[i] < low)
		{
			low = x[i] - r[i];
		}

		if (x[i] + r[i] > high)
		{
			high = x[i] + r[i];
		}
	}
	if (high - low<min)
	{
		min = high - low;
	}
}

// Բ���еĻ����㷢
void Circle::Backtrack(int t)
{
	if (t>n)
	{
		Compute();
	}
	else
	{
		for (int j = t; j <= n; j++)
		{
			// �Ƚ���
			Swap(r[t], r[j]);

			float centerx = Center(t);
			if (centerx + r[t] + r[1] < min)//�½�Լ��
			{
				x[t] = centerx;
				// ��һ��Բ�����ټ�һ��Բ
				Backtrack(t + 1);
			}

			// �ٽ������������ݣ�
			Swap(r[t], r[j]);
		}
	}
}

// Բ�����㷨
float CirclePerm(int n, float *a)
{
	Circle X;
	X.n = n;
	X.r = a;
	X.min = 100000;
	float *x = new float[n + 1];
	X.x = x;
	X.Backtrack(1);
	delete[]x;
	return X.min;
}

// ����һ����������
template <class Type>
inline void Swap(Type &a, Type &b)
{
	Type temp = a;
	a = b;
	b = temp;
}

int _tmain(int argc, _TCHAR* argv[])
{
	float *a = new float[4];
	a[1] = 1, a[2] = 1, a[3] = 2;
	cout << "Բ�����и�Բ�İ뾶�ֱ�Ϊ��" << endl;
	for (int i = 1; i < 4; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "��СԲ���г���Ϊ��";
	cout << CirclePerm(3, a) << endl;
	return 0;
}

