// 排序问题（第二次作业）.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <stack>
#define N_MAX_ARR_NUM 10
using namespace std;

// 冒泡排序
void PaoPaoSort(int arrNum[])
{
	// 为了影响原数组，拷贝一遍
	int TepNum[N_MAX_ARR_NUM];
	for (int i = 0; i < N_MAX_ARR_NUM; ++i)
	{
		TepNum[i] = arrNum[i];
	}

	// 算法开始
	cout << "冒泡排序:" << endl;

	for (int i = 0; i < N_MAX_ARR_NUM; ++i)
	{
		// 每一趟最大的沉底，或者最小的冒泡
		for (int j = i + 1; j < N_MAX_ARR_NUM; ++j)
		{
			if (TepNum[j] < TepNum[j - 1])
			{
				// 交换两个值(这里有个技巧，不用设置零时变量，达到了交换的目的)
				// a = a + b
				// b = a - b
				// a = a - b
				TepNum[j] = TepNum[j - 1] + TepNum[j];
				TepNum[j - 1] = TepNum[j] - TepNum[j - 1];
				TepNum[j] = TepNum[j] - TepNum[j - 1];
			}
		}

		// 输出每一步的排序结果
		for (int m = 0; m < N_MAX_ARR_NUM; ++m)
		{
			cout << right << setw(6) << TepNum[m]; //右对齐
		}
		cout << endl;
	}
}

// 选择排序
void SelectSort(int arrNum[])
{
	// 为了影响原数组，拷贝一遍
	int TepNum[N_MAX_ARR_NUM];
	for (int i = 0; i < N_MAX_ARR_NUM; ++i)
	{
		TepNum[i] = arrNum[i];
	}

	// 算法开始
	cout << "选择排序:" << endl;

	
	for (int i = 0; i < N_MAX_ARR_NUM-1; ++i)
	{
		// 每一趟没有两两比较，与冒泡不同，只是记录了最小，或最大的位置，最后交换到合适位置
		int nMinIndex = i;
		for (int j = i + 1; j < N_MAX_ARR_NUM; ++j)
		{
			if (TepNum[j] < TepNum[nMinIndex])
			{
				nMinIndex = j;
			}
		}

		// 交换nMinIdex和i的值
		TepNum[i] = TepNum[nMinIndex] + TepNum[i];
		TepNum[nMinIndex] = TepNum[i] - TepNum[nMinIndex];
		TepNum[i] = TepNum[i] - TepNum[nMinIndex];

		// 输出每一步的排序结果
		for (int m = 0; m < N_MAX_ARR_NUM; ++m)
		{
			cout << right << setw(10) << TepNum[m]; //右对齐
		}
		cout << endl;
	}

}

// 插入排序
void InsertSort(int arrNum[])
{
	// 为了影响原数组，拷贝一遍
	int TepNum[N_MAX_ARR_NUM];
	for (int i = 0; i < N_MAX_ARR_NUM; ++i)
	{
		TepNum[i] = arrNum[i];
	}

	// 算法开始
	cout << "插入排序:" << endl;

	for (int i = 0; i < N_MAX_ARR_NUM; ++i)
	{ 
		// 每次直接插入到位置，然后后面的数值全部向后移动
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

		// 输出每一步的排序结果
		for (int m = 0; m < N_MAX_ARR_NUM; ++m)
		{
			cout << right << setw(10) << TepNum[m]; //右对齐
		}
		cout << endl;
	}

}

// 快速排序
void QuickSort(int arr[], int start, int end) {
	// 输出每一步的排序结果
	for (int m = 0; m < N_MAX_ARR_NUM; ++m)
	{
		cout << right << setw(10) << arr[m]; //右对齐
	}
	cout << endl;
	
	if (start < end) 
	{
		int s = arr[start];
		int i = start;
		int j = end;

		//注意刚开始排序一定得从右向左查找才可以
		while (i < j)
		{
			//从右向左查找第一个小于s的值与a[0]交换
			while (i < j && arr[j] >= s)
			{
				j--;
			}
			if (i < j)
			{
				arr[i++] = arr[j];//把a[j]的值给a[i]，并让i向后走一位
			}

			//从左向右查找第一个大于等于s的值与a[0]交换
			while (i < j && arr[i] < s)
			{
				i++;
			}
			if (i < j)
			{
				arr[j--] = arr[i];//把a[i]的值给此时s所在的地址，并让j向前退一位
			}
		}
		arr[i] = s;//因为在之前的交换值过程中a[i]的值已经不是最初的值，所以要变回来

		QuickSort(arr, start, i - 1);//排序枢轴前数列
		QuickSort(arr, i + 1, end);//排序枢轴后数列
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	int arrNum[N_MAX_ARR_NUM] = { 10, 122, 40, 35, 21, 70, 4, 200, 24, 2 };
	cout << "输入数组为：" << endl;
	for (int i = 0; i < N_MAX_ARR_NUM; ++i)
	{
		cout << arrNum[i] << " ";
	}
	cout << endl;

	// 冒泡排序
	PaoPaoSort(arrNum);

	// 选择排序
	SelectSort(arrNum);

	// 插入排序
	InsertSort(arrNum);

	// 快速排序
	cout << "快速排序:" << endl;
	int arrNum1[N_MAX_ARR_NUM] = { 10, 122, 40, 35, 21, 70, 4, 200, 24, 2 };
	QuickSort(arrNum1, 0, N_MAX_ARR_NUM-1);

	return 0;
}

