// ������������.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*
ʹ�û��ݷ�,���ϵ��´���������ʹ��ÿ�����ʹ��ĸ��Ӷ��������״̬.
��δ�������״̬�ĵ�ǰ���������״ֻ̬���������,�ڵ�ǰ�ڵ���û�����,���Ҳ�ڵ���û�����,���·��ڵ���û�����,���εݹ��ж�.
��¼��ʼ������ֵΪһ�����ֵ,ÿ�η�����뵱ǰ����ֵ�Ƚϲ����´�.
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

// ����һ���������ֵMAX_ARRAY_DEM
const int MMAX_ARRAY_DEM = 100;
// ����5������{0��0}ԭλ�ã�{0��1}�±ߣ�{0��-1}�ϱߣ�{1��0}�ұߣ�{-1��0}���
const int go[5][2] = { { 0, 0 }, { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
// ����n������m
int n, m;
// �����¼���飬�����¼��������
int anx[MMAX_ARRAY_DEM][MMAX_ARRAY_DEM], ans;
// putΪ�������飬spyΪ������飬spysΪ���λ����
int put[MMAX_ARRAY_DEM][MMAX_ARRAY_DEM], spy[MMAX_ARRAY_DEM][MMAX_ARRAY_DEM], tmp, spys = 0;

// ��ΪSearch��Ҫ�õ�Puta��Puta������Ҫ�õ�Search����������ǰ������Search����ȻPuta��������
void Search(int i, int j);

// �������ú���
// x,yΪ����������λ��
// i,jΪ����ص��λ��
void Puta(int x, int y, int i, int j)
{
	// ��ռλ��5������
	put[x][y] = 1;
	tmp++;
	for (int i = 0; i < 5; ++i)
	{
		if (++spy[x + go[i][0]][y + go[i][1]] == 1)
		{
			spys++;
		}
	}

	// ������һ��λ��
	Search(i, j + 1);

	// ����λ��5������
	put[x][y] = 0;
	tmp--;
	for (int i = 0; i < 5; ++i)
	{
		if (--spy[x + go[i][0]][y + go[i][1]] == 0)
		{
			spys--;
		}
	}
}

// ���ĳ�����λ�ã���Ӽ��
void Search(int i, int j)
{
	// ��ǰ����������������С������������������ȥ��
	if (tmp >= ans)
	{
		return;
	}

	//�ѷ��õĲ��ٱ�����
	while (i <= n && spy[i][j]) 
	{
		++j;
		if (j > m)
		{
			++i, j = 1;
		}
	}

	//���´�
	if (i > n)					
	{
		ans = tmp;
		memcpy(anx, put, sizeof(put));
		return;
	}

	//������һ���Ż���֦���ԣ����õĻ����˸������ᳬ��nm/3+1��
	//(��ÿ�������˽��������һ����¿���,�ѵ�������С����,���ֻ��ʣ��11,12,22����ʣ��,������).
	//��n*m/3+2Ϊ��ʼ����ֵ,�����õĸ���������ǰ����ֵʱ,��ȥ.��
	/*
	int lim1 = n * m;
	int lim2 = n * m + m / 4 + 5;
	int reach = spys + (ans - tmp) * 5;
	if (reach <= lim1)
	{
		return;
	}
	if (i < n - 1 && reach <= lim2)
	{
		return;
	}
	*/


	//��(i, j + 1)�ѱ�����, ����(i, j)����һ���������(i + 1, j)���õ������.
	//���Ե��ҽ���(i, j)���������½ǻ���(i, j + 1)δ������ʱ�ſ��Ƿ�����(i, j)�����.
	if ((i == n&&j == m) || spy[i][j + 1] == 0)
	{
		// ����ԭλ��
		Puta(i, j, i, j);
	}
	//��i=nʱ,�����Ƿ�����(i+1,j)�����,����i<nʱ�����ұ�
	if (i < n)
	{
		// �����ұ�
		Puta(i + 1, j, i, j);
	}
	//��(i, j + 1)��(i, j + 2)��������, ����(i + 1, j)����һ���������(i + 1, j)���õ������, 
	//���Ե��ҽ���(i, j + 1)��(i, j + 2)δ������ʱ�ſ��Ƿ�����(i, j + 1)�����.
	if (j < m && (spy[i][j + 1] == 0 || spy[i][j + 2] == 0))
	{
		// ��������
		Puta(i, j + 1, i, j);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "������кţ�";
	cin >> n;
	cout << "������кţ�";
	cin >> m;

	// ���������ó�һ�����ֵ
	ans = n * m / 3 + 2;
	for (int i = 0; i <= n + 1; ++i)
	{
		spy[i][0] = spy[i][m + 1] = 1;
	}
	for (int i = 0; i <= m + 1; ++i)
	{
		spy[0][i] = spy[n + 1][i] = 1;
	}
		
	// �㷨��ʼ
	Search(1, 1);

	// ������
	cout << "������Ҫ" << ans << "������" << endl;
	cout << "����λ��Ϊ��" << endl;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cout << anx[i][j] << (j == m ? '\n' : ' ');
		}
	}
	return 0;
}

