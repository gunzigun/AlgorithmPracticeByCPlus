// ������Ϸ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
using namespace std;
#define NUM_CELL_CUBE_MODEL 11

//����ϸ���ṹ
struct Cell
{
	bool live; //��־�Ƿ���
	int  others; //��־��Χ�Ĵ��ϸ����
};

int _tmain(int argc, _TCHAR* argv[])
{
	//����ϸ������
	Cell cell[NUM_CELL_CUBE_MODEL][NUM_CELL_CUBE_MODEL];

	//����1����ʼ���������и��ӵ�ϸ����ʼ���ɻ�ģ���Χû������ϸ��
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

	
	//��ʼ��ֵ�����Լ��趨
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
	
	//����2��ϸ�����ϱ仯
	while (1)
	{
		//����2.1����������ϸ����������ʾ����ͳ����Χ����
		for (int i = 0; i < NUM_CELL_CUBE_MODEL; i++)
		{
			for (int j = 0; j < NUM_CELL_CUBE_MODEL; j++)
			{
				//����2.1.1��ÿ�α仯ǰ���Ȱ�ÿ��ϸ����Χ����������Ϊ0
				cell[i][j].others = 0;

				//����2.1.2��ÿ��ϸ������ǻ�ı�ǡ���ı�ǡ�
				if (cell[i][j].live)
				{
					cout << "��  ";
				}
				else
				{
					cout << "��  ";
				}

				//����2.1.3�����˸������Ƿ��д��ϸ��������ÿһ��ϸ������Χ�����
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

		//����2.2������ͳ�����������¼�����һ�̵Ĵ�����
		for (int i = 0; i < NUM_CELL_CUBE_MODEL; i++)
		{
			for (int j = 0; j < NUM_CELL_CUBE_MODEL; j++)
			{
				//����2.2.1�����ŵĿ�����
				if (cell[i][j].live)
				{
					switch (cell[i][j].others)
					{
					case 2:
					case 3:cell[i][j].live = true; break;
					default:cell[i][j].live = false; break;
					}
				}
				//����2.2.2�����˵Ŀ��ܻ�
				else
				{
					if (cell[i][j].others == 3)
					{
						cell[i][j].live = true;
					}
				}
			}
		}

		//ÿ1��ˢ��һ��
		Sleep(1000);
		//�����Ļ����
		system("cls");
	}
	return 0;
}

