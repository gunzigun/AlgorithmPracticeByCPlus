// TSP���⣨̰���㷨��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#define N_TOTAL_CITY_NUM 4


int _tmain(int argc, _TCHAR* argv[])
{

	//���ڴ洢�ѷ��ʹ��ĳ���
	int S[N_TOTAL_CITY_NUM];
	//���ڼ����ѷ��ʹ��ĳ��е���С·������
	int sum = 0;
	//���ڴ洢��������֮��ľ���
	int D[N_TOTAL_CITY_NUM][N_TOTAL_CITY_NUM] = {0};

	/*��ʼ��:��̾���Ϊ0*/
	S[0] = 0;
	/*��ʼ��:��������֮��ľ���*/
	D[0][1] = 2; D[0][2] = 6; D[0][3] = 5; D[1][0] = 2; D[1][2] = 4;
	D[1][3] = 4; D[2][0] = 6; D[2][1] = 4; D[2][3] = 2; D[3][0] = 5;
	D[3][1] = 4; D[3][2] = 2;
	cout << "�������еľ������Ϊ��" << endl;
	for (int m = 0; m < N_TOTAL_CITY_NUM; ++m)
	{
		for (int n = 0; n < N_TOTAL_CITY_NUM; ++n)
		{
			cout << D[m][n] << "  ";
		}
		cout << endl;
	}

	// ̰���㷨��ʼ
	int j; // һ����ʱ����
	int i = 1;  //(��ʼ����ʵĳ�����)
	do
	{
		// Dtemp�趨Ϊһ���ܴ����ֵ����ʾ�����
		int Dtemp = 10000;
		int k = 1;  //(�յ���ʵĳ�����)
		do
		{
			int l = 0;
			//��Ϊ���ʵı�־���������ʹ���Ϊ1����δ�����ʹ���Ϊ0
			int flag = 0;
			do
			{
				if (S[l] == k)
				{
					//�жϸó����Ƿ��ѱ����ʹ����������ʹ���
					flag = 1;//��flagΪ1
					break;//����ѭ�������������ıȽ�
				}
				else
				{
					l++;
				}
					
			}while (l < i);

			if (flag == 0 && D[k][S[i - 1]] < Dtemp)
			{
				/*D[k][S[i - 1]]��ʾ��ǰδ�����ʵĳ���k����һ���ѷ��ʹ��ĳ���i-1֮��ľ���*/
				j = k;//j���ڴ洢�ѷ��ʹ��ĳ���k
				Dtemp = D[k][S[i - 1]];//Dtemp������ʱ�洢��ǰ��С·����ֵ
			}

			k++;

		} while (k < N_TOTAL_CITY_NUM);

		S[i] = j;//���ѷ��ʹ��ĳ���j���뵽S[i]��
		i++;
		sum += Dtemp;//���������֮�����̾��룬ע�⣺�ڽ���ѭ��ʱ������������δ�ص�ԭ�����ĳ���

	} while (i < N_TOTAL_CITY_NUM);


	sum += D[0][j];//D[0][j]Ϊ���������ڵ����һ��������ԭ�����ĳ���֮��ľ���
	cout << "���������·��Ϊ��";
	for (j = 0; j < N_TOTAL_CITY_NUM; j++)
	{ 
		//��������ĳ��е�·��
		cout << j << " ";
	}
	cout << endl << "���·����ֵΪ��" << sum << endl; //������·����ֵ

}

