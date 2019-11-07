// ��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// �������������������
#define MaxFirst 3
#define MaxSecond 5
#define MaxThird 8


// ״̬��
class State
{
public:
	int num[3];						// ��¼������ˮ��ĳ��ʱ�̣��ж���ˮ
	int MaxCanPull[3];				// �洢ÿ��ˮ����������
	State* preState;				// ָ��ǰһ��״̬��ָ��
 
public:
	State(int first,int second,int third)
	{
		num[0]=first;
		num[1]=second;
		num[2]=third;	
	}

	void init()
	{		
		MaxCanPull[0] = MaxFirst;
		MaxCanPull[1] = MaxSecond;
		MaxCanPull[2] = MaxThird;
	}
 
	//�ж��Ƿ���Դ�fromˮ���е�ˮ��toˮ����
	bool canPour(int from,int to)
	{
		//�������Լ����Լ���
		if (from == to)
		{
			return false;
		}

		//Դ��Ϊ��
		if (num[from]==0)
		{
			return false;
		}
		//Ŀ�����
		if (num[to] == MaxCanPull[to])
		{
			return false;
		}
		else 
		{
			return true;
		}
	}

	//��ˮ���̣���fromˮ���е�ˮ��toˮ����
	void pour(int from,int to)//��ˮ����
	{
		//Ŀ������ܵ������ˮ
		int nCanPull = MaxCanPull[to] - num[to];
		//Դ��̫���ˣ�ֻ������˵
		if (num[from] > nCanPull)
		{
			num[from] = num[from] - nCanPull;
			num[to] = MaxCanPull[to];
		}
		//����ȫ����ȥ
		else
		{
			num[to]=num[to]+num[from];
			num[from]=0;
		}
	}

	//����hashֵ
	int CalcuHash()
	{
		return num[0]*100 + num[1]*10 + num[2];
	}
 
};

int _tmain(int argc, _TCHAR* argv[])
{
	//��¼�¸���״̬��hashMap
	//���磬0��a��1��b��2��c����haspMap[a*100+b*10+c]=true;
	map<int,bool> haspMap;

	State *start=new State(0,0,8);
	start->init();
	State *endState=new State(8,8,8);//ֻ�л�ý�endState�Ż�ı䣬��ֵȫΪ8Ϊ�˷����ж��Ƿ������ս�

	//��������״̬����
	vector<State> action;
	//�ѳ�ʼ״̬�ȼ��������
	action.push_back(*start);
	
	int n=0;
	//��ǰ״̬
	State *Currentstate = start;
	do{
		//˫��ѭ��Ϊ��iˮ���е�ˮ��jˮ����
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if (Currentstate->canPour(i, j))
					{
						Currentstate->pour(i, j);
						//�����ϣֵ
						int NumHash = Currentstate->CalcuHash();
						//�����״̬����hash���У���Ϊ��һ�γ��ָ�״̬
						if (!haspMap[NumHash])
						{
							haspMap[NumHash] = true;
							(Currentstate->preState) = new State(action[n]);
							action.push_back(*Currentstate);

							//�ҵ�����ֹͣ����
							if (Currentstate->num[0] == 4 || Currentstate->num[1] == 4 || Currentstate->num[2] == 4)
							{
								
								endState = Currentstate;
								i=4;
								break;	
							}
					    }
					}
		
				*Currentstate = action[n];
			}			
		}
		n++;
	}
	while(endState->num[0]==8&&endState->num[1]==8&& n<action.size());

	//������
	cout << endState->num[0] << " " << endState->num[1] << " " << endState->num[2] << endl;
	Currentstate = endState;
	do
	{
		Currentstate = Currentstate->preState;
		cout << Currentstate->num[0] << " " << Currentstate->num[1] << " " << Currentstate->num[2] << endl;
		
	} 
	while (Currentstate->preState != NULL);

	return 0;
}

