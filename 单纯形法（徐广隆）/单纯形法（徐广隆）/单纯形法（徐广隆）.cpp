// �����η������¡��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

// ���任����
int nBaseChangeTime = 0;

/*
// ��������Ĺ�ģ
// �ٶ�������ĸ���
#define N_PARAM 6
// �ڶ���Լ�������ĸ���
#define N_SUBJECT_TO 4
// ���������
int arrBase[N_SUBJECT_TO + 1] = { 0, 3, 4, 5, 6 };
// ����Լ�������ĵ�ʽ
float arrSubject[N_SUBJECT_TO + 1][N_PARAM + 1] =
{
	{ 0, -2, -3, 0, 0, 0, 0 },
	{ 6, 1, 1, 1, 0, 0, 0 },
	{ 8, 1, 2, 0, 1, 0, 0 },
	{ 4, 1, 0, 0, 0, 1, 0 },
	{ 3, 0, 1, 0, 0, 0, 1 }
};
*/

// ��������Ĺ�ģ
// �ٶ�������ĸ���
#define N_PARAM 5
// �ڶ���Լ�������ĸ���
#define N_SUBJECT_TO 3
// ���������
int arrBase[N_SUBJECT_TO + 1] = { 0, 3, 4, 5};
// ����Լ�������ĵ�ʽ
float arrSubject[N_SUBJECT_TO + 1][N_PARAM + 1] =
{
	{ 0, 1500, 2500, 0, 0, 0 },
	{ 65, 3, 2, 1, 0, 0},
	{ 40, 2, 1, 0, 1, 0},
	{ 75, 0, 3, 0, 0, 1},
};

// �ж��б����Ƿ����(�㷨��ֹ����)
bool CheckAllJudgeFinish(const float *arrSubject, int nSize)
{
	for (int i = 1; i < nSize; ++i)
	{
		float nNum = *(arrSubject + i);
		if (nNum > 0)
		{
			return false;
		}
	}

	return true;
}


// ��������б������ڵ��к�
int FindMaxJudgeSerial(const float *arrSubject, int nSize)
{
	float nMaxNum = *(arrSubject + 1);
	int nMaxSerial = 1;

	for (int i = 1; i < nSize; ++i)
	{
		float nNum = *(arrSubject + i);
		if (nNum > 0 && nNum >= nMaxNum)
		{
			nMaxNum = nNum;
			nMaxSerial = i;
		}
	}
	
	return nMaxSerial;
}


// �ҳ�Ҫ�滻�Ļ����
int FindWrapBaseSerial(const float(*arrSubject)[N_PARAM + 1], int nMaxNumSerial)
{
	// �����Ż�������
	float arrJudge[N_SUBJECT_TO + 1];
	for (int l = 0; l <= N_SUBJECT_TO; ++l)
	{
		arrJudge[l] = 0.0;
	}

	// ���oֵ
	for (int o = 1; o <= N_SUBJECT_TO; ++o)
	{

		float b = arrSubject[o][0];
		float a = arrSubject[o][nMaxNumSerial];
		if (a == 0)
		{
			arrJudge[o] = 0;
			continue;
		}
		arrJudge[o] = b / a;
	}

	// ��Сֵ��ΪҪ�滻�Ļ�
	float nMinNum = arrJudge[1];
	int nMinSerial = 1;
	for (int m = 1; m <= N_SUBJECT_TO; ++m)
	{
		float nNum = arrJudge[m];
		if (nNum > 0 && nNum <= nMinNum)
		{
			nMinNum = nNum;
			nMinSerial = m;
		}
	}

	return nMinSerial;
}


// ���任����
void BaseChangeFunction(int nWrapBaseSerial, int nMaxNumSerial)
{
	float  nDiv = arrSubject[nWrapBaseSerial][nMaxNumSerial];
	// �Ȱ�Ҫ�滻�ĵ��й�һ��
	for (int m = 0; m <= N_PARAM; ++m)
	{
		float nNum = arrSubject[nWrapBaseSerial][m];
		arrSubject[nWrapBaseSerial][m] = nNum / nDiv;
	}

	// �ٰѸ��н��б任
	for (int i = 0; i <= N_SUBJECT_TO; ++i)
	{
		if (i == nWrapBaseSerial)
		{
			continue;
		}

		float nRate = arrSubject[i][nMaxNumSerial] / arrSubject[nWrapBaseSerial][nMaxNumSerial];
		for (int j = 0; j <= N_PARAM; ++j)
		{
			float nPre = arrSubject[i][j];
			float nBase = arrSubject[nWrapBaseSerial][j];
			arrSubject[i][j] = nPre - nBase*nRate;
		}
	}

	nBaseChangeTime += 1;
}


// �����ǰ�ĵ����α�
void PrintNowState()
{
	cout << "���ǵ� " << nBaseChangeTime << " ��״̬ʱ�ĵ����α�:" << endl;

	for (int i = 0; i <= N_SUBJECT_TO; ++i)
	{
		for (int j = 0; j <= N_PARAM; ++j)
		{
			cout << arrSubject[i][j] << "  ";
		}
		cout << endl;
	}
}


// �㷨������
int _tmain(int argc, _TCHAR* argv[])
{
	PrintNowState();

	// ��Ҫ������㷨��������
	while (!CheckAllJudgeFinish(arrSubject[0], N_PARAM + 1))
	{
		// ��������б������ڵ��к�
		int nMaxNumSerial = FindMaxJudgeSerial(arrSubject[0], N_PARAM + 1);
		
		// Aik�Ƿ�ȫ���Ƿ���(�ǵĻ�����ֱ�ӽ�����������Ž�)
		bool bAllParamNagetive = true;
		for (int k = 1; k <= N_PARAM; ++k)
		{
			if (arrSubject[k][nMaxNumSerial] > 0)
			{
				bAllParamNagetive = false;
				break;
			}
		}
		if (bAllParamNagetive)
		{
			cout << "���������Ž�" << endl;
			return 0;
		}

		// �ҳ�Ҫ�滻�Ļ����
		int nWrapBaseSerial = FindWrapBaseSerial(arrSubject, nMaxNumSerial);
		arrBase[nWrapBaseSerial] = nMaxNumSerial;

		// ���л��任
		BaseChangeFunction(nWrapBaseSerial, nMaxNumSerial);
		// �����ǰ�ĵ����α�
		PrintNowState();
	}

	// �ҵ������Ž�
	float arrResult[N_PARAM + 1];   //���ڱ������Ž�
	for (int i = 0; i < N_PARAM + 1; ++i)
	{
		arrResult[i] = 0;
	}
	for (int j = 1; j < N_SUBJECT_TO + 1; ++j)
	{
		int nBaseNum = arrBase[j];
		arrResult[nBaseNum] = arrSubject[j][0];
	}
	cout << "���Ž�Ϊ��";

	// ��������Ž���
	for (int i = 1; i <= N_PARAM; ++i)
	{
		cout << "x" << i << " = " << arrResult[i] << "; ";
	}


	cout << endl << "���Ż�ֵΪ��" << -arrSubject[0][0] << endl;

	return 0;
}

