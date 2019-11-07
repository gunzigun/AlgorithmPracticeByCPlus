// ѭ��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

// ѭ����������
void GameTable(vector<vector<int>> &vec)  // �������ã���֤���������ٺ����иı�
{
	// �޶��飬�򷵻�
	if (vec.size() == 0)
	{
		return;
	}
	size_t s = vec.size();

	// ������2�Ķ��ٴη�
	int k = 0;
	while (s = s >> 1)  // �����ƶ�һλ���൱�ڳ���2
	{
		k++;	
	}

	//��ʼ������С����Ϊ���飬����ֱ�ӳ�ʼ����
	vec[0][0] = 1;
	vec[0][1] = 2;
	vec[1][0] = 2;
	vec[1][1] = 1;

	// ����ʹ��ѭ����ÿ�ν���ģ����һ��
	for (int i = 2; i <= k; i++)
	{
		// length = 2^i�η�
		int length = 0x1 << i;
		// halfΪ��һ��
		int half = length >> 1;

		//��һ�����Ϊ4���ӱ����Ͻ���֪�����£����ϣ�����δ֪

		//�� ���� = ���� + helf
		//���½ǵ��ӱ�����Ϊ���Ͻ��ӱ��Ӧ���half=2^(i-1)
		for (int row = 0; row < half; row++)
		{
			for (int col = 0; col < half; col++)
			{
				vec[row + half][col] = vec[row][col] + half;
			}
		}
		
		//�� ���� = ���� 
		//���Ͻǵ��ӱ�������½��ӱ�
		for (int row = 0; row < half; row++)
		{
			for (int col = 0; col < half; col++)
			{
				vec[row][col + half] = vec[row + half][col];
			}
		}

		//�� ���� = ����
		//���½ǵ��ӱ�������Ͻ��ӱ�
		for (int row = 0; row < half; row++)
		{
			for (int col = 0; col < half; col++)
			{
				vec[row + half][col + half] = vec[row][col];
			}
		}
	}
}



int _tmain(int argc, _TCHAR* argv[])
{
	cout << "����2^k��ѡ�ֲμӱ���������k��k>0����" << endl;
	int k;
	do
	{
		cin >> k;
	} 
	while (k < 0 || k > 31); // ����̫�󣬻���ʾ���£����ڴ�

	int s = 0x1 << k; // ���2��k�η�������1����λk�Σ�
	vector<vector<int> > vec(s, vector<int>(s, 0));//��vector��ʾ�Ķ�ά����ȫ����ʼ����0

	GameTable(vec);

	// ������������
	for (size_t i = 0; i < vec.size(); i++)
	{
		for (size_t j = 0; j < vec[i].size(); j++)
		{
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

