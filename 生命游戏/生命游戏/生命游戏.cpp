// 生命游戏.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
using namespace std;
#define NUM_CELL_CUBE_MODEL 11

//定义细胞结构
struct Cell
{
	bool live; //标志是否存活
	int  others; //标志周围的存活细胞数
};

int _tmain(int argc, _TCHAR* argv[])
{
	//定义细胞数组
	Cell cell[NUM_CELL_CUBE_MODEL][NUM_CELL_CUBE_MODEL];

	//步骤1：初始化，把所有格子的细胞初始化成活的，周围没有其他细胞
	/*
	for (int i = 0; i < NUM_CELL_CUBE_MODEL; i++)
	{
		for (int j = 0; j < NUM_CELL_CUBE_MODEL; j++)
		{
			cell[i][j].live = true;
			cell[i][j].others = 0;
		}
	}
	*/

	
	//初始化值可以自己设定
	for (int i = 0; i < NUM_CELL_CUBE_MODEL; i++)
	{
		for (int j = 0; j < NUM_CELL_CUBE_MODEL; j++)
		{
			cell[i][j].live = false;
			cell[i][j].others = 0;
		}
	}
	cell[0][5].live = true;
	cell[1][5].live = true;
	cell[2][5].live = true;
	cell[3][5].live = true;
	cell[4][5].live = true;
	cell[5][5].live = true;
	cell[6][5].live = true;
	cell[7][5].live = true;
	cell[8][5].live = true;
	cell[9][5].live = true;
	cell[10][5].live = true;
	
	//步骤2：细胞不断变化
	while (1)
	{
		//步骤2.1：遍历所有细胞，进行显示，并统计周围数量
		for (int i = 0; i < NUM_CELL_CUBE_MODEL; i++)
		{
			for (int j = 0; j < NUM_CELL_CUBE_MODEL; j++)
			{
				//步骤2.1.1：每次变化前，先把每个细胞周围死亡数量设为0
				cell[i][j].others = 0;

				//步骤2.1.2：每个细胞如果是活的标记★，死的标记☆
				if (cell[i][j].live)
				{
					cout << "★  ";
				}
				else
				{
					cout << "☆  ";
				}

				//步骤2.1.3：检测八个方向是否有存活细胞，计算每一个细胞的周围存活数
				if ((i - 1) >= 0 && (j - 1) >= 0 && cell[i - 1][j - 1].live)
					cell[i][j].others++;
				if ((i - 1) >= 0 && cell[i - 1][j].live)
					cell[i][j].others++;
				if ((i - 1) >= 0 && (j + 1) < NUM_CELL_CUBE_MODEL && cell[i - 1][j + 1].live)
					cell[i][j].others++;
				if ((j - 1) >= 0 && cell[i][j - 1].live)
					cell[i][j].others++;
				if ((j + 1) < NUM_CELL_CUBE_MODEL && cell[i][j + 1].live)
					cell[i][j].others++;
				if ((i + 1) < NUM_CELL_CUBE_MODEL && (j - 1) >= 0 && cell[i + 1][j - 1].live)
					cell[i][j].others++;
				if ((i + 1) < NUM_CELL_CUBE_MODEL && cell[i + 1][j].live)
					cell[i][j].others++;
				if ((i + 1) < NUM_CELL_CUBE_MODEL && (j + 1) < NUM_CELL_CUBE_MODEL && cell[i + 1][j + 1].live)
					cell[i][j].others++;
			}
			cout << endl << endl;
		}

		//步骤2.2：根据统计数量，重新计算下一刻的存活情况
		for (int i = 0; i < NUM_CELL_CUBE_MODEL; i++)
		{
			for (int j = 0; j < NUM_CELL_CUBE_MODEL; j++)
			{
				//步骤2.2.1：活着的可能死
				if (cell[i][j].live)
				{
					switch (cell[i][j].others)
					{
					case 2:
					case 3:cell[i][j].live = true; break;
					default:cell[i][j].live = false; break;
					}
				}
				//步骤2.2.2：死了的可能活
				else
				{
					if (cell[i][j].others == 3)
					{
						cell[i][j].live = true;
					}
				}
			}
		}

		//每1秒刷新一次
		Sleep(1000);
		//清楚屏幕函数
		system("cls");
	}
	return 0;
}

