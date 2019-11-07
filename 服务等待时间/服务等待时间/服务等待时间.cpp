// 服务等待时间.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#define TOTAL_PEOPLE_NUM 7

int _tmain(int argc, _TCHAR* argv[])
{
	int arrNeedTime[TOTAL_PEOPLE_NUM] = { 1, 3, 2, 15, 10, 6, 12 };
	int arrFlag[TOTAL_PEOPLE_NUM] = { 0, 0, 0, 0, 0, 0, 0 };

	// 为了使总等待时间最少，应该保证占用时间短的先去获取资源
	int nFinish = 0;
	// 记录每个人的等待时间（不断变化）
	int nTimeWaitPeople = 0;
	// 记录总等待时间
	int nTimeWait = 0;
	do 
	{
		int nMin = 1000000;
		int nMinIdex;
		for (int i = 0; i < TOTAL_PEOPLE_NUM; ++i)
		{
			// 在"未完成"(arrFlag[i] != 1)的人中选出耗时最少的
			if (arrFlag[i] != 1 && arrNeedTime[i] < nMin)
			{
				nMin = arrNeedTime[i];
				nMinIdex = i;
			}
		}

		cout << "第" << nFinish + 1 << "次选取，第" << nMinIdex << "个人，时间：" << nMin << endl;
		cout << "此人等待时间：" << nTimeWaitPeople << endl;
		arrFlag[nMinIdex] = 1;

		// 增加总等待时长
		nTimeWait += nTimeWaitPeople;

		// 增加下个人等待时长
		nTimeWaitPeople += nMin;

		++nFinish;

	} while (nFinish != TOTAL_PEOPLE_NUM);

	cout << "总等待时间为：" << nTimeWait << endl;
	cout << "总耗时为：" << nTimeWaitPeople << endl;

	return 0;
}

