// ����ȴ�ʱ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#define TOTAL_PEOPLE_NUM 7

int _tmain(int argc, _TCHAR* argv[])
{
	int arrNeedTime[TOTAL_PEOPLE_NUM] = { 1, 3, 2, 15, 10, 6, 12 };
	int arrFlag[TOTAL_PEOPLE_NUM] = { 0, 0, 0, 0, 0, 0, 0 };

	// Ϊ��ʹ�ܵȴ�ʱ�����٣�Ӧ�ñ�֤ռ��ʱ��̵���ȥ��ȡ��Դ
	int nFinish = 0;
	// ��¼ÿ���˵ĵȴ�ʱ�䣨���ϱ仯��
	int nTimeWaitPeople = 0;
	// ��¼�ܵȴ�ʱ��
	int nTimeWait = 0;
	do 
	{
		int nMin = 1000000;
		int nMinIdex;
		for (int i = 0; i < TOTAL_PEOPLE_NUM; ++i)
		{
			// ��"δ���"(arrFlag[i] != 1)������ѡ����ʱ���ٵ�
			if (arrFlag[i] != 1 && arrNeedTime[i] < nMin)
			{
				nMin = arrNeedTime[i];
				nMinIdex = i;
			}
		}

		cout << "��" << nFinish + 1 << "��ѡȡ����" << nMinIdex << "���ˣ�ʱ�䣺" << nMin << endl;
		cout << "���˵ȴ�ʱ�䣺" << nTimeWaitPeople << endl;
		arrFlag[nMinIdex] = 1;

		// �����ܵȴ�ʱ��
		nTimeWait += nTimeWaitPeople;

		// �����¸��˵ȴ�ʱ��
		nTimeWaitPeople += nMin;

		++nFinish;

	} while (nFinish != TOTAL_PEOPLE_NUM);

	cout << "�ܵȴ�ʱ��Ϊ��" << nTimeWait << endl;
	cout << "�ܺ�ʱΪ��" << nTimeWaitPeople << endl;

	return 0;
}

