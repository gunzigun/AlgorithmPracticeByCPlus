// �������⣨�ڶ�����ҵ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <stack>
#define N_MAX_ARR_NUM 10
using namespace std;

// ð������
void PaoPaoSort(int arrNum[])
{
	// Ϊ��Ӱ��ԭ���飬����һ��
	int TepNum[N_MAX_ARR_NUM];
	for (int i = 0; i < N_MAX_ARR_NUM; ++i)
	{
		TepNum[i] = arrNum[i];
	}

	// �㷨��ʼ
	cout << "ð������:" << endl;

	for (int i = 0; i < N_MAX_ARR_NUM; ++i)
	{
		// ÿһ�����ĳ��ף�������С��ð��
		for (int j = i + 1; j < N_MAX_ARR_NUM; ++j)
		{
			if (TepNum[j] < TepNum[j - 1])
			{
				// ��������ֵ(�����и����ɣ�����������ʱ�������ﵽ�˽�����Ŀ��)
				// a = a + b
				// b = a - b
				// a = a - b
				TepNum[j] = TepNum[j - 1] + TepNum[j];
				TepNum[j - 1] = TepNum[j] - TepNum[j - 1];
				TepNum[j] = TepNum[j] - TepNum[j - 1];
			}
		}

		// ���ÿһ����������
		for (int m = 0; m < N_MAX_ARR_NUM; ++m)
		{
			cout << right << setw(6) << TepNum[m]; //�Ҷ���
		}
		cout << endl;
	}
}

// ѡ������
void SelectSort(int arrNum[])
{
	// Ϊ��Ӱ��ԭ���飬����һ��
	int TepNum[N_MAX_ARR_NUM];
	for (int i = 0; i < N_MAX_ARR_NUM; ++i)
	{
		TepNum[i] = arrNum[i];
	}

	// �㷨��ʼ
	cout << "ѡ������:" << endl;

	
	for (int i = 0; i < N_MAX_ARR_NUM-1; ++i)
	{
		// ÿһ��û�������Ƚϣ���ð�ݲ�ͬ��ֻ�Ǽ�¼����С��������λ�ã���󽻻�������λ��
		int nMinIndex = i;
		for (int j = i + 1; j < N_MAX_ARR_NUM; ++j)
		{
			if (TepNum[j] < TepNum[nMinIndex])
			{
				nMinIndex = j;
			}
		}

		// ����nMinIdex��i��ֵ
		TepNum[i] = TepNum[nMinIndex] + TepNum[i];
		TepNum[nMinIndex] = TepNum[i] - TepNum[nMinIndex];
		TepNum[i] = TepNum[i] - TepNum[nMinIndex];

		// ���ÿһ����������
		for (int m = 0; m < N_MAX_ARR_NUM; ++m)
		{
			cout << right << setw(10) << TepNum[m]; //�Ҷ���
		}
		cout << endl;
	}

}

// ��������
void InsertSort(int arrNum[])
{
	// Ϊ��Ӱ��ԭ���飬����һ��
	int TepNum[N_MAX_ARR_NUM];
	for (int i = 0; i < N_MAX_ARR_NUM; ++i)
	{
		TepNum[i] = arrNum[i];
	}

	// �㷨��ʼ
	cout << "��������:" << endl;

	for (int i = 0; i < N_MAX_ARR_NUM; ++i)
	{ 
		// ÿ��ֱ�Ӳ��뵽λ�ã�Ȼ��������ֵȫ������ƶ�
		for (int j = 0; j < i; ++j)
		{
			if (TepNum[j] > TepNum[i])
			{
				int nTempNum = TepNum[i];
				for (int k = i; k > j; --k)
				{
					TepNum[k] = TepNum[k - 1];
				}
				TepNum[j] = nTempNum;

				break;
			}
		}

		// ���ÿһ����������
		for (int m = 0; m < N_MAX_ARR_NUM; ++m)
		{
			cout << right << setw(10) << TepNum[m]; //�Ҷ���
		}
		cout << endl;
	}

}

// ��������
void QuickSort(int arr[], int start, int end) {
	// ���ÿһ����������
	for (int m = 0; m < N_MAX_ARR_NUM; ++m)
	{
		cout << right << setw(10) << arr[m]; //�Ҷ���
	}
	cout << endl;
	
	if (start < end) 
	{
		int s = arr[start];
		int i = start;
		int j = end;

		//ע��տ�ʼ����һ���ô���������Ҳſ���
		while (i < j)
		{
			//����������ҵ�һ��С��s��ֵ��a[0]����
			while (i < j && arr[j] >= s)
			{
				j--;
			}
			if (i < j)
			{
				arr[i++] = arr[j];//��a[j]��ֵ��a[i]������i�����һλ
			}

			//�������Ҳ��ҵ�һ�����ڵ���s��ֵ��a[0]����
			while (i < j && arr[i] < s)
			{
				i++;
			}
			if (i < j)
			{
				arr[j--] = arr[i];//��a[i]��ֵ����ʱs���ڵĵ�ַ������j��ǰ��һλ
			}
		}
		arr[i] = s;//��Ϊ��֮ǰ�Ľ���ֵ������a[i]��ֵ�Ѿ����������ֵ������Ҫ�����

		QuickSort(arr, start, i - 1);//��������ǰ����
		QuickSort(arr, i + 1, end);//�������������
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	int arrNum[N_MAX_ARR_NUM] = { 10, 122, 40, 35, 21, 70, 4, 200, 24, 2 };
	cout << "��������Ϊ��" << endl;
	for (int i = 0; i < N_MAX_ARR_NUM; ++i)
	{
		cout << arrNum[i] << " ";
	}
	cout << endl;

	// ð������
	PaoPaoSort(arrNum);

	// ѡ������
	SelectSort(arrNum);

	// ��������
	InsertSort(arrNum);

	// ��������
	cout << "��������:" << endl;
	int arrNum1[N_MAX_ARR_NUM] = { 10, 122, 40, 35, 21, 70, 4, 200, 24, 2 };
	QuickSort(arrNum1, 0, N_MAX_ARR_NUM-1);

	return 0;
}

